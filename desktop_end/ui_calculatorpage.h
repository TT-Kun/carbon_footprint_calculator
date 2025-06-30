/********************************************************************************
** Form generated from reading UI file 'calculatorpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATORPAGE_H
#define UI_CALCULATORPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalculatorPage
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_8;
    QFrame *summaryFrame;
    QHBoxLayout *horizontalLayout_10;
    QFrame *totalFrame;
    QVBoxLayout *verticalLayout_3;
    QLabel *totalLabel;
    QLabel *totalCarbonLabel;
    QFrame *perCapitaFrame;
    QVBoxLayout *verticalLayout_4;
    QLabel *perCapitaTextLabel;
    QLabel *perCapitaCarbonLabel;
    QFrame *rankFrame;
    QVBoxLayout *verticalLayout_5;
    QLabel *rankTextLabel;
    QLabel *carbonRankLabel;
    QHBoxLayout *buttonLayout;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *calculateButton;
    QPushButton *saveResultButton;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_6;
    QFrame *clothesFrame;
    QHBoxLayout *horizontalLayout_7;
    QLabel *disposableChopstickIconLabel;
    QLabel *disposableChopstickTextLabel;
    QSpacerItem *horizontalSpacer;
    QSlider *disposableChopstickSlider;
    QLineEdit *disposableChopstickValueEdit;
    QLabel *disposableChopstickUnitLabel;
    QFrame *homeEnergyFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *plasticBagIconLabel;
    QLabel *plasticBagTextLabel;
    QSpacerItem *horizontalSpacer_2;
    QSlider *plasticBagSlider;
    QLineEdit *plasticBagValueEdit;
    QLabel *plasticBagUnitLabel;
    QFrame *consumptionFrame;
    QHBoxLayout *horizontalLayout_8;
    QLabel *clothesIconLabel;
    QLabel *clothesTextLabel;
    QSpacerItem *horizontalSpacer_3;
    QSlider *clothesSlider;
    QLineEdit *consumptionValueEdit;
    QLabel *consumptionUnitLabel;
    QFrame *paperFrame;
    QHBoxLayout *horizontalLayout_6;
    QLabel *paperIconLabel;
    QLabel *paperTextLabel;
    QSpacerItem *horizontalSpacer_4;
    QSlider *paperSlider;
    QLineEdit *paperValueEdit;
    QLabel *paperUnitLabel;
    QLabel *separator2;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_7;
    QFrame *airplaneFrame;
    QHBoxLayout *horizontalLayout_3;
    QLabel *airplaneIconLabel;
    QLabel *airplaneTextLabel;
    QSlider *airplaneSlider;
    QLineEdit *airplaneValueEdit;
    QLabel *airplaneUnitLabel;
    QFrame *trainFrame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *trainIconLabel;
    QLabel *trainTextLabel;
    QSlider *trainSlider;
    QLineEdit *trainValueEdit;
    QLabel *trainUnitLabel;
    QFrame *busFrame;
    QHBoxLayout *horizontalLayout_9;
    QLabel *busIconLabel;
    QLabel *busTextLabel;
    QSlider *busSlider;
    QLineEdit *busValueEdit;
    QLabel *busUnitLabel;
    QFrame *carFrame;
    QHBoxLayout *horizontalLayout_13;
    QLabel *carIconLabel;
    QLabel *carTextLabel;
    QSlider *carSlider;
    QLineEdit *carValueEdit;
    QLabel *carUnitLabel;
    QLabel *separator1;
    QVBoxLayout *verticalLayout;
    QFrame *familyMemberFrame;
    QHBoxLayout *horizontalLayout_12;
    QLabel *familyMemberIconLabel;
    QLabel *familyMemberTextLabel;
    QSlider *familyMemberSlider;
    QLineEdit *familyMemberValueEdit;
    QLabel *familyMemberUnitLabel;
    QFrame *publicServiceFrame;
    QHBoxLayout *horizontalLayout_4;
    QLabel *livingAreaIconLabel;
    QLabel *livingAreaTextLabel;
    QSlider *livingAreaSlider;
    QLineEdit *livingAreaValueEdit;
    QLabel *livingAreaUnitLabel;
    QFrame *waterFrame;
    QHBoxLayout *horizontalLayout_5;
    QLabel *electricityIconLabel;
    QLabel *electricityTextLabel;
    QSlider *electricitySlider;
    QLineEdit *electricityValueEdit;
    QLabel *electricityUnitLabel;
    QLabel *titleLabel;

    void setupUi(QWidget *CalculatorPage)
    {
        if (CalculatorPage->objectName().isEmpty())
            CalculatorPage->setObjectName("CalculatorPage");
        CalculatorPage->resize(794, 697);
        CalculatorPage->setStyleSheet(QString::fromUtf8("background-color: #3c4b64;"));
        gridLayout = new QGridLayout(CalculatorPage);
        gridLayout->setObjectName("gridLayout");
        scrollArea = new QScrollArea(CalculatorPage);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"QScrollArea > QWidget > QWidget {\n"
"    background-color: transparent;\n"
"}\n"
"QScrollBar:vertical {\n"
"    background: #2c3e50;\n"
"    width: 10px;\n"
"    margin: 0px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background: #34495e;\n"
"    min-height: 20px;\n"
"    border-radius: 5px;\n"
"}\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}"));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 782, 57));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(10, 10, 10, 10);
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 5, 0, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");

        gridLayout->addLayout(verticalLayout_8, 0, 0, 1, 1);

        summaryFrame = new QFrame(CalculatorPage);
        summaryFrame->setObjectName("summaryFrame");
        summaryFrame->setMinimumSize(QSize(0, 80));
        summaryFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(52, 73, 94, 150);\n"
"border-radius: 10px;"));
        summaryFrame->setFrameShape(QFrame::StyledPanel);
        summaryFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_10 = new QHBoxLayout(summaryFrame);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        totalFrame = new QFrame(summaryFrame);
        totalFrame->setObjectName("totalFrame");
        totalFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(39, 174, 96, 100);\n"
"border-radius: 8px;"));
        totalFrame->setFrameShape(QFrame::StyledPanel);
        totalFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(totalFrame);
        verticalLayout_3->setObjectName("verticalLayout_3");
        totalLabel = new QLabel(totalFrame);
        totalLabel->setObjectName("totalLabel");
        totalLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"font-size: 12px;"));
        totalLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(totalLabel);

        totalCarbonLabel = new QLabel(totalFrame);
        totalCarbonLabel->setObjectName("totalCarbonLabel");
        totalCarbonLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"font-size: 16px;\n"
"font-weight: bold;"));
        totalCarbonLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(totalCarbonLabel);


        horizontalLayout_10->addWidget(totalFrame);

        perCapitaFrame = new QFrame(summaryFrame);
        perCapitaFrame->setObjectName("perCapitaFrame");
        perCapitaFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(41, 128, 185, 100);\n"
"border-radius: 8px;"));
        perCapitaFrame->setFrameShape(QFrame::StyledPanel);
        perCapitaFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(perCapitaFrame);
        verticalLayout_4->setObjectName("verticalLayout_4");
        perCapitaTextLabel = new QLabel(perCapitaFrame);
        perCapitaTextLabel->setObjectName("perCapitaTextLabel");
        perCapitaTextLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"font-size: 12px;"));
        perCapitaTextLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(perCapitaTextLabel);

        perCapitaCarbonLabel = new QLabel(perCapitaFrame);
        perCapitaCarbonLabel->setObjectName("perCapitaCarbonLabel");
        perCapitaCarbonLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"font-size: 16px;\n"
"font-weight: bold;"));
        perCapitaCarbonLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(perCapitaCarbonLabel);


        horizontalLayout_10->addWidget(perCapitaFrame);

        rankFrame = new QFrame(summaryFrame);
        rankFrame->setObjectName("rankFrame");
        rankFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(155, 89, 182, 100);\n"
"border-radius: 8px;"));
        rankFrame->setFrameShape(QFrame::StyledPanel);
        rankFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(rankFrame);
        verticalLayout_5->setObjectName("verticalLayout_5");
        rankTextLabel = new QLabel(rankFrame);
        rankTextLabel->setObjectName("rankTextLabel");
        rankTextLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"font-size: 12px;"));
        rankTextLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(rankTextLabel);

        carbonRankLabel = new QLabel(rankFrame);
        carbonRankLabel->setObjectName("carbonRankLabel");
        carbonRankLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"font-size: 16px;\n"
"font-weight: bold;"));
        carbonRankLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(carbonRankLabel);


        horizontalLayout_10->addWidget(rankFrame);


        gridLayout->addWidget(summaryFrame, 7, 0, 1, 1);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer_5);

        calculateButton = new QPushButton(CalculatorPage);
        calculateButton->setObjectName("calculateButton");
        calculateButton->setMinimumSize(QSize(200, 50));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        calculateButton->setFont(font);
        calculateButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #27ae60;\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2ecc71;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #219653;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/calculate.png"), QSize(), QIcon::Normal, QIcon::Off);
        calculateButton->setIcon(icon);
        calculateButton->setIconSize(QSize(24, 24));

        buttonLayout->addWidget(calculateButton);

        saveResultButton = new QPushButton(CalculatorPage);
        saveResultButton->setObjectName("saveResultButton");
        saveResultButton->setMinimumSize(QSize(200, 50));
        saveResultButton->setFont(font);
        saveResultButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2980b9;\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #3498db;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1a5276;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/electricity_bluegreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveResultButton->setIcon(icon1);
        saveResultButton->setIconSize(QSize(24, 24));

        buttonLayout->addWidget(saveResultButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer_6);


        gridLayout->addLayout(buttonLayout, 6, 0, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        clothesFrame = new QFrame(CalculatorPage);
        clothesFrame->setObjectName("clothesFrame");
        clothesFrame->setMinimumSize(QSize(0, 50));
        clothesFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(40, 40, 40, 180);"));
        clothesFrame->setFrameShape(QFrame::StyledPanel);
        clothesFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(clothesFrame);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        disposableChopstickIconLabel = new QLabel(clothesFrame);
        disposableChopstickIconLabel->setObjectName("disposableChopstickIconLabel");
        disposableChopstickIconLabel->setMinimumSize(QSize(40, 40));
        disposableChopstickIconLabel->setMaximumSize(QSize(40, 40));
        disposableChopstickIconLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(211, 84, 0, 150);\n"
"border-radius: 20px;\n"
"padding: 5px;"));
        disposableChopstickIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/resource/disposableChopstick.png")));
        disposableChopstickIconLabel->setScaledContents(true);

        horizontalLayout_7->addWidget(disposableChopstickIconLabel);

        disposableChopstickTextLabel = new QLabel(clothesFrame);
        disposableChopstickTextLabel->setObjectName("disposableChopstickTextLabel");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(disposableChopstickTextLabel->sizePolicy().hasHeightForWidth());
        disposableChopstickTextLabel->setSizePolicy(sizePolicy);
        disposableChopstickTextLabel->setMinimumSize(QSize(120, 0));
        disposableChopstickTextLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));

        horizontalLayout_7->addWidget(disposableChopstickTextLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        disposableChopstickSlider = new QSlider(clothesFrame);
        disposableChopstickSlider->setObjectName("disposableChopstickSlider");
        disposableChopstickSlider->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    margin: 6px 0;\n"
"	background:transparent\357\274\233\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #555555;          /* \350\275\250\351\201\223\350\276\271\346\241\206 */\n"
"    height: 5px;                        /* \350\275\250\351\201\223\351\253\230\345\272\246 */\n"
"    background: #222222;                /* \350\275\250\351\201\223\350\203\214\346\231\257\350\211\262 */\n"
"    margin: 2px 0;                      /* \344\270\212\344\270\213\350\276\271\350\267\235 */\n"
"    border-radius: 4px;                 /* \350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #ffffff;                /* \346\273\221\345\235\227\350\203\214\346\231\257\350\211\262-\347\231\275\350\211\262 */\n"
"    border: 1px solid #cccccc;          /* \346\273\221\345\235\227\350\276\271\346\241\206 */\n"
"    width: 10px;                        /* \346\273\221\345\235\227\345\256\275\345\272\246 */\n"
"    height: 10px;  "
                        "                     /* \346\273\221\345\235\227\351\253\230\345\272\246 */\n"
