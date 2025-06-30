/********************************************************************************
** Form generated from reading UI file 'userpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPAGE_H
#define UI_USERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserPage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QWidget *formContainer;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameInput;
    QLabel *passwordLabel;
    QLineEdit *passwordInput;
    QLabel *emailLabel;
    QLineEdit *emailInput;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QPushButton *logoutButton;

    void setupUi(QWidget *UserPage)
    {
        if (UserPage->objectName().isEmpty())
            UserPage->setObjectName("UserPage");
        UserPage->resize(800, 600);
        UserPage->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #2c3e50;\n"
"    color: #ecf0f1;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #ecf0f1;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    padding: 12px;\n"
"    border-radius: 6px;\n"
"    background-color: rgba(52, 73, 94, 0.8);\n"
"    border: 2px solid #3498db;\n"
"    color: #ecf0f1;\n"
"    font-size: 14px;\n"
"    selection-background-color: #3498db;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2980b9;\n"
"    background-color: rgba(44, 62, 80, 0.9);\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #95a5a6;\n"
"}\n"
"\n"
"QPushButton {\n"
"    padding: 12px;\n"
"    border-radius: 6px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"    border: none;\n"
"    min-width: 120px;\n"
"}\n"
"\n"
"QPushButton#loginButton {\n"
"    background-color: #2ecc71;\n"
"}\n"
"\n"
"QPushButton#loginButton:hover {\n"
"    background-color: #27ae60;\n"
"}\n"
"\n"
"QPush"
                        "Button#loginButton:pressed {\n"
"    background-color: #219a52;\n"
"}\n"
"\n"
"QPushButton#registerButton {\n"
"    background-color: #3498db;\n"
"}\n"
"\n"
"QPushButton#registerButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"\n"
"QPushButton#registerButton:pressed {\n"
"    background-color: #2472a4;\n"
"}\n"
"\n"
"#titleLabel {\n"
"    color: #3498db;\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"    margin: 20px;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#formContainer {\n"
"    background-color: rgba(52, 73, 94, 0.7);\n"
"    border-radius: 10px;\n"
"    padding: 20px;\n"
"}"));
        verticalLayout = new QVBoxLayout(UserPage);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(40, 40, 40, 40);
        titleLabel = new QLabel(UserPage);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        formContainer = new QWidget(UserPage);
        formContainer->setObjectName("formContainer");
        verticalLayout_2 = new QVBoxLayout(formContainer);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(30, 30, 30, 30);
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(20);
        formLayout->setVerticalSpacing(20);
        usernameLabel = new QLabel(formContainer);
        usernameLabel->setObjectName("usernameLabel");
        usernameLabel->setMinimumSize(QSize(80, 0));

        formLayout->setWidget(0, QFormLayout::LabelRole, usernameLabel);

        usernameInput = new QLineEdit(formContainer);
        usernameInput->setObjectName("usernameInput");
        usernameInput->setMinimumSize(QSize(0, 40));

        formLayout->setWidget(0, QFormLayout::FieldRole, usernameInput);

        passwordLabel = new QLabel(formContainer);
        passwordLabel->setObjectName("passwordLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, passwordLabel);

        passwordInput = new QLineEdit(formContainer);
        passwordInput->setObjectName("passwordInput");
        passwordInput->setMinimumSize(QSize(0, 40));

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordInput);

        emailLabel = new QLabel(formContainer);
        emailLabel->setObjectName("emailLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, emailLabel);

        emailInput = new QLineEdit(formContainer);
        emailInput->setObjectName("emailInput");
        emailInput->setMinimumSize(QSize(0, 40));

        formLayout->setWidget(2, QFormLayout::FieldRole, emailInput);


        verticalLayout_2->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName("horizontalLayout");
        loginButton = new QPushButton(formContainer);
        loginButton->setObjectName("loginButton");
        loginButton->setMinimumSize(QSize(0, 45));

        horizontalLayout->addWidget(loginButton);

        registerButton = new QPushButton(formContainer);
        registerButton->setObjectName("registerButton");
        registerButton->setMinimumSize(QSize(0, 45));

        horizontalLayout->addWidget(registerButton);


        verticalLayout_2->addLayout(horizontalLayout);

        logoutButton = new QPushButton(formContainer);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setMinimumSize(QSize(0, 45));
        logoutButton->setStyleSheet(QString::fromUtf8("background-color: #e74c3c;\n"
"\n"
"QPushButton#logoutButton:hover {\n"
"    background-color: #c0392b;\n"
"}\n"
"\n"
"QPushButton#logoutButton:pressed {\n"
"    background-color: #a93226;\n"
"}"));

        verticalLayout_2->addWidget(logoutButton);


        verticalLayout->addWidget(formContainer);


        retranslateUi(UserPage);

        QMetaObject::connectSlotsByName(UserPage);
    } // setupUi

    void retranslateUi(QWidget *UserPage)
    {
        UserPage->setWindowTitle(QCoreApplication::translate("UserPage", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        titleLabel->setText(QCoreApplication::translate("UserPage", "\347\242\263\350\266\263\350\277\271\350\256\241\347\256\227\345\231\250 - \347\224\250\346\210\267\344\270\255\345\277\203", nullptr));
        usernameLabel->setText(QCoreApplication::translate("UserPage", "\347\224\250\346\210\267\345\220\215", nullptr));
        usernameInput->setPlaceholderText(QCoreApplication::translate("UserPage", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        passwordLabel->setText(QCoreApplication::translate("UserPage", "\345\257\206\347\240\201", nullptr));
        passwordInput->setPlaceholderText(QCoreApplication::translate("UserPage", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        emailLabel->setText(QCoreApplication::translate("UserPage", "\351\202\256\347\256\261", nullptr));
        emailInput->setPlaceholderText(QCoreApplication::translate("UserPage", "\350\257\267\350\276\223\345\205\245\351\202\256\347\256\261\357\274\210\344\273\205\346\263\250\345\206\214\351\234\200\350\246\201\357\274\211", nullptr));
        loginButton->setText(QCoreApplication::translate("UserPage", "\347\231\273\345\275\225", nullptr));
        registerButton->setText(QCoreApplication::translate("UserPage", "\346\263\250\345\206\214", nullptr));
        logoutButton->setText(QCoreApplication::translate("UserPage", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserPage: public Ui_UserPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPAGE_H
