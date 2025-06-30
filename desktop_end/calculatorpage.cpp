#include "calculatorpage.h"
#include "ui_calculatorpage.h"
#include <QDebug>
#include <QInputDialog>
#include <QDoubleValidator>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDir>
#include <QFileInfo>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QIcon>

// ValueEditor类的实现
ValueEditor::ValueEditor(QLineEdit *valueEdit, QLabel *unitLabel, QSlider *slider, 
                         double &valueRef, double maxValue, QWidget *parent, bool integerMode, int decimalPlaces) 
    : QObject(parent),
      valueEdit(valueEdit),
      unitLabel(unitLabel),
      slider(slider),
      valueRef(valueRef),
      maxValue(maxValue),
      isIntegerMode(integerMode),
      decimalPlaces(decimalPlaces)
{
    // 计算滑块系数，根据整数模式调整系数
    if (isIntegerMode) {
        // 对于整数模式，让滑块值直接对应显示值
        sliderFactor = 1.0;
        // 调整滑块最大值为maxValue
        slider->setMaximum(static_cast<int>(maxValue));
    } else {
        // 对于浮点数模式，保持1000作为滑块最大值
        sliderFactor = 1000.0 / maxValue;
    }
    
    // 设置值编辑器为只读状态，需要双击才能编辑
    valueEdit->setReadOnly(true);
    valueEdit->installEventFilter(parent);
    
    // 为编辑器设置验证器，只允许输入浮点数或整数
    if (isIntegerMode) {
        QIntValidator *validator = new QIntValidator(0, static_cast<int>(maxValue), this);
        valueEdit->setValidator(validator);
    } else {
        QDoubleValidator *validator = new QDoubleValidator(0, maxValue, decimalPlaces, this);
    validator->setNotation(QDoubleValidator::StandardNotation);
    valueEdit->setValidator(validator);
    }
    
    // 连接信号和槽
    connect(valueEdit, &QLineEdit::editingFinished, this, &ValueEditor::onEditingFinished);
    connect(valueEdit, &QLineEdit::returnPressed, this, &ValueEditor::onReturnPressed);
    connect(slider, &QSlider::valueChanged, this, &ValueEditor::onSliderValueChanged);
    
    // 设置工具提示
    valueEdit->setToolTip("双击修改数值");
}

void ValueEditor::setValue(double value)
{
    // 更新内部值和显示
    valueRef = value;
    
    // 对整数模式进行取整
    if (isIntegerMode) {
        valueRef = qRound(valueRef);
    }
    
    // 根据模式显示整数或浮点数
    if (isIntegerMode) {
        valueEdit->setText(QString::number(static_cast<int>(valueRef)));
    } else {
        valueEdit->setText(QString::number(valueRef, 'f', decimalPlaces));
    }
    
    // 更新滑块位置（避免循环触发）
    slider->blockSignals(true);
    slider->setValue(qRound(valueRef * sliderFactor));
    slider->blockSignals(false);
}

void ValueEditor::setUnit(const QString &unit)
{
    // 设置单位标签文本
    unitLabel->setText(unit);
}

void ValueEditor::enableEditMode()
{
    // 启用编辑模式
    valueEdit->setReadOnly(false);
    valueEdit->setFocus();
    valueEdit->selectAll();
}

void ValueEditor::disableEditMode()
{
    // 禁用编辑模式
    valueEdit->setReadOnly(true);
    valueEdit->clearFocus();
}

void ValueEditor::onEditingFinished()
{
    // 获取编辑器中的值
    bool ok;
    double newValue;
    
    if (isIntegerMode) {
        int intValue = valueEdit->text().toInt(&ok);
        newValue = static_cast<double>(intValue);
    } else {
        newValue = valueEdit->text().toDouble(&ok);
    }
    
    if (ok) {
        // 如果输入的是有效数字，则更新模型值和滑块位置
        valueRef = newValue;
        
        // 更新滑块值（避免循环触发）
        slider->blockSignals(true);
        // 对于整数模式和浮点数模式使用不同的计算方式
        if (isIntegerMode) {
            slider->setValue(qRound(newValue)); // 整数模式直接设置值
        } else {
            slider->setValue(qRound(newValue * sliderFactor)); // 浮点数模式使用系数
        }
        slider->blockSignals(false);
    } else {
        // 如果输入的不是有效数字，恢复为原来的值
        if (isIntegerMode) {
            valueEdit->setText(QString::number(static_cast<int>(valueRef)));
        } else {
            valueEdit->setText(QString::number(valueRef, 'f', decimalPlaces));
        }
    }
    
    // 确保文本框恢复只读状态
    valueEdit->setReadOnly(true);
}

