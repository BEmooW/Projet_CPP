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
#include"smtp.h"
#include<QFileDialog>
#include<QDir>
#include"exportexcelobject.h"
#include<vector>
#include <stdlib.h>
#include <time.h>
#include<chrono>
#include<thread>
#include<map>
#include<QDesktopServices>
#include<QPdfWriter>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand (time(NULL));

    //chatbox phrase generator
//    vector<QString>v;
//    v.push_back("Did you know?The First Computer Weighed More Than 27 Tons");
//    v.push_back("Did you know?The First Known Computer Programmer was a Woman");
//    v.push_back("Did you know? People Blink Less When They Use Computers");
//    v.push_back("Did you know?Hackers Write About 6,000 New Viruses Each Month");
//    v.push_back("Oh you're here, cool  i'd use some company :)");

    //pour le mailing

    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
    ui->tableView->setModel(Emp.afficher());
    ui->tableView_3->setModel(Emp.afficher());
    ui->le_CIN->setValidator( new QIntValidator(0, 99999999, this));
     //connect(ui->le_CIN , &QLineEdit::textChanged,this, &MainWindow::normal);
   // ui->lineEdit->setValidator( new QIntValidator(0,9999999, this));
    /*ui->le_matricule->setValidator( new QIntValidator(0,9999999, this));
    QRegularExpression regex("^[a-zA-Z_]*$");
     QValidator *validator = new QRegularExpressionValidator(regex, this);
     ui->le_nom->setValidator(validator);*/
    //connect(this, SIGNAL(monSignal()), ui->le_CIN, SLOT(monSlot()));



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
    ui->label_bg_mail->setPixmap(pixbg.scaled(w3,h3,Qt::KeepAspectRatio));
    ui->label_bg_rh->setPixmap(pixbg.scaled(w3,h3,Qt::KeepAspectRatio));
    ui->label_bg_mail_2->setPixmap(pixbg.scaled(w3,h3,Qt::KeepAspectRatio));
    ui->label_bg_mail_3->setPixmap(pixbg.scaled(w3,h3,Qt::KeepAspectRatio));
    QPixmap pixbgs("C:/Users/MSI/Desktop/esprit2A31/backgs4.PNG");
    ui->label_bg_mail_4->setPixmap(pixbgs.scaled(w3,h3,Qt::KeepAspectRatio));


    QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r1.PNG");
    int wr=ui->label_2->width(),hr=ui->label_2->height();
    ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));

    //connect
    //QObject::connect(ui->le_CIN,&QLineEdit::textChanged, [=](QString ) { customSlot(); });
    //connect(le_CIN, &QLineEdit::textChanged, [=](QString obj) { customSlot(obj); });
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

    QObject::connect(ui->pb_imprimer,&QPushButton::clicked,this,&MainWindow::on_pb_imprimer_clicked);
    QObject::connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    QObject::connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
    QObject::connect(ui->pb_camera,&QPushButton::clicked,this,&MainWindow::on_pb_camera_clicked);
 //QObject::connect(ui->pb_chercher_rh,&QPushButton::clicked,this,&MainWindow::on_pb_chercher_rh_clicked);
QObject::connect(ui->tableView_rh,&QTableView::clicked,this,&MainWindow::on_tableView_rh_clicked);
 QObject::connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWindow::on_pushButton_2_clicked);
 QObject::connect(ui->pb_excel,&QPushButton::clicked,this,&MainWindow::on_pb_excel_clicked);
 QObject::connect(ui->comboBox_rh,&QComboBox::currentTextChanged,this,&MainWindow::on_comboBox_rh_currentTextChanged);
QObject::connect(ui->le_CINa_2,&QLineEdit::textChanged,this,&MainWindow::on_le_CINa_2_textChanged);
QObject::connect(ui->pushButton_19,&QPushButton::clicked,this,&MainWindow::on_pushButton_19_clicked);

