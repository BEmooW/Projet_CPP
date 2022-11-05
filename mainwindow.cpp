#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include"employes.h"
#include<QMessageBox>
#include<QDateEdit>
#include<QDate>
#include<QTextStream>
#include<QTextDocument>
#include<iostream>
#include<QPixmap>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include<QGraphicsDropShadowEffect>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Emp.afficher());
    ui->tableView_3->setModel(Emp.afficher());




    //logo app

    ui->setupUi(this);
    QPixmap pixlogo("C:/Users/MSI/Desktop/esprit2A31/projet c++/logoapp.PNG");
    int w=ui->label_logo->width(),h=ui->label_logo->height();
    ui->label_logo->setPixmap(pixlogo.scaled(w,h,Qt::KeepAspectRatio));
    //photo de profil

    QPixmap pixpic("C:/Users/MSI/Desktop/esprit2A31/projet c++/pfp3.PNG");
    int w2=ui->label_pic->width(),h2=ui->label_pic->height();
    ui->label_pic->setPixmap(pixpic.scaled(w2,h2,Qt::KeepAspectRatio));

    //photo background

    QPixmap pixbg("C:/Users/MSI/Desktop/esprit2A31/backg1.PNG");
    int w3=ui->label_bg_aff->width(),h3=ui->label_bg_aff->height();
    ui->label_bg_modif->setPixmap(pixbg.scaled(w3,h3,Qt::KeepAspectRatio));
    ui->label_bg_aj->setPixmap(pixbg.scaled(w3,h3,Qt::KeepAspectRatio));
    ui->label_bg_aff->setPixmap(pixbg.scaled(w3,h3,Qt::KeepAspectRatio));
    //connect
    QObject::connect(ui->pb_ajouter,&QPushButton::clicked,this,&MainWindow::on_pb_ajouter_clicked);
    QObject::connect(ui->pb_afficher,&QPushButton::clicked,this,&MainWindow::on_pb_afficher_clicked);
    QObject::connect(ui->pb_modifier,&QPushButton::clicked,this,&MainWindow::on_pb_modifier_clicked);
    QObject::connect(ui->pb_supprimer,&QPushButton::clicked,this,&MainWindow::on_pb_supprimer_clicked);
    QObject::connect(ui->pb_finance,&QPushButton::clicked,this,&MainWindow::on_pb_finance_clicked);
    QObject::connect(ui->tableView,&QTableView::clicked,this,&MainWindow::on_tableView_clicked);
   // QObject::connect(ui->tableView,&QTableView::clicked,this,&MainWindow::on_tableView_3_clicked);
    QObject::connect(ui->pb_rh,&QPushButton::clicked,this,&MainWindow::on_pb_rh_clicked);
    QObject::connect(ui->pb_client,&QPushButton::clicked,this,&MainWindow::on_pb_client_clicked);
    QObject::connect(ui->pb_espace,&QPushButton::clicked,this,&MainWindow::on_pb_espace_clicked);
    QObject::connect(ui->pb_equip,&QPushButton::clicked,this,&MainWindow::on_pb_equip_clicked);
    QObject::connect(ui->le_CINa,&QLineEdit::textChanged,this,&MainWindow::on_le_CINa_textChanged);
    QObject::connect(ui->le_CINs,&QLineEdit::textChanged,this,&MainWindow::on_le_CINs_textChanged);
    QObject::connect(ui->comboBox_19,&QComboBox::currentTextChanged,this,&MainWindow::on_comboBox_19_currentTextChanged);
    QObject::connect(ui->comboBox_5,&QComboBox::currentTextChanged,this,&MainWindow::on_comboBox_5_currentTextChanged);
    QObject::connect(ui->pb_imprimer,&QPushButton::clicked,this,&MainWindow::on_pb_imprimer_clicked);



}


MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_pushButton_clicked()
{
   qDebug()<<"boutton ajouter personne appuye";
}*/

/*void MainWindow::on_pushButton_2_clicked()
{
   qDebug()<<"boutton afficher personne appuye";
   //ui->tableView->setModel(Emp.afficher());
}*/

