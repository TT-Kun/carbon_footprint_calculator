#include "chartpage.h"
#include "ui_chartpage.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVBoxLayout>
#include <QPainter>
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QMessageBox>
#include <QPainterPath>

ChartPage::ChartPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChartPage),
    currentUsername("默认用户") // 初始化当前用户名
{
    ui->setupUi(this);

    // 初始化用户信息标签
    ui->userInfoLabel->setText("当前用户：未登录 (显示的是默认数据)");

    // 设置滚动区域属性
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    // 初始化时显示noDataLabel
    ui->noDataLabel->setVisible(true);


}

ChartPage::~ChartPage()
{
    delete ui;
}

void ChartPage::updateCharts(const QString &username)
{
    currentUsername = username;

    // 更新用户信息标签
    if (username.isEmpty() || username == "默认用户") {
        ui->userInfoLabel->setText("当前用户：未登录 (显示的是默认数据)");
    } else {
        ui->userInfoLabel->setText("当前用户：" + username + " ");
    }

    loadChartData(username);

    // 清除现有图表
    while (QLayoutItem* item = ui->chartsLayout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }

    // 根据是否有数据显示noDataLabel
    if (timestamps.isEmpty()) {
        ui->noDataLabel->setVisible(true);
    } else {
        ui->noDataLabel->setVisible(false);

        // 添加新的图表
        ui->chartsLayout->addWidget(createBasicTrendChart(), 0, 0);
        ui->chartsLayout->addWidget(createBasicCategoryChart(), 0, 1);
        ui->chartsLayout->addWidget(createBasicComparisonChart(), 1, 0, 1, 2);
    }
}

void ChartPage::loadChartData(const QString &username)
{
    // 清除旧数据
    currentTotalData.clear();
    categoryData.clear();
    timestamps.clear();
    values.clear();

    // 如果用户名为空或默认用户，则不加载数据
    if (username.isEmpty() || username == "默认用户") {
        return;
    }

    // 获取应用程序所在目录
    QString appDir = QCoreApplication::applicationDirPath();
    QString dataDir = appDir + "/data";
    QString userSpecificFile = dataDir + "/carbon_data_" + username + ".json";
    
    // 检查用户特定的文件是否存在
    QFile userFile(userSpecificFile);
    if (!userFile.exists()) {
        return; // 如果用户文件不存在，则不加载数据
    }
    
    // 加载用户特定的数据文件
    if (userFile.open(QIODevice::ReadOnly)) {
        QByteArray data = userFile.readAll();
            QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonArray dataArray = doc.array();
        
        // 解析数据数组
        for (const QJsonValue &value : dataArray) {
            QJsonObject obj = value.toObject();

            // 获取时间戳和总碳足迹
            QDateTime timestamp = QDateTime::fromString(obj["timestamp"].toString(), Qt::ISODate);
            double totalCarbon = obj["totalCarbonFootprint"].toDouble();

            // 添加到趋势数据
            timestamps.append(timestamp);
            values.append(totalCarbon);

            // 获取排放详情数据
            QJsonObject detailDataObj = obj["detailData"].toObject();
            QMap<QString, double> detailData;

            // 直接提取三大类别数据，已经是以个人为单位计算的
            double transportEmission = 0.0;
            double homeEmission = 0.0;
            double consumptionEmission = 0.0;
            
            // 检查详情数据中是否已经包含三大分类
            if (detailDataObj.contains("交通排放")) {
                transportEmission = detailDataObj["交通排放"].toDouble();
                detailData["交通排放"] = transportEmission;
            }
            if (detailDataObj.contains("家居排放")) {
                homeEmission = detailDataObj["家居排放"].toDouble();
                detailData["家居排放"] = homeEmission;
            }
            if (detailDataObj.contains("消费排放")) {
                consumptionEmission = detailDataObj["消费排放"].toDouble();
                detailData["消费排放"] = consumptionEmission;
            }
            
            // 如果没有找到分类总数，则尝试从细分项汇总
            if (transportEmission == 0.0 && homeEmission == 0.0 && consumptionEmission == 0.0) {
                // 飞机、火车、公交车、私家车 -> 交通排放
                for (const QString &key : {"飞机", "火车", "公交车", "私家车"}) {
                    if (detailDataObj.contains(key)) {
                        transportEmission += detailDataObj[key].toDouble();
                    }
                }
                detailData["交通排放"] = transportEmission;

                // 用电、居住面积 -> 家居排放
                for (const QString &key : {"用电", "居住面积"}) {
                    if (detailDataObj.contains(key)) {
                        homeEmission += detailDataObj[key].toDouble();
                    }
                }
                detailData["家居排放"] = homeEmission;
                
                // 一次性筷子、塑料袋、衣物、纸张 -> 消费排放
                for (const QString &key : {"一次性筷子", "塑料袋", "衣物", "纸张"}) {
                    if (detailDataObj.contains(key)) {
                        consumptionEmission += detailDataObj[key].toDouble();
                    }
                }
                detailData["消费排放"] = consumptionEmission;
            }
            
            // 更新分类数据
            QString monthKey = timestamp.toString("yyyy-MM");
            if (!categoryData.contains(monthKey)) {
                categoryData[monthKey] = QMap<QString, double>();
                }
            
            categoryData[monthKey]["交通排放"] += transportEmission;
            categoryData[monthKey]["家居排放"] += homeEmission;
            categoryData[monthKey]["消费排放"] += consumptionEmission;
            
            // 更新总数据
            currentTotalData["交通排放"] += transportEmission;
            currentTotalData["家居排放"] += homeEmission;
            currentTotalData["消费排放"] += consumptionEmission;
            }

        userFile.close();
    }

    // 如果没有数据，显示提示
    if (timestamps.isEmpty()) {
        ui->noDataLabel->setVisible(true);
    } else {
        ui->noDataLabel->setVisible(false);
    }
}

