#include "datapage.h"
#include "ui_datapage.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QJsonObject>
#include <QJsonArray>
#include <QPushButton>
#include <QStandardPaths>
#include <QDir>
#include <QTextStream>
#include <QDebug>
#include <QJsonDocument>
#include <QHBoxLayout>
#include <algorithm>
#include <QBrush>
#include <QColor>
#include <QPixmap>
#include <QItemSelectionModel>
#include <QCoreApplication>

DataPage::DataPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataPage),
    currentUsername("")
{
    ui->setupUi(this);
    
    // 设置数据存储基础目录
    dataDir = QCoreApplication::applicationDirPath() + "/data";
    QDir dir(dataDir);
    if (!dir.exists()) {
        dir.mkpath(dataDir);
    }
    
    // 数据文件路径将在loadUserData中基于用户名设置
    dataFilePath = "";
    
    // 设置日期控件的默认值
    QDate currentDate = QDate::currentDate();
    ui->fromDateEdit->setDate(currentDate.addMonths(-1));
    ui->toDateEdit->setDate(currentDate);
    
    // 连接信号和槽
    connect(ui->searchButton, &QPushButton::clicked, this, &DataPage::onSearchButtonClicked);
    connect(ui->resetButton, &QPushButton::clicked, [this]() {
        QDate currentDate = QDate::currentDate();
        ui->fromDateEdit->setDate(currentDate.addMonths(-1));
        ui->toDateEdit->setDate(currentDate);
        loadUserData(currentUsername);
    });
    connect(ui->exportButton, &QPushButton::clicked, this, &DataPage::onExportButtonClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &DataPage::onDeleteButtonClicked);
    connect(ui->selectAllButton, &QPushButton::clicked, this, &DataPage::onSelectAllButtonClicked);
    
    // 连接表格选择变化信号
    connect(ui->dataTableWidget->selectionModel(), &QItemSelectionModel::selectionChanged, 
            this, &DataPage::onSelectionChanged);
    
    // 设置表格属性
    ui->dataTableWidget->setColumnCount(7);
    ui->dataTableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->dataTableWidget->verticalHeader()->setVisible(false);
    
    // 初始化选择计数
    updateSelectionCount();
    
    // 初始状态下禁用删除按钮
    ui->deleteButton->setEnabled(false);
}

DataPage::~DataPage()
{
    delete ui;
}

void DataPage::addCarbonData(const QString &username, double totalCarbonFootprint, const QMap<QString, double> &detailData)
{
    qDebug() << "DataPage::addCarbonData - 添加新的碳足迹数据记录";
    qDebug() << "用户名:" << username;
    qDebug() << "总碳排放量:" << totalCarbonFootprint << "kg";
    
    // 确保加载了正确用户的数据
    if (username != currentUsername) {
        loadUserData(username);
    }
    
    // 创建新的碳足迹数据记录
    CarbonData data;
    data.id = 0; // 临时ID，将在排序后重新设置
    data.username = username;
    data.timestamp = QDateTime::currentDateTime();
    data.totalCarbonFootprint = totalCarbonFootprint;
    data.detailData = detailData;
    
    // 添加到数据集合
    allCarbonData.append(data);
    filteredCarbonData = allCarbonData; // 由于现在是用户特定的文件，所以filteredCarbonData就是allCarbonData
    
    // 重新排序并重置ID
    resetAllIds();
    
    // 保存数据
    saveDataToFile();
    
    // 更新显示
    updateTableView();
    
    // 发出数据更新信号
    emit dataUpdated();
    
    qDebug() << "数据已添加并保存到用户特定文件:" << dataFilePath;
}

void DataPage::loadUserData(const QString &username)
{
    currentUsername = username;
    
    // 如果用户名为空或默认用户，则清空数据
    if (username.isEmpty() || username == "默认用户") {
        clearData();
        return;
    }
    
    // 根据用户名设置数据文件路径
    dataFilePath = dataDir + "/carbon_data_" + username + ".json";
    
    // 清空现有数据
    allCarbonData.clear();
    filteredCarbonData.clear();
    
    // 加载用户特定的数据文件
    loadDataFromFile();
    
    // 所有加载的数据都属于当前用户，不需要过滤
    filteredCarbonData = allCarbonData;
    
    // 更新表格显示
    updateTableView();
}