"    margin: -6px 0;                     /* \346\273\221\345\235\227\350\266\205\345\207\272\350\275\250\351\201\223\347\232\204\351\203\250\345\210\206 */\n"
"    border-radius: 5px;                 /* \346\273\221\345\235\227\345\234\206\350\247\222\357\274\210\345\215\212\345\276\204\344\270\272\345\256\275\345\272\246\347\232\204\344\270\200\345\215\212\357\274\214\345\256\236\347\216\260\345\234\206\345\275\242\357\274\211 */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: #222222;                /* \346\273\221\345\235\227\345\217\263\344\276\247\350\275\250\351\201\223\351\242\234\350\211\262 */\n"
"    border-radius: 4px;                 /* \345\217\263\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: rgb(222, 222, 222);                /* \346\273\221\345\235\227\345\267\246\344\276\247\350\275\250\351\201\223\351\242\234\350\211"
                        "\262 */\n"
"    border-radius: 4px;                 /* \345\267\246\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}"));
        disposableChopstickSlider->setMaximum(1000);
        disposableChopstickSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(disposableChopstickSlider);

        disposableChopstickValueEdit = new QLineEdit(clothesFrame);
        disposableChopstickValueEdit->setObjectName("disposableChopstickValueEdit");
        disposableChopstickValueEdit->setMinimumSize(QSize(60, 30));
        disposableChopstickValueEdit->setMaximumSize(QSize(60, 30));
        disposableChopstickValueEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(60, 60, 60, 200);\n"
"color: white;\n"
"font-size: 14px;\n"
"border: 1px solid rgba(80, 80, 80, 200);\n"
"border-radius: 4px;\n"
"padding: 2px 5px;"));
        disposableChopstickValueEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(disposableChopstickValueEdit);

        disposableChopstickUnitLabel = new QLabel(clothesFrame);
        disposableChopstickUnitLabel->setObjectName("disposableChopstickUnitLabel");
        disposableChopstickUnitLabel->setMinimumSize(QSize(60, 0));
        disposableChopstickUnitLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));
        disposableChopstickUnitLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(disposableChopstickUnitLabel);


        verticalLayout_6->addWidget(clothesFrame);

        homeEnergyFrame = new QFrame(CalculatorPage);
        homeEnergyFrame->setObjectName("homeEnergyFrame");
        homeEnergyFrame->setMinimumSize(QSize(0, 50));
        homeEnergyFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(40, 40, 40, 180);"));
        homeEnergyFrame->setFrameShape(QFrame::StyledPanel);
        homeEnergyFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(homeEnergyFrame);
        horizontalLayout->setObjectName("horizontalLayout");
        plasticBagIconLabel = new QLabel(homeEnergyFrame);
        plasticBagIconLabel->setObjectName("plasticBagIconLabel");
        plasticBagIconLabel->setMinimumSize(QSize(40, 40));
        plasticBagIconLabel->setMaximumSize(QSize(40, 40));
        plasticBagIconLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(44, 62, 80, 150);\n"
"border-radius: 20px;\n"
"padding: 5px;"));
        plasticBagIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/resource/plasticBag.png")));
        plasticBagIconLabel->setScaledContents(true);

        horizontalLayout->addWidget(plasticBagIconLabel);

        plasticBagTextLabel = new QLabel(homeEnergyFrame);
        plasticBagTextLabel->setObjectName("plasticBagTextLabel");
        sizePolicy.setHeightForWidth(plasticBagTextLabel->sizePolicy().hasHeightForWidth());
        plasticBagTextLabel->setSizePolicy(sizePolicy);
        plasticBagTextLabel->setMinimumSize(QSize(120, 0));
        plasticBagTextLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));

        horizontalLayout->addWidget(plasticBagTextLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        plasticBagSlider = new QSlider(homeEnergyFrame);
        plasticBagSlider->setObjectName("plasticBagSlider");
        plasticBagSlider->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    margin: 6px 0;\n"
"	background:transparent\357\274\233\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #555555;          /* \350\275\250\351\201\223\350\276\271\346\241\206 */\n"
"    height: 5px;                        /* \350\275\250\351\201\223\351\253\230\345\272\246 */\n"
"    background: #222222;                /* \350\275\250\351\201\223\350\203\214\346\231\257\350\211\262 */\n"
"    margin: 2px 0;                      /* \344\270\212\344\270\213\350\276\271\350\267\235 */\n"
"    border-radius: 4px;                 /* \350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #ffffff;                /* \346\273\221\345\235\227\350\203\214\346\231\257\350\211\262-\347\231\275\350\211\262 */\n"
"    border: 1px solid #cccccc;          /* \346\273\221\345\235\227\350\276\271\346\241\206 */\n"
"    width: 10px;                        /* \346\273\221\345\235\227\345\256\275\345\272\246 */\n"
"    height: 10px;  "
                        "                     /* \346\273\221\345\235\227\351\253\230\345\272\246 */\n"
"    margin: -6px 0;                     /* \346\273\221\345\235\227\350\266\205\345\207\272\350\275\250\351\201\223\347\232\204\351\203\250\345\210\206 */\n"
"    border-radius: 5px;                 /* \346\273\221\345\235\227\345\234\206\350\247\222\357\274\210\345\215\212\345\276\204\344\270\272\345\256\275\345\272\246\347\232\204\344\270\200\345\215\212\357\274\214\345\256\236\347\216\260\345\234\206\345\275\242\357\274\211 */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: #222222;                /* \346\273\221\345\235\227\345\217\263\344\276\247\350\275\250\351\201\223\351\242\234\350\211\262 */\n"
"    border-radius: 4px;                 /* \345\217\263\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: rgb(222, 222, 222);                /* \346\273\221\345\235\227\345\267\246\344\276\247\350\275\250\351\201\223\351\242\234\350\211"
                        "\262 */\n"
"    border-radius: 4px;                 /* \345\267\246\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}"));
        plasticBagSlider->setMaximum(1000);
        plasticBagSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(plasticBagSlider);

        plasticBagValueEdit = new QLineEdit(homeEnergyFrame);
        plasticBagValueEdit->setObjectName("plasticBagValueEdit");
        plasticBagValueEdit->setMinimumSize(QSize(60, 30));
        plasticBagValueEdit->setMaximumSize(QSize(60, 30));
        plasticBagValueEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(60, 60, 60, 200);\n"
