#include "client.h"

Client::Client(int cin,int num, QString nom, QString prenom, QString mail)
{
    this->cin=cin;
    this->num=num;
    this->nom=nom;
    this->prenom=prenom;
    this->mail=mail;
}

bool Client::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(cin);

    query.prepare("insert into client(nom,prenom,cin,num,mail)" "values(:nom,:prenom,:cin,:num,:mail)");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":cin",res);
    query.bindValue(":num",num);
    query.bindValue(":mail",mail);

    return query.exec();
}

QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel  * model=new QSqlQueryModel();
    model->setQuery("select * from client");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("num"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse mail"));

    return model;
}

bool Client::supprimer(int cin)
{
    QSqlQuery query;
    QString res=QString::number(cin);

    query.prepare("delete from client where cin= :cin");
    query.bindValue(":cin",res);

    return query.exec();
}

bool Client::modifier()
{
    QSqlQuery query;
    QString res = QString::number(cin);

    query.prepare("UPDATE client SET nom=:nom, prenom=:prenom,num=:num, mail=:mail WHERE cin=:cin" );

    query.bindValue(":cin",res);
    query.bindValue(":num",num);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":mail",mail);

    return query.exec();
}


// Metiers

QSqlQueryModel * Client::rechercherNom(QString nom)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from client where nom like '" +nom+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("num"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse mail"));

    return model;
}

QSqlQueryModel * Client::triNom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from client order by nom");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("num"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse mail"));

    return model;
}


