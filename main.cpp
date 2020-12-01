#include "mainwindow.h"
#include "qdebug.h"
#include <QApplication>
#include "connection.h"
#include <QMessageBox>
int main(int argc, char *argv[])
{ connection c;
    QApplication a(argc, argv);
    MainWindow w;
    bool test=c.createCnx();
       if(test)
       {
            w.show();
           //qDebug() <<"connection reussite";
           QMessageBox::information(nullptr,QObject::tr("database is open"),QObject::tr("connection reussite \n click ok to exit")
                   ,QMessageBox::Ok);
      }
       else //qDebug() <<"erreur de connection";
           QMessageBox::critical(nullptr,QObject::tr("database is not open"),QObject::tr("connection failed \n click cancel to exit")
                   ,QMessageBox::Cancel);

    return a.exec();
}
