#include "mainwindow.h"
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion C;
    bool test=C.ouvrirConnexion();
    MainWindow w;
    if (test)
    { w.show();
        QMessageBox::information(nullptr,QObject::tr("database is not open"),QObject::tr("connection succesful \n click cancel to exit")
                ,QMessageBox::Cancel);
    }
              else
                  QMessageBox::critical(nullptr,QObject::tr("database is not open"),QObject::tr("connection failed \n click cancel to exit")
                          ,QMessageBox::Cancel);
 return a.exec();
}
