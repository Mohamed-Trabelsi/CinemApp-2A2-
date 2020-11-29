QT       += core gui sql printsupport multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    facture.cpp \
    kiosque.cpp \
    main.cpp \
    mainwindow.cpp \
    produit.cpp \
    qcustomplot.cpp

HEADERS += \
    connection.h \
    facture.h \
    kiosque.h \
    mainwindow.h \
    produit.h \
    qcustomplot.h

FORMS += \
    kiosque.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc

QMAKE_CXXFLAGS += -std=gnu++11