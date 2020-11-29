#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "kiosque.h"
#include "ui_kiosque.h"
#include "produit.h"
#include"facture.h"
#include <QMessageBox>
#include"QIntValidator"
#include <QDateEdit>
#include <QPlainTextEdit>
#include <QPrinter>
#include <QPrinterInfo>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include "qcustomplot.h"
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QMediaPlayer>
#include <strstream>
kiosque::kiosque(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kiosque)
{
    ui->setupUi(this);
    mMediaPlayer = new QMediaPlayer(this);
       connect(mMediaPlayer,& QMediaPlayer::positionChanged,[&](qint64 pos){
           ui->avance->setValue(pos);
       });
       connect(mMediaPlayer,& QMediaPlayer::durationChanged,[&] (quint64 dur)
       {
           ui->avance->setMaximum(dur);
       });
    ui->LineEditid_prod->setValidator(new QIntValidator(0,99999,this));//idajout_produit//
    ui->lineEdit->setValidator(new QIntValidator(0,99999,this));//idsuppproduit//
    ui->lineEdit_5->setValidator(new QIntValidator(0,99999,this));
    ui->lineEdit_6->setValidator(new QIntValidator(0,99999,this));//idsupp_facture
    Produit tempProduit;
    facture temFacture;
    //***///
     ui->comboBox->setModel(tempProduit.afficher());
     ui->comboBox_3->setModel(tempProduit.afficher());
     ui->comboBox_2->setModel(temFacture.afficher());
     ui->comboBox_4->setModel(temFacture.afficher());
    ui->tableView->setModel(tempProduit.afficher());
    ui->tableView_2->setModel(temFacture.afficher());
}

kiosque::~kiosque()
{
    delete ui;
}

