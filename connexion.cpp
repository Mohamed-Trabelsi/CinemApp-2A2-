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
    db.setDatabaseName("Projet_2a");
    db.setUserName("wiem");
    db.setPassword("wiem");
    if (db.open())
        test=true;
    else throw QString ("Erreur Parametres"+test);
    return test;
}
void Connexion::fermerConnexion()
{
    db.close();
}
