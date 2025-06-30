#ifndef CALCULATORPAGE_H
#define CALCULATORPAGE_H

#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QMap>
#include <QString>
#include <QLineEdit>

namespace Ui {
class CalculatorPage;
}

// 值编辑器辅助类，用于管理QLineEdit和QLabel组合的值编辑器
class ValueEditor : public QObject
{
    Q_OBJECT

public:
    ValueEditor(QLineEdit *valueEdit, QLabel *unitLabel, QSlider *slider, 
                double &valueRef, double maxValue, QWidget *parent = nullptr, bool integerMode = false, int decimalPlaces = 2);
    
    // 设置值
    void setValue(double value);
    
    // 获取值
    double value() const { return valueRef; }
    
    // 获取滑块系数
    double getSliderFactor() const { return sliderFactor; }
    
    // 设置单位
    void setUnit(const QString &unit);
    
    // 启用编辑模式
    void enableEditMode();
    
    // 禁用编辑模式
    void disableEditMode();

private slots:
    // 编辑完成
    void onEditingFinished();
    
    // 回车键处理
    void onReturnPressed();
    
    // 滑块值改变
    void onSliderValueChanged(int value);

private:
    QLineEdit *valueEdit;
    QLabel *unitLabel;
    QSlider *slider;
    double &valueRef;
    double maxValue;
    double sliderFactor;
    bool isIntegerMode; // 是否为整数模式
    int decimalPlaces; // 小数位数
};

class CalculatorPage : public QWidget
{
    Q_OBJECT

public:
    explicit CalculatorPage(QWidget *parent = nullptr);
    ~CalculatorPage();
    
    // 添加事件过滤器，处理标签双击事件
    bool eventFilter(QObject *watched, QEvent *event) override;
    
    // 设置当前用户名
    void setCurrentUsername(const QString &username) { currentUsername = username; }

signals:
    // 添加保存结果的信号
    void saveResultRequested(double totalCarbonKg, const QMap<QString, double>& detailData);

private slots:
    void updateSliderValues();
    void calculateCarbonFootprint();
    // 添加计算按钮点击事件
    void on_calculateButton_clicked();
    // 添加保存结果按钮点击事件
    void onSaveResultButtonClicked();
    // 添加车辆数值编辑完成的槽函数
    void onCarValueEditingFinished();
    // 添加飞机数值编辑完成的槽函数
    void onAirplaneValueEditingFinished();
    
private:
    // 保存数据到文件
    void saveDataToFile();
    
    // 保存数据到CSV格式
    void saveDataToCSV(const QString &dataDir);
    
    // 初始化值编辑器
    void initializeValueEditors();
    
    Ui::CalculatorPage *ui;
    
    // 存储每个滑块的值
    double airplaneValue;
    double trainValue;
    double busValue;
    double carValue;
    double familyMemberValue;
    double livingAreaValue;
    double electricityValue;
    double disposableChopstickValue;
    double plasticBagValue;
    double clothesValue;
    double paperValue;
    
    // 当前用户名
    QString currentUsername;
    
    // 总碳足迹
    double totalCarbonFootprint;
    
    // 全球人均CO2排放量(吨)
    const double GLOBAL_PER_CAPITA_EMISSION = 9.34;
    
    // 保存详细的碳排放数据
    QMap<QString, double> latestDetailData;
    
    // 值编辑器对象
    ValueEditor *carValueEditor;
    ValueEditor *airplaneValueEditor;
    ValueEditor *trainValueEditor;
    ValueEditor *busValueEditor;
    ValueEditor *familyMemberValueEditor;
    ValueEditor *livingAreaValueEditor;
    ValueEditor *electricityValueEditor;
    ValueEditor *disposableChopstickValueEditor;
    ValueEditor *plasticBagValueEditor;
    ValueEditor *clothesValueEditor;
    ValueEditor *paperValueEditor;
};

#endif // CALCULATORPAGE_H 