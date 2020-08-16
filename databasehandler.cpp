#include "databasehandler.h"


databaseHandler::databaseHandler(QString x)
{
    databaseLocation = x;
    initializeDatabase();
}

/*!
*@brief Function that initializes a database connection that is passed by the constructor
*@param None*/
void databaseHandler::initializeDatabase()
{
    /*initialize and create database*/    
    qDebug() << "db connection initializing...";
    QSqlDatabase hourDb;
    hourDb = QSqlDatabase::addDatabase("QSQLITE");
    //QString dbPath = "../db/db.sqlite";
    hourDb.setDatabaseName(databaseLocation);
    qDebug() << "opening database: " << databaseLocation;


    if(!hourDb.open())
    {
        QMessageBox dbNotLoaded;
        dbNotLoaded.critical(0, "Error", "Database could not be opened!");
        qDebug() << "Error: database could not be opened: " << hourDb.lastError();

    #ifndef DEBUG
         // If database could not be laoded, kill application and return error
        QCoreApplication::exit(1);
    #endif
    }



    // if(hourDb.tables()contains(QLatin1String("records")))
    //{

    //}
}

void databaseHandler::createTables()
{

}

void databaseHandler::insertJob()
{

}

bool databaseHandler::checkJob()
{

}







