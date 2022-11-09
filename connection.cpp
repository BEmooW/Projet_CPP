#include <QDebug>
#include "connection.h"

connection::connection(){}

bool connection::createConnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("2Aprojet");
    db.setUserName("system");
    db.setPassword("chedli2001");

    if (db.open()) test=true;
    return test;
}

