#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyle>
#include <QPainter>
#include <QPixmap>
#include <QBitmap>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentUser("默认用户") // 设置默认用户名
    , currentSlideIndex(0)
{
    ui->setupUi(this);
    this->setWindowTitle("碳足迹计算器");
    
    // 设置窗口大小
    this->setMinimumSize(1000, 700);
    
    // 设置背景图片
    setAppBackground();
    
    // 初始化导航栏按钮样式
    QPushButton* navButtons[] = {
        ui->homeButton,
        ui->calculatorButton,
        ui->dataButton,
        ui->settingsButton,
        ui->infoButton,
        ui->userButton
    };
    
    for (auto button : navButtons) {
        button->setStyleSheet(
            "QPushButton {"
            "    background-color: transparent;"
            "    color: white;"
            "    border: none;"
            "    border-radius: 5px;"
            "}"
            "QPushButton:hover {"
            "    background-color: #34495e;"
            "}"
        );
    }
    
    // 创建计算页面
    calculatorPage = new CalculatorPage();
    ui->stackedWidget->removeWidget(ui->calculatorPage);
    ui->stackedWidget->insertWidget(1, calculatorPage);
    
    // 创建数据页面
    dataPage = new DataPage();
    ui->stackedWidget->insertWidget(2, dataPage);
    
    // 创建图表页面
    chartPage = new ChartPage();
    ui->stackedWidget->insertWidget(3, chartPage);
    
    // 创建关于页面
    aboutPage = new AboutPage();
    ui->stackedWidget->insertWidget(4, aboutPage);
    
    // 创建用户页面
    userPage = new UserPage();
    ui->stackedWidget->insertWidget(5, userPage);
    
    // 检查是否已经登录，如果已登录则更新当前用户名
    if (userPage->isUserLoggedIn()) {
        currentUser = userPage->getUsername();
    }
    
    // 设置当前用户名
    calculatorPage->setCurrentUsername(currentUser);
    
    // 默认显示首页
    ui->stackedWidget->setCurrentIndex(0);
    
    // 设置连接
    setupConnections();
    
    // 初始化轮播图
    initializeSlideshow();
}

MainWindow::~MainWindow()
{
    // 停止轮播图定时器
    if (slideshowTimer) {
        slideshowTimer->stop();
        delete slideshowTimer;
    }
    
    // 释放页面对象
    delete aboutPage;
    delete chartPage;
    delete userPage;
    
    delete ui;
}

void MainWindow::initializeSlideshow()
{
    // 配置轮播图标签
    ui->carouselLabel->setScaledContents(false); // 不再使用自动缩放
    
    // 创建前一张和后一张按钮 - 现在将它们创建为contentFrame的子控件而不是carouselFrame的
    prevButton = new QPushButton("<", ui->contentFrame);
    nextButton = new QPushButton(">", ui->contentFrame);
    
    // 设置按钮样式和位置
    QString buttonStyle = "QPushButton {"
                          "  background-color: rgba(0, 0, 0, 100);"
                          "  color: white;"
                          "  border-radius: 15px;"
                          "  font-size: 20px;"
                          "  font-weight: bold;"
                          "  min-width: 30px;"
                          "  max-width: 30px;"
                          "  min-height: 60px;"
                          "  max-height: 60px;"
                          "}"
                          "QPushButton:hover {"
                          "  background-color: rgba(0, 0, 0, 150);"
                          "}";
    
    prevButton->setStyleSheet(buttonStyle);
    nextButton->setStyleSheet(buttonStyle);
    
    // 设置按钮位置（以中央垂直对齐）
    // 暂时不设置位置，等界面完全加载后再通过resizeEvent设置
    
    // 连接按钮信号
    connect(prevButton, &QPushButton::clicked, this, &MainWindow::showPreviousSlide);
    connect(nextButton, &QPushButton::clicked, this, &MainWindow::showNextSlide);
    
    // 设置按钮光标为手型
    prevButton->setCursor(Qt::PointingHandCursor);
    nextButton->setCursor(Qt::PointingHandCursor);
    
    // 设置指示点鼠标样式为手型，表示可点击
    ui->dot1->setCursor(Qt::PointingHandCursor);
    ui->dot2->setCursor(Qt::PointingHandCursor);
    ui->dot3->setCursor(Qt::PointingHandCursor);
    ui->dot4->setCursor(Qt::PointingHandCursor);
    
    // 加载轮播图图片
    slideshowImages.clear();
    slideshowImages.append(QPixmap(":/resource/slideshow1.png"));
    slideshowImages.append(QPixmap(":/resource/slideshow2.png"));
    slideshowImages.append(QPixmap(":/resource/slideshow3.png"));
    slideshowImages.append(QPixmap(":/resource/slideshow4.png"));
    
    // 如果没有图片，返回
    if (slideshowImages.isEmpty()) {
        return;
    }
    
    // 创建定时器
    slideshowTimer = new QTimer(this);
    connect(slideshowTimer, &QTimer::timeout, this, &MainWindow::updateSlideshow);
    
    // 使用单次触发的定时器确保界面完全加载后再设置初始图片
    QTimer::singleShot(100, this, [this]() {
        // 初始化显示第一张图片
        updateSlideImage(0);
        setActiveDot(0);
        
        // 启动自动轮播
        slideshowTimer->start(5000);
        
        // 调整按钮位置
        adjustButtonPositions();
    });
}