void ValueEditor::onReturnPressed()
{
    // 清除焦点，触发editingFinished信号
    valueEdit->clearFocus();
    
    // 恢复只读状态
    valueEdit->setReadOnly(true);
}

void ValueEditor::onSliderValueChanged(int value)
{
    // 根据滑块值更新实际值
    if (isIntegerMode) {
        // 整数模式直接使用滑块值
        valueRef = value;
    } else {
        // 浮点数模式使用缩放系数
    valueRef = value / sliderFactor;
    }
    
    // 更新显示
    if (isIntegerMode) {
        valueEdit->setText(QString::number(static_cast<int>(valueRef)));
    } else {
        valueEdit->setText(QString::number(valueRef, 'f', decimalPlaces));
    }
}

CalculatorPage::CalculatorPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculatorPage),
    airplaneValue(0),
    trainValue(0),
    busValue(0),
    carValue(0),
    familyMemberValue(0),
    livingAreaValue(0),
    electricityValue(0),
    disposableChopstickValue(0),
    plasticBagValue(0),
    clothesValue(0),
    paperValue(0),
    currentUsername("默认用户"),
    totalCarbonFootprint(0),
    carValueEditor(nullptr),
    airplaneValueEditor(nullptr),
    trainValueEditor(nullptr),
    busValueEditor(nullptr),
    familyMemberValueEditor(nullptr),
    livingAreaValueEditor(nullptr),
    electricityValueEditor(nullptr),
    disposableChopstickValueEditor(nullptr),
    plasticBagValueEditor(nullptr),
    clothesValueEditor(nullptr),
    paperValueEditor(nullptr)
{
    ui->setupUi(this);
    
    // 设置滑块的最大值和步长
    // 交通类 - 浮点数模式
    ui->airplaneSlider->setMaximum(1000);
    ui->airplaneSlider->setSingleStep(5);
    ui->trainSlider->setMaximum(1000);
    ui->trainSlider->setSingleStep(5);
    ui->busSlider->setMaximum(1000);
    ui->busSlider->setSingleStep(10);
    ui->carSlider->setMaximum(1000);
    ui->carSlider->setSingleStep(10);
    
    // 家居类 - 整数模式
    ui->familyMemberSlider->setMaximum(10); // 最大10人
    ui->familyMemberSlider->setSingleStep(1);
    ui->livingAreaSlider->setMaximum(500); // 最大500平方米
    ui->livingAreaSlider->setSingleStep(5);
    ui->electricitySlider->setMaximum(1000); // 最大1000度
    ui->electricitySlider->setSingleStep(10);
    
    // 消费类 - 整数模式
    ui->disposableChopstickSlider->setMaximum(50); // 最大50双
    ui->disposableChopstickSlider->setSingleStep(1);
    ui->plasticBagSlider->setMaximum(100); // 最大100个
    ui->plasticBagSlider->setSingleStep(1);
    ui->clothesSlider->setMaximum(100); // 最大100件
    ui->clothesSlider->setSingleStep(1);
    ui->paperSlider->setMaximum(1000); // 最大1000张
    ui->paperSlider->setSingleStep(10);
    
    // 连接所有滑块的值变化信号到updateSliderValues槽
    connect(ui->airplaneSlider, &QSlider::valueChanged, this, &CalculatorPage::updateSliderValues);
    connect(ui->trainSlider, &QSlider::valueChanged, this, &CalculatorPage::updateSliderValues);
    connect(ui->busSlider, &QSlider::valueChanged, this, &CalculatorPage::updateSliderValues);
    connect(ui->carSlider, &QSlider::valueChanged, this, &CalculatorPage::updateSliderValues);
    connect(ui->familyMemberSlider, &QSlider::valueChanged, this, &CalculatorPage::updateSliderValues);
    connect(ui->livingAreaSlider, &QSlider::valueChanged, this, &CalculatorPage::updateSliderValues);
    connect(ui->electricitySlider, &QSlider::valueChanged, this, &CalculatorPage::updateSliderValues);
    connect(ui->disposableChopstickSlider, &QSlider::valueChanged, this, &CalculatorPage::updateSliderValues);
    connect(ui->plasticBagSlider, &QSlider::valueChanged, this, &CalculatorPage::updateSliderValues);
    connect(ui->clothesSlider, &QSlider::valueChanged, this, &CalculatorPage::updateSliderValues);
    connect(ui->paperSlider, &QSlider::valueChanged, this, &CalculatorPage::updateSliderValues);
    
    // 初始化值编辑器
    initializeValueEditors();
    
    // 连接保存按钮信号
    connect(ui->saveResultButton, &QPushButton::clicked, this, &CalculatorPage::onSaveResultButtonClicked);
    
    // 修改保存按钮图标
    ui->saveResultButton->setIcon(QIcon(":/resource/save.png"));
    
    // 初始化所有滑块的值显示
    updateSliderValues();
    
    // 更新人均碳排放量显示
    ui->perCapitaTextLabel->setText(QString("全球人均每年排放CO₂ %1吨").arg(GLOBAL_PER_CAPITA_EMISSION));
    
    // 初始化，不显示比较信息
    ui->perCapitaCarbonLabel->setText("");
    
    // 初始化总碳足迹和碳中和需要的树木数量
    ui->totalCarbonLabel->setText("0.00 (吨)");
    ui->carbonRankLabel->setText("0 棵树用10年来抵偿");
    
    // 为数值编辑框添加事件过滤器，支持双击编辑功能
    ui->carValueEdit->installEventFilter(this);
    ui->airplaneValueEdit->installEventFilter(this);
    ui->trainValueEdit->installEventFilter(this);
    ui->busValueEdit->installEventFilter(this);
    ui->familyMemberValueEdit->installEventFilter(this);
    ui->livingAreaValueEdit->installEventFilter(this);
    ui->electricityValueEdit->installEventFilter(this);
    ui->paperValueEdit->installEventFilter(this);
    ui->disposableChopstickValueEdit->installEventFilter(this);
    ui->plasticBagValueEdit->installEventFilter(this);
    ui->consumptionValueEdit->installEventFilter(this);
    
    // 设置工具提示
    QString editHint = "双击修改数值";
    ui->carValueEdit->setToolTip(editHint);
    ui->airplaneValueEdit->setToolTip(editHint);
    ui->trainValueEdit->setToolTip(editHint);
    ui->busValueEdit->setToolTip(editHint);
    ui->familyMemberValueEdit->setToolTip(editHint);
    ui->livingAreaValueEdit->setToolTip(editHint);
    ui->electricityValueEdit->setToolTip(editHint);
    ui->paperValueEdit->setToolTip(editHint);
    ui->disposableChopstickValueEdit->setToolTip(editHint);
    ui->plasticBagValueEdit->setToolTip(editHint);
    ui->consumptionValueEdit->setToolTip(editHint);
}

