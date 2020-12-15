#include "Programmation.h"
#include "ui_Programmation.h"
#include "film.h"
#include "ticket.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextDocument>
QSound *sonClick;

Programmation::Programmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Programmation)
{
    ui->setupUi(this);
    ui->tableView_Film->setModel(tempFilm.afficherFilm());
    ui->tableView_Ticket->setModel(tempTicket.afficherTicket());
    sonClick=new QSound(":/new/son/Click.wav");
}

Programmation::~Programmation()
{
    delete ui;
}



void Programmation::on_pushButton_ajoutTicket_clicked()
{
    sonClick->play();
   int ID=ui->lineEdit_IDE->text().toInt();
   int NbPlaces=ui->lineEdit_NbPlaces->text().toInt();
   QString NomC=ui->lineEdit_nomC->text();
   QString DateF=ui->dateEdit->date().toString();
   QString HeureF=ui->timeEdit->time().toString();
   Ticket t(ID, NomC, NbPlaces, DateF, HeureF);
   ui->lineEdit_IDE->clear();
   ui->lineEdit_NbPlaces->clear();
   ui->lineEdit_nomC->clear();
   ui->dateEdit->clear();
   ui->timeEdit->clear();
   bool test=t.ajouterTicket();
   if (test)
   {
       ui->tableView_Ticket->setModel(tempTicket.afficherTicket());
       QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Ajout avec succès \n click cancel to exit")
               ,QMessageBox::Cancel);
   }
   else
   {
       QMessageBox::critical(nullptr,QObject::tr("Ajout"),QObject::tr("Ajout échoué \n click cancel to exit")
               ,QMessageBox::Cancel);
   }
}

void Programmation::on_pushButton_supprimerTicket_clicked()
{
    sonClick->play();
int id=ui->lineEdit_supprimerTicket->text().toInt();
ui->lineEdit_supprimerTicket->clear();
bool test = tempTicket.supprimerTicket(id);
if (test)
{
    ui->tableView_Ticket->setModel(tempTicket.afficherTicket());
    QMessageBox::information(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression avec succès \n click cancel to exit")
            ,QMessageBox::Cancel);
}
else
{
    QMessageBox::critical(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression échouée \n click cancel to exit")
            ,QMessageBox::Cancel);
}
}


void Programmation::on_pushButton_ajoutFilm_clicked()
{
    sonClick->play();
    int ID=ui->lineEdit_ID->text().toInt();
    QString nom=ui->lineEdit_Nom->text();
    int duree=ui->lineEdit_duree->text().toInt();
    QString categorie=ui->lineEdit_categorie->text();
    Film f(ID ,nom , categorie, duree);
    ui->lineEdit_ID->clear();
    ui->lineEdit_Nom->clear();
    ui->lineEdit_duree->clear();
    ui->lineEdit_categorie->clear();
    bool test=f.ajouterFilm();
    if (test)
    {
         ui->tableView_Film->setModel(tempFilm.afficherFilm());
        QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Ajout avec succés \n click cancel to exit")
                ,QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Ajout"),QObject::tr("Ajout échoué \n click cancel to exit")
                ,QMessageBox::Cancel);
    }
}

void Programmation::on_pushButton_suppFilm_clicked()
{
    sonClick->play();
    int ID=ui->lineEdit_suppFilm->text().toInt();
    ui->lineEdit_suppFilm->clear();
    bool test = tempFilm.supprimerFilm(ID);
    if (test)
    {
        ui->tableView_Film->setModel(tempFilm.afficherFilm());
        QMessageBox::information(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression avec succés \n click cancel to exit")
                ,QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Suppression"),QObject::tr("Suppression échouée \n click cancel to exit")
                ,QMessageBox::Cancel);
    }
}

