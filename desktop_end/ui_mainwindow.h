/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *leftNavBar;
    QVBoxLayout *verticalLayout;
    QLabel *logoLabel;
    QPushButton *homeButton;
    QPushButton *calculatorButton;
    QPushButton *dataButton;
    QPushButton *settingsButton;
    QPushButton *infoButton;
    QSpacerItem *verticalSpacer;
    QPushButton *userButton;
    QStackedWidget *stackedWidget;
    QWidget *homePage;
    QVBoxLayout *verticalLayout_2;
    QFrame *headerFrame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *titleLabel;
    QFrame *contentFrame;
    QVBoxLayout *verticalLayout_3;
    QFrame *carouselFrame;
    QVBoxLayout *verticalLayout_4;
    QLabel *carouselLabel;
    QFrame *dotFrame;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *dot1;
    QLabel *dot2;
    QLabel *dot3;
    QLabel *dot4;
    QSpacerItem *horizontalSpacer_2;
    QFrame *actionButtonsFrame;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *startCalculateButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *officialWebsiteButton;
    QSpacerItem *horizontalSpacer_4;
    QWidget *calculatorPage;
    QVBoxLayout *verticalLayout_5;
    QLabel *calculatorPageLabel;
    QWidget *dataPage;
    QVBoxLayout *verticalLayout_6;
    QLabel *dataPageLabel;
    QWidget *settingsPage;
    QVBoxLayout *verticalLayout_7;
    QLabel *settingsPageLabel;
    QWidget *infoPage;
    QVBoxLayout *verticalLayout_8;
    QLabel *infoPageLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(782, 600);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        leftNavBar = new QWidget(centralwidget);
        leftNavBar->setObjectName("leftNavBar");
        leftNavBar->setMinimumSize(QSize(70, 0));
        leftNavBar->setMaximumSize(QSize(70, 16777215));
        leftNavBar->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 150);"));
        verticalLayout = new QVBoxLayout(leftNavBar);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 20, 0, 0);
        logoLabel = new QLabel(leftNavBar);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setMinimumSize(QSize(50, 50));
        logoLabel->setMaximumSize(QSize(50, 50));
        logoLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-radius: 25px;"));
        logoLabel->setPixmap(QPixmap(QString::fromUtf8(":/resource/logo.png")));
        logoLabel->setScaledContents(true);
        logoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(logoLabel, 0, Qt::AlignHCenter);

        homeButton = new QPushButton(leftNavBar);
        homeButton->setObjectName("homeButton");
        homeButton->setMinimumSize(QSize(50, 50));
        homeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/homepage_white.png"), QSize(), QIcon::Normal, QIcon::Off);
        homeButton->setIcon(icon);
        homeButton->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(homeButton);

        calculatorButton = new QPushButton(leftNavBar);
        calculatorButton->setObjectName("calculatorButton");
        calculatorButton->setMinimumSize(QSize(50, 50));
        calculatorButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/calculator_white.png"), QSize(), QIcon::Normal, QIcon::Off);
        calculatorButton->setIcon(icon1);
        calculatorButton->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(calculatorButton);

        dataButton = new QPushButton(leftNavBar);
        dataButton->setObjectName("dataButton");
        dataButton->setMinimumSize(QSize(50, 50));
        dataButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resource/statistics_white.png"), QSize(), QIcon::Normal, QIcon::Off);
        dataButton->setIcon(icon2);
        dataButton->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(dataButton);

        settingsButton = new QPushButton(leftNavBar);
        settingsButton->setObjectName("settingsButton");
        settingsButton->setMinimumSize(QSize(50, 50));
        settingsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resource/data.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingsButton->setIcon(icon3);
        settingsButton->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(settingsButton);

        infoButton = new QPushButton(leftNavBar);
        infoButton->setObjectName("infoButton");
        infoButton->setMinimumSize(QSize(50, 50));
        infoButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resource/setting_white.png"), QSize(), QIcon::Normal, QIcon::Off);
        infoButton->setIcon(icon4);
        infoButton->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(infoButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        userButton = new QPushButton(leftNavBar);
        userButton->setObjectName("userButton");
        userButton->setMinimumSize(QSize(50, 50));
        userButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #34495e;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resource/user_white.png"), QSize(), QIcon::Normal, QIcon::Off);
        userButton->setIcon(icon5);
        userButton->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(userButton);


        horizontalLayout->addWidget(leftNavBar);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        homePage = new QWidget();
        homePage->setObjectName("homePage");
        verticalLayout_2 = new QVBoxLayout(homePage);
        verticalLayout_2->setObjectName("verticalLayout_2");
        headerFrame = new QFrame(homePage);
        headerFrame->setObjectName("headerFrame");
        headerFrame->setMinimumSize(QSize(600, 120));
        headerFrame->setMaximumSize(QSize(800, 120));
        headerFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(52, 73, 94, 150);\n"
"border-radius: 10px;"));
        headerFrame->setFrameShape(QFrame::StyledPanel);
        headerFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(headerFrame);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        titleLabel = new QLabel(headerFrame);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 36px;\n"