// 添加初始化值编辑器的方法
void CalculatorPage::initializeValueEditors()
{
    // 初始化汽车值编辑器 - 最大值与滑块匹配
    carValueEditor = new ValueEditor(ui->carValueEdit, ui->carUnitLabel, ui->carSlider, 
                                     carValue, 200.0, this, false, 1);
    carValueEditor->setUnit("千米/天");
    
    // 初始化飞机值编辑器
    airplaneValueEditor = new ValueEditor(ui->airplaneValueEdit, ui->airplaneUnitLabel, ui->airplaneSlider, 
                                         airplaneValue, 2000.0, this, true, 0);
    airplaneValueEditor->setUnit("千米/年");
    
    // 初始化火车值编辑器
    trainValueEditor = new ValueEditor(ui->trainValueEdit, ui->trainUnitLabel, ui->trainSlider, 
                                      trainValue, 2000.0, this, true, 0);
    trainValueEditor->setUnit("千米/年");
    
    // 初始化公交车值编辑器
    busValueEditor = new ValueEditor(ui->busValueEdit, ui->busUnitLabel, ui->busSlider, 
                                    busValue, 100.0, this, false, 1);
    busValueEditor->setUnit("千米/天");
    
    // 初始化家庭成员值编辑器 - 整数模式
    familyMemberValueEditor = new ValueEditor(ui->familyMemberValueEdit, ui->familyMemberUnitLabel, ui->familyMemberSlider, 
                                            familyMemberValue, 10.0, this, true, 0);
    familyMemberValueEditor->setUnit("人/家");
    
    // 初始化居住面积值编辑器 - 整数模式
    livingAreaValueEditor = new ValueEditor(ui->livingAreaValueEdit, ui->livingAreaUnitLabel, ui->livingAreaSlider, 
                                          livingAreaValue, 500.0, this, true, 0);
    livingAreaValueEditor->setUnit("平方米");
    
    // 初始化用电量值编辑器 - 整数模式
    electricityValueEditor = new ValueEditor(ui->electricityValueEdit, ui->electricityUnitLabel, ui->electricitySlider, 
                                           electricityValue, 1000.0, this, true, 0);
    electricityValueEditor->setUnit("度/月");
    
    // 初始化一次性筷子值编辑器 - 整数模式
    disposableChopstickValueEditor = new ValueEditor(ui->disposableChopstickValueEdit, ui->disposableChopstickUnitLabel, ui->disposableChopstickSlider, 
                                                   disposableChopstickValue, 50.0, this, true, 0);
    disposableChopstickValueEditor->setUnit("双/周");
    
    // 初始化塑料袋值编辑器 - 整数模式
    plasticBagValueEditor = new ValueEditor(ui->plasticBagValueEdit, ui->plasticBagUnitLabel, ui->plasticBagSlider, 
                                          plasticBagValue, 100.0, this, true, 0);
    plasticBagValueEditor->setUnit("个/周");
    
    // 初始化衣物值编辑器 - 整数模式
    clothesValueEditor = new ValueEditor(ui->consumptionValueEdit, ui->consumptionUnitLabel, ui->clothesSlider, 
                                        clothesValue, 100.0, this, true, 0);
    clothesValueEditor->setUnit("件/年");
    
    // 初始化纸张值编辑器 - 整数模式
    paperValueEditor = new ValueEditor(ui->paperValueEdit, ui->paperUnitLabel, ui->paperSlider, 
                                      paperValue, 1000.0, this, true, 0);
    paperValueEditor->setUnit("张/周");
    
    // 重置所有滑块到初始位置
    ui->airplaneSlider->setValue(0);
    ui->trainSlider->setValue(0);
    ui->busSlider->setValue(0);
    ui->carSlider->setValue(0);
    ui->familyMemberSlider->setValue(1); // 默认一人
    ui->livingAreaSlider->setValue(0);
    ui->electricitySlider->setValue(0);
    ui->disposableChopstickSlider->setValue(0);
    ui->plasticBagSlider->setValue(0);
    ui->clothesSlider->setValue(0);
    ui->paperSlider->setValue(0);
}

