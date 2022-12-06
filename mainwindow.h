#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"equipement.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QEvent>
#include "arduino.h"




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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pb_ajouter_clicked();

    //void on_pushButton_3_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pushButton_rechercher_clicked();

    void on_pushButton_trier_clicked();

    void on_pushButton_PDF_clicked();

    void on_calendarWidget_clicked(const QDate &date);
    /*void sendMail();
    void mailSent(QString);*/
    void browse();


    void on_sendBtn_2_clicked();






    void on_qrcodegen_clicked();
    void on_statsmed_clicked();
    void on_pushButton_stats_clicked();

    void on_qrcodegen_2_clicked();

    void on_pushButton_trier_2_clicked();


    void show_from_arduino();
    void on_pushButton_lcd_clicked();
    void on_pushButton_lcd_2_clicked();
    void on_pushButton_lcd_3_clicked();
    void on_pushButton_lcd_4_clicked();
    void on_pushButton_lcd_5_clicked();

    void on_pushButton_lcd_6_clicked();

private:
    Ui::MainWindow *ui;
    Equipement E;
    Equipement *EP;
     QStringList files;
       Arduino A;
     QByteArray data;




};

#endif // MAINWINDOW_H
