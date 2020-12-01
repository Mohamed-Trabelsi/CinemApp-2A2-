#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employe
{
public:
    Employe();
    Employe(int i,float s);
    void  setsalaire(float s);
    bool  modifier_salaire();
private :
    int id;
    QString nom;
    float salaire;
};

#endif // EMPLOYE_H
