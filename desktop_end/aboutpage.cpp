#include "aboutpage.h"
#include "ui_aboutpage.h"
#include <QDateTime>
#include <QFile>

AboutPage::AboutPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutPage),
    settings(new QSettings("CarbonFootprint", "Calculator", this))
{
    ui->setupUi(this);
    
    // 初始化UI
    initUI();
    
    // 设置连接
    setupConnections();
}

AboutPage::~AboutPage()
{
    delete ui;
}

QString AboutPage::getVersion() const
{
    return appVersion;
}

bool AboutPage::clearHistory()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("确认清空历史"), 
                                tr("确定要清空所有历史记录吗？此操作不可撤销。"), 
                                QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        // 清空历史数据的文件路径
        QString dataFilePath = QDir::currentPath() + "/carbon_data.json";
        
        // 检查文件是否存在
        QFile dataFile(dataFilePath);
        if (dataFile.exists()) {
            // 创建空JSON对象和文档
            QJsonObject emptyObject;
            QJsonDocument emptyDoc(emptyObject);
            
            // 尝试打开文件进行写入
            if (dataFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
                dataFile.write(emptyDoc.toJson());
                dataFile.close();
                
                // 发送历史清空信号
                emit historyCleared();
                
                QMessageBox::information(this, tr("操作成功"), tr("历史记录已成功清空。"));
                return true;
            } else {
                QMessageBox::critical(this, tr("错误"), tr("无法打开数据文件进行写入: ") + dataFile.errorString());
                return false;
            }
        } else {
            QMessageBox::information(this, tr("提示"), tr("没有找到历史数据文件。"));
            return true;
        }
    }
    return false;
}

void AboutPage::initUI()
{
    // 设置版本信息
    ui->versionLabel->setText("版本: " + appVersion);
    
    // 设置构建日期
    ui->buildDateLabel->setText("构建日期: " + buildDate);
    
    // 设置版权信息
    ui->copyrightLabel->setText("版权所有 © " + QString::number(QDateTime::currentDateTime().date().year()) + " 碳足迹计算器团队");
    
    // 设置关于文本
    QString aboutText = "碳足迹计算器是一款帮助用户计算和跟踪个人碳排放的工具。\n\n"
                       "通过记录日常活动，如交通出行、能源使用、食物消费等，用户可以了解自己对环境的影响，"
                       "并找到减少碳排放的方法。\n\n"
                       "我们的目标是提高环保意识，促进可持续发展。";
    ui->aboutTextEdit->setText(aboutText);
    ui->aboutTextEdit->setReadOnly(true);
}

void AboutPage::setupConnections()
{
    // 连接按钮点击事件
    connect(ui->visitWebsiteButton, &QPushButton::clicked, this, &AboutPage::onVisitWebsiteButtonClicked);
    connect(ui->viewSourceButton, &QPushButton::clicked, this, &AboutPage::onViewSourceButtonClicked);
    connect(ui->contactUsButton, &QPushButton::clicked, this, &AboutPage::onContactUsButtonClicked);
    connect(ui->privacyPolicyButton, &QPushButton::clicked, this, &AboutPage::onPrivacyPolicyButtonClicked);
    connect(ui->clearHistoryButton, &QPushButton::clicked, this, &AboutPage::onClearHistoryButtonClicked);
    connect(ui->exportSettingsButton, &QPushButton::clicked, this, &AboutPage::onExportSettingsButtonClicked);
    connect(ui->importSettingsButton, &QPushButton::clicked, this, &AboutPage::onImportSettingsButtonClicked);
}

void AboutPage::onVisitWebsiteButtonClicked()
{
    QDesktopServices::openUrl(QUrl(websiteUrl));
}

void AboutPage::onViewSourceButtonClicked()
{
    QDesktopServices::openUrl(QUrl(sourceCodeUrl));
}

void AboutPage::onContactUsButtonClicked()
{
    QMessageBox::information(this, "联系我们", 
                            "如有任何问题或建议，请通过以下方式联系我们：\n\n"
                            "电子邮件: support@carbonfootprint.example.com\n"
                            "官方网站: " + websiteUrl);
}

void AboutPage::onPrivacyPolicyButtonClicked()
{
    QMessageBox::information(this, "隐私政策", 
                            "我们重视您的隐私。我们收集的所有数据仅用于计算碳足迹，"
                            "并且在未经您同意的情况下不会与第三方共享。\n\n"
                            "详细的隐私政策可在我们的官方网站上查看。");
}

void AboutPage::onClearHistoryButtonClicked()
{
    clearHistory();
}

void AboutPage::onExportSettingsButtonClicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("导出设置"), 
                                                  QDir::homePath() + "/settings.json", 
                                                  tr("JSON文件 (*.json)"));
    if (!fileName.isEmpty()) {
        // 创建设置对象
        QJsonObject settingsObject;
        
        // 将当前设置保存到JSON对象
        settingsObject["theme"] = settings->value("theme", "dark").toString();
        settingsObject["language"] = settings->value("language", "zh_CN").toString();
        settingsObject["units"] = settings->value("units", "metric").toString();
        settingsObject["dataSaveDays"] = settings->value("dataSaveDays", 365).toInt();
        settingsObject["autoSave"] = settings->value("autoSave", true).toBool();
        settingsObject["checkUpdateOnStart"] = settings->value("checkUpdateOnStart", true).toBool();
        
        // 创建JSON文档
        QJsonDocument doc(settingsObject);
        
        // 打开文件并写入
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly)) {
            file.write(doc.toJson());
            file.close();
            QMessageBox::information(this, tr("导出成功"), tr("设置已成功导出到文件。"));
        } else {
            QMessageBox::critical(this, tr("导出失败"), tr("无法写入文件: ") + file.errorString());
        }
    }
}

void AboutPage::onImportSettingsButtonClicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("导入设置"), 
                                                  QDir::homePath(), 
                                                  tr("JSON文件 (*.json)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        
        if (file.open(QIODevice::ReadOnly)) {
            QByteArray data = file.readAll();
            file.close();
            
            QJsonDocument doc = QJsonDocument::fromJson(data);
            if (doc.isNull()) {
                QMessageBox::critical(this, tr("导入失败"), tr("无法解析JSON文件。"));
                return;
            }
            
            QJsonObject settingsObject = doc.object();
            
            // 验证设置文件格式
            if (settingsObject.isEmpty()) {
                QMessageBox::critical(this, tr("导入失败"), tr("设置文件格式无效或为空。"));
                return;
            }
            
            // 从JSON对象加载设置到应用程序
            if (settingsObject.contains("theme")) {
                settings->setValue("theme", settingsObject["theme"].toString());
            }
            
            if (settingsObject.contains("language")) {
                settings->setValue("language", settingsObject["language"].toString());
            }
            
            if (settingsObject.contains("units")) {
                settings->setValue("units", settingsObject["units"].toString());
            }
            
            if (settingsObject.contains("dataSaveDays")) {
                settings->setValue("dataSaveDays", settingsObject["dataSaveDays"].toInt());
            }
            
            if (settingsObject.contains("autoSave")) {
                settings->setValue("autoSave", settingsObject["autoSave"].toBool());
            }
            
            if (settingsObject.contains("checkUpdateOnStart")) {
                settings->setValue("checkUpdateOnStart", settingsObject["checkUpdateOnStart"].toBool());
            }
            
            QMessageBox::information(this, tr("导入成功"), tr("设置已成功从文件导入。部分设置可能需要重启应用后生效。"));
        } else {
            QMessageBox::critical(this, tr("导入失败"), tr("无法打开文件: ") + file.errorString());
        }
    }
} 