CalculatorPage::~CalculatorPage()
{
    delete ui;
}

void CalculatorPage::updateSliderValues()
{
    // 获取滑块值，并通过ValueEditor进行转换和显示
    // 获取滑块的当前值
    if (airplaneValueEditor) {
        airplaneValue = ui->airplaneSlider->value() / airplaneValueEditor->getSliderFactor();
        airplaneValueEditor->setValue(airplaneValue);
    }
    if (trainValueEditor) {
        trainValue = ui->trainSlider->value() / trainValueEditor->getSliderFactor();
        trainValueEditor->setValue(trainValue);
    }
    if (busValueEditor) {
        busValue = ui->busSlider->value() / busValueEditor->getSliderFactor();
        busValueEditor->setValue(busValue);
    }
    if (carValueEditor) {
        carValue = ui->carSlider->value() / carValueEditor->getSliderFactor();
        carValueEditor->setValue(carValue);
    }
    if (familyMemberValueEditor) {
        familyMemberValue = ui->familyMemberSlider->value() / familyMemberValueEditor->getSliderFactor();
        familyMemberValueEditor->setValue(familyMemberValue);
    }
    if (livingAreaValueEditor) {
        livingAreaValue = ui->livingAreaSlider->value() / livingAreaValueEditor->getSliderFactor();
        livingAreaValueEditor->setValue(livingAreaValue);
    }
    if (electricityValueEditor) {
        electricityValue = ui->electricitySlider->value() / electricityValueEditor->getSliderFactor();
        electricityValueEditor->setValue(electricityValue);
    }
    if (disposableChopstickValueEditor) {
        disposableChopstickValue = ui->disposableChopstickSlider->value() / disposableChopstickValueEditor->getSliderFactor();
        disposableChopstickValueEditor->setValue(disposableChopstickValue);
    }
    if (plasticBagValueEditor) {
        plasticBagValue = ui->plasticBagSlider->value() / plasticBagValueEditor->getSliderFactor();
        plasticBagValueEditor->setValue(plasticBagValue);
    }
    if (clothesValueEditor) {
        clothesValue = ui->clothesSlider->value() / clothesValueEditor->getSliderFactor();
        clothesValueEditor->setValue(clothesValue);
    }
    if (paperValueEditor) {
        paperValue = ui->paperSlider->value() / paperValueEditor->getSliderFactor();
        paperValueEditor->setValue(paperValue);
    }
}

