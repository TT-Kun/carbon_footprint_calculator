#include "userpage.h"
#include "ui_userpage.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QDebug>
#include <QSettings>
#include <QLabel>

UserPage::UserPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserPage),
    networkManager(new QNetworkAccessManager(this)),
    isLoggedIn(false)
{
    ui->setupUi(this);
    
    // 设置密码输入框为密码模式
    ui->passwordInput->setEchoMode(QLineEdit::Password);
    
    // 设置密码输入框的提示信息
    ui->passwordInput->setToolTip("密码必须包含：\n- 至少8位\n- 至少1个大写字母\n- 至少1个小写字母\n- 至少1个数字\n- 至少1个特殊字符(@$!%*?&#)");
    
    // 初始隐藏退出登录按钮
    ui->logoutButton->setVisible(false);
    
    // 加载保存的token
    apiToken = loadToken();
    if (!apiToken.isEmpty()) {
        validateToken();
    }
    
    // 连接退出登录按钮
    connect(ui->logoutButton, &QPushButton::clicked, this, &UserPage::logout);
}

UserPage::~UserPage()
{
    delete ui;
}

void UserPage::on_loginButton_clicked()
{
    QString username = ui->usernameInput->text().trimmed();
    QString password = ui->passwordInput->text();
    
    // 输入验证
    if(username.isEmpty()) {
        showError("请输入用户名");
        ui->usernameInput->setFocus();
        return;
    }
    
    if(password.isEmpty()) {
        showError("请输入密码");
        ui->passwordInput->setFocus();
        return;
    }
    
    // 显示加载提示
    QLabel* loadingLabel = new QLabel("正在登录...", this);
    loadingLabel->setStyleSheet("QLabel { color: #2196F3; padding: 10px; background: #34495e; border: 1px solid #2c3e50; border-radius: 5px; }");
    loadingLabel->setAlignment(Qt::AlignCenter);
    loadingLabel->move(width()/2 - loadingLabel->width()/2, height()/2 - loadingLabel->height()/2);
    loadingLabel->show();

    QJsonObject jsonObj;
    jsonObj["username"] = username;
    jsonObj["password"] = password;

    QNetworkRequest request(QUrl(baseUrl + "/api/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = networkManager->post(request, QJsonDocument(jsonObj).toJson());
    connect(reply, &QNetworkReply::finished, this, [this, reply, username, loadingLabel]() {
        loadingLabel->deleteLater();
        reply->deleteLater();
        
        QByteArray responseData = reply->readAll();
        
        if (reply->error() == QNetworkReply::NoError) {
            QJsonDocument doc = QJsonDocument::fromJson(responseData);
            QJsonObject obj = doc.object();
            
            if (obj["success"].toBool()) {
                QString token = obj["token"].toString();
                saveToken(token);
                currentUsername = username;
                isLoggedIn = true;
                updateUIForLoggedInUser();
                QMessageBox::information(this, "登录成功", 
                    QString("欢迎回来，%1\n您现在可以开始使用碳足迹计算器了。").arg(username));
                emit loginSuccessful();
            } else {
                QString errorMsg = obj["message"].toString();
                if(errorMsg.isEmpty()) {
                    errorMsg = "用户名或密码错误";
                } else if(errorMsg.contains("password", Qt::CaseInsensitive)) {
                    errorMsg = "密码错误，请重新输入";
                } else if(errorMsg.contains("user", Qt::CaseInsensitive) || 
                         errorMsg.contains("username", Qt::CaseInsensitive)) {
                    errorMsg = "用户不存在，请检查用户名或注册新账号";
                }
                showError(errorMsg);
            }
        } else {
            // 处理网络错误
            if (reply->error() == QNetworkReply::AuthenticationRequiredError) {
                // 401错误，认证失败，表示用户名或密码错误
                showError("用户名或密码错误，请重新输入");
            } else {
                // 尝试解析错误响应中的JSON
                QJsonDocument errorDoc = QJsonDocument::fromJson(responseData);
                if (!errorDoc.isNull() && errorDoc.isObject()) {
                    QJsonObject errorObj = errorDoc.object();
                    if (errorObj.contains("message")) {
                        QString serverMessage = errorObj["message"].toString();
                        if (!serverMessage.isEmpty()) {
                            showError(serverMessage);
                            return;
                        }
                    }
                }
                
                // 其他网络错误
                showError("连接服务器失败，请检查网络连接。\n错误信息：" + reply->errorString());
            }
        }
    });
}

void UserPage::on_registerButton_clicked()
{
    QString username = ui->usernameInput->text().trimmed();
    QString password = ui->passwordInput->text();
    QString email = ui->emailInput->text().trimmed();
    
    // 输入验证
    if(username.isEmpty()) {
        showError("请输入用户名");
        ui->usernameInput->setFocus();
        return;
    }
    
    if(password.isEmpty()) {
        showError("请输入密码");
        ui->passwordInput->setFocus();
        return;
    }
    
    if(email.isEmpty()) {
        showError("请输入邮箱地址");
        ui->emailInput->setFocus();
        return;
    }
    
    // 邮箱格式验证
    QRegularExpression emailRegex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}\\b");
    QRegularExpressionMatch match = emailRegex.match(email);
    if(!match.hasMatch()) {
        showError("请输入有效的邮箱地址");
        ui->emailInput->setFocus();
        return;
    }
    
    // 密码验证
    if (!validatePassword(password)) {
        return;
    }
    
    // 显示加载提示
    QLabel* loadingLabel = new QLabel("正在注册...", this);
    loadingLabel->setStyleSheet("QLabel { color: #2196F3; padding: 10px; background: #34495e; border: 1px solid #2c3e50; border-radius: 5px; }");
    loadingLabel->setAlignment(Qt::AlignCenter);
    loadingLabel->move(width()/2 - loadingLabel->width()/2, height()/2 - loadingLabel->height()/2);
    loadingLabel->show();
    
    QJsonObject jsonObj;
    jsonObj["username"] = username;
    jsonObj["password"] = password;
    jsonObj["email"] = email;
    
    QNetworkRequest request(QUrl(baseUrl + "/api/register"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    
    QNetworkReply *reply = networkManager->post(request, QJsonDocument(jsonObj).toJson());
    connect(reply, &QNetworkReply::finished, this, [this, reply, username, loadingLabel]() {
        loadingLabel->deleteLater();
        reply->deleteLater();
        
        QByteArray responseData = reply->readAll();
        qDebug() << "Register response:" << responseData;
        
        if (reply->error() == QNetworkReply::NoError) {
            QJsonDocument doc = QJsonDocument::fromJson(responseData);
            QJsonObject obj = doc.object();
            
            if (obj["success"].toBool()) {
                QString token = obj["token"].toString();
                saveToken(token);
                currentUsername = username;
                isLoggedIn = true;
                updateUIForLoggedInUser();
                QMessageBox::information(this, "注册成功", 
                    QString("账户创建成功！\n欢迎使用碳足迹计算器，%1。").arg(username));
                emit loginSuccessful();
            } else {
                // 改进错误消息处理，支持Unicode编码的错误信息
                QString errorMsg = obj["message"].toString();
                
                // 尝试解码可能的Unicode转义序列
                errorMsg.replace("\\u", "\\\\u"); // 防止QRegularExpression误解Unicode转义
                QRegularExpression unicodePattern("\\\\\\\\u([0-9a-fA-F]{4})");
                QRegularExpressionMatchIterator i = unicodePattern.globalMatch(errorMsg);
                while (i.hasNext()) {
                    QRegularExpressionMatch match = i.next();
                    QString hexCode = match.captured(1);
                    bool ok;
                    int unicodeValue = hexCode.toInt(&ok, 16);
                    if (ok) {
                        errorMsg.replace("\\\\u" + hexCode, QChar(unicodeValue));
                    }
                }
                
                if(errorMsg.isEmpty()) {
                    errorMsg = "注册失败，请稍后重试";
                } else if(errorMsg.contains("username", Qt::CaseInsensitive) || 
                         errorMsg.contains("already exists", Qt::CaseInsensitive) ||
                         errorMsg.contains("已存在", Qt::CaseInsensitive)) {
                    errorMsg = "用户名已被占用，请尝试其他用户名";
                } else if(errorMsg.contains("email", Qt::CaseInsensitive) ||
                          errorMsg.contains("邮箱", Qt::CaseInsensitive)) {
                    errorMsg = "邮箱已被注册，请使用其他邮箱或尝试找回密码";
                }
                showError(errorMsg);
            }
        } else {
            QString errorString = reply->errorString();
            QString responseString = QString::fromUtf8(responseData);
            
            // 处理网络错误
            if (reply->error() == QNetworkReply::AuthenticationRequiredError) {
                // 401错误，认证失败
                showError("注册失败：认证错误，请稍后重试");
                return;
            }
            
            // 尝试解析错误响应中的JSON
            QJsonDocument errorDoc = QJsonDocument::fromJson(responseData);
            if (!errorDoc.isNull() && errorDoc.isObject()) {
                QJsonObject errorObj = errorDoc.object();
                if (errorObj.contains("message")) {
                    QString serverMessage = errorObj["message"].toString();
                    // 尝试解码Unicode转义序列
                    serverMessage.replace("\\u", "\\\\u");
                    QRegularExpression unicodePattern("\\\\\\\\u([0-9a-fA-F]{4})");
                    QRegularExpressionMatchIterator i = unicodePattern.globalMatch(serverMessage);
                    while (i.hasNext()) {
                        QRegularExpressionMatch match = i.next();
                        QString hexCode = match.captured(1);
                        bool ok;
                        int unicodeValue = hexCode.toInt(&ok, 16);
                        if (ok) {
                            serverMessage.replace("\\\\u" + hexCode, QChar(unicodeValue));
                        }
                    }
                    
                    if (!serverMessage.isEmpty()) {
                        showError("注册失败: " + serverMessage);
                        return;
                    }
                }
            }
            
            showError("连接服务器失败，请检查网络连接。\n错误信息：" + errorString);
        }
    });
}

void UserPage::validateToken()
{
    QNetworkRequest request(QUrl(baseUrl + "/api/me"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", QString("Bearer %1").arg(apiToken).toUtf8());
    
    QNetworkReply *reply = networkManager->get(request);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        reply->deleteLater();
        QByteArray responseData = reply->readAll();
        
        if (reply->error() == QNetworkReply::NoError) {
            QJsonDocument doc = QJsonDocument::fromJson(responseData);
            QJsonObject obj = doc.object();
            if (obj["success"].toBool()) {
                currentUsername = obj["user"].toObject()["username"].toString();
                isLoggedIn = true;
                updateUIForLoggedInUser();
                emit loginSuccessful();
            } else {
                clearToken();
                updateUIForLoggedOutUser();
            }
        } else {
            // 处理网络错误，对于令牌验证，任何错误都视为令牌无效
            clearToken();
            updateUIForLoggedOutUser();
            
            // 不需要显示错误信息，因为这是后台验证过程
        }
    });
}

void UserPage::saveToken(const QString &token)
{
    QSettings settings;
    settings.setValue("apiToken", token);
    apiToken = token;
}

QString UserPage::loadToken()
{
    QSettings settings;
    return settings.value("apiToken").toString();
}

void UserPage::clearToken()
{
    QSettings settings;
    settings.remove("apiToken");
    apiToken.clear();
    isLoggedIn = false;
}

void UserPage::showError(const QString &message)
{
    QMessageBox::warning(this, "错误", message);
}

bool UserPage::validatePassword(const QString &password)
{
    if (password.length() < 8) {
        showError("密码长度必须至少为8位");
        return false;
    }

    QRegularExpression lowerCase("[a-z]");
    QRegularExpression upperCase("[A-Z]");
    QRegularExpression digit("\\d");
    QRegularExpression special("[@$!%*?&#]");

    if (!password.contains(lowerCase)) {
        showError("密码必须包含至少一个小写字母");
        return false;
    }
    if (!password.contains(upperCase)) {
        showError("密码必须包含至少一个大写字母");
        return false;
    }
    if (!password.contains(digit)) {
        showError("密码必须包含至少一个数字");
        return false;
    }
    if (!password.contains(special)) {
        showError("密码必须包含至少一个特殊字符(@$!%*?&#)");
        return false;
    }

    return true;
}

void UserPage::logout()
{
    // 清除令牌
    clearToken();
    
    // 清空输入框
    ui->usernameInput->clear();
    ui->passwordInput->clear();
    ui->emailInput->clear();
    
    // 更新UI
    updateUIForLoggedOutUser();
    
    // 通知主窗口用户已退出
    emit logoutSuccessful();
    
    QMessageBox::information(this, "退出成功", "您已成功退出登录");
}

void UserPage::updateUIForLoggedInUser()
{
    // 显示退出登录按钮
    ui->logoutButton->setVisible(true);
    
    // 禁用输入框和登录/注册按钮
    ui->usernameInput->setEnabled(false);
    ui->passwordInput->setEnabled(false);
    ui->emailInput->setEnabled(false);
    ui->loginButton->setEnabled(false);
    ui->registerButton->setEnabled(false);
    
    // 设置用户名显示
    ui->usernameInput->setText(currentUsername);
    ui->passwordInput->setText("********");
    ui->emailInput->clear();
    
    // 更新标题
    ui->titleLabel->setText("碳足迹计算器 - 用户中心 (已登录)");
}

void UserPage::updateUIForLoggedOutUser()
{
    // 隐藏退出登录按钮
    ui->logoutButton->setVisible(false);
    
    // 启用输入框和登录/注册按钮
    ui->usernameInput->setEnabled(true);
    ui->passwordInput->setEnabled(true);
    ui->emailInput->setEnabled(true);
    ui->loginButton->setEnabled(true);
    ui->registerButton->setEnabled(true);
    
    // 清空输入框
    ui->usernameInput->clear();
    ui->passwordInput->clear();
    ui->emailInput->clear();
    
    // 更新标题
    ui->titleLabel->setText("碳足迹计算器 - 用户中心");
} 