"color: white;\n"
"font-size: 14px;\n"
"border: 1px solid rgba(80, 80, 80, 200);\n"
"border-radius: 4px;\n"
"padding: 2px 5px;"));
        plasticBagValueEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(plasticBagValueEdit);

        plasticBagUnitLabel = new QLabel(homeEnergyFrame);
        plasticBagUnitLabel->setObjectName("plasticBagUnitLabel");
        plasticBagUnitLabel->setMinimumSize(QSize(60, 0));
        plasticBagUnitLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));
        plasticBagUnitLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(plasticBagUnitLabel);


        verticalLayout_6->addWidget(homeEnergyFrame);

        consumptionFrame = new QFrame(CalculatorPage);
        consumptionFrame->setObjectName("consumptionFrame");
        consumptionFrame->setMinimumSize(QSize(0, 50));
        consumptionFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(40, 40, 40, 180);"));
        consumptionFrame->setFrameShape(QFrame::StyledPanel);
        consumptionFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(consumptionFrame);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        clothesIconLabel = new QLabel(consumptionFrame);
        clothesIconLabel->setObjectName("clothesIconLabel");
        clothesIconLabel->setMinimumSize(QSize(40, 40));
        clothesIconLabel->setMaximumSize(QSize(40, 40));
        clothesIconLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(142, 68, 173, 150);\n"
"border-radius: 20px;\n"
"padding: 5px;"));
        clothesIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/resource/clothes.png")));
        clothesIconLabel->setScaledContents(true);

        horizontalLayout_8->addWidget(clothesIconLabel);

        clothesTextLabel = new QLabel(consumptionFrame);
        clothesTextLabel->setObjectName("clothesTextLabel");
        sizePolicy.setHeightForWidth(clothesTextLabel->sizePolicy().hasHeightForWidth());
        clothesTextLabel->setSizePolicy(sizePolicy);
        clothesTextLabel->setMinimumSize(QSize(120, 0));
        clothesTextLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));

        horizontalLayout_8->addWidget(clothesTextLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        clothesSlider = new QSlider(consumptionFrame);
        clothesSlider->setObjectName("clothesSlider");
        clothesSlider->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    margin: 6px 0;\n"
"	background:transparent\357\274\233\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #555555;          /* \350\275\250\351\201\223\350\276\271\346\241\206 */\n"
"    height: 5px;                        /* \350\275\250\351\201\223\351\253\230\345\272\246 */\n"
"    background: #222222;                /* \350\275\250\351\201\223\350\203\214\346\231\257\350\211\262 */\n"
"    margin: 2px 0;                      /* \344\270\212\344\270\213\350\276\271\350\267\235 */\n"
"    border-radius: 4px;                 /* \350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #ffffff;                /* \346\273\221\345\235\227\350\203\214\346\231\257\350\211\262-\347\231\275\350\211\262 */\n"
"    border: 1px solid #cccccc;          /* \346\273\221\345\235\227\350\276\271\346\241\206 */\n"
"    width: 10px;                        /* \346\273\221\345\235\227\345\256\275\345\272\246 */\n"
"    height: 10px;  "
                        "                     /* \346\273\221\345\235\227\351\253\230\345\272\246 */\n"
"    margin: -6px 0;                     /* \346\273\221\345\235\227\350\266\205\345\207\272\350\275\250\351\201\223\347\232\204\351\203\250\345\210\206 */\n"
"    border-radius: 5px;                 /* \346\273\221\345\235\227\345\234\206\350\247\222\357\274\210\345\215\212\345\276\204\344\270\272\345\256\275\345\272\246\347\232\204\344\270\200\345\215\212\357\274\214\345\256\236\347\216\260\345\234\206\345\275\242\357\274\211 */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: #222222;                /* \346\273\221\345\235\227\345\217\263\344\276\247\350\275\250\351\201\223\351\242\234\350\211\262 */\n"
"    border-radius: 4px;                 /* \345\217\263\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: rgb(222, 222, 222);                /* \346\273\221\345\235\227\345\267\246\344\276\247\350\275\250\351\201\223\351\242\234\350\211"
                        "\262 */\n"
"    border-radius: 4px;                 /* \345\267\246\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}"));
        clothesSlider->setMaximum(1000);
        clothesSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(clothesSlider);

        consumptionValueEdit = new QLineEdit(consumptionFrame);
        consumptionValueEdit->setObjectName("consumptionValueEdit");
        consumptionValueEdit->setMinimumSize(QSize(60, 30));
        consumptionValueEdit->setMaximumSize(QSize(60, 30));
        consumptionValueEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(60, 60, 60, 200);\n"
"color: white;\n"
"font-size: 14px;\n"
"border: 1px solid rgba(80, 80, 80, 200);\n"
"border-radius: 4px;\n"
"padding: 2px 5px;"));
        consumptionValueEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(consumptionValueEdit);

        consumptionUnitLabel = new QLabel(consumptionFrame);
        consumptionUnitLabel->setObjectName("consumptionUnitLabel");
        consumptionUnitLabel->setMinimumSize(QSize(60, 0));
        consumptionUnitLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));
        consumptionUnitLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(consumptionUnitLabel);


        verticalLayout_6->addWidget(consumptionFrame);

        paperFrame = new QFrame(CalculatorPage);
        paperFrame->setObjectName("paperFrame");
        paperFrame->setMinimumSize(QSize(0, 50));
        paperFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(40, 40, 40, 180);"));
        paperFrame->setFrameShape(QFrame::StyledPanel);
        paperFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(paperFrame);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        paperIconLabel = new QLabel(paperFrame);
        paperIconLabel->setObjectName("paperIconLabel");
        paperIconLabel->setMinimumSize(QSize(40, 40));
        paperIconLabel->setMaximumSize(QSize(40, 40));
        paperIconLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(22, 160, 133, 150);\n"
