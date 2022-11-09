#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QDebug>


class connection
{
    QSqlDatabase db;
public:
    connection();
    bool createConnection();
};

#endif // CONNECTION_H