void MainWindow::adjustButtonPositions()
{
    // 确保按钮位置正确
    if (prevButton && nextButton && ui->contentFrame) {
        // 获取轮播图容器的位置和大小
        QRect carouselFrameGeometry = ui->carouselFrame->geometry();
        
        // 计算按钮位置 - 使按钮位于轮播图容器左右两侧外部
        int buttonY = carouselFrameGeometry.y() + carouselFrameGeometry.height() / 2 - 30; // 垂直居中于轮播图容器
        
        // 左侧按钮位于轮播图容器左侧外部
        prevButton->setGeometry(
            carouselFrameGeometry.x() - 40, // 位于轮播图左侧外10像素
            buttonY, 
            30, 
            60
        );
        
        // 右侧按钮位于轮播图容器右侧外部
        nextButton->setGeometry(
            carouselFrameGeometry.x() + carouselFrameGeometry.width() + 10, // 位于轮播图右侧外10像素
            buttonY, 
            30, 
            60
        );
        
        // 确保按钮在最上层显示
        prevButton->raise();
        nextButton->raise();
    }
}

void MainWindow::updateSlideshow()
{
    // 更新当前图片索引
    currentSlideIndex = (currentSlideIndex + 1) % slideshowImages.size();
    
    // 显示当前图片
    updateSlideImage(currentSlideIndex);
    
    // 更新指示点
    setActiveDot(currentSlideIndex);
}