bool CalculatorPage::eventFilter(QObject *watched, QEvent *event)
{
    // 处理双击事件
    if (event->type() == QEvent::MouseButtonDblClick) {
        QLineEdit *lineEdit = qobject_cast<QLineEdit*>(watched);
        if (lineEdit) {
            if (lineEdit == ui->carValueEdit) {
                carValueEditor->enableEditMode();
                return true;
            } else if (lineEdit == ui->airplaneValueEdit) {
                airplaneValueEditor->enableEditMode();
                return true;
            } else if (lineEdit == ui->trainValueEdit) {
                trainValueEditor->enableEditMode();
                return true;
            } else if (lineEdit == ui->busValueEdit) {
                busValueEditor->enableEditMode();
                return true;
            } else if (lineEdit == ui->familyMemberValueEdit) {
                familyMemberValueEditor->enableEditMode();
                return true;
            } else if (lineEdit == ui->livingAreaValueEdit) {
                livingAreaValueEditor->enableEditMode();
                return true;
            } else if (lineEdit == ui->electricityValueEdit) {
                electricityValueEditor->enableEditMode();
                return true;
            } else if (lineEdit == ui->disposableChopstickValueEdit) {
                disposableChopstickValueEditor->enableEditMode();
                return true;
            } else if (lineEdit == ui->plasticBagValueEdit) {
                plasticBagValueEditor->enableEditMode();
                return true;
            } else if (lineEdit == ui->consumptionValueEdit) {
                clothesValueEditor->enableEditMode();
                return true;
            } else if (lineEdit == ui->paperValueEdit) {
                paperValueEditor->enableEditMode();
                return true;
            }
        }
    }
    
    // 处理失去焦点事件
    if (event->type() == QEvent::FocusOut) {
        QLineEdit *lineEdit = qobject_cast<QLineEdit*>(watched);
        if (lineEdit) {
            if (lineEdit == ui->carValueEdit) {
                carValueEditor->disableEditMode();
                // 不再自动计算
            } else if (lineEdit == ui->airplaneValueEdit) {
                airplaneValueEditor->disableEditMode();
                // 不再自动计算
            } else if (lineEdit == ui->trainValueEdit) {
                trainValueEditor->disableEditMode();
                // 不再自动计算
            } else if (lineEdit == ui->busValueEdit) {
                busValueEditor->disableEditMode();
                // 不再自动计算
            } else if (lineEdit == ui->familyMemberValueEdit) {
                familyMemberValueEditor->disableEditMode();
                // 不再自动计算
            } else if (lineEdit == ui->livingAreaValueEdit) {
                livingAreaValueEditor->disableEditMode();
                // 不再自动计算
            } else if (lineEdit == ui->electricityValueEdit) {
                electricityValueEditor->disableEditMode();
                // 不再自动计算
            } else if (lineEdit == ui->disposableChopstickValueEdit) {
                disposableChopstickValueEditor->disableEditMode();
                // 不再自动计算
            } else if (lineEdit == ui->plasticBagValueEdit) {
                plasticBagValueEditor->disableEditMode();
                // 不再自动计算
            } else if (lineEdit == ui->consumptionValueEdit) {
                clothesValueEditor->disableEditMode();
                // 不再自动计算
            } else if (lineEdit == ui->paperValueEdit) {
                paperValueEditor->disableEditMode();
                // 不再自动计算
            }
        }
    }
    
    return QWidget::eventFilter(watched, event);
}