void kiosque::on_pushButton_9_clicked()
{
    int identifiant=ui->LineEditid_prod->text().toInt();
    QString nom=ui->LineEditnom_produit->text();//nomproduit//
   // QString categorie=ui->LineEditcategorie_produit->text();//categorieproduit//
    QString categorie;
    bool C=ui->radioButton->isChecked();
    if (C)
    { categorie="local";
    }
    else categorie="importe";


    int quantite=ui->LineEdit_17->text().toInt();//quantiteproduit//
    int prix=ui->LineEdit_18->text().toInt();

    Produit P( identifiant,nom, categorie,quantite,prix);
    bool test=P.ajouter();
    if (test)
    {
        ui->tableView->setModel(tempProduit.afficher());
          //int gain=calcul();
        QMessageBox::information(nullptr, QObject::tr("Ajout produit"),
                    QObject::tr("produit ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->comboBox->setModel(tempProduit.afficher());


    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajout produit"),
                    QObject::tr("ajout echoué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

 }


void kiosque::on_pushButton_19_clicked()//suppproduit//
{
    //int identifiant=ui->lineEdit_29->text().toInt();
 int identifiant=ui->comboBox_3->currentText().toInt();
    bool test=tempProduit.supprimer(identifiant);
    if (test)
    {
        ui->tableView->setModel(tempProduit.afficher());
        QMessageBox::information(nullptr, QObject::tr("suppression produit"),
                    QObject::tr("produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->comboBox->setModel(tempProduit.afficher());


    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("suppression produit"),
                    QObject::tr("supression echouée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
}


void kiosque::on_pushButton_12_clicked()
{
    //int identifiant=ui->lineEdit_35->text().toInt();
    int identifiant=ui->comboBox->currentText().toInt();
        QString nom= ui->lineEdit_25->text();
      //QString nom=ui->comboBox_2->currentText();
       QString categorie= ui->lineEdit_5Produit->text();
       int quantite = ui->lineEdit_26->text().toInt();
       int prix = ui->LineEdit_19->text().toInt();
        Produit P( identifiant,nom,categorie,quantite,prix);

      bool test=P.modifier(identifiant);
      if(test)
    {
          ui->comboBox->setModel(P.afficher());

          ui->tableView->setModel(P.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("modifier un produit"),
                      QObject::tr("Produit modifié.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("modifier un produit"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}


//------------------------------------FACTURE----------------------------------------------//

void kiosque::on_pushButton_clicked()
{
    int numfacture=ui->lineEdit->text().toInt();
    QString datefacture=ui->dateEdit->text();
    int prixachat=ui->lineEdit_5->text().toInt();
    int prixvente=ui->lineEdit_6->text().toInt();
    facture F(numfacture,datefacture,prixachat,prixvente);
    bool test=F.ajouter();
    if (test)
    {
        ui->tableView_2->setModel(temFacture.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajout facture"),
                    QObject::tr("facture  ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajout facture"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

}


void kiosque::on_pushButton_S_clicked()
{
   // int numfacture=ui->lineEdit_11->text().toInt();
    int numfacture=ui->comboBox_4->currentText().toInt();
    bool test=temFacture.supprimer(numfacture);
    if (test)
    {
        ui->tableView_2->setModel(temFacture.afficher());
        QMessageBox::information(nullptr, QObject::tr("suppression facture"),
                    QObject::tr("facture supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("suppression facture"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
}


void kiosque::on_pushButton_14Valmodif_clicked()
{
    //int numfacture=ui->lineEdit_2->text().toInt();
    int numfacture =ui->comboBox_2->currentText().toInt();
    QString date=ui->dateEdit_5->date().toString();
    int prixachat=ui->lineEdit_9->text().toInt();
    int prixvente=ui->lineEdit_10->text().toInt();

        facture F( numfacture,date,prixachat,prixvente);
//*******//
      bool test=F.modifier(numfacture);
      if(test)
    {
          ui->comboBox_2->setModel(F.afficher());
          ui->tableView_2->setModel(F.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("modifier une facture"),
                      QObject::tr("Facture modifiée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("modifier une facture"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}

//----------------------Statistiques produit-----------------//
void kiosque::on_tabWidget_currentChanged(int index)
{
    // set dark background gradient:
              QLinearGradient gradient(0, 0, 0, 400);
              gradient.setColorAt(0, QColor(90, 90, 90));
              gradient.setColorAt(0.38, QColor(105, 105, 105));
              gradient.setColorAt(1, QColor(70, 70, 70));
              ui->plot->setBackground(QBrush(gradient));


              // create empty bar chart objects:
              QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
              amande->setAntialiased(false);
              amande->setStackingGap(1);
               //set names and colors:
              amande->setName("Repartition des produit selon quantite ");
              amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
              amande->setBrush(QColor(0, 168, 140));
              // stack bars on top of each other:

              // prepare x axis with country labels:
              QVector<double> ticks;
              QVector<QString> labels;
              tempProduit.statistique(&ticks,&labels);

              QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
              textTicker->addTicks(ticks, labels);
              ui->plot->xAxis->setTicker(textTicker);
              ui->plot->xAxis->setTickLabelRotation(60);
              ui->plot->xAxis->setSubTicks(false);
              ui->plot->xAxis->setTickLength(0, 4);
              ui->plot->xAxis->setRange(0, 8);
              ui->plot->xAxis->setBasePen(QPen(Qt::white));
              ui->plot->xAxis->setTickPen(QPen(Qt::white));
              ui->plot->xAxis->grid()->setVisible(true);
              ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
              ui->plot->xAxis->setTickLabelColor(Qt::white);
              ui->plot->xAxis->setLabelColor(Qt::white);

              // prepare y axis:
              ui->plot->yAxis->setRange(0,10);
              ui->plot->yAxis->setPadding(5); // a bit more space to the left border
              ui->plot->yAxis->setLabel("Statistiques");
              ui->plot->yAxis->setBasePen(QPen(Qt::white));
              ui->plot->yAxis->setTickPen(QPen(Qt::white));
              ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
              ui->plot->yAxis->grid()->setSubGridVisible(true);
              ui->plot->yAxis->setTickLabelColor(Qt::white);
              ui->plot->yAxis->setLabelColor(Qt::white);
              ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
              ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

              // Add data:

              QVector<double> PlaceData;
              QSqlQuery q1("select QUANTITE from produit");
              while (q1.next()) {
                            int  nbr_fautee = q1.value(0).toInt();
                            PlaceData<< nbr_fautee;
                              }
              amande->setData(ticks, PlaceData);
              // setup legend:
              ui->plot->legend->setVisible(true);
              ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
              ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
              ui->plot->legend->setBorderPen(Qt::NoPen);
              QFont legendFont = font();
              legendFont.setPointSize(5);//888//
              ui->plot->legend->setFont(legendFont);
              ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


}

void kiosque::on_radioButton_3_clicked()//tri produit//
{
    ui->tableView->setModel(tempProduit.trie_produitN());
}

void kiosque::on_radioButton_4_clicked()
{
     ui->tableView->setModel(tempProduit.trie_produitQ());
}




//------------------TRIFACTURE----------------//
void kiosque::on_radioButton_triedate_clicked()
{
     ui->tableView_2->setModel(temFacture.trie_facture());
}

void kiosque::on_radioButtontrigain_clicked()
{
     //ui->tableView_2->setModel(temFacture.trie_factureP());
    ui->tableView_2->setModel(temFacture.trie_factureP());
}

//----------------------PDF PRODUIT--------------------------------------------
void kiosque::on_pushButton_PDF_clicked()
{

    QSqlDatabase db;
                QTableView table_produit;
                QSqlQueryModel * Modal=new  QSqlQueryModel();

                QSqlQuery qry;
                 qry.prepare("SELECT * FROM PRODUIT ");
                 qry.exec();
                 Modal->setQuery(qry);
                 table_produit.setModel(Modal);



                 db.close();


                 QString strStream;
                 QTextStream out(&strStream);


                 const int rowCount = table_produit.model()->rowCount();
                 const int columnCount =  table_produit.model()->columnCount();


                 const QString strTitle ="Document";


                 out <<  "<html>\n"
                         "<img src='C:/Users/ASUS/Documents/kiosqueK/logocin.png' height='120' width='120'/>"
                     "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         "<img src='e-care.png'>"
                     <<  QString("<title>%1</title>\n").arg(strTitle)
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"
                    << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des produits")
                    <<"<br>"

                    <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                 out << "<thead><tr bgcolor=#f0f0f0>";
                 for (int column = 0; column < columnCount; column++)
                     if (!table_produit.isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(table_produit.model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!table_produit.isColumnHidden(column)) {
                             QString data = table_produit.model()->data(table_produit.model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table>\n"
                         "<br><br>"
                         <<"<br>"
                         <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                     out << "<thead><tr bgcolor=#f0f0f0>";

                         out <<  "</table>\n"

                     "</body>\n"
                     "</html>\n";

                 QTextDocument *document = new QTextDocument();
                 document->setHtml(strStream);

                 QPrinter printer;
                 QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                 if (dialog->exec() == QDialog::Accepted) {

                     QLabel lab;
                      QPixmap pixmap(":/img/aze.png");
                     lab.setPixmap(pixmap);
                     QPainter painter(&lab);
                     //QPrinter printer(QPrinter::PrinterResolution);

                     //pixmap.load("aze.png");
                     //painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
                     //painter.drawPixmap(10,10,50,50, pixmap);

                     document->print(&printer);
                 }

                 printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                 printer.setOutputFileName("/tmp/produit.pdf");
                 printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                 delete document;
}



void kiosque::on_lineEdit_14_textChanged(const QString &arg1)
{
    QString q = arg1;

                if (q=="")
                {
                    ui->tableView->setModel(tempProduit.afficher());
                }
                else {
                  ui->tableView->setModel(tempProduit.rechercher(q)) ;


                }
}
//-------------son///
void kiosque::on_pushButton_apport_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,"pushButton_apport");
        if(filename.isEmpty()){
            return;
        }
        mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
        mMediaPlayer->setVolume(ui->volume->value());
               on_play_clicked();
}

/*void kiosque::on_pushButton_6_clicked()//play //
{
   mMediaPlayer->play();
}*/

void kiosque::on_pushButton_5_clicked()
{

   mMediaPlayer->pause();
}

void kiosque::on_pushButton_stop_clicked()
{
    mMediaPlayer->stop();
}

void kiosque::on_pushButton_3_clicked()
{
    if(ui->mute->text()=="mute")
        {
            mMediaPlayer->setMuted(true);
            ui->mute->setText("unMute");
        }
        mMediaPlayer->setMuted(false);
        ui->mute->setText("Mute");
    }


/*void kiosque::on_volume_actionTriggered(int action)
{
     mMediaPlayer->setVolume(action);
}*/

void kiosque::on_play_clicked()
{
     mMediaPlayer->play();
}

void kiosque::on_avance_valueChanged(int value)
{
      mMediaPlayer->setVolume(value);
}



//-------------------PDF_Facture-------------------------//
void kiosque::on_pushButton_PDFFac_clicked()
{
    QSqlDatabase db;
                QTableView table_facture;
                QSqlQueryModel * Modal=new  QSqlQueryModel();

                QSqlQuery qry;
                 qry.prepare("SELECT * FROM FACTURE ");
                 qry.exec();
                 Modal->setQuery(qry);
                 table_facture.setModel(Modal);



                 db.close();


                 QString strStream;
                 QTextStream out(&strStream);


                 const int rowCount = table_facture.model()->rowCount();
                 const int columnCount =  table_facture.model()->columnCount();


                 const QString strTitle ="Document";


                 out <<  "<html>\n"
                         "<img src='C:/Users/ASUS/Documents/kiosqueK/logocin.png' height='120' width='120'/>"
                     "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         "<img src='e-care.png'>"
                     <<  QString("<title>%1</title>\n").arg(strTitle)
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"
                    << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des factutres")
                    <<"<br>"

                    <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                 out << "<thead><tr bgcolor=#f0f0f0>";
                 for (int column = 0; column < columnCount; column++)
                     if (!table_facture.isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(table_facture.model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!table_facture.isColumnHidden(column)) {
                             QString data = table_facture.model()->data(table_facture.model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table>\n"
                         "<br><br>"
                         <<"<br>"
                         <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                     out << "<thead><tr bgcolor=#f0f0f0>";

                         out <<  "</table>\n"

                     "</body>\n"
                     "</html>\n";

                 QTextDocument *document = new QTextDocument();
                 document->setHtml(strStream);

                 QPrinter printer;
                 QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                 if (dialog->exec() == QDialog::Accepted) {

                     QLabel lab;
                      QPixmap pixmap(":/img/aze.png");
                     lab.setPixmap(pixmap);
                     QPainter painter(&lab);
                     //QPrinter printer(QPrinter::PrinterResolution);

                     //pixmap.load("aze.png");
                     //painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
                     //painter.drawPixmap(10,10,50,50, pixmap);

                     document->print(&printer);
                 }

                 printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                 printer.setOutputFileName("/tmp/facture.pdf");
                 printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                 delete document;

}

void kiosque::on_lineEdit_2_textChanged(const QString &arg1)//recherche facture //
{
    QString q = arg1;

                if (q=="")
                {
                    ui->tableView_2->setModel(temFacture.afficher());
                }
                else {
                  ui->tableView_2->setModel(temFacture.rechercher(q)) ;

                }
}





