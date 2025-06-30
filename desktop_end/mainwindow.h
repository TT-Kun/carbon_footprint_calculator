#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include <QPixmap>
#include <QVector>
#include <QEvent>
#include <QResizeEvent>
#include "calculatorpage.h"
#include "datapage.h"
#include "aboutpage.h"
#include "chartpage.h"
#include "userpage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
    // 事件过滤器用于处理轮播图指示点的点击
    bool eventFilter(QObject *watched, QEvent *event) override;

protected:
    // 处理窗口大小变化事件
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void navigateToPage(int index);
    void setupConnections();
    
    // 处理碳足迹数据保存
    void handleSaveResult(double totalCarbonKg, const QMap<QString, double>& detailData);
    
    // 轮播图相关槽函数
    void updateSlideshow();
    void setActiveDot(int index);
    void initializeSlideshow();
    void showPreviousSlide();
    void showNextSlide();
    void updateSlideImage(int index);
    void adjustButtonPositions();

    // 打开官方网站
    void onOfficialWebsiteButtonClicked();

private:
    Ui::MainWindow *ui;
    CalculatorPage *calculatorPage; // 计算页面实例
    DataPage *dataPage; // 数据页面实例
    AboutPage *aboutPage; // 关于页面实例
    ChartPage *chartPage; // 图表页面实例
    UserPage *userPage; // 用户页面实例
    
    // 当前登录用户名（简化版）
    QString currentUser;
    
    // 轮播图相关变量
    QTimer *slideshowTimer;
    int currentSlideIndex;
    QVector<QPixmap> slideshowImages;
    QPushButton *prevButton;  // 上一张按钮
    QPushButton *nextButton;  // 下一张按钮
    
    // 设置应用背景图片
    void setAppBackground();
};
#endif // MAINWINDOW_H
