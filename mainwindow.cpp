#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "kiosque.h"
#include "produit.h"
#include "facture.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //mMediaPlayer = new QMediaPlayer(this);
   // ui->tableView->setModel(tempProduit.afficher());
   //ui->tableView_2->setModel(tempFacture.afficher());

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    kiosque d;
     d.setModal(true);
     d.exec();

}
