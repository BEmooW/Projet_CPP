#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include <QIntValidator>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QtDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QPixmap>
#include <QDesktopServices>
#include <QUrl>
#include <QApplication>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QtCore>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QtDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QPixmap>
#include <QDesktopServices>
#include <QUrl>
#include <QApplication>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QtCore>
#include <QtSvg/QSvgRenderer>
#include <QIntValidator>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

#include "QSqlQuery"
#include "QStringListModel"
#include<QFileDialog>
#include<QTextDocument>
#include<QTextStream>
#include<QGraphicsView>
#include<QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QMessageBox>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QtPrintSupport/QPrinter>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QIntValidator>
#include <QMessageBox>
#include <QMainWindow>
#include <QMessageBox>
#include <QDialog>
#include <QPixmap>
#include <QFile>
#include <QDialog>
#include <QFileDialog>
#include <QUrl>
#include <QSystemTrayIcon>
#include<QPropertyAnimation>
#include <QRegularExpression>
#include <QTranslator>
#include <QPixmap>
#include<QLineSeries>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include<QFileDialog>
#include<QTextDocument>
#include<QTextStream>
#include<QGraphicsView>
#include<QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QMessageBox>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QtPrintSupport/QPrinter>
#include <QDebug>
#include <QDate>
#include <QDateTime>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

#include <QMediaPlayer>
#include <QFileDialog>


#include "QSqlQuery"
#include "QStringListModel"
#include<QFileDialog>
#include<QTextDocument>
#include<QTextStream>
#include<QGraphicsView>
#include<QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QMessageBox>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QtPrintSupport/QPrinter>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include "QrCode.hpp"


using namespace qrcodegen;
QString days="";
using namespace std;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(E.afficher());
    /*QPixmap pix("C:/Users/MSI/Pictures/label_8.PNG");
        int w=ui->label_8->width(),h=ui->label_8->height();
        ui->label_8->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));*/

    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
    //QObject::connect(ui->pushButton_lcd,&QPushButton::clicked,this,&MainWindow::on_pushButton_lcd_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   qDebug()<<"boutton ajouter equipement appuye";
}

void MainWindow::on_pushButton_2_clicked()
{
   qDebug()<<"boutton afficher equipement appuye";
}

