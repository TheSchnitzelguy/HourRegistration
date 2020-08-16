#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include "main.h"

//#include <QDebug>
//#include <QString>
#include <QtSql>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlQuery>


class databaseHandler
{
public:
    databaseHandler(QString x);
    void initializeDatabase();
    void createTables();
    void insertJob();
    bool checkJob();

private:
    QString databaseLocation;

};



#endif // DATABASEHANDLER_H
