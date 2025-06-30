/********************************************************************************
** Form generated from reading UI file 'aboutpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTPAGE_H
#define UI_ABOUTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutPage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QFrame *aboutFrame;
    QVBoxLayout *aboutLayout;
    QLabel *versionLabel;
    QLabel *buildDateLabel;
    QLabel *copyrightLabel;
    QTextEdit *aboutTextEdit;
    QHBoxLayout *topButtonLayout;
    QPushButton *visitWebsiteButton;
    QPushButton *viewSourceButton;
    QHBoxLayout *bottomButtonLayout;
    QPushButton *contactUsButton;
    QPushButton *privacyPolicyButton;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *dataGroup;
    QHBoxLayout *dataLayout;
    QPushButton *clearHistoryButton;
    QPushButton *exportSettingsButton;
    QPushButton *importSettingsButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *AboutPage)
    {
        if (AboutPage->objectName().isEmpty())
            AboutPage->setObjectName("AboutPage");
        AboutPage->resize(800, 683);
        AboutPage->setStyleSheet(QString::fromUtf8("background-color: #3c4b64;"));
        verticalLayout = new QVBoxLayout(AboutPage);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(AboutPage);
        titleLabel->setObjectName("titleLabel");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: rgba(52, 73, 94, 120);\n"
"border-radius: 10px;\n"
"padding: 10px;"));
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        aboutFrame = new QFrame(AboutPage);
        aboutFrame->setObjectName("aboutFrame");
        aboutFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(52, 73, 94, 120);\n"
"border-radius: 10px;\n"
"padding: 10px;"));
        aboutFrame->setFrameShape(QFrame::StyledPanel);
        aboutFrame->setFrameShadow(QFrame::Raised);
        aboutLayout = new QVBoxLayout(aboutFrame);
        aboutLayout->setObjectName("aboutLayout");
        versionLabel = new QLabel(aboutFrame);
        versionLabel->setObjectName("versionLabel");
        versionLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"font-weight: bold;"));
        versionLabel->setAlignment(Qt::AlignCenter);

        aboutLayout->addWidget(versionLabel);

        buildDateLabel = new QLabel(aboutFrame);
        buildDateLabel->setObjectName("buildDateLabel");
        buildDateLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;"));
        buildDateLabel->setAlignment(Qt::AlignCenter);

        aboutLayout->addWidget(buildDateLabel);

        copyrightLabel = new QLabel(aboutFrame);
        copyrightLabel->setObjectName("copyrightLabel");
        copyrightLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;"));
        copyrightLabel->setAlignment(Qt::AlignCenter);

        aboutLayout->addWidget(copyrightLabel);

        aboutTextEdit = new QTextEdit(aboutFrame);
        aboutTextEdit->setObjectName("aboutTextEdit");
        aboutTextEdit->setMinimumSize(QSize(0, 150));
        aboutTextEdit->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"  background-color: #2c3e50;\n"
"  border: 1px solid #34495e;\n"
"  border-radius: 5px;\n"
"  color: white;\n"
"  padding: 10px;\n"
"}"));

        aboutLayout->addWidget(aboutTextEdit);

        topButtonLayout = new QHBoxLayout();
        topButtonLayout->setObjectName("topButtonLayout");
        visitWebsiteButton = new QPushButton(aboutFrame);
        visitWebsiteButton->setObjectName("visitWebsiteButton");
        visitWebsiteButton->setMinimumSize(QSize(0, 40));
        visitWebsiteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: #2980b9;\n"
"  color: white;\n"
"  border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"  background-color: #3498db;\n"
"}"));

        topButtonLayout->addWidget(visitWebsiteButton);

        viewSourceButton = new QPushButton(aboutFrame);
        viewSourceButton->setObjectName("viewSourceButton");
        viewSourceButton->setMinimumSize(QSize(0, 40));
        viewSourceButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: #8e44ad;\n"
"  color: white;\n"
"  border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"  background-color: #9b59b6;\n"
"}"));

        topButtonLayout->addWidget(viewSourceButton);


        aboutLayout->addLayout(topButtonLayout);

        bottomButtonLayout = new QHBoxLayout();
        bottomButtonLayout->setObjectName("bottomButtonLayout");
        contactUsButton = new QPushButton(aboutFrame);
        contactUsButton->setObjectName("contactUsButton");
        contactUsButton->setMinimumSize(QSize(0, 40));
        contactUsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: #16a085;\n"
"  color: white;\n"
"  border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"  background-color: #1abc9c;\n"
"}"));

        bottomButtonLayout->addWidget(contactUsButton);

        privacyPolicyButton = new QPushButton(aboutFrame);
        privacyPolicyButton->setObjectName("privacyPolicyButton");
        privacyPolicyButton->setMinimumSize(QSize(0, 40));
        privacyPolicyButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: #7f8c8d;\n"
"  color: white;\n"
"  border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"  background-color: #95a5a6;\n"
"}"));

        bottomButtonLayout->addWidget(privacyPolicyButton);


        aboutLayout->addLayout(bottomButtonLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        aboutLayout->addItem(verticalSpacer_2);

        dataGroup = new QGroupBox(aboutFrame);
        dataGroup->setObjectName("dataGroup");
        dataGroup->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"  color: white;\n"
"  border: 1px solid #2c3e50;\n"
"  border-radius: 5px;\n"
"  margin-top: 1ex;\n"
"  font-weight: bold;\n"
"}\n"
"QGroupBox::title {\n"
"  subcontrol-origin: margin;\n"
"  subcontrol-position: top center;\n"
"  padding: 0 5px;\n"
"}"));
        dataLayout = new QHBoxLayout(dataGroup);
        dataLayout->setObjectName("dataLayout");
        clearHistoryButton = new QPushButton(dataGroup);
        clearHistoryButton->setObjectName("clearHistoryButton");
        clearHistoryButton->setMinimumSize(QSize(0, 40));
        clearHistoryButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: #e74c3c;\n"
"  color: white;\n"
"  border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"  background-color: #c0392b;\n"
"}"));

        dataLayout->addWidget(clearHistoryButton);

        exportSettingsButton = new QPushButton(dataGroup);
        exportSettingsButton->setObjectName("exportSettingsButton");
        exportSettingsButton->setMinimumSize(QSize(0, 40));
        exportSettingsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: #2980b9;\n"
"  color: white;\n"
"  border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"  background-color: #3498db;\n"
"}"));

        dataLayout->addWidget(exportSettingsButton);

        importSettingsButton = new QPushButton(dataGroup);
        importSettingsButton->setObjectName("importSettingsButton");
        importSettingsButton->setMinimumSize(QSize(0, 40));
        importSettingsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: #27ae60;\n"
"  color: white;\n"
"  border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"  background-color: #2ecc71;\n"
"}"));

        dataLayout->addWidget(importSettingsButton);


        aboutLayout->addWidget(dataGroup);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        aboutLayout->addItem(verticalSpacer);


        verticalLayout->addWidget(aboutFrame);


        retranslateUi(AboutPage);

        QMetaObject::connectSlotsByName(AboutPage);
    } // setupUi

    void retranslateUi(QWidget *AboutPage)
    {
        AboutPage->setWindowTitle(QCoreApplication::translate("AboutPage", "\345\205\263\344\272\216", nullptr));
        titleLabel->setText(QCoreApplication::translate("AboutPage", "\345\205\263\344\272\216\347\242\263\350\266\263\350\277\271\350\256\241\347\256\227\345\231\250", nullptr));
        versionLabel->setText(QCoreApplication::translate("AboutPage", "\347\211\210\346\234\254: 1.0.0", nullptr));
        buildDateLabel->setText(QCoreApplication::translate("AboutPage", "\346\236\204\345\273\272\346\227\245\346\234\237: 2023-05-01", nullptr));
        copyrightLabel->setText(QCoreApplication::translate("AboutPage", "\347\211\210\346\235\203\346\211\200\346\234\211 \302\251 2023 \347\242\263\350\266\263\350\277\271\350\256\241\347\256\227\345\231\250\345\233\242\351\230\237", nullptr));
        aboutTextEdit->setHtml(QCoreApplication::translate("AboutPage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">\347\242\263\350\266\263\350\277\271\350\256\241\347\256\227\345\231\250\346\230\257\344\270\200\346\254\276\345\270\256\345\212\251\347\224\250\346\210\267\350\256\241\347\256\227\345\222\214\350\267\237\350\270\252\344\270\252\344\272\272\347\242\263\346\216\222\346\224\276\347\232\204\345\267\245\345\205\267\343\200\202</span></p>\n"
"<p style=\"-qt-"
                        "paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">\351\200\232\350\277\207\350\256\260\345\275\225\346\227\245\345\270\270\346\264\273\345\212\250\357\274\214\345\246\202\344\272\244\351\200\232\345\207\272\350\241\214\343\200\201\350\203\275\346\272\220\344\275\277\347\224\250\343\200\201\351\243\237\347\211\251\346\266\210\350\264\271\347\255\211\357\274\214\347\224\250\346\210\267\345\217\257\344\273\245\344\272\206\350\247\243\350\207\252\345\267\261\345\257\271\347\216\257\345\242\203\347\232\204\345\275\261\345\223\215\357\274\214\345\271\266\346\211\276\345\210\260\345\207\217\345\260\221\347\242\263\346\216\222\346\224\276\347\232\204\346\226\271\346\263\225\343\200\202</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-t"
                        "op:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">\346\210\221\344\273\254\347\232\204\347\233\256\346\240\207\346\230\257\346\217\220\351\253\230\347\216\257\344\277\235\346\204\217\350\257\206\357\274\214\344\277\203\350\277\233\345\217\257\346\214\201\347\273\255\345\217\221\345\261\225\343\200\202</span></p></body></html>", nullptr));
        visitWebsiteButton->setText(QCoreApplication::translate("AboutPage", "\350\256\277\351\227\256\345\256\230\347\275\221", nullptr));
        viewSourceButton->setText(QCoreApplication::translate("AboutPage", "\346\237\245\347\234\213\346\272\220\347\240\201", nullptr));
        contactUsButton->setText(QCoreApplication::translate("AboutPage", "\350\201\224\347\263\273\346\210\221\344\273\254", nullptr));
        privacyPolicyButton->setText(QCoreApplication::translate("AboutPage", "\351\232\220\347\247\201\346\224\277\347\255\226", nullptr));
        dataGroup->setTitle(QCoreApplication::translate("AboutPage", "\346\225\260\346\215\256\347\256\241\347\220\206", nullptr));
        clearHistoryButton->setText(QCoreApplication::translate("AboutPage", "\346\270\205\347\251\272\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        exportSettingsButton->setText(QCoreApplication::translate("AboutPage", "\345\257\274\345\207\272\350\256\276\347\275\256", nullptr));
        importSettingsButton->setText(QCoreApplication::translate("AboutPage", "\345\257\274\345\205\245\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutPage: public Ui_AboutPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTPAGE_H
