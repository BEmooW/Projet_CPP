#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"employes.h"
#include <QMainWindow>
#include<ui_mainwindow.h>

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
    void on_tableView_3_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_box_role_2_currentTextChanged(const QString &arg1);

    void on_le_CINa_textChanged(const QString &arg1);

    void on_le_CINs_textChanged(const QString &arg1);

    void on_comboBox_19_currentTextChanged(const QString &arg1);

    void on_comboBox_5_currentTextChanged(const QString &arg1);

    void on_pushButton_13_clicked();

    void on_pb_imprimer_clicked();

    void on_pb_envoyer_clicked();

    void on_pb_browse_clicked();

private:
    Ui::MainWindow *ui;
    Employes Emp;
};

#endif // MAINWINDOW_H