void MainWindow::on_pb_ajouter_clicked()
{
    int code=ui->le_code->text().toInt();
    int quantite=ui->sb_quantite->text().toInt();
    QString nom=ui->le_nom->currentText();
    QString type=ui->le_type->text();
    Equipement E(code,nom,type,quantite);
    bool test=E.ajouter();
    if(test)
    {
        ui->tableView_2->setModel(E.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Ajouter non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{
    int code=ui->le_codes->text().toInt();
    bool test=E.supprimer(code);
    if(test)
    {
        if(test)
        {
            ui->tableView_2->setModel(E.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Suppression effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Suppression non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_pb_modifier_clicked()
{

    int code=ui->le_code_2->text().toInt();
    int quantite=ui->sb_quantite_2->text().toInt();
    QString nom=ui->le_nom_2->currentText();
    QString type=ui->le_type_2->text();


    Equipement E(code,nom,type,quantite);
    bool test=E.modifier(code);
    ui->tableView_2->setModel(E.afficher());
 if(test){

    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("modification effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
}else{
     QMessageBox::information(nullptr,QObject::tr("Not oK"),
                              QObject::tr("modification non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);


 }

}





void MainWindow::on_pushButton_rechercher_clicked()
{ int code ;
    QSqlQueryModel *model;
    code = ui->lineEdit_rechercher->text().toInt() ;
     model =EP->chercher (code);
     ui->tableView_2->show() ;
     ui->tableView_2->setModel(model);


}

void MainWindow::on_pushButton_trier_clicked()
{
 ui->tableView_2->setModel( E.sortid());
}

void MainWindow::on_pushButton_PDF_clicked()
{

    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                         "/home",
                                                         QFileDialog::ShowDirsOnly
                                                         | QFileDialog::DontResolveSymlinks);
             qDebug()<<dir;
             QPdfWriter pdf(dir+"/PdfList.pdf");
                                    QPainter painter(&pdf);
                                   int i = 4000;

                                   painter.drawPixmap(QRect(100,100,2000,2000),QPixmap("C:/Users/Admin/Desktop/msi.png"));
                                       //painter.drawText(900,650,"Tiny hues");

                                        //painter.drawPixmap(QRect(7600,100,2100,2700),QPixmap("C:/Users/Admin/Desktop/msi.png"));

                                        painter.setPen(Qt::red);
                                        painter.setFont(QFont("Time New Roman", 25));
                                        painter.drawText(3000,1450,"Liste Des Equipements");
                                        painter.setPen(Qt::black);
                                        painter.setFont(QFont("Time New Roman", 15));
                                        painter.drawRect(100,100,9400,2500);
                                        painter.drawRect(100,3000,9400,500);
                                        painter.setFont(QFont("Time New Roman", 10));
                                        painter.drawText(300,3300,"Code");
                                        painter.drawText(3000,3300,"Nom");
                                        painter.drawText(5600,3300,"Type");
                                        painter.drawText(8300,3300,"Qunatite");

                                        painter.drawRect(100,3000,9400,10700);


                                        QTextDocument previewDoc;
                                        QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");


                                        QTextCursor cursor(&previewDoc);



                                        QSqlQuery query;
                                        query.prepare("select * from EQUIPEMENT");
                                        query.exec();
                                        while (query.next())
                                        {
                                            painter.drawText(300,i,query.value(0).toString());
                                            painter.drawText(3000,i,query.value(1).toString());
                                            painter.drawText(5600,i,query.value(2).toString());
                                            painter.drawText(8300,i,query.value(3).toString());


                                           i = i +500;
                                        }
                                        int reponse = QMessageBox::question(this, "Générer PDF", " PDF Enregistré ! Voulez Vous Affichez Le PDF ?",
                                                                            QMessageBox::Yes|QMessageBox::No);
                                            if (reponse == QMessageBox::Yes)
                                            {
                                                QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PdfList.pdf"));

                                                painter.end();
                                            }
                                            else
                                            {
                                                 painter.end();
   }
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    days=days+date.toString()+"|";
    ui->les_jours->setText(days);

}
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
/*void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("bencheikh.salim@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("bencheikh.salim@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("bencheikh.salim@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
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
*/
void MainWindow::on_sendBtn_2_clicked()
{
    QString link="https://mail.google.com/mail/u/1/#inbox?compose=new";
            QDesktopServices::openUrl(link);
}

void MainWindow::on_statsmed_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from EQUIPEMENT where NOM='meuble' ");
     int number1=model->rowCount();
     model->setQuery("select * from EQUIPEMENT where NOM='materiel info' ");
     int number2=model->rowCount();
     model->setQuery("select * from EQUIPEMENT where NOM='cuisine' ");
     int number3=model->rowCount(); // calculer le nombre des evenement pour engament
    model->setQuery("select * from EQUIPEMENT where NOM='loisir' ");
          int number4=model->rowCount();
          model->setQuery("select * from EQUIPEMENT where NOM='composant reseau' ");
          int number5=model->rowCount();
     model->setQuery("select * from EQUIPEMENT where NOM='autre' ");
     int number6=model->rowCount();
     int total=number1+number2+number3+number4+number5+number6;
     QString a = QString("meuble"+QString::number((number1*100)/total,'f',2)+"%" );
     QString b = QString("materiel info"+QString::number((number2*100)/total,'f',2)+"%" );
     QString c = QString("cuisine"+QString::number((number3*100)/total,'f',2)+"%" );
     QString d = QString("loisir" +QString::number((number4*100)/total,'f',2)+"%" );

      QString e = QString("composant reseau" +QString::number((number5*100)/total,'f',2)+"%" );

     QString f = QString("autre "+QString::number((number6*100)/total,'f',2)+"%" );

QPieSeries *series = new QPieSeries();
     series->append(a,number1);
     series->append(b,number2);
     series->append(c,number3);
     series->append(d,number4);
     series->append(e,number5);
     series->append(f,number6);
     if (number1!= 0)
     {
         QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());
     }
     if (number2!=0)
     {
              // Add label, explode and define brush for 2nd slice
              QPieSlice *slice1 = series->slices().at(1);
              //slice1->setExploded();
              slice1->setLabelVisible();
     }
     if(number3!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice2 = series->slices().at(2);
              //slice1->setExploded();
              slice2->setLabelVisible();
     }
     if(number4!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice3 = series->slices().at(3);
              //slice1->setExploded();
              slice3->setLabelVisible();
     }
     if(number5!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice4 = series->slices().at(4);
              //slice1->setExploded();
              slice4->setLabelVisible();
     }
     if(number6!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice5 = series->slices().at(5);
              //slice1->setExploded();
              slice5->setLabelVisible();
     }
             // Create the chart widget
             QChart *chart = new QChart();
             // Add data to chart with title and hide legend
             chart->addSeries(series);
             chart->setTitle("Pourcentage par type des nom"+ QString::number(total));
             chart->legend()->hide();
             // Used to display the chart
             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(1000,500);
             chartView->show();

}

void MainWindow::on_qrcodegen_2_clicked()
{


        int tabeq=ui->tableView_2->currentIndex().row();
               QVariant idd=ui->tableView_2->model()->data(ui->tableView_2->model()->index(tabeq,0));
               QString id= idd.toString();
               QSqlQuery qry;
               qry.prepare("select * from EQUIPEMENT where CODE=:code");
               qry.bindValue(":CODE",id);
               qry.exec();
                  QString  type,nom,ide;

               while(qry.next()){

                   id=qry.value(1).toString();
                   nom=qry.value(3).toString();
                   type=qry.value(2).toString();



               }
               ide=QString(id);
                      ide="NOM:"+nom+"TYPE:"+type;
               QrCode qr = QrCode::encodeText(ide.toUtf8().constData(), QrCode::Ecc::HIGH);

               // Read the black & white pixels
               QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
               for (int y = 0; y < qr.getSize(); y++) {
                   for (int x = 0; x < qr.getSize(); x++) {
                       int color = qr.getModule(x, y);  // 0 for white, 1 for black

                       // You need to modify this part
                       if(color==0)
                           im.setPixel(x, y,qRgb(254, 254, 254));
                       else
                           im.setPixel(x, y,qRgb(0, 0, 0));
                   }
               }
               im=im.scaled(200,200);
               ui->qrcodecommande_2->setPixmap(QPixmap::fromImage(im));
}




void MainWindow::on_pushButton_trier_2_clicked()
{
    ui->tableView_2->setModel( E.sortquantite());
}
void MainWindow::show_from_arduino()
{
    data=A.read_from_arduino();
    QString code;
    if(data=="1")
        code="73 F4 62 A7";
    else if(data=="2")
        code="83 32 9D 92";
    QString DataAsString = QString(data);

    QSqlQueryModel *model= new QSqlQueryModel();

    QSqlQuery *query=new QSqlQuery;


    query->prepare("SELECT * FROM employes WHERE RFID  ='"+code+"'");
    query->exec();

    if(query->exec())
    {
    /*cout<<data.toStdString();*/
    model->setQuery(*query);
    ui->tableView_arduino->setModel(model);
    ui->tableView_arduino->show();
    //QDate cd = QDate::currentDate();
       QTime ct = QTime::currentTime();
        ui->le_date->setText(ct.toString());

    }



}



void MainWindow::on_pushButton_lcd_2_clicked()
{
    A.write_to_arduino("4");
}

void MainWindow::on_pushButton_lcd_3_clicked()
{
    A.write_to_arduino("5");
}

void MainWindow::on_pushButton_lcd_4_clicked()
{
    A.write_to_arduino("6");
}

void MainWindow::on_pushButton_lcd_5_clicked()
{
    A.write_to_arduino("7");
}



void MainWindow::on_pushButton_lcd_6_clicked()
{
    A.write_to_arduino("8");
}

void MainWindow::on_pushButton_lcd_clicked()
{
    A.write_to_arduino("3");
}
