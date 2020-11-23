#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "servicetech.h"
#include "employe.h"
#include <QMessageBox>
#include <QStackedWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setid(QString s){id=s;}
void MainWindow::setmdp(QString s){mdp=s;}
QString MainWindow::getid(){return id;}
QString MainWindow::getmdp(){return mdp;}




    /*void MainWindow::on_pushButton_clicked()
    {
        serviceTech d;
            d.setModal(true);
            d.exec();
    }*/


void MainWindow::on_Connect_clicked()
{
    MainWindow C;
        C.setid(ui->lineEdit->text());
        C.setmdp(ui->lineEdit_2->text());
        ui->lineEdit->setText(C.getid());
        ui->lineEdit_2->setText(C.getmdp());
        if((C.getid()=="1"&&C.getmdp()=="1")||(C.getid()=="2"&&C.getmdp()=="2")||(C.getid()=="3"&&C.getmdp()=="3")||(C.getid()=="4"&&C.getmdp()=="4"))
        {
            serviceTech d;
                d.setModal(true);
                d.exec();
        }
        else
            QMessageBox::information(this,"conecter","id ou mdp incorrect");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
}