"border-radius: 20px;\n"
"padding: 5px;"));
        paperIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/resource/paper.png")));
        paperIconLabel->setScaledContents(true);

        horizontalLayout_6->addWidget(paperIconLabel);

        paperTextLabel = new QLabel(paperFrame);
        paperTextLabel->setObjectName("paperTextLabel");
        sizePolicy.setHeightForWidth(paperTextLabel->sizePolicy().hasHeightForWidth());
        paperTextLabel->setSizePolicy(sizePolicy);
        paperTextLabel->setMinimumSize(QSize(120, 0));
        paperTextLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));

        horizontalLayout_6->addWidget(paperTextLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        paperSlider = new QSlider(paperFrame);
        paperSlider->setObjectName("paperSlider");
        paperSlider->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    margin: 6px 0;\n"
"	background:transparent\357\274\233\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #555555;          /* \350\275\250\351\201\223\350\276\271\346\241\206 */\n"
"    height: 5px;                        /* \350\275\250\351\201\223\351\253\230\345\272\246 */\n"
"    background: #222222;                /* \350\275\250\351\201\223\350\203\214\346\231\257\350\211\262 */\n"
"    margin: 2px 0;                      /* \344\270\212\344\270\213\350\276\271\350\267\235 */\n"
"    border-radius: 4px;                 /* \350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #ffffff;                /* \346\273\221\345\235\227\350\203\214\346\231\257\350\211\262-\347\231\275\350\211\262 */\n"
"    border: 1px solid #cccccc;          /* \346\273\221\345\235\227\350\276\271\346\241\206 */\n"
"    width: 10px;                        /* \346\273\221\345\235\227\345\256\275\345\272\246 */\n"
"    height: 10px;  "
                        "                     /* \346\273\221\345\235\227\351\253\230\345\272\246 */\n"
"    margin: -6px 0;                     /* \346\273\221\345\235\227\350\266\205\345\207\272\350\275\250\351\201\223\347\232\204\351\203\250\345\210\206 */\n"
"    border-radius: 5px;                 /* \346\273\221\345\235\227\345\234\206\350\247\222\357\274\210\345\215\212\345\276\204\344\270\272\345\256\275\345\272\246\347\232\204\344\270\200\345\215\212\357\274\214\345\256\236\347\216\260\345\234\206\345\275\242\357\274\211 */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: #222222;                /* \346\273\221\345\235\227\345\217\263\344\276\247\350\275\250\351\201\223\351\242\234\350\211\262 */\n"
"    border-radius: 4px;                 /* \345\217\263\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: rgb(222, 222, 222);                /* \346\273\221\345\235\227\345\267\246\344\276\247\350\275\250\351\201\223\351\242\234\350\211"
                        "\262 */\n"
"    border-radius: 4px;                 /* \345\267\246\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}"));
        paperSlider->setMaximum(1000);
        paperSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(paperSlider);

        paperValueEdit = new QLineEdit(paperFrame);
        paperValueEdit->setObjectName("paperValueEdit");
        paperValueEdit->setMinimumSize(QSize(60, 30));
        paperValueEdit->setMaximumSize(QSize(60, 30));
        paperValueEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(60, 60, 60, 200);\n"
"color: white;\n"
"font-size: 14px;\n"
"border: 1px solid rgba(80, 80, 80, 200);\n"
"border-radius: 4px;\n"
"padding: 2px 5px;"));
        paperValueEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(paperValueEdit);

        paperUnitLabel = new QLabel(paperFrame);
        paperUnitLabel->setObjectName("paperUnitLabel");
        paperUnitLabel->setMinimumSize(QSize(60, 0));
        paperUnitLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));
        paperUnitLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(paperUnitLabel);


        verticalLayout_6->addWidget(paperFrame);


        gridLayout->addLayout(verticalLayout_6, 4, 0, 1, 1);

        separator2 = new QLabel(CalculatorPage);
        separator2->setObjectName("separator2");
        separator2->setMaximumSize(QSize(16777215, 2));
        separator2->setStyleSheet(QString::fromUtf8("background-color:rgb(236, 236, 236);\n"
"border-radius: 1px;"));

        gridLayout->addWidget(separator2, 3, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(-1, -1, -1, 10);
        airplaneFrame = new QFrame(CalculatorPage);
        airplaneFrame->setObjectName("airplaneFrame");
        airplaneFrame->setMinimumSize(QSize(0, 50));
        airplaneFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(40, 40, 40, 180);"));
        airplaneFrame->setFrameShape(QFrame::StyledPanel);
        airplaneFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(airplaneFrame);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(10, 5, 10, 5);
        airplaneIconLabel = new QLabel(airplaneFrame);
        airplaneIconLabel->setObjectName("airplaneIconLabel");
        airplaneIconLabel->setMinimumSize(QSize(40, 40));
        airplaneIconLabel->setMaximumSize(QSize(40, 40));
        airplaneIconLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(41, 128, 185, 150);\n"
"border-radius: 20px;\n"
"padding: 5px;"));
        airplaneIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/resource/airplane.png")));
        airplaneIconLabel->setScaledContents(true);

        horizontalLayout_3->addWidget(airplaneIconLabel);

        airplaneTextLabel = new QLabel(airplaneFrame);
        airplaneTextLabel->setObjectName("airplaneTextLabel");
        sizePolicy.setHeightForWidth(airplaneTextLabel->sizePolicy().hasHeightForWidth());
        airplaneTextLabel->setSizePolicy(sizePolicy);
        airplaneTextLabel->setMinimumSize(QSize(80, 0));
        airplaneTextLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));

        horizontalLayout_3->addWidget(airplaneTextLabel);

        airplaneSlider = new QSlider(airplaneFrame);
        airplaneSlider->setObjectName("airplaneSlider");
        airplaneSlider->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    margin: 6px 0;\n"
"	background:transparent\357\274\233\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #555555;          /* \350\275\250\351\201\223\350\276\271\346\241\206 */\n"
"    height: 5px;                        /* \350\275\250\351\201\223\351\253\230\345\272\246 */\n"
"    background: #222222;                /* \350\275\250\351\201\223\350\203\214\346\231\257\350\211\262 */\n"
"    margin: 2px 0;                      /* \344\270\212\344\270\213\350\276\271\350\267\235 */\n"
"    border-radius: 4px;                 /* \350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #ffffff;                /* \346\273\221\345\235\227\350\203\214\346\231\257\350\211\262-\347\231\275\350\211\262 */\n"
"    border: 1px solid #cccccc;          /* \346\273\221\345\235\227\350\276\271\346\241\206 */\n"
"    width: 10px;                        /* \346\273\221\345\235\227\345\256\275\345\272\246 */\n"
"    height: 10px;  "
                        "                     /* \346\273\221\345\235\227\351\253\230\345\272\246 */\n"
"    margin: -6px 0;                     /* \346\273\221\345\235\227\350\266\205\345\207\272\350\275\250\351\201\223\347\232\204\351\203\250\345\210\206 */\n"
"    border-radius: 5px;                 /* \346\273\221\345\235\227\345\234\206\350\247\222\357\274\210\345\215\212\345\276\204\344\270\272\345\256\275\345\272\246\347\232\204\344\270\200\345\215\212\357\274\214\345\256\236\347\216\260\345\234\206\345\275\242\357\274\211 */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: #222222;                /* \346\273\221\345\235\227\345\217\263\344\276\247\350\275\250\351\201\223\351\242\234\350\211\262 */\n"
"    border-radius: 4px;                 /* \345\217\263\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: rgb(222, 222, 222);                /* \346\273\221\345\235\227\345\267\246\344\276\247\350\275\250\351\201\223\351\242\234\350\211"
                        "\262 */\n"
"    border-radius: 4px;                 /* \345\267\246\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}"));
        airplaneSlider->setMaximum(1000);
        airplaneSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(airplaneSlider);

        airplaneValueEdit = new QLineEdit(airplaneFrame);
        airplaneValueEdit->setObjectName("airplaneValueEdit");
        airplaneValueEdit->setMinimumSize(QSize(60, 30));
        airplaneValueEdit->setMaximumSize(QSize(60, 30));
        airplaneValueEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(60, 60, 60, 200);\n"
"color: white;\n"
"font-size: 14px;\n"
"border: 1px solid rgba(80, 80, 80, 200);\n"
"border-radius: 4px;\n"
"padding: 2px 5px;"));
        airplaneValueEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(airplaneValueEdit);

        airplaneUnitLabel = new QLabel(airplaneFrame);
        airplaneUnitLabel->setObjectName("airplaneUnitLabel");
        airplaneUnitLabel->setMinimumSize(QSize(60, 0));
        airplaneUnitLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));
        airplaneUnitLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(airplaneUnitLabel);


        verticalLayout_7->addWidget(airplaneFrame);

        trainFrame = new QFrame(CalculatorPage);
        trainFrame->setObjectName("trainFrame");
        trainFrame->setMinimumSize(QSize(0, 50));
        trainFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(40, 40, 40, 180);"));
        trainFrame->setFrameShape(QFrame::StyledPanel);
        trainFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(trainFrame);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(10, 5, 10, 5);
        trainIconLabel = new QLabel(trainFrame);
        trainIconLabel->setObjectName("trainIconLabel");
        trainIconLabel->setMinimumSize(QSize(40, 40));
        trainIconLabel->setMaximumSize(QSize(40, 40));
        trainIconLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(52, 152, 219, 150);\n"
"border-radius: 20px;\n"
"padding: 5px;"));
        trainIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/resource/train.png")));
        trainIconLabel->setScaledContents(true);

        horizontalLayout_2->addWidget(trainIconLabel);

        trainTextLabel = new QLabel(trainFrame);
        trainTextLabel->setObjectName("trainTextLabel");
        sizePolicy.setHeightForWidth(trainTextLabel->sizePolicy().hasHeightForWidth());
        trainTextLabel->setSizePolicy(sizePolicy);
        trainTextLabel->setMinimumSize(QSize(80, 0));
        trainTextLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));

        horizontalLayout_2->addWidget(trainTextLabel);

        trainSlider = new QSlider(trainFrame);
        trainSlider->setObjectName("trainSlider");
        trainSlider->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    margin: 6px 0;\n"
