#ifndef DATAPAGE_H
#define DATAPAGE_H

#include <QWidget>
#include <QTableWidget>
#include <QDateTime>
#include <QVector>
#include <QMap>
#include <QFile>
#include <QJsonDocument>

namespace Ui {
class DataPage;
}

// 定义碳足迹数据结构
struct CarbonData {
    int id;                     // 数据ID
    QString username;           // 用户名
    QDateTime timestamp;        // 记录时间
    double totalCarbonFootprint; // 总碳足迹
    
    // 各项详细数据
    QMap<QString, double> detailData;
};

class DataPage : public QWidget
{
    Q_OBJECT

public:
    explicit DataPage(QWidget *parent = nullptr);
    ~DataPage();
    
    // 添加新的碳足迹数据记录
    void addCarbonData(const QString &username, double totalCarbonFootprint, const QMap<QString, double> &detailData);
    
    // 加载指定用户的数据
    void loadUserData(const QString &username);
    
    // 清除当前显示的数据
    void clearData();
    
    // 保存数据到文件
    bool saveDataToFile();
    
    // 从文件加载数据
    bool loadDataFromFile();

signals:
    // 数据更新信号
    void dataUpdated();

private slots:
    // 编辑按钮点击事件
    void onEditButtonClicked();
    
    // 删除按钮点击事件
    void onDeleteButtonClicked();
    
    // 导出数据按钮点击事件
    void onExportButtonClicked();
    
    // 搜索按钮点击事件
    void onSearchButtonClicked();
    
    // 全选/取消全选按钮点击事件
    void onSelectAllButtonClicked();
    
    // 表格选择变化事件
    void onSelectionChanged();

private:
    Ui::DataPage *ui;
    
    // 所有碳足迹数据记录
    QVector<CarbonData> allCarbonData;
    
    // 当前显示的过滤后的数据
    QVector<CarbonData> filteredCarbonData;
    
    // 当前登录的用户名
    QString currentUsername;
    
    // 更新表格显示
    void updateTableView();
    
    // 显示详情对话框
    void showDetailDialog(const CarbonData &data);
    
    // 更新选择计数
    void updateSelectionCount();
    
    // 重置所有数据的ID，从1开始
    void resetAllIds();
    
    // 数据存储目录
    QString dataDir;
    
    // 当前用户的数据文件路径
    QString dataFilePath;
};

#endif // DATAPAGE_H 