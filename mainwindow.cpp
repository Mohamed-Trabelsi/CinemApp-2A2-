#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "servicetech.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QSound>
#include "login.h"
#include<QSqlQueryModel>
#include<QSqlQuery>
#include "arduino.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*int ret = A.connectArduino();
    switch (ret)
    {
    case(0):
        qDebug()<<"arduino is available and connected to : "<<A.getarduino_port_name();
        break;
    case(1):
        qDebug()<<"arduino is available but not connected to: "<<A.getarduino_port_name();
        break;
    case(-1):
        qDebug()<<"arduino is not available";
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::update_label()
{
    data=A.read_from_arduino();
    if (data=="1")
    {
       QMessageBox::information(this,"Entrer","Welcome Mohamed");
    }
    else if (data=="2")
    {
       QMessageBox::information(this,"Entrer","Welcome Yosri");
    }

}
void MainWindow::on_Connect_clicked()
{
QSqlQuery query;
int id=ui->ID->text().toInt();
QString mdp=ui->PWD->text();
ui->ID->clear();
ui->PWD->clear();
if (templog.connect(id,mdp)==1)
{
    QMessageBox::information(this,"connecter","Welcome to CinemApp");
    serviceTech d;
        d.setModal(true);
        d.exec();
}
else
{
 QMessageBox::critical(this,"Login failed","incorrect id or pwd");
}
}
