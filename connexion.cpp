#include "connexion.h"
#include "QSqlDatabase"
#include <QString>
Connexion::Connexion()
{

}
bool Connexion::ouvrirConnexion()
{
    bool test=false;
    QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("cinema");
    db.setUserName("System");
    db.setPassword("system");
    if (db.open())
        test=true;
    else throw QString ("Erreur Parametres"+test);
    return test;
}
void Connexion::fermerConnexion()
{
    db.close();
}
