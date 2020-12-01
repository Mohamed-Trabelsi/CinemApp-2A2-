#include "connection.h"
#include "QSqlDatabase"
#include <QSqlError>
connection::connection()
{

}
bool connection:: createCnx(){
    bool test=false;
    QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet_2a");
    db.setUserName("wiem");
    db.setPassword("wiem");

   if (db.open())
       test=true;
   else throw QString ("erreur parametre"+test);
   return test;


}

