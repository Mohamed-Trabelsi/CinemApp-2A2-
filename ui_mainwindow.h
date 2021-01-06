/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *activer_bip;
    QPushButton *des_bip;
    QLabel *label;
    QLabel *label_3;
    QGroupBox *groupBox;
    QLabel *label_msg;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(450, 349);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        activer_bip = new QPushButton(centralwidget);
        activer_bip->setObjectName(QStringLiteral("activer_bip"));
        activer_bip->setGeometry(QRect(60, 130, 141, 61));
        des_bip = new QPushButton(centralwidget);
        des_bip->setObjectName(QStringLiteral("des_bip"));
        des_bip->setGeometry(QRect(240, 130, 141, 61));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 60, 291, 61));
        QFont font;
        font.setFamily(QStringLiteral("Ebrima"));
        font.setPointSize(17);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 761, 351));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/new/bg/cinemApp.jpg")));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(60, 220, 321, 71));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        groupBox->setFont(font1);
        groupBox->setAutoFillBackground(true);
        label_msg = new QLabel(groupBox);
        label_msg->setObjectName(QStringLiteral("label_msg"));
        label_msg->setGeometry(QRect(10, 20, 301, 41));
        label_msg->setAutoFillBackground(true);
        MainWindow->setCentralWidget(centralwidget);
        label_3->raise();
        activer_bip->raise();
        des_bip->raise();
        label->raise();
        groupBox->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Capteur de Mouvement Arduino", Q_NULLPTR));
        activer_bip->setText(QApplication::translate("MainWindow", "Ouvrir Porte", Q_NULLPTR));
        des_bip->setText(QApplication::translate("MainWindow", "Fermer Porte", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#00007f;\">Entr\303\251e Employ\303\251s RFID</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Statut :", Q_NULLPTR));
        label_msg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