"	background:transparent\357\274\233\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #555555;          /* \350\275\250\351\201\223\350\276\271\346\241\206 */\n"
"    height: 5px;                        /* \350\275\250\351\201\223\351\253\230\345\272\246 */\n"
"    background: #222222;                /* \350\275\250\351\201\223\350\203\214\346\231\257\350\211\262 */\n"
"    margin: 2px 0;                      /* \344\270\212\344\270\213\350\276\271\350\267\235 */\n"
"    border-radius: 4px;                 /* \350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #ffffff;                /* \346\273\221\345\235\227\350\203\214\346\231\257\350\211\262-\347\231\275\350\211\262 */\n"
"    border: 1px solid #cccccc;          /* \346\273\221\345\235\227\350\276\271\346\241\206 */\n"
"    width: 10px;                        /* \346\273\221\345\235\227\345\256\275\345\272\246 */\n"
"    height: 10px;  "
                        "                     /* \346\273\221\345\235\227\351\253\230\345\272\246 */\n"
"    margin: -6px 0;                     /* \346\273\221\345\235\227\350\266\205\345\207\272\350\275\250\351\201\223\347\232\204\351\203\250\345\210\206 */\n"
"    border-radius: 5px;                 /* \346\273\221\345\235\227\345\234\206\350\247\222\357\274\210\345\215\212\345\276\204\344\270\272\345\256\275\345\272\246\347\232\204\344\270\200\345\215\212\357\274\214\345\256\236\347\216\260\345\234\206\345\275\242\357\274\211 */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: #222222;                /* \346\273\221\345\235\227\345\217\263\344\276\247\350\275\250\351\201\223\351\242\234\350\211\262 */\n"
"    border-radius: 4px;                 /* \345\217\263\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: rgb(222, 222, 222);                /* \346\273\221\345\235\227\345\267\246\344\276\247\350\275\250\351\201\223\351\242\234\350\211"
                        "\262 */\n"
"    border-radius: 4px;                 /* \345\267\246\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}"));
        trainSlider->setMaximum(1000);
        trainSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(trainSlider);

        trainValueEdit = new QLineEdit(trainFrame);
        trainValueEdit->setObjectName("trainValueEdit");
        trainValueEdit->setMinimumSize(QSize(60, 30));
        trainValueEdit->setMaximumSize(QSize(60, 30));
        trainValueEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(60, 60, 60, 200);\n"
"color: white;\n"
"font-size: 14px;\n"
"border: 1px solid rgba(80, 80, 80, 200);\n"
"border-radius: 4px;\n"
"padding: 2px 5px;"));
        trainValueEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(trainValueEdit);

        trainUnitLabel = new QLabel(trainFrame);
        trainUnitLabel->setObjectName("trainUnitLabel");
        trainUnitLabel->setMinimumSize(QSize(60, 0));
        trainUnitLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));
        trainUnitLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(trainUnitLabel);


        verticalLayout_7->addWidget(trainFrame);

        busFrame = new QFrame(CalculatorPage);
        busFrame->setObjectName("busFrame");
        busFrame->setMinimumSize(QSize(0, 50));
        busFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(40, 40, 40, 180);"));
        busFrame->setFrameShape(QFrame::StyledPanel);
        busFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_9 = new QHBoxLayout(busFrame);
        horizontalLayout_9->setSpacing(10);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(10, 5, 10, 5);
        busIconLabel = new QLabel(busFrame);
        busIconLabel->setObjectName("busIconLabel");
        busIconLabel->setMinimumSize(QSize(40, 40));
        busIconLabel->setMaximumSize(QSize(40, 40));
        busIconLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(46, 204, 113, 150);\n"
"border-radius: 20px;\n"
"padding: 5px;"));
        busIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/resource/bus.png")));
        busIconLabel->setScaledContents(true);

        horizontalLayout_9->addWidget(busIconLabel);

        busTextLabel = new QLabel(busFrame);
        busTextLabel->setObjectName("busTextLabel");
        sizePolicy.setHeightForWidth(busTextLabel->sizePolicy().hasHeightForWidth());
        busTextLabel->setSizePolicy(sizePolicy);
        busTextLabel->setMinimumSize(QSize(80, 0));
        busTextLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));

        horizontalLayout_9->addWidget(busTextLabel);

        busSlider = new QSlider(busFrame);
        busSlider->setObjectName("busSlider");
        busSlider->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    margin: 6px 0;\n"
"	background:transparent\357\274\233\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #555555;          /* \350\275\250\351\201\223\350\276\271\346\241\206 */\n"
"    height: 5px;                        /* \350\275\250\351\201\223\351\253\230\345\272\246 */\n"
"    background: #222222;                /* \350\275\250\351\201\223\350\203\214\346\231\257\350\211\262 */\n"
"    margin: 2px 0;                      /* \344\270\212\344\270\213\350\276\271\350\267\235 */\n"
"    border-radius: 4px;                 /* \350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #ffffff;                /* \346\273\221\345\235\227\350\203\214\346\231\257\350\211\262-\347\231\275\350\211\262 */\n"
"    border: 1px solid #cccccc;          /* \346\273\221\345\235\227\350\276\271\346\241\206 */\n"
"    width: 10px;                        /* \346\273\221\345\235\227\345\256\275\345\272\246 */\n"
"    height: 10px;  "
                        "                     /* \346\273\221\345\235\227\351\253\230\345\272\246 */\n"
"    margin: -6px 0;                     /* \346\273\221\345\235\227\350\266\205\345\207\272\350\275\250\351\201\223\347\232\204\351\203\250\345\210\206 */\n"
"    border-radius: 5px;                 /* \346\273\221\345\235\227\345\234\206\350\247\222\357\274\210\345\215\212\345\276\204\344\270\272\345\256\275\345\272\246\347\232\204\344\270\200\345\215\212\357\274\214\345\256\236\347\216\260\345\234\206\345\275\242\357\274\211 */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: #222222;                /* \346\273\221\345\235\227\345\217\263\344\276\247\350\275\250\351\201\223\351\242\234\350\211\262 */\n"
"    border-radius: 4px;                 /* \345\217\263\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: rgb(222, 222, 222);                /* \346\273\221\345\235\227\345\267\246\344\276\247\350\275\250\351\201\223\351\242\234\350\211"
                        "\262 */\n"
"    border-radius: 4px;                 /* \345\267\246\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}"));
        busSlider->setMaximum(1000);
        busSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(busSlider);

        busValueEdit = new QLineEdit(busFrame);
        busValueEdit->setObjectName("busValueEdit");
        busValueEdit->setMinimumSize(QSize(60, 30));
        busValueEdit->setMaximumSize(QSize(60, 30));
        busValueEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(60, 60, 60, 200);\n"
"color: white;\n"
"font-size: 14px;\n"
"border: 1px solid rgba(80, 80, 80, 200);\n"
"border-radius: 4px;\n"
"padding: 2px 5px;"));
        busValueEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(busValueEdit);

        busUnitLabel = new QLabel(busFrame);
        busUnitLabel->setObjectName("busUnitLabel");
        busUnitLabel->setMinimumSize(QSize(60, 0));
        busUnitLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));
        busUnitLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(busUnitLabel);


        verticalLayout_7->addWidget(busFrame);

        carFrame = new QFrame(CalculatorPage);
        carFrame->setObjectName("carFrame");
        carFrame->setMinimumSize(QSize(0, 50));
        carFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(40, 40, 40, 180);"));
        carFrame->setFrameShape(QFrame::StyledPanel);
        carFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_13 = new QHBoxLayout(carFrame);
        horizontalLayout_13->setSpacing(10);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_13->setContentsMargins(10, 5, 10, 5);
        carIconLabel = new QLabel(carFrame);
        carIconLabel->setObjectName("carIconLabel");
        carIconLabel->setMinimumSize(QSize(40, 40));
        carIconLabel->setMaximumSize(QSize(40, 40));
        carIconLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(230, 126, 34, 150);\n"
