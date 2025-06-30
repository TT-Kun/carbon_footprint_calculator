/********************************************************************************
** Form generated from reading UI file 'chartpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTPAGE_H
#define UI_CHARTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChartPage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *userInfoLabel;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QFrame *chartsContainer;
    QVBoxLayout *verticalLayout_2;
    QLabel *noDataLabel;
    QGridLayout *chartsLayout;

    void setupUi(QWidget *ChartPage)
    {
        if (ChartPage->objectName().isEmpty())
            ChartPage->setObjectName("ChartPage");
        ChartPage->resize(900, 700);
        ChartPage->setMinimumSize(QSize(900, 650));
        ChartPage->setStyleSheet(QString::fromUtf8("background-color: #3c4b64;"));
        verticalLayout = new QVBoxLayout(ChartPage);
        verticalLayout->setSpacing(12);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(15, 15, 15, 15);
        titleLabel = new QLabel(ChartPage);
        titleLabel->setObjectName("titleLabel");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: rgba(52, 73, 94, 150);\n"
"border-radius: 8px;\n"
"padding: 10px;"));
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        userInfoLabel = new QLabel(ChartPage);
        userInfoLabel->setObjectName("userInfoLabel");
        QFont font1;
        font1.setPointSize(10);
        userInfoLabel->setFont(font1);
        userInfoLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: rgba(52, 73, 94, 100);\n"
"border-radius: 8px;\n"
"padding: 8px;"));
        userInfoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(userInfoLabel);

        scrollArea = new QScrollArea(ChartPage);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    background-color: rgba(52, 73, 94, 150);\n"
"    border-radius: 10px;\n"
"    border: none;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background-color: rgba(52, 73, 94, 80);\n"
"    width: 12px;\n"
"    margin: 0px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background-color: rgba(41, 128, 185, 150);\n"
"    min-height: 20px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background-color: rgba(41, 128, 185, 200);\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"    background-color: rgba(52, 73, 94, 50);\n"
"    border-radius: 6px;\n"
"}"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 870, 566));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(15);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(15, 15, 15, 15);
        chartsContainer = new QFrame(scrollAreaWidgetContents);
        chartsContainer->setObjectName("chartsContainer");
        chartsContainer->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: rgba(52, 73, 94, 150);\n"
"    border-radius: 10px;\n"
"}"));
        chartsContainer->setFrameShape(QFrame::StyledPanel);
        chartsContainer->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(chartsContainer);
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(15, 15, 15, 15);
        noDataLabel = new QLabel(chartsContainer);
        noDataLabel->setObjectName("noDataLabel");
        QFont font2;
        font2.setPointSize(14);
        noDataLabel->setFont(font2);
        noDataLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: rgba(52, 73, 94, 100);\n"
"border-radius: 10px;\n"
"padding: 30px;"));
        noDataLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(noDataLabel);

        chartsLayout = new QGridLayout();
        chartsLayout->setSpacing(15);
        chartsLayout->setObjectName("chartsLayout");

        verticalLayout_2->addLayout(chartsLayout);


        verticalLayout_3->addWidget(chartsContainer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(ChartPage);

        QMetaObject::connectSlotsByName(ChartPage);
    } // setupUi

    void retranslateUi(QWidget *ChartPage)
    {
        ChartPage->setWindowTitle(QCoreApplication::translate("ChartPage", "\346\225\260\346\215\256\345\233\276\350\241\250", nullptr));
        titleLabel->setText(QCoreApplication::translate("ChartPage", "\347\224\250\346\210\267\346\225\260\346\215\256\347\273\237\350\256\241", nullptr));
        userInfoLabel->setText(QCoreApplication::translate("ChartPage", "\345\275\223\345\211\215\347\224\250\346\210\267\357\274\232\346\234\252\347\231\273\345\275\225", nullptr));
        noDataLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChartPage: public Ui_ChartPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTPAGE_H
