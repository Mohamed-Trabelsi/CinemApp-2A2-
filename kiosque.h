#ifndef KIOSQUE_H
#define KIOSQUE_H
#include "produit.h"
#include"facture.h"

#include <QDialog>
class QMediaPlayer;
namespace Ui {
class kiosque;
}

class kiosque : public QDialog
{
    Q_OBJECT

public:
    explicit kiosque(QWidget *parent = nullptr);
    ~kiosque();

private slots:

    void on_pushButton_9_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_clicked();
    void on_pushButton_S_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_14Valmodif_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_pushButton_PDF_clicked();
    //void on_pushButton_triFac_clicked();
    void on_radioButton_3_clicked();
    void on_radioButton_4_clicked();
    void on_lineEdit_14_textChanged(const QString &arg1);
    void on_pushButton_apport_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_stop_clicked();
    void on_pushButton_3_clicked();
    void on_play_clicked();
    void on_avance_valueChanged(int value);



    void on_pushButton_PDFFac_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);



    void on_radioButton_triedate_clicked();

    void on_radioButtontrigain_clicked();

private:
    Ui::kiosque *ui;
    Produit tempProduit;
    facture temFacture;
     QMediaPlayer *mMediaPlayer;
};

#endif // KIOSQUE_H
