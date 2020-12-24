#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Programmation.h"
#include "film.h"
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





    void MainWindow::on_pushButton_clicked()
    {
        Programmation d;
            d.setModal(true);
            d.exec();
    }

