#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "histo.h"
#include "WebAxWidget.h"
#include <QMessageBox>
#include <QDate>
#include <QIntValidator>
#include <QRegExpValidator>
#include <QDebug>
#include<QWidget>
#include <QTextDocument>
#include <QTextEdit>
#include <fstream>
#include <QTextStream>
#include <QRadioButton>
#include <QFileDialog>
#include <QPixmap>
#include <QPainter>
#include <QtSvg/QSvgRenderer>
#include <QtSvg/QSvgGenerator>
#include <QDirModel>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QAbstractPrintDialog>
#include <QDirModel>
#include <QtPrintSupport/QPrintDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QErrorMessage>
#include <QFile>
#include <QDataStream>
#include <QQuickItem>
#include <QAxBase>
#include <QVariant>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);
    // QObject::connect(ui->affichageClient_3,&QTableView::clicked,this,&MainWindow::on_affichageClient_3_clicked);
     ui->affichageClient->setModel(Etmp.afficher());
     // Controle saisie
     QRegExp rx("[A-Z][a-z]{0,30}");
     QRegExp rxM("[a-z]{0,10}@[a-z]{0,10}.[a-z]{0,10}");
     ui->ajouter_nom_4->setValidator(new QRegExpValidator(rxM,this));
     ui->ajouter_prenom_4->setValidator(new QRegExpValidator(rxM,this));
     ui->ajouter_cin_4->setValidator(new QIntValidator(0,99999999,this));
     ui->ajouter_num_4->setValidator(new QIntValidator(0,99999999,this));
     ui->ajouter_adresseMail_4->setValidator(new QRegExpValidator(rxM,this));
     ui->WebBrowser_2->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");
     QSettings settings(QSettings::IniFormat, QSettings::UserScope,
     QCoreApplication::organizationName(), QCoreApplication::applicationName());

         QBarSet *set0 = new QBarSet("num");
         *set0 << 1 << 2 << 3 ;
         QBarSeries *series = new QBarSeries();
         series->append(set0);
         QChart *chart = new QChart();
         chart->addSeries(series);
         chart->setTitle("statistiques des numeros de telph");
         chart->setAnimationOptions(QChart::SeriesAnimations);
         QStringList categories;
         categories << "orange" << "ooredoo" << "telecom" ;
         QBarCategoryAxis *axis = new QBarCategoryAxis();
         axis->append(categories);
         chart->createDefaultAxes();
         chart->setAxisX(axis, series);
         QChartView *chartView = new QChartView(chart);
         chartView->setParent(ui->horizontalFrame);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouterClient_4_clicked()
{
        QString nom=ui->ajouter_nom_4->text();
        QString prenom=ui->ajouter_prenom_4->text();
        int res=ui->ajouter_cin_4->text().toInt();
        int num_tel=ui->ajouter_num_4->text().toInt();
        QString adresse_mail=ui->ajouter_adresseMail_4->text();
        Client c(res,num_tel,nom, prenom, adresse_mail);
        bool test=c.ajouter();
        if(test)
        {
            ui->affichageClient->setModel(Etmp.afficher());  //Actualiser
            QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué! \n" "Click cancel to exit"),QMessageBox::Cancel);
            histor.save("cin :"+ui->ajouter_cin_4->text(),"num_tel :"+ui->ajouter_num_4->text(),"nom :"+ui->ajouter_nom_4->text(),"prenom :"+ui->ajouter_prenom_4->text(),"adresse mail :"+ui->ajouter_adresseMail_4->text());
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effectué! \n" "Click cancel to exit"),QMessageBox::Cancel);
        }
}


void MainWindow::on_supprimerClient_4_clicked()
{
    int cin =ui->cinClient_8->text().toInt();
    bool test=Etmp.supprimer(cin);

    if(test)
    {
        ui->affichageClient->setModel(Etmp.afficher());  //Actualiser

        QMessageBox::information(nullptr,QObject::tr("OK"), QObject::tr("Suppression effectuée \n" "Click cancel to exit"), QMessageBox::Cancel);
        histor1.save1("SUPPRIMER","cin :"+ui->cinClient_8->text());

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"), QObject::tr("Suppression non effectuée \n" "Click cancel to exit"), QMessageBox::Cancel);
    }
}


void MainWindow::on_modifierClient_4_clicked()
{
    QString nom=ui->modifier_nom_4->text();
    QString prenom=ui->modifier_prenom_4->text();
    int res=ui->cinClient_8->text().toInt();
    int num_tel=ui->num_8->text().toInt();
    QString adresse_mail=ui->modifier_adresseMail_4->text();
    int card=ui->num_8->text().toInt();
    Client c(res,num_tel,nom, prenom, adresse_mail);
    bool test=c.modifier();
    if(test)
    {
        ui->affichageClient->setModel(Etmp.afficher());  //Actualiser
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectuée! \n" "Click cancel to exit"),QMessageBox::Cancel);
        histor.save2("SUPPRIMER","cin :"+ui->cinClient_8->text(),"num_tel :"+ui->num_8->text(),"nom :"+ui->modifier_nom_4->text(),"prenom :"+ui->modifier_prenom_4->text(),"adresse mail :"+ui->modifier_adresseMail_4->text());
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Modification non effectuée! \n" "Click cancel to exit"),QMessageBox::Cancel);
    }

}

//Metiers

void MainWindow::on_rechercherClient_4_clicked()
{
    QString nom=ui->recherche_4->text();
    if(nom=="")
    {
        QMessageBox::information(nullptr,QObject::tr("Champ vide"),QObject::tr("Veuiller insérer un NOM!"),QMessageBox::Cancel);
        ui->affichageClient->setModel(Etmp.afficher());
    }
    else
    {
        ui->affichageClient->setModel(Etmp.rechercherNom(nom));
    }
}


void MainWindow::on_afficherHisto_clicked()
{
    QFile file("C:/Users/MSI/Desktop/interfacechedly/historique.txt");
        if (!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"info",file.errorString());
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());
}

void MainWindow::on_tri_clicked()
{
    ui->affichageClient->setModel(Etmp.triNom());
}


void MainWindow::on_pdf_6_clicked()
{
            QPrinter printer;
            printer.setPrinterName("Printer Name");

            QPrintDialog pDialog(&printer, this);

            if(pDialog.exec() == QDialog::Rejected){
                QMessageBox::warning(this, "Warning", "Cannot Access Printer");
                return;
            }
            ui->affichageClient->render(&printer);

}

/*
void MainWindow::on_plus_clicked()
{
    QString nom=ui->recherche_5->text();
    QString prenom=prenom;
    int res=res;
    int num_tel=num_tel;
    int card=card;
    QString adresse_mail=adresse_mail;
    Client c(res,num_tel,nom, prenom, adresse_mail);
    bool test=c.update();
    if(test)
    {
        ui->affichageClient_3->setModel(Etmp.plus(nom));
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("presence ajoutée! \n" "Click cancel to exit"),QMessageBox::Cancel);
        histor.save2("SUPPRIMER","cin :"+ui->cinClient_8->text(),"num_tel :"+ui->num_8->text(),"nom :"+ui->modifier_nom_4->text(),"prenom :"+ui->modifier_prenom_4->text(),"adresse mail :"+ui->modifier_adresseMail_4->text());
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Modification non effectuée! \n" "Click cancel to exit"),QMessageBox::Cancel);
    }

}

void MainWindow::on_tricard_clicked()
{
   ui->affichageClient_2->setModel(Etmp.plus2());
}


*/
