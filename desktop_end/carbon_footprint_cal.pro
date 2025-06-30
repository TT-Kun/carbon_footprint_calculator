QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutpage.cpp \
    calculatorpage.cpp \
    chartpage.cpp \
    datapage.cpp \
    main.cpp \
    mainwindow.cpp \
    userpage.cpp

HEADERS += \
    aboutpage.h \
    calculatorpage.h \
    chartpage.h \
    datapage.h \
    mainwindow.h \
    userpage.h

FORMS += \
    aboutpage.ui \
    calculatorpage.ui \
    chartpage.ui \
    datapage.ui \
    mainwindow.ui \
    userpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
