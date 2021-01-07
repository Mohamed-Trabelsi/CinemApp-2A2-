#ifndef CLIENTETFINANCE_H
#define CLIENTETFINANCE_H

#include <QDialog>
#include "client.h"
#include "caisse.h"
#include <QSound>
namespace Ui {
class clientetfinance;
}

class clientetfinance : public QDialog
{
    Q_OBJECT

public:
    explicit clientetfinance(QWidget *parent = nullptr);
    ~clientetfinance();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();



    void on_pushButton_2_clicked();



    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_recherche_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_triercaisse_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_pdf_clicked();

    void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_8_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_excel_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_id_currentIndexChanged(int index);

    void on_comboBox_id_currentIndexChanged(const QString &arg1);

    void on_envoyer_clicked();

private:
    Ui::clientetfinance *ui;
    Client clienttemp;
     Caisse caissetemp;
      QSound *son;

};

#endif // CLIENTETFINANCE_H