void DataPage::clearData()
{
    ui->dataTableWidget->setRowCount(0);
    filteredCarbonData.clear();
    ui->totalRecordsLabel->setText("总记录数：0");
    ui->averageLabel->setText("平均碳足迹：0 kg");
}

bool DataPage::saveDataToFile()
{
    QFile file(dataFilePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "无法打开文件进行写入: " << dataFilePath;
        return false;
    }
    
    QJsonArray dataArray;
    
    for (const CarbonData &data : allCarbonData) {
        QJsonObject dataObject;
        dataObject["id"] = data.id;
        dataObject["username"] = data.username;
        dataObject["timestamp"] = data.timestamp.toString(Qt::ISODate);
        dataObject["totalCarbonFootprint"] = data.totalCarbonFootprint;
        
        QJsonObject detailObject;
        for (auto it = data.detailData.constBegin(); it != data.detailData.constEnd(); ++it) {
            detailObject[it.key()] = it.value();
        }
        
        dataObject["detailData"] = detailObject;
        dataArray.append(dataObject);
    }
    
    QJsonDocument doc(dataArray);
    file.write(doc.toJson());
    file.close();
    
    return true;
}

bool DataPage::loadDataFromFile()
{
    // 如果用户名为空或是默认用户，或者文件路径为空，则返回
    if (currentUsername.isEmpty() || currentUsername == "默认用户" || dataFilePath.isEmpty()) {
        allCarbonData.clear();
        return true;
    }
    
    QFile file(dataFilePath);
    if (!file.exists()) {
        // 文件不存在，创建空数据
        allCarbonData.clear();
        return true;
    }
    
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "无法打开文件进行读取: " << dataFilePath;
        return false;
    }
    
    QByteArray jsonData = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    
    if (doc.isNull()) {
        qDebug() << "解析JSON文件失败";
        file.close();
        return false;
    }
    
    if (!doc.isArray()) {
        qDebug() << "JSON文件不是数组格式";
        file.close();
        return false;
    }
    
    // 清空现有数据
    allCarbonData.clear();
    
    QJsonArray dataArray = doc.array();
    for (const QJsonValue &value : dataArray) {
        QJsonObject obj = value.toObject();
        
        CarbonData data;
        data.id = obj["id"].toInt();
        data.username = obj["username"].toString();
        data.timestamp = QDateTime::fromString(obj["timestamp"].toString(), Qt::ISODate);
        data.totalCarbonFootprint = obj["totalCarbonFootprint"].toDouble();
        
        QJsonObject detailObj = obj["detailData"].toObject();
        for (auto it = detailObj.constBegin(); it != detailObj.constEnd(); ++it) {
            data.detailData[it.key()] = it.value().toDouble();
        }
        
        allCarbonData.append(data);
    }
    
    file.close();
    
    // 确保ID从1开始且连续
    resetAllIds();
    
    return true;
}

void DataPage::onEditButtonClicked()
{
    int row = ui->dataTableWidget->currentRow();
    if (row < 0 || row >= filteredCarbonData.size()) {
        QMessageBox::warning(this, "警告", "请先选择要编辑的数据");
        return;
    }
    
    // 获取当前选中的数据
    CarbonData &data = filteredCarbonData[row];
    
    // 在此处可以打开编辑对话框，进行数据编辑
    // 这里只是一个简单示例
    QMessageBox::information(this, "信息", "编辑功能待实现");
    
    // 保存更新后的数据
    saveDataToFile();
    
    // 刷新显示
    updateTableView();
}

void DataPage::onDeleteButtonClicked()
{
    // 获取当前选中的行
    QList<int> selectedRows;
    QModelIndexList indexes = ui->dataTableWidget->selectionModel()->selectedRows();
    for (int i = indexes.count() - 1; i >= 0; i--) {
        selectedRows.append(indexes.at(i).row());
    }
    
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "警告", "请先选择要删除的数据");
        return;
    }
    
    // 确认删除
    QMessageBox::StandardButton reply = QMessageBox::question(this, "确认删除", 
        "确定要删除选中的 " + QString::number(selectedRows.size()) + " 条数据吗？",
        QMessageBox::Yes | QMessageBox::No);
        
    if (reply != QMessageBox::Yes) {
        return;
    }
    
    // 删除选择的数据
    std::sort(selectedRows.begin(), selectedRows.end(), std::greater<int>());
    for (int row : selectedRows) {
        if (row < filteredCarbonData.size()) {
            int dataId = filteredCarbonData[row].id;
            
            // 从全局数据中删除
            for (int i = 0; i < allCarbonData.size(); i++) {
                if (allCarbonData[i].id == dataId) {
                    allCarbonData.remove(i);
                    break;
                }
            }
            
            // 从过滤数据中删除
            filteredCarbonData.remove(row);
        }
    }
    
    // 重新排序ID
    resetAllIds();
    
    // 保存更新后的数据
    saveDataToFile();
    
    // 刷新显示
    updateTableView();
    
    // 更新选择计数
    updateSelectionCount();
    
    // 显示删除成功消息
    QMessageBox::information(this, "删除成功", "已成功删除选中的 " + QString::number(selectedRows.size()) + " 条数据");
}

