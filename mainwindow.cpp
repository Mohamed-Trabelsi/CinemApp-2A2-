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
#include "clientetfinance.h"
#include "kiosque.h"
#include "Programmation.h"
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




    /*void MainWindow::on_Connect_clicked()
    {
        serviceTech d;
            d.setModal(true);
            d.exec();
        ui->stackedWidget->setCurrentIndex(2);
    }*/


void MainWindow::on_connect_clicked()
{

    MainWindow C;
        C.setid(ui->ID->text());
        C.setmdp(ui->PWD->text());
        ui->ID->setText(C.getid());
        ui->PWD->setText(C.getmdp());
        if((C.getid()=="1"&&C.getmdp()=="1")||(C.getid()=="2"&&C.getmdp()=="2")||(C.getid()=="3"&&C.getmdp()=="3")||(C.getid()=="4"&&C.getmdp()=="4"))
        {
            serviceTech d;
                d.setModal(true);
                d.exec();
        }
        else
            QMessageBox::information(this,"conecter","id ou mdp incorrect");
        ui->ID->clear();
        ui->PWD->clear();
QSqlQuery query;
int id=ui->ID->text().toInt();
QString mpd=ui->PWD->text();
Login c(id,mdp);
ui->ID->clear();
ui->PWD->clear();
int test=c.connect();
if (test==1)
{
    QMessageBox::information(this,"connecter","welcome");
    //serviceTech d;
        //d.setModal(true);
        //d.exec();
    ui->stackedWidget->setCurrentIndex(1);
}
else
{
 QMessageBox::critical(this,"connecter","id ou mdp incorrrecte");
}
}




/*void MainWindow::on_connect_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);
}
*/


void MainWindow::on_hama_clicked()
{
    serviceTech d;
        d.setModal(true);
        d.exec();
}

void MainWindow::on_wiem_clicked()
{
   clientetfinance c;
        c.setModal(true);
        c.exec();
}

void MainWindow::on_farah_clicked()
{
   kiosque k;
         k.setModal(true);
         k.exec();
}

void MainWindow::on_prog_clicked()
{ Programmation p;
    p.setModal(true);
    p.exec();

}