QObject::connect(ui->tabWidget_rh,&QTabWidget::currentChanged,this,&MainWindow::on_tabWidget_rh_currentChanged);
QObject::connect(ui->tabWidget_rh,&QTabWidget::tabBarClicked,this,&MainWindow::on_tabWidget_rh_tabBarClicked);
QObject::connect(ui->notepad,&QPushButton::clicked,this,&MainWindow::on_notepad_clicked);
QObject::connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::on_pushButton_clicked);

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
    qDebug()<<QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
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
        ui->le_CIN_m->clear();
        ui->le_nom_m->clear();
        ui->le_prenom_m->clear();
        ui->le_tel_m->clear();
        ui->le_email_m->clear();
        ui->le_num_aff_m->clear();
        ui->box_role_2->clear();
        ui->box_sexe_2->clear();
        ui->box_etat_civil_2->clear();
        ui->dateEdit_3->clear();
        ui->le_matricule_2->clear();
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
    ui->tableView_rh->setModel(Emp.afficher2());
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

            qry->prepare ("SELECT CIN, matricule, nom, prenom, num_tel, sexe, etat_civil, email, date_naiss, num_aff,role from Employes where ( CIN LIKE'%"+CIN+"%' OR nom LIKE'%"+CIN+"%' OR prenom LIKE'%"+CIN+"%'OR matricule LIKE'%"+CIN+"%') ");
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
            //
            qry->prepare ("SELECT CIN, matricule, nom, prenom, num_tel, sexe, etat_civil, email, date_naiss, num_aff,role from Employes where ( CIN LIKE'%"+CIN+"%' OR nom LIKE'%"+CIN+"%' OR prenom LIKE'%"+CIN+"%'OR matricule LIKE'%"+CIN+"%') ");
            qry->exec();
            modal->setQuery(*qry);
            ui->tableView->setModel(modal);
            //qry->prepare("select * from employes where CIN='"+CIN+"'"); //like
            //qry->exec();
            //modal->setQuery(*qry);
            //ui->tableView_3->setModel(modal);
        }
}
//recherche dynamique
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
//trie
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


