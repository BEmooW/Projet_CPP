#include "mainwindow.h"
#include "connection.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connection c;
    bool test=c.createConnection();
    if(test)
    {
        w.show();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),QObject::tr("connection failed.\n""Click Cancel to exit."), QMessageBox::Cancel);    }
    return a.exec();
}
