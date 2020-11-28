#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "servicetech.h"
#include <QMessageBox>
#include <QStackedWidget>
#include "login.h"

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





    /*void MainWindow::on_pushButton_clicked()
    {
        serviceTech d;
            d.setModal(true);
            d.exec();
    }*/


void MainWindow::on_Connect_clicked()
{
    int id=ui->ID->text().toInt();
    QString pwd=ui->PWD->text();
    ui->ID->clear();
    ui->PWD->clear();
}
