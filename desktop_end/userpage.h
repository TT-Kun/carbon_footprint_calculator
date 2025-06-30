#ifndef USERPAGE_H
#define USERPAGE_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

namespace Ui {
class UserPage;
}

class UserPage : public QWidget
{
    Q_OBJECT

public:
    explicit UserPage(QWidget *parent = nullptr);
    ~UserPage();
    
    // 获取当前用户名
    QString getCurrentUsername() const { return currentUsername; }
    
    // 检查是否已登录
    bool isUserLoggedIn() const { return isLoggedIn; }
    QString getUserToken() const { return apiToken; }
    QString getUsername() const { return currentUsername; }
    
public slots:
    void clearToken();
    void logout();

signals:
    // 登录成功信号
    void loginSuccessful();
    
    // 登出成功信号
    void logoutSuccessful();

private slots:
    void on_loginButton_clicked();
    void on_registerButton_clicked();

private:
    Ui::UserPage *ui;
    
    // 网络管理器
    QNetworkAccessManager *networkManager;
    
    // API基础URL
    const QString baseUrl = "http://8.138.115.164:5000";
    
    // 当前用户名
    QString currentUsername;
    
    // API令牌
    QString apiToken;
    
    // 登录状态
    bool isLoggedIn;
    
    // 验证令牌
    void validateToken();
    
    // 保存令牌
    void saveToken(const QString &token);
    
    // 加载令牌
    QString loadToken();

    
    // 显示错误信息
    void showError(const QString &message);
    
    // 更新UI以反映登录状态
    void updateUIForLoggedInUser();
    void updateUIForLoggedOutUser();
    
    // 密码验证
    bool validatePassword(const QString &password);
};

#endif // USERPAGE_H 
