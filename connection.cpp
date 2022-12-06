#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("salimbch6");//inserer nom de l'utilisateur
db.setPassword("salim666");//inserer mot de passe de cet utilisateur

if (db.open())test=true;
test=true;





    return  test;
}
void Connection::closeConnection(){db.close();}