"border-radius: 20px;\n"
"padding: 5px;"));
        carIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/resource/car.png")));
        carIconLabel->setScaledContents(true);

        horizontalLayout_13->addWidget(carIconLabel);

        carTextLabel = new QLabel(carFrame);
        carTextLabel->setObjectName("carTextLabel");
        sizePolicy.setHeightForWidth(carTextLabel->sizePolicy().hasHeightForWidth());
        carTextLabel->setSizePolicy(sizePolicy);
        carTextLabel->setMinimumSize(QSize(80, 0));
        carTextLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));

        horizontalLayout_13->addWidget(carTextLabel);

        carSlider = new QSlider(carFrame);
        carSlider->setObjectName("carSlider");
        carSlider->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    margin: 6px 0;\n"
"	background:transparent\357\274\233\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #555555;          /* \350\275\250\351\201\223\350\276\271\346\241\206 */\n"
"    height: 5px;                        /* \350\275\250\351\201\223\351\253\230\345\272\246 */\n"
"    background: #222222;                /* \350\275\250\351\201\223\350\203\214\346\231\257\350\211\262 */\n"
"    margin: 2px 0;                      /* \344\270\212\344\270\213\350\276\271\350\267\235 */\n"
"    border-radius: 4px;                 /* \350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #ffffff;                /* \346\273\221\345\235\227\350\203\214\346\231\257\350\211\262-\347\231\275\350\211\262 */\n"
"    border: 1px solid #cccccc;          /* \346\273\221\345\235\227\350\276\271\346\241\206 */\n"
"    width: 10px;                        /* \346\273\221\345\235\227\345\256\275\345\272\246 */\n"
"    height: 10px;  "
                        "                     /* \346\273\221\345\235\227\351\253\230\345\272\246 */\n"
"    margin: -6px 0;                     /* \346\273\221\345\235\227\350\266\205\345\207\272\350\275\250\351\201\223\347\232\204\351\203\250\345\210\206 */\n"
"    border-radius: 5px;                 /* \346\273\221\345\235\227\345\234\206\350\247\222\357\274\210\345\215\212\345\276\204\344\270\272\345\256\275\345\272\246\347\232\204\344\270\200\345\215\212\357\274\214\345\256\236\347\216\260\345\234\206\345\275\242\357\274\211 */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: #222222;                /* \346\273\221\345\235\227\345\217\263\344\276\247\350\275\250\351\201\223\351\242\234\350\211\262 */\n"
"    border-radius: 4px;                 /* \345\217\263\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: rgb(222, 222, 222);                /* \346\273\221\345\235\227\345\267\246\344\276\247\350\275\250\351\201\223\351\242\234\350\211"
                        "\262 */\n"
"    border-radius: 4px;                 /* \345\267\246\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}"));
        carSlider->setMaximum(1000);
        carSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_13->addWidget(carSlider);

        carValueEdit = new QLineEdit(carFrame);
        carValueEdit->setObjectName("carValueEdit");
        carValueEdit->setMinimumSize(QSize(60, 30));
        carValueEdit->setMaximumSize(QSize(60, 30));
        carValueEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(60, 60, 60, 200);\n"
"color: white;\n"
"font-size: 14px;\n"
"border: 1px solid rgba(80, 80, 80, 200);\n"
"border-radius: 4px;\n"
"padding: 2px 5px;"));
        carValueEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_13->addWidget(carValueEdit);

        carUnitLabel = new QLabel(carFrame);
        carUnitLabel->setObjectName("carUnitLabel");
        carUnitLabel->setMinimumSize(QSize(60, 0));
        carUnitLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));
        carUnitLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_13->addWidget(carUnitLabel);


        verticalLayout_7->addWidget(carFrame);


        horizontalLayout_11->addLayout(verticalLayout_7);

        separator1 = new QLabel(CalculatorPage);
        separator1->setObjectName("separator1");
        separator1->setMaximumSize(QSize(2, 16777215));
        separator1->setStyleSheet(QString::fromUtf8("background-color:rgb(236, 236, 236);\n"
"border-radius: 1px;"));

        horizontalLayout_11->addWidget(separator1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        familyMemberFrame = new QFrame(CalculatorPage);
        familyMemberFrame->setObjectName("familyMemberFrame");
        familyMemberFrame->setMinimumSize(QSize(0, 50));
        familyMemberFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(40, 40, 40, 180);"));
        familyMemberFrame->setFrameShape(QFrame::StyledPanel);
        familyMemberFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_12 = new QHBoxLayout(familyMemberFrame);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        familyMemberIconLabel = new QLabel(familyMemberFrame);
        familyMemberIconLabel->setObjectName("familyMemberIconLabel");
        familyMemberIconLabel->setMinimumSize(QSize(40, 40));
        familyMemberIconLabel->setMaximumSize(QSize(40, 40));
        familyMemberIconLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(155, 89, 182, 150);\n"
"border-radius: 20px;\n"
"padding: 5px;"));
        familyMemberIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/resource/famliyMember.png")));
        familyMemberIconLabel->setScaledContents(true);

        horizontalLayout_12->addWidget(familyMemberIconLabel);

        familyMemberTextLabel = new QLabel(familyMemberFrame);
        familyMemberTextLabel->setObjectName("familyMemberTextLabel");
        sizePolicy.setHeightForWidth(familyMemberTextLabel->sizePolicy().hasHeightForWidth());
        familyMemberTextLabel->setSizePolicy(sizePolicy);
        familyMemberTextLabel->setMinimumSize(QSize(120, 0));
        familyMemberTextLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));

        horizontalLayout_12->addWidget(familyMemberTextLabel);

        familyMemberSlider = new QSlider(familyMemberFrame);
        familyMemberSlider->setObjectName("familyMemberSlider");
        familyMemberSlider->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    margin: 6px 0;\n"
"	background:transparent\357\274\233\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #555555;          /* \350\275\250\351\201\223\350\276\271\346\241\206 */\n"
"    height: 5px;                        /* \350\275\250\351\201\223\351\253\230\345\272\246 */\n"
"    background: #222222;                /* \350\275\250\351\201\223\350\203\214\346\231\257\350\211\262 */\n"
"    margin: 2px 0;                      /* \344\270\212\344\270\213\350\276\271\350\267\235 */\n"
"    border-radius: 4px;                 /* \350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #ffffff;                /* \346\273\221\345\235\227\350\203\214\346\231\257\350\211\262-\347\231\275\350\211\262 */\n"
"    border: 1px solid #cccccc;          /* \346\273\221\345\235\227\350\276\271\346\241\206 */\n"
"    width: 10px;                        /* \346\273\221\345\235\227\345\256\275\345\272\246 */\n"
"    height: 10px;  "
                        "                     /* \346\273\221\345\235\227\351\253\230\345\272\246 */\n"
"    margin: -6px 0;                     /* \346\273\221\345\235\227\350\266\205\345\207\272\350\275\250\351\201\223\347\232\204\351\203\250\345\210\206 */\n"
"    border-radius: 5px;                 /* \346\273\221\345\235\227\345\234\206\350\247\222\357\274\210\345\215\212\345\276\204\344\270\272\345\256\275\345\272\246\347\232\204\344\270\200\345\215\212\357\274\214\345\256\236\347\216\260\345\234\206\345\275\242\357\274\211 */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: #222222;                /* \346\273\221\345\235\227\345\217\263\344\276\247\350\275\250\351\201\223\351\242\234\350\211\262 */\n"
"    border-radius: 4px;                 /* \345\217\263\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: rgb(222, 222, 222);                /* \346\273\221\345\235\227\345\267\246\344\276\247\350\275\250\351\201\223\351\242\234\350\211"
                        "\262 */\n"
"    border-radius: 4px;                 /* \345\267\246\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}"));
        familyMemberSlider->setMaximum(1000);
        familyMemberSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_12->addWidget(familyMemberSlider);

        familyMemberValueEdit = new QLineEdit(familyMemberFrame);
        familyMemberValueEdit->setObjectName("familyMemberValueEdit");
        familyMemberValueEdit->setMinimumSize(QSize(60, 30));
        familyMemberValueEdit->setMaximumSize(QSize(60, 30));
        familyMemberValueEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(60, 60, 60, 200);\n"