// 基本绘图实现的图表部件
class BasicChartWidget : public QWidget {
public:
    enum ChartType { TrendChart, CategoryChart, ComparisonChart };

    BasicChartWidget(ChartType type, const QVector<QDateTime>& timestamps,
                    const QVector<double>& values,
                    const QMap<QString, double>& categoryData,
                    const QMap<QString, QMap<QString, double>>& monthlyData,
                    QWidget* parent = nullptr)
        : QWidget(parent), m_type(type), m_timestamps(timestamps),
          m_values(values), m_categoryData(categoryData), m_monthlyData(monthlyData)
    {
        // 调整图表尺寸，使其更紧凑
        if (type == TrendChart) {
            setMinimumSize(380, 300); // 趋势图稍微缩小
            setMaximumHeight(350);
        } else {
            setMinimumSize(400, 320);
            setMaximumHeight(400); // 限制最大高度
        }

        // 设置背景色
        QPalette pal = palette();
        pal.setColor(QPalette::Window, QColor(245, 245, 245)); // 更柔和的背景色
        setAutoFillBackground(true);
        setPalette(pal);

        // 创建标题标签
        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->setContentsMargins(10, 10, 10, 10); // 增加边距

        m_titleLabel = new QLabel(this);
        m_titleLabel->setAlignment(Qt::AlignCenter);
        QFont titleFont = m_titleLabel->font();
        titleFont.setPointSize(14); // 调整字号
        titleFont.setBold(true);
        m_titleLabel->setFont(titleFont);
        m_titleLabel->setStyleSheet("color: #1a5276; background-color: rgba(255, 255, 255, 180); border-radius: 4px; padding: 4px;"); // 深蓝色字体，白色半透明背景

        switch (m_type) {
            case TrendChart:
                m_titleLabel->setText("碳足迹趋势图");
                break;
            case CategoryChart:
                m_titleLabel->setText("碳足迹分类占比");
                break;
            case ComparisonChart:
                m_titleLabel->setText("月度碳足迹对比");
                break;
        }

        layout->addWidget(m_titleLabel);
        layout->addStretch();
    }

protected:
    void paintEvent(QPaintEvent* event) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        // 绘制边框和背景
        painter.setPen(QPen(QColor(220, 220, 220), 1));
        painter.setBrush(QColor(255, 255, 255));
        painter.drawRoundedRect(10, 40, width() - 20, height() - 60, 5, 5);

