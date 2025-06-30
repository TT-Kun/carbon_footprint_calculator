/********************************************************************************
** Form generated from reading UI file 'datapage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAPAGE_H
#define UI_DATAPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataPage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QFrame *searchFrame;
    QHBoxLayout *searchLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *dateFromLabel;
    QDateEdit *fromDateEdit;
    QLabel *dateToLabel;
    QDateEdit *toDateEdit;
    QPushButton *searchButton;
    QPushButton *resetButton;
    QHBoxLayout *selectionToolsLayout;
    QPushButton *selectAllButton;
    QLabel *selectionCountLabel;
    QSpacerItem *horizontalSpacer_3;
    QTableWidget *dataTableWidget;
    QFrame *statsFrame;
    QHBoxLayout *statsLayout;
    QLabel *totalRecordsLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *averageLabel;
    QHBoxLayout *buttonsLayout;
    QPushButton *exportButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *deleteButton;

    void setupUi(QWidget *DataPage)
    {
        if (DataPage->objectName().isEmpty())
            DataPage->setObjectName("DataPage");
        DataPage->resize(800, 600);
        DataPage->setStyleSheet(QString::fromUtf8("background-color: #3c4b64;"));
        verticalLayout = new QVBoxLayout(DataPage);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(DataPage);
        titleLabel->setObjectName("titleLabel");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        titleLabel->setFont(font);
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

        verticalLayout->addWidget(titleLabel);

        searchFrame = new QFrame(DataPage);
        searchFrame->setObjectName("searchFrame");
        searchFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(52, 73, 94, 120);\n"
"border-radius: 10px;\n"
"padding: 10px;"));
        searchFrame->setFrameShape(QFrame::StyledPanel);
        searchFrame->setFrameShadow(QFrame::Raised);
        searchLayout = new QHBoxLayout(searchFrame);
        searchLayout->setObjectName("searchLayout");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        searchLayout->addItem(horizontalSpacer_4);

        dateFromLabel = new QLabel(searchFrame);
        dateFromLabel->setObjectName("dateFromLabel");
        dateFromLabel->setMinimumSize(QSize(40, 0));
        dateFromLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;"));

        searchLayout->addWidget(dateFromLabel);

        fromDateEdit = new QDateEdit(searchFrame);
        fromDateEdit->setObjectName("fromDateEdit");
        fromDateEdit->setMinimumSize(QSize(0, 30));
        fromDateEdit->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"  background-color: rgb(150, 150, 150);\n"
"  border-radius: 5px;\n"
"  color: white;\n"
"  padding: 2px 8px;\n"
"}\n"
"QDateEdit::drop-down {\n"
"  border: 0px;\n"
"  width: 20px;\n"
"}\n"
"QDateEdit::down-arrow {\n"
"  image: url(:/resource/calendar.png);\n"
"  width: 16px;\n"
"  height: 16px;\n"
"}"));
        fromDateEdit->setCalendarPopup(true);

        searchLayout->addWidget(fromDateEdit);

        dateToLabel = new QLabel(searchFrame);
        dateToLabel->setObjectName("dateToLabel");
        dateToLabel->setMinimumSize(QSize(10, 0));
        dateToLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;"));

        searchLayout->addWidget(dateToLabel);

        toDateEdit = new QDateEdit(searchFrame);
        toDateEdit->setObjectName("toDateEdit");
        toDateEdit->setMinimumSize(QSize(0, 30));
        toDateEdit->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"  background-color: rgb(150, 150, 150);\n"
"  border: 1px solid #34495e;\n"
"  border-radius: 5px;\n"
"  color: white;\n"
"  padding: 2px 8px;\n"
"}\n"
"QDateEdit::drop-down {\n"
"  border: 0px;\n"
"  width: 20px;\n"
"}\n"
"QDateEdit::down-arrow {\n"
"  image: url(:/resource/calendar.png);\n"
"  width: 16px;\n"
"  height: 16px;\n"
"}"));
        toDateEdit->setCalendarPopup(true);

        searchLayout->addWidget(toDateEdit);

        searchButton = new QPushButton(searchFrame);
        searchButton->setObjectName("searchButton");
        searchButton->setMinimumSize(QSize(80, 30));
        searchButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: #3498db;\n"
"  color: white;\n"
"  border-radius: 5px;\n"
"  padding: 5px 15px;\n"
"}\n"
"QPushButton:hover {\n"
"  background-color: #2980b9;\n"
"}\n"
"QPushButton:pressed {\n"
"  background-color: #1f6dad;\n"
"}"));

        searchLayout->addWidget(searchButton);

        resetButton = new QPushButton(searchFrame);
        resetButton->setObjectName("resetButton");
        resetButton->setMinimumSize(QSize(80, 30));
        resetButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: #7f8c8d;\n"
"  color: white;\n"
"  border-radius: 5px;\n"
"  padding: 5px 15px;\n"
"}\n"
"QPushButton:hover {\n"
"  background-color: #95a5a6;\n"
"}\n"
"QPushButton:pressed {\n"
"  background-color: #5f6c6d;\n"
"}"));

        searchLayout->addWidget(resetButton);


        verticalLayout->addWidget(searchFrame);

        selectionToolsLayout = new QHBoxLayout();
        selectionToolsLayout->setObjectName("selectionToolsLayout");
        selectAllButton = new QPushButton(DataPage);
        selectAllButton->setObjectName("selectAllButton");
        selectAllButton->setMinimumSize(QSize(100, 30));
        selectAllButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: #34495e;\n"
"  color: white;\n"
"  border-radius: 4px;\n"
"  padding: 4px 8px;\n"
"}\n"
"QPushButton:hover {\n"
"  background-color: #2c3e50;\n"
"}\n"
"QPushButton:pressed {\n"
"  background-color: #1f2c38;\n"
"}"));

        selectionToolsLayout->addWidget(selectAllButton);

        selectionCountLabel = new QLabel(DataPage);
        selectionCountLabel->setObjectName("selectionCountLabel");
        selectionCountLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 12px;"));

        selectionToolsLayout->addWidget(selectionCountLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        selectionToolsLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(selectionToolsLayout);

        dataTableWidget = new QTableWidget(DataPage);
        if (dataTableWidget->columnCount() < 7)
            dataTableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        dataTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        dataTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        dataTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        dataTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        dataTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        dataTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        dataTableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        dataTableWidget->setObjectName("dataTableWidget");
        dataTableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"  background-color: rgba(0, 0, 0, 130);\n"
"  alternate-background-color: rgba(44, 62, 80, 80);\n"
"  color: white;\n"
"  gridline-color: #34495e;\n"
"  border-radius: 10px;\n"
"  padding: 5px;\n"
"  selection-background-color: #2980b9;\n"
"  selection-color: white;\n"
"  outline: none;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"  padding: 5px;\n"
"  border-bottom: 1px solid rgba(255, 255, 255, 20);\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"  background-color: #3498db;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"  background-color: #2c3e50;\n"
"  color: white;\n"
"  padding: 8px;\n"
"  font-weight: bold;\n"
"  border: none;\n"
"  border-right: 1px solid #34495e;\n"
"}\n"
"\n"
"QTableWidget QScrollBar:vertical {\n"
"  background: #2c3e50;\n"
"  width: 10px;\n"
"  margin: 0px;\n"
"}\n"
"\n"
"QTableWidget QScrollBar::handle:vertical {\n"
"  background: #34495e;\n"
"  min-height: 20px;\n"
"  border-radius: 5px;\n"
"}\n"
"\n"
"QTableWidget QScrollBar::add-line:vertical,\n"
"QTableWidget QScroll"
                        "Bar::sub-line:vertical {\n"
"  height: 0px;\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"  background-color: #2c3e50;\n"
"  border: none;\n"
"}"));
        dataTableWidget->setFrameShape(QFrame::NoFrame);
        dataTableWidget->setFrameShadow(QFrame::Plain);
        dataTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        dataTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        dataTableWidget->setAlternatingRowColors(true);
        dataTableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
        dataTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        dataTableWidget->setShowGrid(false);
        dataTableWidget->setGridStyle(Qt::DotLine);
        dataTableWidget->setSortingEnabled(true);
        dataTableWidget->setCornerButtonEnabled(false);
        dataTableWidget->horizontalHeader()->setMinimumSectionSize(50);
        dataTableWidget->horizontalHeader()->setDefaultSectionSize(100);
        dataTableWidget->horizontalHeader()->setStretchLastSection(true);
        dataTableWidget->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(dataTableWidget);

        statsFrame = new QFrame(DataPage);
        statsFrame->setObjectName("statsFrame");
        statsFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(41, 128, 185, 100);\n"
"border-radius: 10px;"));
        statsFrame->setFrameShape(QFrame::StyledPanel);
        statsFrame->setFrameShadow(QFrame::Raised);
        statsLayout = new QHBoxLayout(statsFrame);
        statsLayout->setObjectName("statsLayout");
        totalRecordsLabel = new QLabel(statsFrame);
        totalRecordsLabel->setObjectName("totalRecordsLabel");
        totalRecordsLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"font-size: 14px;\n"
"font-weight: bold;"));

        statsLayout->addWidget(totalRecordsLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        statsLayout->addItem(horizontalSpacer);

        averageLabel = new QLabel(statsFrame);
        averageLabel->setObjectName("averageLabel");
        averageLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"font-size: 14px;\n"
"font-weight: bold;"));

        statsLayout->addWidget(averageLabel);


        verticalLayout->addWidget(statsFrame);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setObjectName("buttonsLayout");
        exportButton = new QPushButton(DataPage);
        exportButton->setObjectName("exportButton");
        exportButton->setMinimumSize(QSize(150, 40));
        exportButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: #27ae60;\n"
"  color: white;\n"
"  border-radius: 5px;\n"
"  padding: 5px 15px;\n"
"  font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"  background-color: #2ecc71;\n"
"}\n"
"QPushButton:pressed {\n"
"  background-color: #16a085;\n"
"}"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("document-save")));
        exportButton->setIcon(icon);

        buttonsLayout->addWidget(exportButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonsLayout->addItem(horizontalSpacer_2);

        deleteButton = new QPushButton(DataPage);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setMinimumSize(QSize(150, 40));
        deleteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: #e74c3c;\n"
"  color: white;\n"
"  border-radius: 5px;\n"
"  padding: 5px 15px;\n"
"  font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"  background-color: #c0392b;\n"
"}\n"
"QPushButton:pressed {\n"
"  background-color: #a52a2a;\n"
"}"));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("edit-delete")));
        deleteButton->setIcon(icon1);

        buttonsLayout->addWidget(deleteButton);


        verticalLayout->addLayout(buttonsLayout);


        retranslateUi(DataPage);

        QMetaObject::connectSlotsByName(DataPage);
    } // setupUi

    void retranslateUi(QWidget *DataPage)
    {
        DataPage->setWindowTitle(QCoreApplication::translate("DataPage", "\346\225\260\346\215\256\347\256\241\347\220\206", nullptr));
        titleLabel->setText(QCoreApplication::translate("DataPage", "\347\242\263  \350\266\263  \350\277\271  \350\256\241  \347\256\227  \350\256\260  \345\275\225  \345\210\227  \350\241\250", nullptr));
        dateFromLabel->setText(QCoreApplication::translate("DataPage", "\344\273\216\357\274\232", nullptr));
        fromDateEdit->setDisplayFormat(QCoreApplication::translate("DataPage", "yyyy-MM-dd", nullptr));
        dateToLabel->setText(QCoreApplication::translate("DataPage", "\345\210\260\357\274\232", nullptr));
        toDateEdit->setDisplayFormat(QCoreApplication::translate("DataPage", "yyyy-MM-dd", nullptr));
        searchButton->setText(QCoreApplication::translate("DataPage", "\346\220\234\347\264\242", nullptr));
        resetButton->setText(QCoreApplication::translate("DataPage", "\351\207\215\347\275\256", nullptr));
        selectAllButton->setText(QCoreApplication::translate("DataPage", "\345\205\250\351\200\211/\345\217\226\346\266\210\345\205\250\351\200\211", nullptr));
        selectionCountLabel->setText(QCoreApplication::translate("DataPage", "\345\267\262\351\200\211\346\213\251: 0 \346\235\241\350\256\260\345\275\225", nullptr));
        QTableWidgetItem *___qtablewidgetitem = dataTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DataPage", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = dataTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DataPage", "\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = dataTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DataPage", "\346\200\273\347\242\263\350\266\263\350\277\271(kg)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = dataTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DataPage", "\344\272\244\351\200\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = dataTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DataPage", "\345\256\266\345\272\255", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = dataTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DataPage", "\346\266\210\350\264\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = dataTableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("DataPage", "\346\223\215\344\275\234", nullptr));
        totalRecordsLabel->setText(QCoreApplication::translate("DataPage", "\346\200\273\350\256\260\345\275\225\346\225\260\357\274\2320", nullptr));
        averageLabel->setText(QCoreApplication::translate("DataPage", "\345\271\263\345\235\207\347\242\263\350\266\263\350\277\271\357\274\2320 kg", nullptr));
        exportButton->setText(QCoreApplication::translate("DataPage", "\345\257\274\345\207\272\346\225\260\346\215\256", nullptr));
        deleteButton->setText(QCoreApplication::translate("DataPage", "\345\210\240\351\231\244\346\211\200\351\200\211\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataPage: public Ui_DataPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAPAGE_H