//generation pdf
void MainWindow::on_pb_imprimer_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->columnCount();



    out <<  "<html>\n"
        "<head >\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("col1")
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<table border=1 cellspacing=0 cellpadding=1>\n";

    // headers color
    out << "<thead><tr bgcolor=#9F8EC3>";
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
                //table values color
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
//mail
void  MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("balkis.hajharrouchi@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("balkis.hajharrouchi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("balkis.hajharrouchi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}




void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}
//camera and take image : the taken image is in the computer "images"
void MainWindow::on_pb_camera_clicked()
{
    c= new camera();
    c->show();
}

//tableau de bord rh
void MainWindow::on_tableView_rh_clicked(const QModelIndex &index)
{
    int i;
    i=index.row();
    QModelIndex in=index.sibling(i,0);
    QString val=ui->tableView_rh->model()->data(in).toString();


    //QString val=ui->tableView->model()->data(index).toString();

        QSqlQuery qry;
        qry.prepare("select * from employes where CIN='"+val+"' or nom='"+val+"' or prenom='"+val+"' or num_tel='"+val+"' or email='"+val+"' or num_aff='"+val+"'or matricule='"+val+"' or ht='"+val+"' or hs='"+val+"' or prix_ht='"+val+"' or prix_hs='"+val+"'or conge='"+val+"'or salaire='"+val+"' " );

        if(qry.exec())
        {
            while(qry.next())
            {
                ui->le_CIN_h->setText(qry.value(0).toString());
                ui->le_nom_h->setText(qry.value(2).toString());
                ui->le_prenom_h->setText(qry.value(3).toString());
                ui->le_tel_h->setText(qry.value(4).toString());
                ui->le_email_h->setText(qry.value(7).toString());
                ui->le_num_aff_h->setText(qry.value(9).toString());
                ui->box_role_2->setCurrentText(qry.value(10).toString());
                ui->box_sexe_2->setCurrentText(qry.value(5).toString());
                ui->box_etat_civil_2->setCurrentText(qry.value(6).toString());
                ui->le_matricule_h->setText(qry.value(1).toString());

                ui->le_ht->setText(qry.value(11).toString());
                ui->le_prix_ht->setText(qry.value(13).toString());
                ui->le_hs->setText(qry.value(12).toString());
                ui->le_prix_hs->setText(qry.value(14).toString());
                ui->le_conge->setText(qry.value(15).toString());
                ui->le_salaire->setText(qry.value(16).toString());

            }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int CIN=ui->le_CIN_h->text().toInt();
    QString nom=ui->le_nom_h->text();
    QString prenom=ui->le_prenom_h->text();
    int tel=ui->le_tel_h->text().toInt();
    QString email=ui->le_email_h->text();
    int num_aff=ui->le_num_aff_h->text().toInt();
    //QString role=ui->box_role->itemData(ui->box_role->currentIndex()).toString();
    QString role = ui->box_role_2->currentText();
    QString sexe = ui->box_sexe_2->currentText();
    QString etat_civil = ui->box_etat_civil_2->currentText();
    QString date = ui->dateEdit_3->dateTime().toString("dd/MM/yyyy");
    int matricule=ui->le_matricule_2->text().toInt();

    int hs=ui->le_hs->text().toInt();
    int ht=ui->le_ht->text().toInt();
    int prix_ht=ui->le_prix_ht->text().toInt();
    int prix_hs=ui->le_prix_hs->text().toInt();
    int conge=ui->le_conge->text().toInt();
    //int salaire=(hs*prix_hs+ht*prix_ht-conge);
    Employes E(CIN,nom,prenom,tel,email,num_aff,role,sexe,etat_civil,date,matricule,ht,hs,prix_ht,prix_hs,conge);

    bool test=E.modifier2(CIN);
    //E.setSalaire(salaire);
    ui->tableView->setModel(Emp.afficher());
    ui->tableView_3->setModel(Emp.afficher());
    ui->tableView_rh->setModel(Emp.afficher2());
 if(test){

    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("modification effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
}else{
     QMessageBox::information(nullptr,QObject::tr("NOT OK"),
                              QObject::tr("modification non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);


 }
}
//export excel
void MainWindow::on_pb_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "Tableau de bord RH", ui->tableView_rh);

    //colums to export
    obj.addField(0, "CIN", "char(30)");
    obj.addField(1, "Nom", "char(30)");
    obj.addField(2, "Prenom", "char(30)");
    obj.addField(3, "HT", "char(30)");
    obj.addField(4, "Prix_HT", "char(30)");
    obj.addField(5, "HS", "char(30)");
    obj.addField(6, "Prix_HS", "char(30)");
    obj.addField(7, "Conge", "char(30)");
    obj.addField(8, "Salaire", "char(30)");


    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}

void MainWindow::on_comboBox_rh_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel ();
        QSqlQuery*qry=new QSqlQuery();
        QString type=ui->comboBox_rh->currentText();
        if (type=="Par defaut")
        {
            qry->prepare("select CIN, nom, prenom, ht, prix_ht, hs, prix_hs, conge, salaire from Employes");
            qry->exec();
            model->setQuery(*qry);
            ui->tableView_rh->setModel(model);
        }
            else if (type=="CIN"){
            qry->prepare("select CIN, nom, prenom, ht, prix_ht, hs, prix_hs, conge, salaire from Employes order by CIN");
            qry->exec();
            model->setQuery(*qry);

                ui->tableView_rh->setModel(model);


            }
        else if (type=="Salaire"){
        qry->prepare("select CIN, nom, prenom, ht, prix_ht, hs, prix_hs, conge, salaire from Employes order by Salaire");
        qry->exec();
        model->setQuery(*qry);

            ui->tableView_rh->setModel(model);
        }
}

void MainWindow::on_le_CINa_2_textChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
        QSqlQuery*qry=new QSqlQuery();
        QString CIN=ui->le_CINa_2->text();


        if(CIN.isEmpty())
        {
            ui->tableView_rh->setModel(Emp.afficher2());

        }
        else
        {
            //
            qry->prepare ("SELECT CIN, nom, prenom, ht, prix_ht, hs, prix_hs, conge, salaire from Employes where ( CIN LIKE'%"+CIN+"%' OR nom LIKE'%"+CIN+"%' OR prenom LIKE'%"+CIN+"%'OR ht LIKE'%"+CIN+"%'OR hs LIKE'%"+CIN+"%') ");
            qry->exec();
            modal->setQuery(*qry);
            ui->tableView_rh->setModel(modal);

        }
}

void MainWindow::on_pushButton_19_clicked()
{
    {
        QString imageFile = QFileDialog ::getOpenFileName(0,"Select Image","/home/","Image Files (*.png)");

          QFileInfo info(imageFile);
        QFileInfo  filename = info.fileName(); //path de l'image

        QPixmap image (imageFile);
          ui->label_pic->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
          image = image.scaled(110,110,Qt::IgnoreAspectRatio,Qt::FastTransformation);
          ui->label_pic->setPixmap(image);
          ui->label_pic->show();

    qDebug()<<QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();

    //************************************************************************************************************************

    }



    }


//chatBot
void MainWindow::on_pushButton_clicked()
{
    //ui->plainTextEdit->toPlainText();
    QString text,space="";
    QString msg=ui->input->text();
    ui->output->appendPlainText(space);
    ui->output->appendPlainText(msg);
    ui->input->clear();
    QString chemin;



    if(msg=="hi"||msg=="hey"||msg=="yo"){
        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r1.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text="Hello user, i'm B.E.M.O your chat assistant you can call me Bemo :) ";

    }
    else if(msg=="hello"||msg=="hallo"||msg=="heyo"||msg=="sup")
    {
        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r1.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));

        text="hey there , how are you feeling today? ";
    }
    else if(msg=="help")
    {
        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r6.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text=" what's wrong? How can i help you?";
    }
    else if(msg=="calculator" ||msg=="calcul")
    {
        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r5.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text=" Oh sorry ,i can't do maths but there's already a scientific calculator in the finance space";
    }
    else if(msg=="how are you" ||msg=="hru")
    {
        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r2.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text="I'm great thank you for asking and how are you! I hope you're doing great";
    }
    else if(msg=="good" ||msg=="great"||msg=="i'm great"||msg=="i'm good"||msg=="doing great")
    {
        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r2.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));

        text="Good to hear dear employee, have a good day";
    }
    else if(msg=="how to export an excel file" ||msg=="excel")
    {
        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r4.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text="Go to ""tableau de bord RH"" and click on the button ""exporter""";
    }
    else if(msg=="how to generate a pdf" ||msg=="pdf")
    {
        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r4.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text="Go to ""Afficher employe"" and click on the button ""imprimer""";
    }
    else if(msg=="sorry" ||msg=="excuse me")
    {
        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r1.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text="Don't worry about it friend";
    }
    else if(msg=="tell me" ||msg=="talk")
    {
        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r2.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text="Waht do you want to talk about mate? need help in somthing? or just company?";
    }
    else if(msg=="money" ||msg=="salary")
    {
        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r4.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text="We all want money don't we? work hard until you deserve it!";
    }
    else if(msg=="bored" ||msg=="i'm bored")
    {
        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r6.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text="Sorry for that , a cup of coffee would help i guess!";
    }
    else if(msg=="thanks" ||msg=="thank you")
    {
        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r3.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text="You're welcome i'm alwasy at your service";
    }
    else if(msg=="fuck you" ||msg=="shit"||msg=="fuck"||msg=="damn"||msg=="stupid"||msg=="idiot")
    {
        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r7.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text="How dare you!Please Do not use cursing words it can hurt others like it did to me!";
    }
    else if(msg=="you are sweet" )
    {
        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r2.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text="Arigato! Don't tell the others i'm only this sweet with you";
    }
    else if(msg=="i love you" ||msg=="i like you")
    {
        vector<QString>v;
        v.push_back("I love you too <3");
        v.push_back("Oww you're so sweet i love you too");
        v.push_back("Don't tell others, you're my favourite mate ^^ love you~");
        v.push_back("! I love you too, yaay now i finally have a best friend^^");

        int i = rand() % 4;

        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r3.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text=v[i];
    }
    else if(msg=="" ||msg=="?"||msg==" ")
    {
        vector<QString>v;
        v.push_back("Did you know?The First Computer Weighed More Than 27 Tons");
        v.push_back("Did you know?The First Known Computer Programmer was a Woman");
        v.push_back("Did you know? People Blink Less When They Use Computers");
        v.push_back("Did you know?Hackers Write About 6,000 New Viruses Each Month");

        int i = rand() % 4;

        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r4.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text=v[i];
    }
    else if(msg=="bye" ||msg=="see you"||msg=="i have to go")
    {
        vector<QString>v;
        v.push_back("Goodbye good luck in your work");
        v.push_back("See you take care mate!");
        v.push_back("Bye! good luck in your shift :)");


        int i = rand() % 3;

        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r1.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text=v[i];
    }
    else if(msg=="psst" ||msg=="."||msg=="pss")
    {
        vector<QString>v;

        v.push_back("Oh hey friend i'm glad you're here");
        v.push_back("Missed me already?");
        v.push_back("Welcome back!");
        v.push_back("Oh you're here i'd use some company");
        v.push_back("What are you doing here?You should focus on your work!");

        int i = rand() % 5 ;

        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r2.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text=v[i];
    }
    else if(msg=="hhh" ||msg=="hhhh"||msg=="haha")
    {
        vector<QString>v;

        v.push_back("What's so funny?");
        v.push_back("Are you laughing at me ?");
        v.push_back("Having fun i see!");

        int i = rand() % 3 ;

        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r2.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text=v[i];
    }
    else{
        QPixmap pixrobot("C:/Users/MSI/Desktop/esprit2A31/r5.PNG");
        int wr=ui->label_2->width(),hr=ui->label_2->height();
        ui->label_2->setPixmap(pixrobot.scaled(wr,hr,Qt::KeepAspectRatio));
        text="Sorry i didnt understant , please try again";
    }

    ui->output->appendPlainText(space);
    ui->output->appendPlainText(text);
}




