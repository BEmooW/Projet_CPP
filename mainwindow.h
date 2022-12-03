#ifndef MainWindow_H
#define MainWindow_H
#include "client.h"
#include "histo.h"
#include <QMainWindow>
#include <QMessageBox>
#include<QString>
#include<QtWidgets>
#include<QTableView>
#include <QDialog>
#include<QAbstractItemModel>
#include<QString>
#include<QMessageBox>
#include<QTableView>
#include<QSqlQueryModel>
#include <QDialog>
#include <QAbstractItemModel>
#include <QMainWindow>
#include <QFileDialog>
#include <QMainWindow>
#include <QVariant>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouterClient_4_clicked();
    void on_supprimerClient_4_clicked();
    void on_modifierClient_4_clicked();
    void on_rechercherClient_4_clicked();
    void on_tri_clicked();
    void on_afficherHisto_clicked();
    void on_pdf_6_clicked();
    void on_plus_clicked();
    void on_tricard_clicked();


private:
    Ui::MainWindow *ui;
    Client Etmp;
    QStringList files;
    histo histor;
    histo histor1;
    histo histor2;
    QByteArray data; // variable contenant les données reçues
signals:
    void setCenter(QVariant, QVariant);
    void addMarker(QVariant, QVariant);
};

#endif // MainWindow_H