"color: white;\n"
"font-size: 14px;\n"
"border: 1px solid rgba(80, 80, 80, 200);\n"
"border-radius: 4px;\n"
"padding: 2px 5px;"));
        familyMemberValueEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_12->addWidget(familyMemberValueEdit);

        familyMemberUnitLabel = new QLabel(familyMemberFrame);
        familyMemberUnitLabel->setObjectName("familyMemberUnitLabel");
        familyMemberUnitLabel->setMinimumSize(QSize(60, 0));
        familyMemberUnitLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));
        familyMemberUnitLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_12->addWidget(familyMemberUnitLabel);


        verticalLayout->addWidget(familyMemberFrame);

        publicServiceFrame = new QFrame(CalculatorPage);
        publicServiceFrame->setObjectName("publicServiceFrame");
        publicServiceFrame->setMinimumSize(QSize(0, 50));
        publicServiceFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(40, 40, 40, 180);"));
        publicServiceFrame->setFrameShape(QFrame::StyledPanel);
        publicServiceFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(publicServiceFrame);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        livingAreaIconLabel = new QLabel(publicServiceFrame);
        livingAreaIconLabel->setObjectName("livingAreaIconLabel");
        livingAreaIconLabel->setMinimumSize(QSize(40, 40));
        livingAreaIconLabel->setMaximumSize(QSize(40, 40));
        livingAreaIconLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(26, 188, 156, 150);\n"
"border-radius: 20px;\n"
"padding: 5px;"));
        livingAreaIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/resource/livingArea.png")));
        livingAreaIconLabel->setScaledContents(true);

        horizontalLayout_4->addWidget(livingAreaIconLabel);

        livingAreaTextLabel = new QLabel(publicServiceFrame);
        livingAreaTextLabel->setObjectName("livingAreaTextLabel");
        sizePolicy.setHeightForWidth(livingAreaTextLabel->sizePolicy().hasHeightForWidth());
        livingAreaTextLabel->setSizePolicy(sizePolicy);
        livingAreaTextLabel->setMinimumSize(QSize(120, 0));
        livingAreaTextLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));

        horizontalLayout_4->addWidget(livingAreaTextLabel);

        livingAreaSlider = new QSlider(publicServiceFrame);
        livingAreaSlider->setObjectName("livingAreaSlider");
        livingAreaSlider->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    margin: 6px 0;\n"
"	background:transparent\357\274\233\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #555555;          /* \350\275\250\351\201\223\350\276\271\346\241\206 */\n"
"    height: 5px;                        /* \350\275\250\351\201\223\351\253\230\345\272\246 */\n"
"    background: #222222;                /* \350\275\250\351\201\223\350\203\214\346\231\257\350\211\262 */\n"
"    margin: 2px 0;                      /* \344\270\212\344\270\213\350\276\271\350\267\235 */\n"
"    border-radius: 4px;                 /* \350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #ffffff;                /* \346\273\221\345\235\227\350\203\214\346\231\257\350\211\262-\347\231\275\350\211\262 */\n"
"    border: 1px solid #cccccc;          /* \346\273\221\345\235\227\350\276\271\346\241\206 */\n"
"    width: 10px;                        /* \346\273\221\345\235\227\345\256\275\345\272\246 */\n"
"    height: 10px;  "
                        "                     /* \346\273\221\345\235\227\351\253\230\345\272\246 */\n"
"    margin: -6px 0;                     /* \346\273\221\345\235\227\350\266\205\345\207\272\350\275\250\351\201\223\347\232\204\351\203\250\345\210\206 */\n"
"    border-radius: 5px;                 /* \346\273\221\345\235\227\345\234\206\350\247\222\357\274\210\345\215\212\345\276\204\344\270\272\345\256\275\345\272\246\347\232\204\344\270\200\345\215\212\357\274\214\345\256\236\347\216\260\345\234\206\345\275\242\357\274\211 */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: #222222;                /* \346\273\221\345\235\227\345\217\263\344\276\247\350\275\250\351\201\223\351\242\234\350\211\262 */\n"
"    border-radius: 4px;                 /* \345\217\263\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: rgb(222, 222, 222);                /* \346\273\221\345\235\227\345\267\246\344\276\247\350\275\250\351\201\223\351\242\234\350\211"
                        "\262 */\n"
"    border-radius: 4px;                 /* \345\267\246\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}"));
        livingAreaSlider->setMaximum(1000);
        livingAreaSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(livingAreaSlider);

        livingAreaValueEdit = new QLineEdit(publicServiceFrame);
        livingAreaValueEdit->setObjectName("livingAreaValueEdit");
        livingAreaValueEdit->setMinimumSize(QSize(60, 30));
        livingAreaValueEdit->setMaximumSize(QSize(60, 30));
        livingAreaValueEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(60, 60, 60, 200);\n"
"color: white;\n"
"font-size: 14px;\n"
"border: 1px solid rgba(80, 80, 80, 200);\n"
"border-radius: 4px;\n"
"padding: 2px 5px;"));
        livingAreaValueEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(livingAreaValueEdit);

        livingAreaUnitLabel = new QLabel(publicServiceFrame);
        livingAreaUnitLabel->setObjectName("livingAreaUnitLabel");
        livingAreaUnitLabel->setMinimumSize(QSize(60, 0));
        livingAreaUnitLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));
        livingAreaUnitLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(livingAreaUnitLabel);


        verticalLayout->addWidget(publicServiceFrame);

        waterFrame = new QFrame(CalculatorPage);
        waterFrame->setObjectName("waterFrame");
        waterFrame->setMinimumSize(QSize(0, 50));
        waterFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(40, 40, 40, 180);"));
        waterFrame->setFrameShape(QFrame::StyledPanel);
        waterFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(waterFrame);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        electricityIconLabel = new QLabel(waterFrame);
        electricityIconLabel->setObjectName("electricityIconLabel");
        electricityIconLabel->setMinimumSize(QSize(40, 40));
        electricityIconLabel->setMaximumSize(QSize(40, 40));
        electricityIconLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(241, 196, 15, 150);\n"
"border-radius: 20px;\n"
"padding: 5px;"));
        electricityIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/resource/electricity_bluegreen.png")));
        electricityIconLabel->setScaledContents(true);

        horizontalLayout_5->addWidget(electricityIconLabel);

        electricityTextLabel = new QLabel(waterFrame);
        electricityTextLabel->setObjectName("electricityTextLabel");
        sizePolicy.setHeightForWidth(electricityTextLabel->sizePolicy().hasHeightForWidth());
        electricityTextLabel->setSizePolicy(sizePolicy);
        electricityTextLabel->setMinimumSize(QSize(120, 0));
        electricityTextLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));

        horizontalLayout_5->addWidget(electricityTextLabel);

        electricitySlider = new QSlider(waterFrame);
        electricitySlider->setObjectName("electricitySlider");
        electricitySlider->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    margin: 6px 0;\n"
"	background:transparent\357\274\233\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #555555;          /* \350\275\250\351\201\223\350\276\271\346\241\206 */\n"
"    height: 5px;                        /* \350\275\250\351\201\223\351\253\230\345\272\246 */\n"
"    background: #222222;                /* \350\275\250\351\201\223\350\203\214\346\231\257\350\211\262 */\n"
"    margin: 2px 0;                      /* \344\270\212\344\270\213\350\276\271\350\267\235 */\n"
"    border-radius: 4px;                 /* \350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #ffffff;                /* \346\273\221\345\235\227\350\203\214\346\231\257\350\211\262-\347\231\275\350\211\262 */\n"
"    border: 1px solid #cccccc;          /* \346\273\221\345\235\227\350\276\271\346\241\206 */\n"
"    width: 10px;                        /* \346\273\221\345\235\227\345\256\275\345\272\246 */\n"
"    height: 10px;  "
                        "                     /* \346\273\221\345\235\227\351\253\230\345\272\246 */\n"
"    margin: -6px 0;                     /* \346\273\221\345\235\227\350\266\205\345\207\272\350\275\250\351\201\223\347\232\204\351\203\250\345\210\206 */\n"
"    border-radius: 5px;                 /* \346\273\221\345\235\227\345\234\206\350\247\222\357\274\210\345\215\212\345\276\204\344\270\272\345\256\275\345\272\246\347\232\204\344\270\200\345\215\212\357\274\214\345\256\236\347\216\260\345\234\206\345\275\242\357\274\211 */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: #222222;                /* \346\273\221\345\235\227\345\217\263\344\276\247\350\275\250\351\201\223\351\242\234\350\211\262 */\n"
"    border-radius: 4px;                 /* \345\217\263\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: rgb(222, 222, 222);                /* \346\273\221\345\235\227\345\267\246\344\276\247\350\275\250\351\201\223\351\242\234\350\211"
                        "\262 */\n"
"    border-radius: 4px;                 /* \345\267\246\344\276\247\350\275\250\351\201\223\345\234\206\350\247\222 */\n"
"}"));
        electricitySlider->setMaximum(1000);
        electricitySlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(electricitySlider);

        electricityValueEdit = new QLineEdit(waterFrame);
        electricityValueEdit->setObjectName("electricityValueEdit");
        electricityValueEdit->setMinimumSize(QSize(60, 30));
        electricityValueEdit->setMaximumSize(QSize(60, 30));
        electricityValueEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(60, 60, 60, 200);\n"