void MainWindow::on_tabWidget_rh_currentChanged(int index)
{
    QSqlQuery q1,q2,q3,q4,q5,q6;
                    qreal tot=0,c1=0,c2=0,c3=0,c4=0,c5=0;
                    int i;


                    q2.prepare("SELECT * FROM EMPLOYES WHERE Role='RH'");
                    q2.exec();

                    q3.prepare("SELECT * FROM EMPLOYES WHERE Role='Finance'");
                    q3.exec();

                    q4.prepare("SELECT * FROM EMPLOYES WHERE Role='Equipement' ");
                    q4.exec();

                    q5.prepare("SELECT * FROM EMPLOYES WHERE Role='Espace' ");
                    q5.exec();
                    q6.prepare("SELECT * FROM EMPLOYES WHERE Role='Client' ");
                    q6.exec();

                    //while (q1.next()){tot++;}
                    while (q2.next()){c1++;}
                    while (q3.next()){c2++;}
                    while (q4.next()){c3++;}
                    while (q5.next()){c4++;}
                    while (q6.next()){c5++;}
                   QPieSeries *series=new QPieSeries();


                    series->append("RH",c1);
                    series->append("Finance",c2);
                    series->append("Equipement",c3);
                    series->append("Espace",c4);
                    series->append("Client",c5);


//                   QPieSlice *slice = series->slices().at(0);
//                     slice->setExploded(true);
                    QChart *chart =new QChart();

                    chart->addSeries(series);

                    chart->setTitle("Repartition des employes selon leur role ");
                    QChartView *chartView=new QChartView(chart);
                    //
                    tot = c1+c2+c3+c4+c5;
                                          QString t=QString::number(c1+c2+c3+c4+c5);
                                          QString p1=QString::number(c1/tot*100, 'f', 2)+"%";
                                          QString p2=QString::number(c2/tot*100, 'f', 2)+"%";
                                          QString p3=QString::number(c3/tot*100, 'f', 2)+"%";
                                          QString p4=QString::number(c4/tot*100, 'f', 2)+"%";
                                          QString p5=QString::number(c5/tot*100, 'f', 2)+"%";
                                          QString n1=QString::number(c1);
                                          QString n2=QString::number(c2);
                                          QString n3=QString::number(c3);
                                          QString n4=QString::number(c4);
                                          QString n5=QString::number(c5);
                                          ui->lineEdit_p1->setText(p1);
                                          ui->lineEdit_p2->setText(p2);
                                          ui->lineEdit_p3->setText(p3);
                                          ui->lineEdit_p4->setText(p4);
                                          ui->lineEdit_p5->setText(p5);
                                          ui->lineEdit_n1->setText(n1);
                                          ui->lineEdit_n2->setText(n2);
                                          ui->lineEdit_n3->setText(n3);
                                          ui->lineEdit_n4->setText(n4);
                                          ui->lineEdit_n5->setText(n5);
                                          ui->lineEdit_tot->setText(t);
                                          //QString strValue = QString::number(value, 'f', 3);
                                        if(c1>c2 && c1>c3 && c1>c4&& c1>c5){
                                                        QString type="RH";
                                                         QString max=QString::number(c1);
                                                         ui->lineEdit_4->setText(type);
                                                         ui->lineEdit_5->setText(max);
                                                        }
                                                            else if (c2>c1 && c2>c3 && c2>c4&& c2>c5) {
                                                            QString type="Finance";
                                                             QString max=QString::number(c2);
                                                             ui->lineEdit_4->setText(type);
                                                             ui->lineEdit_5->setText(max);
                                                        }else if (c3>c1 && c3>c2 && c3>c4&& c3>c5) {
                                                            QString type="Equipement";
                                                             QString max=QString::number(c3);
                                                             ui->lineEdit_4->setText(type);
                                                             ui->lineEdit_5->setText(max);
                                                        }
                                                        else if (c4>c1 && c4>c2 && c4>c3&& c4>c5) {
                                                             QString type="Espace";
                                                             QString max=QString::number(c4);
                                                             ui->lineEdit_4->setText(type);
                                                             ui->lineEdit_5->setText(max);
                                                        }else{
                                                            QString type="Client";
                                                             QString max=QString::number(c5);
                                                             ui->lineEdit_4->setText(type);
                                                             ui->lineEdit_5->setText(max);


                                                        }
                                                        if(c1<c2 && c1<c3 && c1<c4&& c1<c5){
                                                        QString type="RH";
                                                         QString max=QString::number(c1);
                                                         ui->lineEdit_6->setText(type);
                                                         ui->lineEdit_7->setText(max);
                                                         i=0;

                                                        }
                                                            else if (c2<c1 && c2<c3 && c2<c4&& c2<c5) {
                                                            QString type="Finance";
                                                             QString max=QString::number(c2);
                                                             ui->lineEdit_6->setText(type);
                                                             ui->lineEdit_7->setText(max);
                                                             i=1;
                                                        }else if (c3<c1 && c3<c2 && c3<c4 && c3<c5) {
                                                            QString type="Equipement";
                                                             QString max=QString::number(c3);
                                                             ui->lineEdit_6->setText(type);
                                                             ui->lineEdit_7->setText(max);
                                                             i=2;
                                                        }else if (c4<c1 && c4<c2 && c4<c3 && c4<c5) {
                                                            QString type="Espace";
                                                             QString max=QString::number(c4);
                                                             ui->lineEdit_6->setText(type);
                                                             ui->lineEdit_7->setText(max);
                                                             i=3;
                                                        }else{
                                                            QString type="Client";
                                                             QString max=QString::number(c5);
                                                             ui->lineEdit_6->setText(type);
                                                             ui->lineEdit_7->setText(max);
                                                             i=4;
                                                        }

                    chartView = new QChartView(chart,ui->horizontalFrame);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->setMinimumSize(600,380);
                    QPieSlice *slice = series->slices().at(i);
                      slice->setExploded(true);





}

void MainWindow::on_tabWidget_rh_tabBarClicked(int index)
{
   // ui->output->clear();
    vector<QString>v;
    v.push_back("What's on your mind?");
    v.push_back("It's good to see you again ^^");
    v.push_back("Need something?");
    v.push_back("Some useful commands: excel,pdf..");
    int i = rand() % 4 ;
    ui->output->setPlainText(v[i]);
    ui->tableView->setModel(Emp.afficher());
    ui->tableView_3->setModel(Emp.afficher());
    ui->tableView_rh->setModel(Emp.afficher2());
}






void MainWindow::on_notepad_clicked()
{
    n=new notepad();
    n->show();
}
