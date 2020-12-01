QT       += core gui sql printsupport
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    caisse.cpp \
    client.cpp \
    clientetfinance.cpp \
    connection.cpp \
    excel.cpp \
    main.cpp \
    mainwindow.cpp \
    notification.cpp \
    qcustomplot.cpp \


HEADERS += \
    caisse.h \
    client.h \
    clientetfinance.h \
    connection.h \
    excel.h \
    mainwindow.h \
    notification.h \
    qcustomplot.h \


FORMS += \
    clientetfinance.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    cinemapp.qrc \
    logo.qrc

DISTFILES += \
    ../logocin.png