"color: white;\n"
"font-size: 14px;\n"
"border: 1px solid rgba(80, 80, 80, 200);\n"
"border-radius: 4px;\n"
"padding: 2px 5px;"));
        electricityValueEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(electricityValueEdit);

        electricityUnitLabel = new QLabel(waterFrame);
        electricityUnitLabel->setObjectName("electricityUnitLabel");
        electricityUnitLabel->setMinimumSize(QSize(60, 0));
        electricityUnitLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"font-size: 14px;"));
        electricityUnitLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(electricityUnitLabel);


        verticalLayout->addWidget(waterFrame);


        horizontalLayout_11->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_11, 2, 0, 1, 1);

        titleLabel = new QLabel(CalculatorPage);
        titleLabel->setObjectName("titleLabel");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(titleLabel->sizePolicy().hasHeightForWidth());
        titleLabel->setSizePolicy(sizePolicy1);
        titleLabel->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(16);
        font1.setBold(true);
        titleLabel->setFont(font1);
        titleLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: rgba(45, 45, 45, 180);\n"
"border-radius: 12px;\n"
"padding: 8px 15px;\n"
"letter-spacing: 2px;\n"
"font-weight: bold;\n"
"box-shadow: 0 4px 6px rgba(0, 0, 0, 60);\n"
"backdrop-filter: blur(8px);\n"
"-webkit-backdrop-filter: blur(8px);"));
        titleLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(titleLabel, 1, 0, 1, 1);


        retranslateUi(CalculatorPage);

        QMetaObject::connectSlotsByName(CalculatorPage);
    } // setupUi

    void retranslateUi(QWidget *CalculatorPage)
    {
        CalculatorPage->setWindowTitle(QCoreApplication::translate("CalculatorPage", "Form", nullptr));
        totalLabel->setText(QCoreApplication::translate("CalculatorPage", "\346\202\250\344\270\200\345\271\264\346\216\222\346\224\276\347\232\204CO2", nullptr));
        totalCarbonLabel->setText(QCoreApplication::translate("CalculatorPage", "0.00 (\345\220\250)", nullptr));
        perCapitaTextLabel->setText(QCoreApplication::translate("CalculatorPage", "\345\205\250\347\220\203\344\272\272\345\235\207\346\257\217\345\271\264\346\216\222\346\224\276CO\342\202\202 4.5\345\220\250", nullptr));
        perCapitaCarbonLabel->setText(QCoreApplication::translate("CalculatorPage", "\346\202\250\345\267\262\350\277\234\350\266\205\344\272\272\345\235\207\347\242\263\346\216\222\346\224\276\351\207\217", nullptr));
        rankTextLabel->setText(QCoreApplication::translate("CalculatorPage", "\346\202\2501\345\271\264\346\216\222\346\224\276\347\232\204CO\342\202\202\351\234\200\350\246\201", nullptr));
        carbonRankLabel->setText(QCoreApplication::translate("CalculatorPage", "0 \346\243\265\346\240\221\347\224\25010\345\271\264\346\235\245\346\212\265\345\201\277", nullptr));
        calculateButton->setText(QCoreApplication::translate("CalculatorPage", "\350\256\241\347\256\227\347\242\263\350\266\263\350\277\271", nullptr));
        saveResultButton->setText(QCoreApplication::translate("CalculatorPage", "\344\277\235\345\255\230\347\273\223\346\236\234", nullptr));
        disposableChopstickIconLabel->setText(QString());
        disposableChopstickTextLabel->setText(QCoreApplication::translate("CalculatorPage", "\344\270\200\346\254\241\346\200\247\347\255\267\345\255\220", nullptr));
        disposableChopstickValueEdit->setText(QCoreApplication::translate("CalculatorPage", "0.00", nullptr));
        disposableChopstickUnitLabel->setText(QCoreApplication::translate("CalculatorPage", "\345\217\214/\345\221\250", nullptr));
        plasticBagIconLabel->setText(QString());
        plasticBagTextLabel->setText(QCoreApplication::translate("CalculatorPage", "\345\241\221\346\226\231\350\242\213", nullptr));
        plasticBagValueEdit->setText(QCoreApplication::translate("CalculatorPage", "0.00", nullptr));
        plasticBagUnitLabel->setText(QCoreApplication::translate("CalculatorPage", "\344\270\252/\345\221\250", nullptr));
        clothesIconLabel->setText(QString());
        clothesTextLabel->setText(QCoreApplication::translate("CalculatorPage", "\346\226\260\347\275\256\350\241\243\347\211\251", nullptr));
        consumptionValueEdit->setText(QCoreApplication::translate("CalculatorPage", "0.00", nullptr));
        consumptionUnitLabel->setText(QCoreApplication::translate("CalculatorPage", "\344\273\266/\345\271\264", nullptr));
        paperIconLabel->setText(QString());
        paperTextLabel->setText(QCoreApplication::translate("CalculatorPage", "\347\272\270\345\274\240", nullptr));
        paperValueEdit->setText(QCoreApplication::translate("CalculatorPage", "0.00", nullptr));
        paperUnitLabel->setText(QCoreApplication::translate("CalculatorPage", "\345\274\240/\345\221\250", nullptr));
        separator2->setText(QString());
        airplaneIconLabel->setText(QString());
        airplaneTextLabel->setText(QCoreApplication::translate("CalculatorPage", "\351\243\236\346\234\272", nullptr));
        airplaneValueEdit->setText(QCoreApplication::translate("CalculatorPage", "0.00", nullptr));
        airplaneUnitLabel->setText(QCoreApplication::translate("CalculatorPage", "\345\215\203\347\261\263/\345\271\264", nullptr));
        trainIconLabel->setText(QString());
        trainTextLabel->setText(QCoreApplication::translate("CalculatorPage", "\347\201\253\350\275\246", nullptr));
        trainValueEdit->setText(QCoreApplication::translate("CalculatorPage", "0.00", nullptr));
        trainUnitLabel->setText(QCoreApplication::translate("CalculatorPage", "\345\215\203\347\261\263/\345\271\264", nullptr));
        busIconLabel->setText(QString());
        busTextLabel->setText(QCoreApplication::translate("CalculatorPage", "\345\205\254\344\272\244\350\275\246", nullptr));
        busValueEdit->setText(QCoreApplication::translate("CalculatorPage", "0.00", nullptr));
        busUnitLabel->setText(QCoreApplication::translate("CalculatorPage", "\345\215\203\347\261\263/\345\244\251", nullptr));
        carIconLabel->setText(QString());
        carTextLabel->setText(QCoreApplication::translate("CalculatorPage", "\347\247\201\345\256\266\350\275\246", nullptr));
        carValueEdit->setText(QCoreApplication::translate("CalculatorPage", "0.00", nullptr));
        carUnitLabel->setText(QCoreApplication::translate("CalculatorPage", "\345\215\203\347\261\263/\345\244\251", nullptr));
        separator1->setText(QString());
        familyMemberIconLabel->setText(QString());
        familyMemberTextLabel->setText(QCoreApplication::translate("CalculatorPage", "\345\256\266\345\272\255\346\210\220\345\221\230", nullptr));
        familyMemberValueEdit->setText(QCoreApplication::translate("CalculatorPage", "0.00", nullptr));
        familyMemberUnitLabel->setText(QCoreApplication::translate("CalculatorPage", "\344\272\272/\345\256\266", nullptr));
        livingAreaIconLabel->setText(QString());
        livingAreaTextLabel->setText(QCoreApplication::translate("CalculatorPage", "\345\261\205\344\275\217\345\234\260\351\235\242\347\247\257", nullptr));
        livingAreaValueEdit->setText(QCoreApplication::translate("CalculatorPage", "0.00", nullptr));
        livingAreaUnitLabel->setText(QCoreApplication::translate("CalculatorPage", "\345\271\263\346\226\271\347\261\263", nullptr));
        electricityIconLabel->setText(QString());
        electricityTextLabel->setText(QCoreApplication::translate("CalculatorPage", "\347\224\250\347\224\265\345\272\246\346\225\260", nullptr));
        electricityValueEdit->setText(QCoreApplication::translate("CalculatorPage", "0.00", nullptr));
        electricityUnitLabel->setText(QCoreApplication::translate("CalculatorPage", "\345\272\246/\346\234\210", nullptr));
        titleLabel->setText(QCoreApplication::translate("CalculatorPage", "\347\242\263  \350\266\263  \350\277\271  \350\256\241  \347\256\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalculatorPage: public Ui_CalculatorPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATORPAGE_H
