#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produit.h"
#include "facture.h"
#include <QSound>
#include <QMainWindow>

QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QMediaPlayer;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Produit tempProduit;
    facture temFacture;
    QMediaPlayer *mMediaPlayer;
    QSound *son;

};
#endif // MAINWINDOW_H
