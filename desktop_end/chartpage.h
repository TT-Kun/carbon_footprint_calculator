#ifndef CHARTPAGE_H
#define CHARTPAGE_H

#include <QWidget>
#include <QDateTime>
#include <QMap>
#include <QGridLayout>
#include <QVector>
#include <QPainter>
#include <QLabel>

namespace Ui {
class ChartPage;
}

class ChartPage : public QWidget
{
    Q_OBJECT

public:
    explicit ChartPage(QWidget *parent = nullptr);
    ~ChartPage();

    // 更新图表数据
    void updateCharts(const QString &username);

private:
    Ui::ChartPage *ui;

    // 使用基本Qt绘图功能的图表
    QWidget* createBasicTrendChart();    // 创建简单趋势图
    QWidget* createBasicCategoryChart(); // 创建简单分类图
    QWidget* createBasicComparisonChart(); // 创建简单对比图
    
    // 从数据文件加载数据
    void loadChartData(const QString &username);
    
    // 当前用户数据
    QString currentUsername;
    QMap<QString, double> currentTotalData;
    QMap<QString, QMap<QString, double>> categoryData;
    QVector<QDateTime> timestamps;
    QVector<double> values;
};

#endif // CHARTPAGE_H 