"color: white;\n"
"background-color: transparent;"));
        titleLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(titleLabel);


        verticalLayout_2->addWidget(headerFrame, 0, Qt::AlignHCenter);

        contentFrame = new QFrame(homePage);
        contentFrame->setObjectName("contentFrame");
        contentFrame->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-radius: 10px;"));
        contentFrame->setFrameShape(QFrame::StyledPanel);
        contentFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(contentFrame);
        verticalLayout_3->setObjectName("verticalLayout_3");
        carouselFrame = new QFrame(contentFrame);
        carouselFrame->setObjectName("carouselFrame");
        carouselFrame->setMinimumSize(QSize(0, 300));
        carouselFrame->setMaximumSize(QSize(720, 16777215));
        carouselFrame->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border-radius: 10px;"));
        carouselFrame->setFrameShape(QFrame::StyledPanel);
        carouselFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(carouselFrame);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(5, 5, 5, 5);
        carouselLabel = new QLabel(carouselFrame);
        carouselLabel->setObjectName("carouselLabel");
        carouselLabel->setMinimumSize(QSize(600, 0));
        carouselLabel->setMaximumSize(QSize(700, 16777215));
        carouselLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        carouselLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(carouselLabel, 0, Qt::AlignHCenter);

        dotFrame = new QFrame(carouselFrame);
        dotFrame->setObjectName("dotFrame");
        dotFrame->setMaximumSize(QSize(16777215, 30));
        dotFrame->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        dotFrame->setFrameShape(QFrame::StyledPanel);
        dotFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(dotFrame);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        dot1 = new QLabel(dotFrame);
        dot1->setObjectName("dot1");
        dot1->setMinimumSize(QSize(16, 16));
        dot1->setMaximumSize(QSize(16, 16));
        dot1->setStyleSheet(QString::fromUtf8("background-color: #2980b9;\n"
"border-radius: 8px;"));

        horizontalLayout_3->addWidget(dot1);

        dot2 = new QLabel(dotFrame);
        dot2->setObjectName("dot2");
        dot2->setMinimumSize(QSize(16, 16));
        dot2->setMaximumSize(QSize(16, 16));
        dot2->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 8px;"));

        horizontalLayout_3->addWidget(dot2);

        dot3 = new QLabel(dotFrame);
        dot3->setObjectName("dot3");
        dot3->setMinimumSize(QSize(16, 16));
        dot3->setMaximumSize(QSize(16, 16));
        dot3->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 8px;"));

        horizontalLayout_3->addWidget(dot3);

        dot4 = new QLabel(dotFrame);
        dot4->setObjectName("dot4");
        dot4->setMinimumSize(QSize(16, 16));
        dot4->setMaximumSize(QSize(16, 16));
        dot4->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 8px;"));

        horizontalLayout_3->addWidget(dot4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_4->addWidget(dotFrame);


        verticalLayout_3->addWidget(carouselFrame, 0, Qt::AlignHCenter);

        actionButtonsFrame = new QFrame(contentFrame);
        actionButtonsFrame->setObjectName("actionButtonsFrame");
        actionButtonsFrame->setMinimumSize(QSize(0, 80));
        actionButtonsFrame->setMaximumSize(QSize(16777215, 80));
        actionButtonsFrame->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        actionButtonsFrame->setFrameShape(QFrame::StyledPanel);
        actionButtonsFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(actionButtonsFrame);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        startCalculateButton = new QPushButton(actionButtonsFrame);
        startCalculateButton->setObjectName("startCalculateButton");
        startCalculateButton->setMinimumSize(QSize(140, 40));
        startCalculateButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #27ae60;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2ecc71;\n"
"}"));

        horizontalLayout_4->addWidget(startCalculateButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        officialWebsiteButton = new QPushButton(actionButtonsFrame);
        officialWebsiteButton->setObjectName("officialWebsiteButton");
        officialWebsiteButton->setMinimumSize(QSize(140, 40));
        officialWebsiteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2980b9;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #3498db;\n"
"}"));

        horizontalLayout_4->addWidget(officialWebsiteButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_3->addWidget(actionButtonsFrame);


        verticalLayout_2->addWidget(contentFrame);

        stackedWidget->addWidget(homePage);
        calculatorPage = new QWidget();
        calculatorPage->setObjectName("calculatorPage");
        verticalLayout_5 = new QVBoxLayout(calculatorPage);
        verticalLayout_5->setObjectName("verticalLayout_5");
        calculatorPageLabel = new QLabel(calculatorPage);
        calculatorPageLabel->setObjectName("calculatorPageLabel");
        calculatorPageLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 24px;"));
        calculatorPageLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(calculatorPageLabel);

        stackedWidget->addWidget(calculatorPage);
        dataPage = new QWidget();
        dataPage->setObjectName("dataPage");
        verticalLayout_6 = new QVBoxLayout(dataPage);
        verticalLayout_6->setObjectName("verticalLayout_6");
        dataPageLabel = new QLabel(dataPage);
        dataPageLabel->setObjectName("dataPageLabel");
        dataPageLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 24px;"));
        dataPageLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(dataPageLabel);

        stackedWidget->addWidget(dataPage);
        settingsPage = new QWidget();
        settingsPage->setObjectName("settingsPage");
        verticalLayout_7 = new QVBoxLayout(settingsPage);
        verticalLayout_7->setObjectName("verticalLayout_7");
        settingsPageLabel = new QLabel(settingsPage);
        settingsPageLabel->setObjectName("settingsPageLabel");
        settingsPageLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 24px;"));
        settingsPageLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(settingsPageLabel);

        stackedWidget->addWidget(settingsPage);
        infoPage = new QWidget();
        infoPage->setObjectName("infoPage");
        verticalLayout_8 = new QVBoxLayout(infoPage);
        verticalLayout_8->setObjectName("verticalLayout_8");
        infoPageLabel = new QLabel(infoPage);
        infoPageLabel->setObjectName("infoPageLabel");
        infoPageLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 24px;"));
        infoPageLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(infoPageLabel);

        stackedWidget->addWidget(infoPage);

        horizontalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\242\263\350\266\263\350\277\271\350\256\241\347\256\227\345\231\250", nullptr));
        logoLabel->setText(QString());
        homeButton->setText(QString());
        calculatorButton->setText(QString());
        dataButton->setText(QString());
        settingsButton->setText(QString());
        infoButton->setText(QString());
        userButton->setText(QString());
        titleLabel->setText(QCoreApplication::translate("MainWindow", "\347\242\263\350\266\263\350\277\271\350\256\241\347\256\227\345\231\250", nullptr));
        carouselLabel->setText(QString());
        dot1->setText(QString());
        dot2->setText(QString());
        dot3->setText(QString());
        dot4->setText(QString());
        startCalculateButton->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\350\256\241\347\256\227", nullptr));
        officialWebsiteButton->setText(QCoreApplication::translate("MainWindow", "\347\275\221\351\241\265\347\211\210\350\256\241\347\256\227\345\231\250", nullptr));
        calculatorPageLabel->setText(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227\351\241\265\351\235\242 - \345\276\205\345\256\236\347\216\260", nullptr));
        dataPageLabel->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\351\241\265\351\235\242 - \345\276\205\345\256\236\347\216\260", nullptr));
        settingsPageLabel->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\351\241\265\351\235\242 - \345\276\205\345\256\236\347\216\260", nullptr));
        infoPageLabel->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216\351\241\265\351\235\242 - \345\276\205\345\256\236\347\216\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