// 重置所有数据的ID，从1开始
void DataPage::resetAllIds()
{
    // 按时间戳排序
    std::sort(allCarbonData.begin(), allCarbonData.end(), [](const CarbonData &a, const CarbonData &b) {
        return a.timestamp < b.timestamp;
    });
    
    // 重新分配ID
    for (int i = 0; i < allCarbonData.size(); i++) {
        allCarbonData[i].id = i + 1;
    }
    
    // 同步更新过滤数据的ID
    for (int i = 0; i < filteredCarbonData.size(); i++) {
        const QDateTime timestamp = filteredCarbonData[i].timestamp;
        
        // 查找对应的全局数据，更新ID
        for (int j = 0; j < allCarbonData.size(); j++) {
            if (allCarbonData[j].timestamp == timestamp && 
                allCarbonData[j].username == filteredCarbonData[i].username &&
                allCarbonData[j].totalCarbonFootprint == filteredCarbonData[i].totalCarbonFootprint) {
                filteredCarbonData[i].id = allCarbonData[j].id;
                break;
            }
        }
    }
}

void DataPage::onExportButtonClicked()
{
    if (filteredCarbonData.isEmpty()) {
        QMessageBox::warning(this, "警告", "没有数据可导出");
        return;
    }
    
    QString fileName = QFileDialog::getSaveFileName(this, "导出数据", 
        QDir::homePath() + "/carbon_footprint_data.csv", 
        "CSV文件 (*.csv)");
        
    if (fileName.isEmpty()) {
        return;
    }
    
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "错误", "无法打开文件进行写入");
        return;
    }
    
    QTextStream out(&file);
    
    // 写入标题行
    out << "ID,日期,总碳足迹(kg),交通碳排放(kg),家庭碳排放(kg),消费碳排放(kg)\n";
    
    // 写入数据行
    for (const CarbonData &data : filteredCarbonData) {
        out << data.id << ","
            << data.timestamp.toString("yyyy-MM-dd") << ","
            << QString::number(data.totalCarbonFootprint, 'f', 2) << ",";
        
        // 获取详细数据
        double transportation = 0;
        double household = 0;
        double consumption = 0;
        
        // 根据实际键名汇总交通数据
        if (data.detailData.contains("交通排放")) {
            transportation = data.detailData.value("交通排放");
        } else {
            // 如果没有总的"交通排放"键，则尝试汇总各个交通项
            if (data.detailData.contains("飞机")) transportation += data.detailData.value("飞机");
            if (data.detailData.contains("火车")) transportation += data.detailData.value("火车");
            if (data.detailData.contains("公交车")) transportation += data.detailData.value("公交车");
            if (data.detailData.contains("私家车")) transportation += data.detailData.value("私家车");
            
            // 兼容旧版键名
            if (data.detailData.contains("airplane")) transportation += data.detailData.value("airplane");
            if (data.detailData.contains("train")) transportation += data.detailData.value("train");
            if (data.detailData.contains("bus")) transportation += data.detailData.value("bus");
            if (data.detailData.contains("car")) transportation += data.detailData.value("car");
        }
        
        // 根据实际键名汇总家庭数据
        if (data.detailData.contains("家居排放")) {
            household = data.detailData.value("家居排放");
        } else {
            // 如果没有总的"家居排放"键，则尝试汇总各个家居项
            if (data.detailData.contains("居住面积")) household += data.detailData.value("居住面积");
            if (data.detailData.contains("用电")) household += data.detailData.value("用电");
            
            // 兼容旧版键名
            if (data.detailData.contains("livingArea")) household += data.detailData.value("livingArea");
            if (data.detailData.contains("electricity")) household += data.detailData.value("electricity");
        }
        
        // 根据实际键名汇总消费数据
        if (data.detailData.contains("消费排放")) {
            consumption = data.detailData.value("消费排放");
        } else {
            // 如果没有总的"消费排放"键，则尝试汇总各个消费项
            if (data.detailData.contains("一次性筷子")) consumption += data.detailData.value("一次性筷子");
            if (data.detailData.contains("塑料袋")) consumption += data.detailData.value("塑料袋");
            if (data.detailData.contains("衣物")) consumption += data.detailData.value("衣物");
            if (data.detailData.contains("纸张")) consumption += data.detailData.value("纸张");
            
            // 兼容旧版键名
            if (data.detailData.contains("disposableChopstick")) consumption += data.detailData.value("disposableChopstick");
            if (data.detailData.contains("plasticBag")) consumption += data.detailData.value("plasticBag");
            if (data.detailData.contains("clothes")) consumption += data.detailData.value("clothes");
            if (data.detailData.contains("paper")) consumption += data.detailData.value("paper");
        }
        
        out << QString::number(transportation, 'f', 2) << ","
            << QString::number(household, 'f', 2) << ","
            << QString::number(consumption, 'f', 2) << "\n";
    }
    
    file.close();
    
    QMessageBox::information(this, "成功", "数据已成功导出到：" + fileName);
}

