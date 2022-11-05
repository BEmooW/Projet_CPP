#ifndef EMPLOYES_H
#define EMPLOYES_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<ui_mainwindow.h>

class Employes
{
    QString nom,prenom,email,date_naiss,role,sexe,etat_civil;
    int CIN,tel,num_aff,matricule;
public:
    //constructeurs
    Employes();
    Employes(int,QString,QString,int,QString,int,QString,QString,QString,QString,int);
    //Getters
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    int getCIN(){return CIN;}
    //setters
    void setNom(QString n){nom=n;}
    void setPrenom(QString p){prenom=p;}
    void setCIN(int CIN){this->CIN=CIN;}
    //Fonctionnalités de base relatives à l'entité employé
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool supprimer1(int);
    bool modifier(int CIN);
    //void Employes::login_modifier_afficher_tab(ui);
    //void login_modifier_afficher_tab(Ui::MainWindow *ui);
    bool chercher(QTableView *table,int cas );

};

#endif // EMPLOYES_H
