#ifndef ABOUTPAGE_H
#define ABOUTPAGE_H

#include <QWidget>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QSettings>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDir>

namespace Ui {
class AboutPage;
}

class AboutPage : public QWidget
{
    Q_OBJECT

public:
    explicit AboutPage(QWidget *parent = nullptr);
    ~AboutPage();
    
    // 获取当前版本号
    QString getVersion() const;
    
    // 清空历史记录
    bool clearHistory();

signals:
    // 清空历史记录信号
    void historyCleared();

private slots:
    // 访问官网按钮点击事件
    void onVisitWebsiteButtonClicked();
    
    // 查看源码按钮点击事件
    void onViewSourceButtonClicked();
    
    // 联系我们按钮点击事件
    void onContactUsButtonClicked();
    
    // 隐私政策按钮点击事件
    void onPrivacyPolicyButtonClicked();
    
    // 清空历史按钮点击事件
    void onClearHistoryButtonClicked();
    
    // 导出设置按钮点击事件
    void onExportSettingsButtonClicked();
    
    // 导入设置按钮点击事件
    void onImportSettingsButtonClicked();

private:
    Ui::AboutPage *ui;
    
    // 应用版本号
    const QString appVersion = "1.0.0";
    
    // 应用构建日期
    const QString buildDate = __DATE__;
    
    // 官方网站URL
    const QString websiteUrl = "http://8.138.115.164/";
    
    // 源码仓库URL
    const QString sourceCodeUrl = "https://gitee.com/ttkun/carbon_footprint_calculator";
    
    // 设置对象
    QSettings *settings;
    
    // 初始化UI
    void initUI();
    
    // 连接信号和槽
    void setupConnections();
};

#endif // ABOUTPAGE_H 