void CalculatorPage::onSaveResultButtonClicked()
{
    // 先将数据保存到本地文件
    saveDataToFile();
    
    // 显示保存成功提示
    QMessageBox::information(this, "保存成功", "碳足迹计算结果已保存！");
}

void CalculatorPage::saveDataToFile()
{
    // 如果用户未登录，提示先登录
    if (currentUsername.isEmpty() || currentUsername == "默认用户") {
        QMessageBox::warning(this, "需要登录", "请先登录后再保存数据！");
        return;
    }
    
    // 创建数据存储目录
    QString dataDir = QCoreApplication::applicationDirPath() + "/data";
    QDir dir(dataDir);
    if (!dir.exists()) {
        dir.mkpath(dataDir);
    }
    
    // 用户特定的数据文件路径
    QString userFilePath = dataDir + "/carbon_data_" + currentUsername + ".json";
    QFile userFile(userFilePath);
    
    QJsonArray dataArray;
    
    // 如果文件已存在，先读取现有数据
    if (userFile.exists() && userFile.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(userFile.readAll());
        if (doc.isArray()) {
            dataArray = doc.array();
        }
        userFile.close();
    }
    
    // 创建新数据对象
    QJsonObject jsonData;
    
    // 添加基本信息
    jsonData["id"] = dataArray.size() + 1;
    jsonData["username"] = currentUsername;
    jsonData["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
    jsonData["totalCarbonFootprint"] = totalCarbonFootprint * 1000.0; // 转换为kg
    jsonData["familyMembers"] = familyMemberValue;
    
    // 添加输入参数
    QJsonObject inputsObj;
    inputsObj["airplane"] = airplaneValue;
    inputsObj["train"] = trainValue;
    inputsObj["bus"] = busValue;
    inputsObj["car"] = carValue;
    inputsObj["familyMember"] = familyMemberValue;
    inputsObj["livingArea"] = livingAreaValue;
    inputsObj["electricity"] = electricityValue;
    inputsObj["disposableChopstick"] = disposableChopstickValue;
    inputsObj["plasticBag"] = plasticBagValue;
    inputsObj["clothes"] = clothesValue;
    inputsObj["paper"] = paperValue;
    jsonData["inputs"] = inputsObj;
    
    // 添加详细排放数据
    QJsonObject detailDataObj;
    for (auto it = latestDetailData.constBegin(); it != latestDetailData.constEnd(); ++it) {
        detailDataObj[it.key()] = it.value();
    }
    jsonData["detailData"] = detailDataObj;
    
    // 添加到数据数组
    dataArray.append(jsonData);
    
    // 写入文件
    if (userFile.open(QIODevice::WriteOnly)) {
        QJsonDocument doc(dataArray);
        userFile.write(doc.toJson());
        userFile.close();
        
        qDebug() << "数据已保存到用户特定的文件:" << userFilePath;
        
        // 显示成功消息
        QMessageBox::information(this, "保存成功", "您的碳足迹数据已成功保存！");
        
        // 发送保存数据的信号，以便其他组件可以使用
        double totalCarbonFootprintKg = totalCarbonFootprint * 1000.0;
        emit saveResultRequested(totalCarbonFootprintKg, latestDetailData);
    } else {
        QMessageBox::warning(this, "保存失败", "无法保存到文件 " + userFilePath);
    }
    
    // 为了保持向后兼容，也保存一个传统格式的文件
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd_HH-mm-ss");
    QString legacyFilename = QString("%1/carbon_footprint_%2_%3.json").arg(dataDir).arg(currentUsername).arg(timestamp);
    
    QJsonObject legacyData;
    legacyData["username"] = currentUsername;
    legacyData["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
    legacyData["totalCarbonFootprint_ton"] = totalCarbonFootprint;
    legacyData["totalCarbonFootprint_kg"] = totalCarbonFootprint * 1000.0;
    legacyData["familyMembers"] = familyMemberValue;
    legacyData["inputs"] = inputsObj;
    legacyData["emissions"] = detailDataObj;
    
    QFile legacyFile(legacyFilename);
    if (legacyFile.open(QIODevice::WriteOnly)) {
        QJsonDocument legacyDoc(legacyData);
        legacyFile.write(legacyDoc.toJson());
        legacyFile.close();
    }
    
    // 保存到CSV格式的累积数据文件，便于统计
    saveDataToCSV(dataDir);
}

void CalculatorPage::saveDataToCSV(const QString &dataDir)
{
    // 用CSV格式保存累积数据，便于统计分析
    QString csvFilename = dataDir + "/carbon_footprint_data.csv";
    bool fileExists = QFileInfo::exists(csvFilename);
    
    QFile file(csvFilename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        
        // 如果文件不存在，先写入表头
        if (!fileExists) {
            stream << "日期时间,总碳排放(kg),家庭成员,交通排放(吨),家居排放(吨),消费排放(吨),";
            stream << "飞机(千米),火车(千米),公交车(千米/天),私家车(千米/天),";
            stream << "居住面积(平方米),用电量(度/月),一次性筷子(双/周),塑料袋(个/周),衣物(件/年),纸张(张/周)";
            stream << Qt::endl;
        }
        
        // 写入数据行
        QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        stream << timestamp << ",";
        stream << QString::number(totalCarbonFootprint * 1000.0, 'f', 2) << ",";
        stream << QString::number(familyMemberValue, 'f', 0) << ",";
        stream << QString::number(latestDetailData["交通排放"], 'f', 3) << ",";
        stream << QString::number(latestDetailData["家居排放"], 'f', 3) << ",";
        stream << QString::number(latestDetailData["消费排放"], 'f', 3) << ",";
        
        // 输入参数数据
        stream << QString::number(airplaneValue, 'f', 2) << ",";
        stream << QString::number(trainValue, 'f', 2) << ",";
        stream << QString::number(busValue, 'f', 2) << ",";
        stream << QString::number(carValue, 'f', 2) << ",";
        stream << QString::number(livingAreaValue, 'f', 2) << ",";
        stream << QString::number(electricityValue, 'f', 2) << ",";
        stream << QString::number(disposableChopstickValue, 'f', 2) << ",";
        stream << QString::number(plasticBagValue, 'f', 2) << ",";
        stream << QString::number(clothesValue, 'f', 2) << ",";
        stream << QString::number(paperValue, 'f', 2);
        stream << Qt::endl;
        
        file.close();
        qDebug() << "累积数据已保存到:" << csvFilename;
    } else {
        qDebug() << "无法打开累积数据文件:" << csvFilename;
    }
}

void CalculatorPage::calculateCarbonFootprint()
{
    // 定义各项排放因子（单位：吨CO₂/单位）
    const double AIRPLANE_FACTOR = 0.02166;     // 吨CO₂/千米·年
    const double TRAIN_FACTOR = 0.01524;        // 吨CO₂/千米·年
    const double BUS_FACTOR = 0.27375;          // 吨CO₂/千米·天·年
    const double CAR_FACTOR = 0.0691;           // 吨CO₂/千米·天·年
    const double ELECTRICITY_FACTOR = 0.00684;  // 吨CO₂/度·月·年
    const double LIVING_AREA_FACTOR = 0.2 / 50.0;  // 吨CO₂/平方米·年，考虑住所使用50年
    const double CHOPSTICK_FACTOR = 0.00052;    // 吨CO₂/双·周·年
    const double PLASTIC_BAG_FACTOR = 0.00026;  // 吨CO₂/个·周·年
    const double CLOTHES_FACTOR = 0.007;        // 吨CO₂/件·年
    const double PAPER_FACTOR = 0.000052;       // 吨CO₂/张·周·年
    
    // 防止除以零
    double members = (familyMemberValue > 0) ? familyMemberValue : 1.0;
    
    // 计算各项碳排放量（吨CO₂/年）
    double airplaneEmission = airplaneValue * AIRPLANE_FACTOR;
    double trainEmission = trainValue * TRAIN_FACTOR;
    double busEmission = busValue * BUS_FACTOR;
    double carEmission = carValue * CAR_FACTOR;
    double electricityEmission = electricityValue * ELECTRICITY_FACTOR;
    double livingAreaEmission = livingAreaValue * LIVING_AREA_FACTOR;
    double chopstickEmission = disposableChopstickValue * CHOPSTICK_FACTOR;
    double plasticBagEmission = plasticBagValue * PLASTIC_BAG_FACTOR;
    double clothesEmission = clothesValue * CLOTHES_FACTOR;
    double paperEmission = paperValue * PAPER_FACTOR;
    
    // 保存详细数据用于记录
    latestDetailData.clear();
    latestDetailData["飞机"] = airplaneEmission;
    latestDetailData["火车"] = trainEmission;
    latestDetailData["公交车"] = busEmission;
    latestDetailData["私家车"] = carEmission;
    latestDetailData["用电"] = electricityEmission;
    latestDetailData["居住面积"] = livingAreaEmission;
    latestDetailData["一次性筷子"] = chopstickEmission;
    latestDetailData["塑料袋"] = plasticBagEmission;
    latestDetailData["衣物"] = clothesEmission;
    latestDetailData["纸张"] = paperEmission;
    
    // 计算家庭总碳排放量并平均到个人（除以家庭人数）
    double transportEmission = (airplaneEmission + trainEmission + busEmission + carEmission) / members;
    double homeEmission = (electricityEmission + livingAreaEmission) / members;
    double consumptionEmission = (chopstickEmission + plasticBagEmission + clothesEmission + paperEmission) / members;
    
    // 计算总个人碳足迹
    totalCarbonFootprint = transportEmission + homeEmission + consumptionEmission;
    
    // 保存分类数据
    latestDetailData["交通排放"] = transportEmission;
    latestDetailData["家居排放"] = homeEmission;
    latestDetailData["消费排放"] = consumptionEmission;
    latestDetailData["总排放"] = totalCarbonFootprint;
    latestDetailData["家庭人数"] = familyMemberValue;
    
    // 更新总碳足迹显示
    ui->totalCarbonLabel->setText(QString::number(totalCarbonFootprint, 'f', 2) + " (吨)");
    
    // 计算需要多少棵树来抵消碳排放（一棵树10年吸收约0.1132吨CO₂）
    int treesNeeded = qRound(totalCarbonFootprint / 0.1132);
    ui->carbonRankLabel->setText(QString::number(treesNeeded) + " 棵树用10年来抵偿");
    
    // 更新人均碳足迹比较，使用新的全球人均值9.34吨
    if (totalCarbonFootprint > GLOBAL_PER_CAPITA_EMISSION) {
        ui->perCapitaCarbonLabel->setText("您已远超人均碳排放量");
    } else {
        ui->perCapitaCarbonLabel->setText("您的碳排放低于全球人均水平");
    }
    
    // 更新人均碳排放量显示
    ui->perCapitaTextLabel->setText(QString("全球人均每年排放CO₂ %1吨").arg(GLOBAL_PER_CAPITA_EMISSION));
}

void CalculatorPage::onCarValueEditingFinished()
{
    // 这个方法已经被ValueEditor类中的方法替代
    // 保留空实现以兼容现有代码
    calculateCarbonFootprint();
}

void CalculatorPage::onAirplaneValueEditingFinished()
{
    // 这个方法已经被ValueEditor类中的方法替代
    // 保留空实现以兼容现有代码
    calculateCarbonFootprint();
}

void CalculatorPage::on_calculateButton_clicked()
{
    // 点击计算按钮时执行计算
    calculateCarbonFootprint();
} 
