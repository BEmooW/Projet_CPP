#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "espace.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);









   ui->le_numsalle->setValidator (new QIntValidator (0,999, this));
   ui->le_capacite->setValidator (new QIntValidator (0,999, this));
   ui->tab_espace->setModel(E.afficher());

   QPixmap pixbg("C:/Users/Ismail Zenati/Downloads/Compressed/Atelier_Connexion_ismail/photos/backg1.png");
       int w3=ui->label_background->width(),h3=ui->label_background->height();
       ui->label_background->setPixmap(pixbg.scaled(w3,h3,Qt::KeepAspectRatio));

       QPixmap pixbg2("C:/Users/Ismail Zenati/Downloads/Compressed/Atelier_Connexion_ismail/photos/backg1.png");
           int w4=ui->label_background2->width(),h4=ui->label_background2->height();
           ui->label_background2->setPixmap(pixbg.scaled(w4,h4,Qt::KeepAspectRatio));

           QPixmap pixbg3("C:/Users/Ismail Zenati/Downloads/Compressed/Atelier_Connexion_ismail/photos/backg1.png");
               int w5=ui->label_background3->width(),h5=ui->label_background3->height();
               ui->label_background3->setPixmap(pixbg.scaled(w5,h5,Qt::KeepAspectRatio));

               QPixmap pixbg4("C:/Users/Ismail Zenati/Downloads/Compressed/Atelier_Connexion_ismail/photos/backg1.png");
                   int w6=ui->label_background4->width(),h6=ui->label_background4->height();
                   ui->label_background4->setPixmap(pixbg.scaled(w6,h6,Qt::KeepAspectRatio));

                   QPixmap pixbg5("C:/Users/Ismail Zenati/Downloads/Compressed/Atelier_Connexion_ismail/photos/etage.png");
                       int w7=ui->label_background5->width(),h7=ui->label_background5->height();
                       ui->label_background5->setPixmap(pixbg5.scaled(w7,h7,Qt::KeepAspectRatio));

                       QPixmap pixbg6("C:/Users/Ismail Zenati/Downloads/Compressed/Atelier_Connexion_ismail/photos/backg1.png");
                           int w8=ui->label_background6->width(),h8=ui->label_background6->height();
                           ui->label_background6->setPixmap(pixbg.scaled(w8,h8,Qt::KeepAspectRatio));

                        /*   QPixmap pixbg7("C:/Users/Ismail Zenati/Documents/Lightshot/backg1.png");
                               int w9=ui->label_background7->width(),h9=ui->label_background7->height();
                               ui->label_background7->setPixmap(pixbg.scaled(w9,h9,Qt::KeepAspectRatio)); */





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int numsalle=ui->le_numsalle->text().toInt();
    int capacite=ui->le_capacite->text().toInt();
    QString bloc=ui->le_bloc->text();
    QString type=ui->le_type->text();
    QString etat=ui->le_etat->text();

    Espace E(numsalle,capacite,bloc,type,etat);

    bool test=E.ajouter();
    QMessageBox msgBox;

    if(test)
    {  msgBox.setText("Ajout avec succes.");

    ui->tab_espace->setModel(E.afficher());

    }
    else
        msgBox.setText("Echec d'ajout");
        msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
  Espace E1; E1.setnumsalle(ui->le_numsalle_supp->text().toInt());
  bool test=E1.supprimer(E1.getnumsalle());
  QMessageBox msgBox;

  if(test)
  { msgBox.setText("Suppression avec succes.");

     ui->tab_espace->setModel(E.afficher());

  }
  else
      msgBox.setText("Echec de suppression");
      msgBox.exec();
}

void MainWindow::on_pb_modifier_clicked()
{
    int numsalle=ui->le_numsalle_m->text().toInt();
    int capacite=ui->le_capacite_m->text().toInt();
    QString bloc=ui->le_bloc_m->text();
    QString type=ui->le_type_m->text();
    QString etat=ui->le_etat_m->text();

    Espace E(numsalle,capacite,bloc,type,etat);


    bool test=E.modifier();


    if(test)
    {  QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("Modification avec succee\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

    ui->tab_espace->setModel(E.afficher());

    }
    else
        QMessageBox::critical(nullptr,QObject::tr(" not OK"),
                                        QObject::tr("Modification echec\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
}




/*
{
int ret=A.connect_arduino();
switch (ret)
{
   case(0):qDebug()<<"arduino is available and connected to:"<<getArduino_port_name();
        break;
    case(1):qDebug()<<"arduino is available but not connected to:"<<getArduino_port_name();
        break;
    case(-1):qDebug()<<"arduino is not available :";
}
QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
}
 */