void DataPage::onSearchButtonClicked()
{
    QDate fromDate = ui->fromDateEdit->date();
    QDate toDate = ui->toDateEdit->date();
    
    // 清除现有过滤数据
    filteredCarbonData.clear();
    
    // 应用过滤条件
    for (const CarbonData &data : allCarbonData) {
        // 用户名必须匹配
        if (data.username != currentUsername) {
            continue;
        }
        
        // 检查日期范围
        QDate recordDate = data.timestamp.date();
        if (recordDate < fromDate || recordDate > toDate) {
            continue;
        }
        
        // 匹配所有条件，添加到过滤结果
        filteredCarbonData.append(data);
    }
    
    // 更新表格显示
    updateTableView();
}

void DataPage::updateTableView()
{
    ui->dataTableWidget->setRowCount(filteredCarbonData.size());
    
    QStringList headers;
    headers << "ID" << "日期" << "总碳足迹(kg)" << "交通(kg)" << "家庭(kg)" << "消费(kg)" << "操作";
    ui->dataTableWidget->setHorizontalHeaderLabels(headers);
    
    double totalFootprint = 0.0;
    
    for (int i = 0; i < filteredCarbonData.size(); i++) {
        const CarbonData &data = filteredCarbonData[i];
        totalFootprint += data.totalCarbonFootprint;
        
        // ID列
        QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(data.id));
        idItem->setTextAlignment(Qt::AlignCenter);
        ui->dataTableWidget->setItem(i, 0, idItem);
        
        // 日期列
        QTableWidgetItem *dateItem = new QTableWidgetItem(data.timestamp.toString("yyyy-MM-dd"));
        dateItem->setTextAlignment(Qt::AlignCenter);
        ui->dataTableWidget->setItem(i, 1, dateItem);
        
        // 总碳足迹列
        QTableWidgetItem *totalItem = new QTableWidgetItem(QString::number(data.totalCarbonFootprint, 'f', 2));
        totalItem->setTextAlignment(Qt::AlignCenter);
        if (data.totalCarbonFootprint > 4500) {  // 4.5吨 = 4500kg
            totalItem->setForeground(QBrush(QColor(231, 76, 60)));  // 红色，表示超过人均
        } else {
            totalItem->setForeground(QBrush(QColor(46, 204, 113)));  // 绿色，表示低于人均
        }
        ui->dataTableWidget->setItem(i, 2, totalItem);
        
        // 计算各类别碳足迹
        double transportation = 0.0;
        double household = 0.0;
        double consumption = 0.0;
        
        // 根据实际键名汇总交通数据
        if (data.detailData.contains("交通排放")) {
            transportation = data.detailData.value("交通排放");
        } else {
            // 如果没有总的"交通排放"键，则尝试汇总各个交通项
            if (data.detailData.contains("飞机")) transportation += data.detailData.value("飞机");
            if (data.detailData.contains("火车")) transportation += data.detailData.value("火车");
            if (data.detailData.contains("公交车")) transportation += data.detailData.value("公交车");
            if (data.detailData.contains("私家车")) transportation += data.detailData.value("私家车");
            
            // 兼容旧版键名
            if (data.detailData.contains("airplane")) transportation += data.detailData.value("airplane");
            if (data.detailData.contains("train")) transportation += data.detailData.value("train");
            if (data.detailData.contains("bus")) transportation += data.detailData.value("bus");
            if (data.detailData.contains("car")) transportation += data.detailData.value("car");
        }
        
        // 根据实际键名汇总家庭数据
        if (data.detailData.contains("家居排放")) {
            household = data.detailData.value("家居排放");
        } else {
            // 如果没有总的"家居排放"键，则尝试汇总各个家居项
            if (data.detailData.contains("居住面积")) household += data.detailData.value("居住面积");
            if (data.detailData.contains("用电")) household += data.detailData.value("用电");
            
            // 兼容旧版键名
            if (data.detailData.contains("livingArea")) household += data.detailData.value("livingArea");
            if (data.detailData.contains("electricity")) household += data.detailData.value("electricity");
        }
        
        // 根据实际键名汇总消费数据
        if (data.detailData.contains("消费排放")) {
            consumption = data.detailData.value("消费排放");
        } else {
            // 如果没有总的"消费排放"键，则尝试汇总各个消费项
            if (data.detailData.contains("一次性筷子")) consumption += data.detailData.value("一次性筷子");
            if (data.detailData.contains("塑料袋")) consumption += data.detailData.value("塑料袋");
            if (data.detailData.contains("衣物")) consumption += data.detailData.value("衣物");
            if (data.detailData.contains("纸张")) consumption += data.detailData.value("纸张");
            
            // 兼容旧版键名
            if (data.detailData.contains("disposableChopstick")) consumption += data.detailData.value("disposableChopstick");
            if (data.detailData.contains("plasticBag")) consumption += data.detailData.value("plasticBag");
            if (data.detailData.contains("clothes")) consumption += data.detailData.value("clothes");
            if (data.detailData.contains("paper")) consumption += data.detailData.value("paper");
        }
        
        // 交通列
        QTableWidgetItem *transItem = new QTableWidgetItem(QString::number(transportation, 'f', 2));
        transItem->setTextAlignment(Qt::AlignCenter);
        ui->dataTableWidget->setItem(i, 3, transItem);
        
        // 家庭列
        QTableWidgetItem *houseItem = new QTableWidgetItem(QString::number(household, 'f', 2));
        houseItem->setTextAlignment(Qt::AlignCenter);
        ui->dataTableWidget->setItem(i, 4, houseItem);
        
        // 消费列
        QTableWidgetItem *consItem = new QTableWidgetItem(QString::number(consumption, 'f', 2));
        consItem->setTextAlignment(Qt::AlignCenter);
        ui->dataTableWidget->setItem(i, 5, consItem);
        
        // 操作列 - 添加查看详情按钮
        QWidget *buttonWidget = new QWidget();
        buttonWidget->setStyleSheet("background-color: transparent;");
        QHBoxLayout *buttonLayout = new QHBoxLayout(buttonWidget);
        QPushButton *detailButton = new QPushButton("查看详情");
        detailButton->setMaximumWidth(100);
        detailButton->setCursor(Qt::PointingHandCursor);
        detailButton->setStyleSheet(
            "QPushButton {"
            "   background-color: #3498db;"
            "   color: white;"
            "   border-radius: 4px;"
            "   padding: 4px 8px;"
            "   font-size: 12px;"
            "}"
            "QPushButton:hover {"
            "   background-color: #2980b9;"
            "}"
            "QPushButton:pressed {"
            "   background-color: #1f6dad;"
            "}"
        );
        
        connect(detailButton, &QPushButton::clicked, [this, i]() {
            if (i < filteredCarbonData.size()) {
                const CarbonData &data = filteredCarbonData[i];
                showDetailDialog(data);
            }
        });
        
        buttonLayout->addWidget(detailButton);
        buttonLayout->setAlignment(Qt::AlignCenter);
        buttonLayout->setContentsMargins(0, 0, 0, 0);
        ui->dataTableWidget->setCellWidget(i, 6, buttonWidget);
    }
    
    // 更新统计信息
    ui->totalRecordsLabel->setText("总记录数：" + QString::number(filteredCarbonData.size()));
    
    double avgFootprint = filteredCarbonData.isEmpty() ? 0.0 : (totalFootprint / filteredCarbonData.size());
    ui->averageLabel->setText("平均碳足迹：" + QString::number(avgFootprint, 'f', 2) + " kg");
    
    // 更新选择计数
    updateSelectionCount();
}