        // 根据图表类型绘制图表
        switch (m_type) {
            case TrendChart:
                drawTrendChart(&painter);
                break;
            case CategoryChart:
                drawCategoryChart(&painter);
                break;
            case ComparisonChart:
                drawComparisonChart(&painter);
                break;
        }
    }

private:
    void drawTrendChart(QPainter* painter) {
        int chartWidth = width() - 80; // 进一步减少左右边距，使图表更紧凑
        int chartHeight = height() - 100; // 减少上下边距
        int startX = 60;
        int startY = height() - 40;

        // 绘制坐标轴
        painter->setPen(QPen(QColor(80, 80, 80), 2));
        painter->drawLine(startX, startY, startX + chartWidth, startY);  // X轴
        painter->drawLine(startX, startY, startX, startY - chartHeight); // Y轴

        // 绘制坐标轴标题
        QFont axisFont = painter->font();
        axisFont.setPointSize(9); // 减小字体
        axisFont.setBold(true);
        painter->setFont(axisFont);
        painter->setPen(QColor(50, 50, 50));

        // X轴标题
        painter->drawText(QRect(startX + chartWidth/2 - 40, startY + 20, 80, 15),
                        Qt::AlignCenter, "日期");
        // 增强X轴标题可见性
        painter->fillRect(QRect(startX + chartWidth/2 - 40, startY + 20, 80, 15), QColor(255, 255, 255, 180));
        painter->drawText(QRect(startX + chartWidth/2 - 40, startY + 20, 80, 15),
                        Qt::AlignCenter, "日期");

        // Y轴标题
        painter->save();
        painter->translate(18, startY - chartHeight/2);
        painter->rotate(-90);
        painter->drawText(QRect(-50, 0, 100, 15),
                        Qt::AlignCenter, "碳排放量(kg)");
        painter->restore();

        // 如果有数据，绘制折线图
        if (!m_values.isEmpty()) {
            // 找到最大值
            double maxValue = *std::max_element(m_values.begin(), m_values.end());
            if (maxValue <= 0) maxValue = 100; // 防止除以零

            // 绘制网格线
            painter->setPen(QPen(QColor(220, 220, 220), 1, Qt::DashLine));
            for (int i = 1; i <= 5; ++i) {
                int y = startY - chartHeight * i / 5;
                painter->drawLine(startX, y, startX + chartWidth, y);
            }

            // 绘制Y轴刻度
            painter->setPen(QColor(50, 50, 50));
            QFont scaleFont = painter->font();
            scaleFont.setPointSize(9);
            painter->setFont(scaleFont);

            for (int i = 0; i <= 5; ++i) {
                double value = maxValue * i / 5;
                int y = startY - chartHeight * i / 5;
                painter->drawLine(startX - 5, y, startX, y);
                painter->drawText(QRect(startX - 45, y - 10, 40, 20),
                                Qt::AlignRight | Qt::AlignVCenter,
                                QString("%1").arg(value, 0, 'f', 0));
            }

            // 绘制折线
            QPainterPath path;
            bool firstPoint = true;

            // 限制显示的数据点数量，最多显示8个点以避免拥挤
            int step = m_values.size() <= 8 ? 1 : m_values.size() / 8;

            // 准备渐变填充
            QLinearGradient gradient(0, startY - chartHeight, 0, startY);
            gradient.setColorAt(0, QColor(41, 128, 185, 100));
            gradient.setColorAt(1, QColor(41, 128, 185, 20));

            // 创建填充路径
            QPainterPath fillPath;
            fillPath.moveTo(startX, startY);

            for (int i = 0; i < m_values.size(); i += step) {
                double xRatio = (double)i / (m_values.size() > 1 ? m_values.size() - 1 : 1);
                double yRatio = m_values[i] / maxValue;

                int x = startX + xRatio * chartWidth;
                int y = startY - yRatio * chartHeight;

                if (firstPoint) {
                    path.moveTo(x, y);
                    fillPath.lineTo(x, y);
                    firstPoint = false;
                } else {
                    path.lineTo(x, y);
                    fillPath.lineTo(x, y);
                }

                // 绘制数据点
                painter->setBrush(QColor(41, 128, 185));
                painter->setPen(QPen(Qt::white, 1.5));
                painter->drawEllipse(QPoint(x, y), 6, 6);

                // 绘制数值标签
                painter->setPen(QColor(41, 128, 185));
                QFont valueFont = painter->font();
                valueFont.setPointSize(9);
                valueFont.setBold(true);
                painter->setFont(valueFont);

                painter->drawText(QRect(x - 30, y - 25, 60, 20),
                                Qt::AlignCenter,
                                QString("%1").arg(m_values[i], 0, 'f', 0));

                // 绘制日期标签（仅显示部分）
                if (i == 0 || i == m_values.size() - 1 || i % (2 * step) == 0) {
                    QFont dateFont = painter->font();
                    dateFont.setPointSize(8);
                    dateFont.setBold(false);
                    painter->setFont(dateFont);
                    painter->setPen(QColor(80, 80, 80));

                    // 旋转日期标签以避免重叠
                    painter->save();
                    painter->translate(x, startY + 5);
                    painter->rotate(-45);
                    painter->drawText(QRect(0, 0, 70, 20),
                                    Qt::AlignLeft,
                                    m_timestamps[i].toString("MM-dd HH:mm"));
                    painter->restore();
                }
            }

            // 完成填充路径
            fillPath.lineTo(startX + chartWidth, startY);
            fillPath.lineTo(startX, startY);

            // 填充区域
            painter->setBrush(gradient);
            painter->setPen(Qt::NoPen);
            painter->drawPath(fillPath);

            // 绘制折线
            QPen linePen(QColor(41, 128, 185), 3);
            painter->setPen(linePen);
            painter->drawPath(path);

        } else {
            // 无数据时显示提示
            QFont noDataFont = painter->font();
            noDataFont.setPointSize(14);
            painter->setFont(noDataFont);
            painter->setPen(QColor(150, 150, 150));
            painter->drawText(rect(), Qt::AlignCenter, "暂无数据");
        }
    }

    void drawCategoryChart(QPainter* painter) {
        int centerX = width() / 2;
        int centerY = height() / 2 - 15; // 向上调整饼图位置，避免遮挡底部标题
        int radius = qMin(width(), height()) / 3 - 25; // 进一步减小饼图半径

        // 如果有数据，绘制饼图
        if (!m_categoryData.isEmpty()) {
            // 创建三大类别的数据：出行、家庭、消费
            QMap<QString, double> mainCategories;
            double transportTotal = 0.0;
            double homeTotal = 0.0;
            double consumptionTotal = 0.0;

            // 合并相关分类到三个主要分类
            for (auto it = m_categoryData.begin(); it != m_categoryData.end(); ++it) {
                QString key = it.key();
                double value = it.value();
                
                // 出行碳排放：飞机、火车、公交车、私家车
                if (key == "飞机" || key == "火车" || key == "公交车" || key == "私家车" || key == "交通排放") {
                    transportTotal += value;
                }
                // 家庭碳排放：居住面积、用电
                else if (key == "居住面积" || key == "用电" || key == "家居排放") {
                    homeTotal += value;
                }
                // 消费碳排放：一次性筷子、塑料袋、衣物、纸张
                else if (key == "一次性筷子" || key == "塑料袋" || key == "衣物" || key == "纸张" || key == "消费排放") {
                    consumptionTotal += value;
                }
            }

            // 添加三个主要分类到数据集合
            if (transportTotal > 0) mainCategories["出行碳排放"] = transportTotal;
            if (homeTotal > 0) mainCategories["家庭碳排放"] = homeTotal;
            if (consumptionTotal > 0) mainCategories["消费碳排放"] = consumptionTotal;
            
            double total = transportTotal + homeTotal + consumptionTotal;
            
            if (total <= 0) total = 1; // 防止除以零

            double startAngle = 0;
            int i = 0;

            // 使用专业的配色方案，每个类别一种颜色
            QStringList colors = {
                "#3498db", // 蓝色 - 出行
                "#2ecc71", // 绿色 - 家庭
                "#e74c3c"  // 红色 - 消费
            };

            // 绘制图例标题
            QFont legendTitleFont = painter->font();
            legendTitleFont.setPointSize(10); 
            legendTitleFont.setBold(true);
            painter->setFont(legendTitleFont);
            painter->setPen(QColor(50, 50, 50));
            // 调整图例标题位置
            painter->fillRect(QRect(20, height() - 80, width() - 40, 20), QColor(255, 255, 255, 180));
            painter->drawText(QRect(20, height() - 80, width() - 40, 20),
                            Qt::AlignCenter, "个人碳排放分类占比");

            // 绘制图例
            int legendX = centerX - 120; // 调整起始位置，居中显示
            int legendY = height() - 60; // 向上调整图例位置
            int legendSize = 12; // 增大图例标记大小
            int legendSpacing = 80; // 适当减小图例间距，因为文本更短了

            QFont legendFont = painter->font();
            legendFont.setPointSize(9); // 调整字体大小
            legendFont.setBold(true);
            painter->setFont(legendFont);

            // 绘制饼图
            for (auto it = mainCategories.begin(); it != mainCategories.end(); ++it) {
                double value = it.value();
                double percentage = value / total;
                double sweepAngle = percentage * 360;

                // 设置扇区颜色
                QColor color(colors[i % colors.size()]);
                painter->setBrush(color);
                painter->setPen(Qt::white);

                // 绘制扇区
                QRect pieRect(centerX - radius, centerY - radius, radius * 2, radius * 2);
                painter->drawPie(pieRect, startAngle * 16, sweepAngle * 16);

                // 计算标签位置
                double labelAngle = (startAngle + sweepAngle / 2) * M_PI / 180;
                double labelRadius = radius * 0.7;
                int labelX = centerX + labelRadius * cos(labelAngle);
                int labelY = centerY - labelRadius * sin(labelAngle);

                // 在饼图中显示百分比
                    painter->setPen(Qt::white);
                    QFont percentFont = painter->font();
                percentFont.setPointSize(10); 
                    percentFont.setBold(true);
                    painter->setFont(percentFont);

                    painter->drawText(QRect(labelX - 25, labelY - 10, 50, 20),
                                    Qt::AlignCenter,
                                    QString("%1%").arg(percentage * 100, 0, 'f', 1));

                // 绘制图例
                int legX = legendX + i * legendSpacing; // 使用legendSpacing变量控制间距
                int legY = legendY;

                painter->setBrush(color);
                painter->setPen(QColor(80, 80, 80));
                painter->setFont(legendFont);

                painter->drawRect(legX, legY, legendSize, legendSize);

                painter->drawText(QRect(legX + legendSize + 5, legY - 1,
                                    90, legendSize + 2), // 减小文本区域宽度，避免重叠
                                Qt::AlignLeft | Qt::AlignVCenter,
                                it.key()); // 只显示类别名称，不显示百分比

                startAngle += sweepAngle;
                i++;
            }
        } else {
            // 无数据时显示提示
            QFont noDataFont = painter->font();
            noDataFont.setPointSize(14);
            painter->setFont(noDataFont);
            painter->setPen(QColor(150, 150, 150));
            painter->drawText(rect(), Qt::AlignCenter, "暂无数据");
        }
    }

    void drawComparisonChart(QPainter* painter) {
        int chartWidth = width() - 70; // 减少左右边距
        int chartHeight = height() - 120; // 减少上下边距
        int startX = 55;
        int startY = height() - 50;

        // 绘制坐标轴
        painter->setPen(QPen(QColor(80, 80, 80), 2));
        painter->drawLine(startX, startY, startX + chartWidth, startY);  // X轴
        painter->drawLine(startX, startY, startX, startY - chartHeight); // Y轴

        // 绘制坐标轴标题
        QFont axisFont = painter->font();
        axisFont.setPointSize(9); // 减小字体
        axisFont.setBold(true);
        painter->setFont(axisFont);
        painter->setPen(QColor(50, 50, 50));

        // X轴标题
        painter->fillRect(QRect(startX + chartWidth/2 - 40, startY + 25, 80, 15), QColor(255, 255, 255, 180));
        painter->drawText(QRect(startX + chartWidth/2 - 40, startY + 25, 80, 15),
                        Qt::AlignCenter, "月份");

        // Y轴标题
        painter->save();
        painter->translate(18, startY - chartHeight/2);
        painter->rotate(-90);
        painter->drawText(QRect(-50, 0, 100, 15),
                        Qt::AlignCenter, "碳排放量(kg)");
        painter->restore();

        // 如果有数据，绘制柱状图
        if (!m_monthlyData.isEmpty()) {
            QStringList months = m_monthlyData.keys();
            
            // 固定使用三个分类
            QStringList categories = {"交通排放", "家居排放", "消费排放"};

            // 限制显示的月份数量，最多显示6个月
            int maxMonths = 6;
            if (months.size() > maxMonths) {
                months = months.mid(months.size() - maxMonths);
            }

            int barCount = months.size();
            if (barCount > 0) {
                int barWidth = chartWidth / (barCount * 2);

                // 找到最大值
                double maxValue = 0;
                for (const auto& monthData : m_monthlyData) {
                    double monthTotal = 0;
                    for (const QString& category : categories) {
                        if (monthData.contains(category)) {
                            monthTotal += monthData[category];
                        }
                    }
                    maxValue = qMax(maxValue, monthTotal);
                }

                if (maxValue <= 0) maxValue = 100; // 防止除以零

                // 绘制网格线
                painter->setPen(QPen(QColor(220, 220, 220), 1, Qt::DashLine));
                for (int i = 1; i <= 5; ++i) {
                    int y = startY - chartHeight * i / 5;
                    painter->drawLine(startX, y, startX + chartWidth, y);
                }

                // 绘制Y轴刻度
                painter->setPen(QColor(50, 50, 50));
                QFont scaleFont = painter->font();
                scaleFont.setPointSize(9);
                painter->setFont(scaleFont);

                for (int i = 0; i <= 5; ++i) {
                    double value = maxValue * i / 5;
                    int y = startY - chartHeight * i / 5;
                    painter->drawLine(startX - 5, y, startX, y);
                    painter->drawText(QRect(startX - 45, y - 10, 40, 20),
                                    Qt::AlignRight | Qt::AlignVCenter,
                                    QString("%1").arg(value, 0, 'f', 0));
                }

                // 使用专业的配色方案 - 与饼图保持一致
                QStringList colors = {
                    "#3498db", // 蓝色 - 出行
                    "#2ecc71", // 绿色 - 家庭
                    "#e74c3c"  // 红色 - 消费
                };

                // 绘制图例
                int legendX = startX + 20;
                int legendY = 50;
                int legendSize = 12;
                int legendSpacing = 100;

                QFont legendFont = painter->font();
                legendFont.setPointSize(9);
                legendFont.setBold(true);
                painter->setFont(legendFont);

                QMap<QString, QString> categoryNames = {
                    {"交通排放", "出行碳排放"},
                    {"家居排放", "家庭碳排放"},
                    {"消费排放", "消费碳排放"}
                };

                for (int c = 0; c < categories.size(); ++c) {
                    QColor color(colors[c % colors.size()]);
                    painter->setBrush(color);
                    painter->setPen(QColor(80, 80, 80));
                    painter->drawRect(legendX + c * legendSpacing, legendY, legendSize, legendSize);

                    painter->drawText(QRect(legendX + c * legendSpacing + legendSize + 5, legendY - 1,
                                          100, legendSize + 2),
                                    Qt::AlignLeft | Qt::AlignVCenter,
                                    categoryNames[categories[c]]);
                }

                // 绘制柱状图
                for (int i = 0; i < months.size(); ++i) {
                    QString month = months[i];
                    int x = startX + (i * 2 + 1) * barWidth;

                    // 绘制月份标签
                    painter->setPen(QColor(80, 80, 80));
                    QFont monthFont = painter->font();
                    monthFont.setPointSize(9);
                    monthFont.setBold(false);
                    painter->setFont(monthFont);

                    painter->drawText(QRect(x - barWidth, startY + 5, barWidth * 2, 25),
                                    Qt::AlignCenter, month);

                    // 绘制柱状
                    double accumulatedHeight = 0;
                    int categoryIndex = 0;

                    for (const QString& category : categories) {
                        double value = 0;
                        if (m_monthlyData[month].contains(category)) {
                            value = m_monthlyData[month][category];
                        }

                        double ratio = value / maxValue;
                        int barHeight = ratio * chartHeight;

                        // 设置柱状颜色
                        QColor color(colors[categoryIndex % colors.size()]);

                        // 创建渐变效果
                        QLinearGradient gradient(0, 0, barWidth, 0);
                        gradient.setColorAt(0, color.lighter(120));
                        gradient.setColorAt(1, color);

                        painter->setBrush(gradient);
                        painter->setPen(Qt::white);

                        // 绘制柱状
                        QRect barRect(x - barWidth/2, startY - accumulatedHeight - barHeight,
                                    barWidth, barHeight);
                        painter->drawRect(barRect);

                        // 只有较大的柱状才显示数值
                        if (barHeight > 20) {
                            painter->setPen(Qt::white);
                            QFont valueFont = painter->font();
                            valueFont.setPointSize(8);
                            valueFont.setBold(true);
                            painter->setFont(valueFont);

                            painter->drawText(barRect, Qt::AlignCenter,
                                            QString("%1").arg(value, 0, 'f', 0));
                        }

                        accumulatedHeight += barHeight;
                        categoryIndex++;
                    }

                    // 在柱状顶部显示总值
                    if (accumulatedHeight > 0) {
                        painter->setPen(QColor(50, 50, 50));
                        QFont totalFont = painter->font();
                        totalFont.setPointSize(9);
                        totalFont.setBold(true);
                        painter->setFont(totalFont);

                        double total = 0;
                        for (const QString& category : categories) {
                            if (m_monthlyData[month].contains(category)) {
                                total += m_monthlyData[month][category];
                            }
                        }

                        painter->drawText(QRect(x - barWidth, startY - accumulatedHeight - 20,
                                              barWidth * 2, 20),
                                        Qt::AlignCenter,
                                        QString("%1").arg(total, 0, 'f', 0));
                    }
                }
            }
        } else {
            // 无数据时显示提示
            QFont noDataFont = painter->font();
            noDataFont.setPointSize(14);
            painter->setFont(noDataFont);
            painter->setPen(QColor(150, 150, 150));
            painter->drawText(rect(), Qt::AlignCenter, "暂无数据");
        }
    }

    ChartType m_type;
    QLabel* m_titleLabel;
    QVector<QDateTime> m_timestamps;
    QVector<double> m_values;
    QMap<QString, double> m_categoryData;
    QMap<QString, QMap<QString, double>> m_monthlyData;
};

QWidget* ChartPage::createBasicTrendChart()
{
    return new BasicChartWidget(BasicChartWidget::TrendChart,
                               timestamps, values, currentTotalData, categoryData);
}

QWidget* ChartPage::createBasicCategoryChart()
{
    return new BasicChartWidget(BasicChartWidget::CategoryChart,
                               timestamps, values, currentTotalData, categoryData);
}

QWidget* ChartPage::createBasicComparisonChart()
{
    return new BasicChartWidget(BasicChartWidget::ComparisonChart,
                               timestamps, values, currentTotalData, categoryData);
}