void Programmation::on_pushButton_modifTicket_clicked()
{
    sonClick->play();
    int ID=ui->lineEdit_IDE->text().toInt();
    QString NomC=ui->lineEdit_nomC->text();
    QString DateF=ui->dateEdit->date().toString();
    QString HeureF=ui->timeEdit->time().toString();
    int NbPlaces=ui->lineEdit_NbPlaces->text().toInt();

Ticket t(ID,NomC,NbPlaces,DateF,HeureF);
bool test=t.modifTicket(ID);
        if(test)
        {
           ui->tableView_Ticket->setModel(tempTicket.afficherTicket());
                    QMessageBox::information(nullptr,QObject::tr("modification"),QObject::tr("modification avec succés \n click ok to exit")
                            ,QMessageBox::Ok);
                                           }
                else
                    QMessageBox::critical(nullptr,QObject::tr("modification"),QObject::tr("modification failed \n click cancel to exit")
                            ,QMessageBox::Ok);
}

void Programmation::on_pushButton_modifFilm_clicked()
{
    sonClick->play();
    int ID=ui->lineEdit_ID->text().toInt();
    QString nom=ui->lineEdit_Nom->text();
    int duree=ui->lineEdit_duree->text().toInt();
    QString categorie=ui->lineEdit_categorie->text();
    Film f(ID,nom,categorie,duree);
    ui->lineEdit_ID->clear();
    ui->lineEdit_Nom->clear();
    ui->lineEdit_duree->clear();
    ui->lineEdit_categorie->clear();
bool test=f.modifFilm(ID);
        if(test)
        {
           ui->tableView_Film->setModel(tempFilm.afficherFilm());
                    QMessageBox::information(nullptr,QObject::tr("modification"),QObject::tr("modification avec succés \n click ok to exit")
                            ,QMessageBox::Ok);
                                           }
                else
                    QMessageBox::critical(nullptr,QObject::tr("modification"),QObject::tr("modification failed \n click cancel to exit")
                            ,QMessageBox::Ok);
}


void Programmation::on_pushButton_clicked() //pdf
{
    sonClick->play();

        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM FILM ");
        q.exec();
        QString pdf="<br> <h1  style='color:red'>LISTE FILMS  <br></h1>\n <br> <table>  <tr>  <th>ID FILM </th> <th>NOM </th> <th> CATEGORIE </th><th> DUREE </th> </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"  "" " "</td> <td>" +q.value(3).toString() +"  "" " "</td> </td>" ;

        }
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
    }



void Programmation::on_pushButton_2_clicked() //imprimer
{
    sonClick->play();
    QPrinter rd;
            QPrintDialog d(&rd,this);
            d.setWindowTitle("Print Liste Films");
            d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
            if (d.exec() != QDialog::Accepted)
                return ;
}


void Programmation::on_radioButton_clicked()
{
    sonClick->play();
     ui->tableView_Film->setModel(tempFilm.trier());
}

void Programmation::on_tableView_Film_activated(const QModelIndex &index)
{
    sonClick->play();
    QString ID=ui->tableView_Film->model()->data(index).toString();
          QSqlQuery query;
          query.prepare("select * from film where IDF LIKE '"+ID+"%' or NOM LIKE '"+ID+"%' or CATEGORIE LIKE '"+ID+"%' or DUREEF LIKE '"+ID+"%'");
          if(query.exec())
          {
            while(query.next())
            {
                ui->lineEdit_ID->setText(query.value(0).toString());
                ui->lineEdit_Nom->setText(query.value(1).toString());
                ui->lineEdit_categorie->setText(query.value(2).toString());
                ui->lineEdit_duree->setText(query.value(3).toString());
            }
          }
            else
            {

                //QMessageBox::critical(this,tr("error::"),query.lastError().text());
              QMessageBox::critical(nullptr, QObject::tr("error"),
                          QObject::tr("error.\n""Click Cancel to exit."), QMessageBox::Cancel);
          }
}

void Programmation::on_pushButton_rechercheF_clicked()
{
    sonClick->play();
    QString id =ui->lineEdit_rechercheF->text();
       ui->tableView_Film->setModel(tempFilm.recherche(id));
}
