#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"employes.h"
#include <QMainWindow>
#include<ui_mainwindow.h>
#include "camera.h"
#include"stat_combo.h"
#include"notepad.h"
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
    //void on_pushButton_clicked();

    //void on_pushButton_2_clicked();

    void on_pb_ajouter_clicked();

    //void on_pushButton_3_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_rh_clicked();

    void on_pb_finance_clicked();

    void on_pb_client_clicked();

    void on_pb_espace_clicked();

    void on_pb_equip_clicked();

    void on_pb_afficher_clicked();
    //void login_modifier_afficher_tab();

    void on_tableView_clicked(const QModelIndex &index);





    void on_le_CINa_textChanged(const QString &arg1);

    void on_le_CINs_textChanged(const QString &arg1);

    void on_comboBox_19_currentTextChanged(const QString &arg1);

    void on_comboBox_5_currentTextChanged(const QString &arg1);



    void on_pb_imprimer_clicked();



    void  browse();

    void sendMail();

    void mailSent(QString status);

    void on_pb_camera_clicked();




    void on_tableView_rh_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pb_excel_clicked();



    void on_comboBox_rh_currentTextChanged(const QString &arg1);

    void on_le_CINa_2_textChanged(const QString &arg1);

    void on_pushButton_19_clicked();

    void on_pushButton_clicked();



    void on_tabWidget_rh_currentChanged(int index);

    void on_tabWidget_rh_tabBarClicked(int index);






    void on_notepad_clicked();

private:
    Ui::MainWindow *ui;
    Employes Emp;
    QStringList files;
    camera *c;
    notepad *n;

};

#endif // MAINWINDOW_H