void MainWindow::on_pb_ajouter_clicked()
{
    int CIN=ui->le_CIN->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int tel=ui->le_tel->text().toInt();
    QString email=ui->le_email->text();
    int num_aff=ui->le_num_aff->text().toInt();
    //QString value = box_role.comboBox.currentText();
    //QString role=ui->box_role->itemData(ui->box_role->currentIndex()).toString();
    QString role = ui->box_role->currentText();
    QString sexe = ui->box_sexe->currentText();
    QString etat_civil = ui->box_etat_civil->currentText();
    QString date = ui->dateEdit->dateTime().toString("dd/MM/yyyy");
    int matricule=ui->le_matricule->text().toInt();
    //unicite de CIN to do
    //bool unique=Emp.chercher(ui->tableView_3,CIN);
    /*if(unique==true)
    {
       QMessageBox::critical(nullptr,QObject::tr("not OK"),QObject::tr("Employe existe deja\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
    {*/
    Employes E(CIN,nom,prenom,tel,email,num_aff,role,sexe,etat_civil,date,matricule);

    bool test=E.ajouter();
    if(test)
    {
        ui->tableView->setModel(Emp.afficher());
        ui->tableView_3->setModel(Emp.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Ajouter non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
  //  }
}

void MainWindow::on_pb_supprimer_clicked()
{
    QModelIndex index=ui->tableView->currentIndex();
    int i;
    i=index.row();
    QModelIndex in=index.sibling(i,0);
    QString val=ui->tableView->model()->data(in).toString();

    int CIN=ui->le_CINs->text().toInt();
    bool test=Emp.supprimer(val);
    bool test1=Emp.supprimer1(CIN);
    if(test)
        {
            ui->tableView->setModel(Emp.afficher());
            ui->tableView_3->setModel(Emp.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Suppression effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
    else if(!test)
            QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Suppression non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
    else if(test1)
        {
            ui->tableView->setModel(Emp.afficher());
            ui->tableView_3->setModel(Emp.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Suppression effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Suppression non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_clicked()
{
        int CIN=ui->le_CIN_m->text().toInt();
        QString nom=ui->le_nom_m->text();
        QString prenom=ui->le_prenom_m->text();
        int tel=ui->le_tel_m->text().toInt();
        QString email=ui->le_email_m->text();
        int num_aff=ui->le_num_aff_m->text().toInt();
        //QString role=ui->box_role->itemData(ui->box_role->currentIndex()).toString();
        QString role = ui->box_role_2->currentText();
        QString sexe = ui->box_sexe_2->currentText();
        QString etat_civil = ui->box_etat_civil_2->currentText();
        QString date = ui->dateEdit_3->dateTime().toString("dd/MM/yyyy");
        int matricule=ui->le_matricule_2->text().toInt();
        Employes E(CIN,nom,prenom,tel,email,num_aff,role,sexe,etat_civil,date,matricule);
        bool test=E.modifier(CIN);
        ui->tableView->setModel(Emp.afficher());
        ui->tableView_3->setModel(Emp.afficher());
     if(test){

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("modification effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
    }else{
         QMessageBox::information(nullptr,QObject::tr("NOT OK"),
                                  QObject::tr("modification non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);


     }
}
// pie chart fl select * rodha count
//check readme , smtp.h(NO NOT CHANGE ANTHING)
//close();

void MainWindow::on_pb_afficher_clicked()
{
    ui->tableView->setModel(Emp.afficher());
    ui->tableView_3->setModel(Emp.afficher());
}



void MainWindow::on_pb_rh_clicked()
{
    ui->tabWidget_rh->show();
    //ui->pb_rh->setChecked(false);
    ui->pb_finance->setChecked(false);
    ui->pb_client->setChecked(false);
    ui->pb_espace->setChecked(false);
    ui->pb_equip->setChecked(false);
}

void MainWindow::on_pb_finance_clicked()
{
    ui->tabWidget_rh->hide();
    ui->pb_rh->setChecked(false);
    //ui->pb_finance->setChecked(false);
    ui->pb_client->setChecked(false);
    ui->pb_espace->setChecked(false);
    ui->pb_equip->setChecked(false);
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    int i;
    i=index.row();
    QModelIndex in=index.sibling(i,0);
    QString val=ui->tableView->model()->data(in).toString();


    //QString val=ui->tableView->model()->data(index).toString();

        QSqlQuery qry;
        qry.prepare("select * from employes where CIN='"+val+"' or nom='"+val+"' or prenom='"+val+"' or num_tel='"+val+"' or email='"+val+"' or num_aff='"+val+"'or matricule='"+val+"' " );

        if(qry.exec())
        {
            while(qry.next())
            {
                ui->le_CIN_m->setText(qry.value(0).toString());
                ui->le_nom_m->setText(qry.value(2).toString());
                ui->le_prenom_m->setText(qry.value(3).toString());
                ui->le_tel_m->setText(qry.value(4).toString());
                ui->le_email_m->setText(qry.value(7).toString());
                ui->le_num_aff_m->setText(qry.value(9).toString());
                ui->box_role_2->setCurrentText(qry.value(10).toString());
                ui->box_sexe_2->setCurrentText(qry.value(5).toString());
                ui->box_etat_civil_2->setCurrentText(qry.value(6).toString());
                ui->le_matricule_2->setText(qry.value(1).toString());

            }
    }
}


void MainWindow::on_pb_client_clicked()
{
    ui->tabWidget_rh->hide();
    ui->pb_rh->setChecked(false);
    ui->pb_finance->setChecked(false);
    //ui->pb_client->setChecked(false);
    ui->pb_espace->setChecked(false);
    ui->pb_equip->setChecked(false);
}

void MainWindow::on_pb_espace_clicked()
{
    ui->tabWidget_rh->hide();
    ui->pb_rh->setChecked(false);
    ui->pb_finance->setChecked(false);
    ui->pb_client->setChecked(false);
    //ui->pb_espace->setChecked(false);
    ui->pb_equip->setChecked(false);
}

void MainWindow::on_pb_equip_clicked()
{
    ui->tabWidget_rh->hide();
    ui->pb_rh->setChecked(false);
    ui->pb_finance->setChecked(false);
    ui->pb_client->setChecked(false);
    ui->pb_espace->setChecked(false);
    //ui->pb_equip->setChecked(false);
}

void MainWindow::on_le_CINa_textChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
        QSqlQuery*qry=new QSqlQuery();
        QString CIN=ui->le_CINa->text();

        if(CIN.isEmpty())
        {
            ui->tableView_3->setModel(Emp.afficher());

        }
        else
        {
            qry->prepare("select * from employes where CIN='"+CIN+"'"); //like
            qry->exec();
            modal->setQuery(*qry);
            ui->tableView_3->setModel(modal);
        }
}

void MainWindow::on_le_CINs_textChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
        QSqlQuery*qry=new QSqlQuery();
        QString CIN=ui->le_CINs->text();

        if(CIN.isEmpty())
        {
            ui->tableView->setModel(Emp.afficher());

        }
        else
        {
            qry->prepare("select * from employes where CIN='"+CIN+"'"); //like
            qry->exec();
            modal->setQuery(*qry);
            ui->tableView->setModel(modal);
        }
}

void MainWindow::on_comboBox_19_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel ();
        QSqlQuery*qry=new QSqlQuery();
        QString type=ui->comboBox_19->currentText();
        if (type=="Par defaut")
        {
            qry->prepare("select * from EMPLOYES");
            qry->exec();
            model->setQuery(*qry);
            ui->tableView_3->setModel(model);
        }
            else if (type=="CIN"){
            qry->prepare("select * from EMPLOYES order by CIN");
            qry->exec();
            model->setQuery(*qry);

                ui->tableView_3->setModel(model);


            }
            else if (type=="Matricule"){
            qry->prepare("select * from EMPLOYES order by matricule");
            qry->exec();
            model->setQuery(*qry);

                ui->tableView_3->setModel(model);


            }
            else if (type=="Nom"){
            qry->prepare("select * from EMPLOYES order by nom");
            qry->exec();
            model->setQuery(*qry);

                ui->tableView_3->setModel(model);
            }
        else if (type=="Prenom"){
        qry->prepare("select * from EMPLOYES order by prenom");
        qry->exec();
        model->setQuery(*qry);

            ui->tableView_3->setModel(model);
        }
}

void MainWindow::on_comboBox_5_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel ();
        QSqlQuery*qry=new QSqlQuery();
        QString type=ui->comboBox_5->currentText();
        if (type=="Par defaut")
        {
            qry->prepare("select * from EMPLOYES");
            qry->exec();
            model->setQuery(*qry);
            ui->tableView->setModel(model);
        }
            else if (type=="CIN"){
            qry->prepare("select * from EMPLOYES order by CIN");
            qry->exec();
            model->setQuery(*qry);

                ui->tableView->setModel(model);


            }
            else if (type=="Matricule"){
            qry->prepare("select * from EMPLOYES order by matricule");
            qry->exec();
            model->setQuery(*qry);

                ui->tableView->setModel(model);


            }
            else if (type=="Nom"){
            qry->prepare("select * from EMPLOYES order by nom");
            qry->exec();
            model->setQuery(*qry);

                ui->tableView->setModel(model);
            }
        else if (type=="Prenom"){
        qry->prepare("select * from EMPLOYES order by prenom");
        qry->exec();
        model->setQuery(*qry);

            ui->tableView->setModel(model);
        }
}



void MainWindow::on_pb_imprimer_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("col1")
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView->isColumnHidden(column)) {
                QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
    if (dialog->exec() == QDialog::Accepted) {
        document->print(&printer);
    }

    delete document;
}
