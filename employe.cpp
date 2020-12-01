#include "employe.h"

Employe::Employe()
{

}
Employe::Employe(int i,float s)
{
    id=i;
    salaire=s;

}
void Employe:: setsalaire(float s)
{
 salaire=s;
}
bool Employe:: modifier_salaire()
{
    QSqlQuery query;
    query.prepare("update equipement set salaire=:salaire where id=:id");
    query.bindValue(":id",id);
    query.bindValue(":salaire",salaire);

    return    query.exec();
}
