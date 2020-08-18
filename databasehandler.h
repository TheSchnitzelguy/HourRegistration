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
    static bool createNewDatabase(QSqlDatabase db);
    static void removeDatabase(QSqlDatabase db);
    void insertJob(QDate jobDate, QTime workedHours, QTime startTime, QTime endTime, QString annotation, bool pause);
    bool checkJob();
    bool checkForExistingTables(QSqlDatabase db);


private:
    QString databaseLocation;

};



#endif // DATABASEHANDLER_H
