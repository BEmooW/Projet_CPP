#include "employes.h"
#include<QSqlQuery>
#include<QtDebug>
#include<ui_mainwindow.h>
#include<QMessageBox>

#include<iostream>
using namespace std;
Employes::Employes()
{

}
Employes::Employes(int CIN,QString nom,QString prenom,int tel,QString email,int num_aff,QString role,QString sexe,QString etat_civil,QString date_naiss,int matricule)
{
    this->CIN=CIN;
    this->nom=nom;
    this->prenom=prenom;
    this->tel=tel;
    this->email=email;
    this->num_aff=num_aff;
    this->role=role;
    this->sexe=sexe;
    this->etat_civil=etat_civil;
    this->date_naiss=date_naiss;
    this->matricule=matricule;
    //this->date_naiss=date_naiss;
}
bool Employes::ajouter()
{
   // bool test=false;
    QSqlQuery query;
   // QString CIN_string=QString::number(CIN);
          query.prepare("INSERT INTO employes (CIN, nom, prenom, num_tel, email, num_aff, role, sexe, etat_civil, matricule, date_naiss) ""VALUES (:CIN, :nom, :prenom, :num_tel, :email, :num_aff, :role, :sexe, :etat_civil, :matricule, :date_naiss)");//ken values kbal yani lezm baedha nafs l nidham mta tableau w kemlin methode 2:
          query.bindValue(":CIN", CIN);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":num_tel", tel);
          query.bindValue(":email", email);
          query.bindValue(":num_aff", num_aff);
          query.bindValue(":role", role);
          query.bindValue(":sexe", sexe);
          query.bindValue(":etat_civil", etat_civil);
          query.bindValue(":matricule", matricule);
          query.bindValue(":date_naiss", date_naiss);


          return query.exec();
    //return test;
}

QSqlQueryModel *Employes::afficher(){
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from Employes");//pour afficher un champ specifique "select champ1 champ2 from Employes" on peut choisir l'ordre , "select * from Employes" : * pour afficher kolchay

return model;
}
bool Employes::supprimer(QString CIN)
{


    QSqlQuery query;
    //QString CIN_string=QString::number(CIN);
          query.prepare("Delete from employes where CIN=:CIN");
          query.bindValue(":CIN", CIN);
          return query.exec();
}
bool Employes::supprimer1(int CIN)
{


    QSqlQuery query;
    QString CIN_string=QString::number(CIN);
          query.prepare("Delete from employes where CIN=:CIN");
          query.bindValue(":CIN", CIN);
          return query.exec();
}

bool Employes::modifier(int CIN)
{
    QSqlQuery query;
           QString res=QString::number(CIN);


             query.prepare("UPDATE employes "" SET CIN=:CIN, nom=:nom, prenom=:prenom, num_tel=:num_tel, email=:email, num_aff=:num_aff, role=:role, sexe=:sexe, etat_civil=:etat_civil, date_naiss=:date_naiss where CIN='"+res+"' ");


                   query.bindValue(":CIN", res);//bindValue=remplir(relier) la valeur de la requette sql à partir de qt  d'une maniere sécurisée
                   query.bindValue(":nom", nom);
                   query.bindValue(":prenom", prenom);
                   query.bindValue(":num_tel", tel);
                   query.bindValue(":email", email);
                   query.bindValue(":num_aff", num_aff);
                   query.bindValue(":role", role);
                   query.bindValue(":sexe", sexe);
                   query.bindValue(":etat_civil", etat_civil);
                   query.bindValue(":date_naiss", date_naiss);


               return query.exec();
}
bool Employes ::chercher(QTableView *table,int CIN )
     {
         QSqlQueryModel *model= new QSqlQueryModel();

         QSqlQuery *query=new QSqlQuery;
         QString CIN_string=QString::number(CIN);

         query->prepare("SELECT * FROM employes WHERE (reference  LIKE "+CIN_string+  ")");
         query->exec();

         if(query->exec())
         {
         model->setQuery(*query);
         table->setModel(model);
         table->show();
         return true;
         }


         if(query->numRowsAffected()==0)
         {

            QMessageBox::warning(nullptr, QObject::tr("database is open"),
                        QObject::tr("employe introuvable .\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            return false;

       }

     }




//tri : ask:ordre croissant /desc:ordre decroissant
//methode 2 selectionner l tableview et cocher sorting enabled
