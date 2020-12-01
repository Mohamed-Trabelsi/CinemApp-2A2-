#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H
#include "film.h"
#include "ticket.h"
#include <QDialog>
#include <QSound>
namespace Ui {
class Programmation;
}

class Programmation : public QDialog
{
    Q_OBJECT

public:
    explicit Programmation(QWidget *parent = nullptr);
    ~Programmation();

private slots:


    void on_pushButton_ajoutTicket_clicked();

    void on_pushButton_supprimerTicket_clicked();

    void on_pushButton_ajoutFilm_clicked();

    void on_pushButton_suppFilm_clicked();

    void on_pushButton_modifTicket_clicked();

    void on_pushButton_modifFilm_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

    void on_tableView_Film_activated(const QModelIndex &index);

    void on_pushButton_rechercheF_clicked();

private:
    Ui::Programmation *ui;
    Film tempFilm;
    Ticket tempTicket;
};

#endif // PROGRAMMATION_H