void MainWindow::updateSlideImage(int index)
{
    if (index < 0 || index >= slideshowImages.size()) {
        return;
    }
    
    QPixmap pixmap = slideshowImages.at(index);
    
    // 确保标签大小已经正确设置
    QSize labelSize = ui->carouselLabel->size();
    
    // 如果标签尺寸不合理，可能界面还没有完全布局好
    if (labelSize.width() < 50 || labelSize.height() < 50) {
        // 获取carouselFrame的尺寸作为参考
        labelSize = ui->contentFrame->size();
        labelSize.setHeight(labelSize.height() - ui->dotFrame->height() - 20); // 减去底部圆点区域高度和一些内边距
    }
    
    // 限制最大宽度，避免图片过宽
    if (labelSize.width() > 600) {
        int originalHeight = labelSize.height();
        labelSize.setWidth(600);
        // 保持宽高比
        double ratio = (double)600 / labelSize.width();
        labelSize.setHeight(originalHeight * ratio);
    }
    
    QSize pixmapSize = pixmap.size();
    
    // 计算缩放比例
    double widthRatio = (double)labelSize.width() / pixmapSize.width();
    double heightRatio = (double)labelSize.height() / pixmapSize.height();
    double ratio = qMin(widthRatio, heightRatio);
    
    // 计算缩放后的尺寸
    int scaledWidth = pixmapSize.width() * ratio;
    int scaledHeight = pixmapSize.height() * ratio;
    
    // 创建一个背景为半透明黑色的画布
    QPixmap result(labelSize);
    result.fill(QColor(0, 0, 0, 120)); // 半透明黑色
    
    // 在画布上绘制缩放后的图片，居中放置
    QPainter painter(&result);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    
    painter.drawPixmap((labelSize.width() - scaledWidth) / 2,
                       (labelSize.height() - scaledHeight) / 2,
                       pixmap.scaled(scaledWidth, scaledHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    
    // 显示合成后的图片
    ui->carouselLabel->setPixmap(result);
    
    // 确保轮播图标签和按钮显示在最前面
    ui->carouselLabel->raise();
    if (prevButton && nextButton) {
        prevButton->raise();
        nextButton->raise();
    }
}

void MainWindow::showPreviousSlide()
{
    // 更新当前图片索引
    int previousIndex = (currentSlideIndex - 1 + slideshowImages.size()) % slideshowImages.size();
    if (previousIndex == currentSlideIndex) {
        return;
    }
    
    currentSlideIndex = previousIndex;
    
    // 显示当前图片
    updateSlideImage(currentSlideIndex);
    
    // 更新指示点
    setActiveDot(currentSlideIndex);
    
    // 重置定时器
    slideshowTimer->start(5000);
}

void MainWindow::showNextSlide()
{
    // 更新当前图片索引
    int nextIndex = (currentSlideIndex + 1) % slideshowImages.size();
    if (nextIndex == currentSlideIndex) {
        return;
    }
    
    currentSlideIndex = nextIndex;
    
    // 显示当前图片
    updateSlideImage(currentSlideIndex);
    
    // 更新指示点
    setActiveDot(currentSlideIndex);
    
    // 重置定时器
    slideshowTimer->start(5000);
}

void MainWindow::setActiveDot(int index)
{
    // 重置所有点的样式为白色
    ui->dot1->setStyleSheet("background-color: white; border-radius: 8px;");
    ui->dot2->setStyleSheet("background-color: white; border-radius: 8px;");
    ui->dot3->setStyleSheet("background-color: white; border-radius: 8px;");
    ui->dot4->setStyleSheet("background-color: white; border-radius: 8px;");
    
    // 根据当前索引设置活动点的样式为蓝色
    switch(index) {
        case 0:
            ui->dot1->setStyleSheet("background-color: #2980b9; border-radius: 8px;");
            break;
        case 1:
            ui->dot2->setStyleSheet("background-color: #2980b9; border-radius: 8px;");
            break;
        case 2:
            ui->dot3->setStyleSheet("background-color: #2980b9; border-radius: 8px;");
            break;
        case 3:
            ui->dot4->setStyleSheet("background-color: #2980b9; border-radius: 8px;");
            break;
    }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    // 轮播图指示点点击事件处理
    if (event->type() == QEvent::MouseButtonPress) {
        if (watched == ui->dot1 && currentSlideIndex != 0) {
            currentSlideIndex = 0;
            updateSlideImage(currentSlideIndex);
            setActiveDot(0);
            slideshowTimer->start(5000); // 重置定时器
            return true;
        } else if (watched == ui->dot2 && currentSlideIndex != 1) {
            currentSlideIndex = 1;
            updateSlideImage(currentSlideIndex);
            setActiveDot(1);
            slideshowTimer->start(5000); // 重置定时器
            return true;
        } else if (watched == ui->dot3 && currentSlideIndex != 2) {
            currentSlideIndex = 2;
            updateSlideImage(currentSlideIndex);
            setActiveDot(2);
            slideshowTimer->start(5000); // 重置定时器
            return true;
        } else if (watched == ui->dot4 && currentSlideIndex != 3) {
            currentSlideIndex = 3;
            updateSlideImage(currentSlideIndex);
            setActiveDot(3);
            slideshowTimer->start(5000); // 重置定时器
            return true;
        }
    }
    
    // 调用基类实现
    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::setupConnections()
{
    // 连接导航按钮到相应页面
    connect(ui->homeButton, &QPushButton::clicked, this, [this]() { navigateToPage(0); });
    connect(ui->calculatorButton, &QPushButton::clicked, this, [this]() { navigateToPage(1); });
    connect(ui->dataButton, &QPushButton::clicked, this, [this]() { navigateToPage(2); });
    connect(ui->settingsButton, &QPushButton::clicked, this, [this]() { navigateToPage(3); }); // 图表页面
    connect(ui->infoButton, &QPushButton::clicked, this, [this]() { navigateToPage(4); });     // 关于页面
    connect(ui->userButton, &QPushButton::clicked, this, [this]() { navigateToPage(5); });     // 用户页面
    
    // 首页上的"开始计算"按钮也导航到计算页面
    connect(ui->startCalculateButton, &QPushButton::clicked, this, [this]() { navigateToPage(1); });
    
    // 连接官方网站按钮到打开网站的槽函数
    connect(ui->officialWebsiteButton, &QPushButton::clicked, this, &MainWindow::onOfficialWebsiteButtonClicked);
    
    // 连接计算页面的保存结果信号到数据页面
    connect(calculatorPage, &CalculatorPage::saveResultRequested, this, &MainWindow::handleSaveResult);
    
    // 使轮播图指示点支持点击
    ui->dot1->installEventFilter(this);
    ui->dot2->installEventFilter(this);
    ui->dot3->installEventFilter(this);
    ui->dot4->installEventFilter(this);
    
    // 用户页面的登录成功信号处理
    connect(userPage, &UserPage::loginSuccessful, this, [this]() {
        // 更新当前用户名
        currentUser = userPage->getUsername();
        // 设置计算器页面的用户名
        calculatorPage->setCurrentUsername(currentUser);
        // 刷新数据页面数据
        dataPage->loadUserData(currentUser);
        // 刷新图表页面数据
        chartPage->updateCharts(currentUser);
    });
    
    // 用户页面的登出信号处理
    connect(userPage, &UserPage::logoutSuccessful, this, [this]() {
        // 重置为默认用户
        currentUser = "默认用户";
        // 更新计算器页面的用户名
        calculatorPage->setCurrentUsername(currentUser);
        // 提示用户已登出
        QMessageBox::information(this, "已登出", "您已成功登出系统。数据和统计页面将不可访问。");
        // 如果当前在数据或图表页面，则回到首页
        int currentIndex = ui->stackedWidget->currentIndex();
        if (currentIndex == 2 || currentIndex == 3) {
            ui->stackedWidget->setCurrentIndex(0);
        }
    });
}

void MainWindow::navigateToPage(int index)
{
    // 检查数据页面和图表页面的访问权限
    if ((index == 2 || index == 3) && !userPage->isUserLoggedIn()) {
        // 未登录状态，显示提示信息
        QMessageBox::information(this, "需要登录", "请先登录后再访问数据和统计页面！");
        // 跳转到用户页面
        ui->stackedWidget->setCurrentIndex(5);
        return;
    }
    
    // 如果导航到数据页面，确保加载当前用户的数据
    if (index == 2) {
        dataPage->loadUserData(currentUser);
    }
    // 如果导航到图表页面，更新图表数据
    else if (index == 3) {
        chartPage->updateCharts(currentUser);
    }
    
    // 切换到指定页面
    ui->stackedWidget->setCurrentIndex(index);
}

void MainWindow::handleSaveResult(double totalCarbonKg, const QMap<QString, double>& detailData)
{
    // 将计算结果传递给数据页面
    dataPage->addCarbonData(currentUser, totalCarbonKg, detailData);
}

// 处理窗口大小变化事件
void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    
    // 更新背景图片以适应新尺寸
    setAppBackground();
    
    // 调整按钮位置
    adjustButtonPositions();
    
    // 如果轮播图已经初始化，更新当前图片
    if (slideshowTimer && !slideshowImages.isEmpty()) {
        updateSlideImage(currentSlideIndex);
    }
}

// 设置应用背景图片
void MainWindow::setAppBackground()
{
    // 清除默认的样式表以避免干扰
    this->setStyleSheet("");

    // 加载背景图片
    QPixmap bgPixmap(":/resource/bg1.jpg");
    if (bgPixmap.isNull()) {
        return;
    }

    // 将图片按照窗口大小进行缩放
    // 使用Qt::KeepAspectRatioByExpanding保持图片比例但确保覆盖整个区域
    QPixmap scaledBg = bgPixmap.scaled(
        this->size(),
        Qt::KeepAspectRatioByExpanding,
        Qt::SmoothTransformation
    );
    
    // 如果缩放后的图片大于窗口，则从中心部分进行裁剪
    if (scaledBg.width() > this->width() || scaledBg.height() > this->height()) {
        int x = (scaledBg.width() - this->width()) / 2;
        int y = (scaledBg.height() - this->height()) / 2;
        scaledBg = scaledBg.copy(x, y, this->width(), this->height());
    }

    // 设置背景调色板
    QPalette palette;
    palette.setBrush(QPalette::Window, scaledBg);
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    // 确保所有内容部件为透明，以便背景可见
    ui->centralwidget->setStyleSheet("background-color: transparent;");
    ui->stackedWidget->setStyleSheet("background-color: transparent;");
    
    // 设置左侧导航栏为半透明黑色
    ui->leftNavBar->setStyleSheet("background-color: rgba(0, 0, 0, 150);");
}

// 实现打开官方网站的槽函数
void MainWindow::onOfficialWebsiteButtonClicked()
{
    QDesktopServices::openUrl(QUrl("http://8.138.115.164/"));
}