void DataPage::showDetailDialog(const CarbonData &data)
{
    // 打印调试信息，查看detailData是否包含所需键值
    qDebug() << "显示详情对话框，数据键值:";
    for (auto it = data.detailData.constBegin(); it != data.detailData.constEnd(); ++it) {
        qDebug() << "  键:" << it.key() << ", 值:" << it.value();
    }
    
    // 计算各类别碳足迹总量
    double transportationTotal = 0.0;
    double householdTotal = 0.0;
    double consumptionTotal = 0.0;
    
    // 根据实际键名汇总交通数据
    if (data.detailData.contains("交通排放")) {
        transportationTotal = data.detailData.value("交通排放");
    } else {
        // 如果没有总的"交通排放"键，则尝试汇总各个交通项
        if (data.detailData.contains("飞机")) transportationTotal += data.detailData.value("飞机");
        if (data.detailData.contains("火车")) transportationTotal += data.detailData.value("火车");
        if (data.detailData.contains("公交车")) transportationTotal += data.detailData.value("公交车");
        if (data.detailData.contains("私家车")) transportationTotal += data.detailData.value("私家车");
    }
    
    // 根据实际键名汇总家庭数据
    if (data.detailData.contains("家居排放")) {
        householdTotal = data.detailData.value("家居排放");
    } else {
        // 如果没有总的"家居排放"键，则尝试汇总各个家居项
        if (data.detailData.contains("居住面积")) householdTotal += data.detailData.value("居住面积");
        if (data.detailData.contains("用电")) householdTotal += data.detailData.value("用电");
    }
    
    // 根据实际键名汇总消费数据
    if (data.detailData.contains("消费排放")) {
        consumptionTotal = data.detailData.value("消费排放");
    } else {
        // 如果没有总的"消费排放"键，则尝试汇总各个消费项
        if (data.detailData.contains("一次性筷子")) consumptionTotal += data.detailData.value("一次性筷子");
        if (data.detailData.contains("塑料袋")) consumptionTotal += data.detailData.value("塑料袋");
        if (data.detailData.contains("衣物")) consumptionTotal += data.detailData.value("衣物");
        if (data.detailData.contains("纸张")) consumptionTotal += data.detailData.value("纸张");
    }
    
    qDebug() << "总计: 交通=" << transportationTotal << ", 家庭=" << householdTotal << ", 消费=" << consumptionTotal;
    
    QString detailText = "碳足迹详细数据：\n\n";
    detailText += "记录日期：" + data.timestamp.toString("yyyy-MM-dd hh:mm:ss") + "\n";
    detailText += "总碳足迹：" + QString::number(data.totalCarbonFootprint, 'f', 2) + " kg\n\n";
    
    // 交通碳排放
    detailText += "交通碳排放：" + QString::number(transportationTotal, 'f', 2) + " kg\n";
    if (data.detailData.contains("飞机")) 
        detailText += "  - 飞机：" + QString::number(data.detailData.value("飞机"), 'f', 2) + " kg\n";
    else if (data.detailData.contains("airplane")) 
        detailText += "  - 飞机：" + QString::number(data.detailData.value("airplane"), 'f', 2) + " kg\n";
        
    if (data.detailData.contains("火车")) 
        detailText += "  - 火车：" + QString::number(data.detailData.value("火车"), 'f', 2) + " kg\n";
    else if (data.detailData.contains("train")) 
        detailText += "  - 火车：" + QString::number(data.detailData.value("train"), 'f', 2) + " kg\n";
        
    if (data.detailData.contains("公交车")) 
        detailText += "  - 公交：" + QString::number(data.detailData.value("公交车"), 'f', 2) + " kg\n";
    else if (data.detailData.contains("bus")) 
        detailText += "  - 公交：" + QString::number(data.detailData.value("bus"), 'f', 2) + " kg\n";
        
    if (data.detailData.contains("私家车")) 
        detailText += "  - 私家车：" + QString::number(data.detailData.value("私家车"), 'f', 2) + " kg\n";
    else if (data.detailData.contains("car")) 
        detailText += "  - 私家车：" + QString::number(data.detailData.value("car"), 'f', 2) + " kg\n";
    
    // 家庭碳排放
    detailText += "\n家庭碳排放：" + QString::number(householdTotal, 'f', 2) + " kg\n";
    if (data.detailData.contains("居住面积")) 
        detailText += "  - 居住面积：" + QString::number(data.detailData.value("居住面积"), 'f', 2) + " kg\n";
    else if (data.detailData.contains("livingArea")) 
        detailText += "  - 居住面积：" + QString::number(data.detailData.value("livingArea"), 'f', 2) + " kg\n";
        
    if (data.detailData.contains("用电")) 
        detailText += "  - 用电量：" + QString::number(data.detailData.value("用电"), 'f', 2) + " kg\n";
    else if (data.detailData.contains("electricity")) 
        detailText += "  - 用电量：" + QString::number(data.detailData.value("electricity"), 'f', 2) + " kg\n";
    
    // 消费碳排放
    detailText += "\n消费碳排放：" + QString::number(consumptionTotal, 'f', 2) + " kg\n";
    if (data.detailData.contains("一次性筷子")) 
        detailText += "  - 一次性筷子：" + QString::number(data.detailData.value("一次性筷子"), 'f', 2) + " kg\n";
    else if (data.detailData.contains("disposableChopstick")) 
        detailText += "  - 一次性筷子：" + QString::number(data.detailData.value("disposableChopstick"), 'f', 2) + " kg\n";
        
    if (data.detailData.contains("塑料袋")) 
        detailText += "  - 塑料袋：" + QString::number(data.detailData.value("塑料袋"), 'f', 2) + " kg\n";
    else if (data.detailData.contains("plasticBag")) 
        detailText += "  - 塑料袋：" + QString::number(data.detailData.value("plasticBag"), 'f', 2) + " kg\n";
        
    if (data.detailData.contains("衣物")) 
        detailText += "  - 新置衣物：" + QString::number(data.detailData.value("衣物"), 'f', 2) + " kg\n";
    else if (data.detailData.contains("clothes")) 
        detailText += "  - 新置衣物：" + QString::number(data.detailData.value("clothes"), 'f', 2) + " kg\n";
        
    if (data.detailData.contains("纸张")) 
        detailText += "  - 纸张：" + QString::number(data.detailData.value("纸张"), 'f', 2) + " kg\n";
    else if (data.detailData.contains("paper")) 
        detailText += "  - 纸张：" + QString::number(data.detailData.value("paper"), 'f', 2) + " kg\n";
    
    QMessageBox detailDialog;
    detailDialog.setWindowTitle("碳足迹详情");
    detailDialog.setText(detailText);
    
    // 处理图标加载问题
    QPixmap icon(":/resource/carbonicon.png");
    if (!icon.isNull()) {
        detailDialog.setIconPixmap(icon.scaled(64, 64, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    
    detailDialog.setStandardButtons(QMessageBox::Ok);
    detailDialog.exec();
}

// 添加新的槽函数：全选/取消全选
void DataPage::onSelectAllButtonClicked()
{
    if (ui->dataTableWidget->selectionModel()->selectedRows().count() == ui->dataTableWidget->rowCount()) {
        // 如果所有行都已选中，则取消全选
        ui->dataTableWidget->clearSelection();
    } else {
        // 否则全选
        ui->dataTableWidget->selectAll();
    }
}

// 添加新的槽函数：处理选择变化
void DataPage::onSelectionChanged()
{
    updateSelectionCount();
}

// 添加新的辅助函数：更新选择计数
void DataPage::updateSelectionCount()
{
    int selectedCount = ui->dataTableWidget->selectionModel()->selectedRows().count();
    ui->selectionCountLabel->setText("已选择: " + QString::number(selectedCount) + " 条记录");
    
    // 根据是否有选择项更新删除按钮的状态
    ui->deleteButton->setEnabled(selectedCount > 0);
    
    // 可选：当选择数量较多时改变标签颜色提醒用户
    if (selectedCount > 5) {
        ui->selectionCountLabel->setStyleSheet("color: #e74c3c; font-size: 12px; font-weight: bold;");
    } else {
        ui->selectionCountLabel->setStyleSheet("color: white; font-size: 12px;");
    }
} 