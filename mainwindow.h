#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "login.h"
#include "arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
void update_label();
private slots:


    void on_Connect_clicked();

private:
    Login templog;
    QByteArray data;
    Arduino A;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
