#ifndef CONNECTION_H
#define CONNECTION_H
#include"QSqlDatabase"
#include <QtSql>
#include <QMessageBox>

class Connection
{
public:
    Connection();
    bool createconnection();
};

#endif // CONNECTION_H
