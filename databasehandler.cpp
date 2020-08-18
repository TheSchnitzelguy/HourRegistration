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
    bool databaseCreated = false;
    /*initialize and create database*/    
    qDebug() << "db connection initializing...";
    QSqlDatabase hourDb;
    hourDb = QSqlDatabase::addDatabase("QSQLITE");
    //QString dbPath = "../db/db.sqlite";
    hourDb.setDatabaseName(databaseLocation);
    qDebug() << "opening database: " << databaseLocation;

    //first, check if connection with SQL driver can be established
    if(hourDb.open())
    {
        qDebug() << "Database opened!" ;
        //if(hourDb.tables()contains(QLatin1String("Dates")))
        createNewDatabase(hourDb);
        //removeDatabase(hourDb);
    }
    else if(!hourDb.open())
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

bool databaseHandler::createNewDatabase(QSqlDatabase db)
{
    QSqlQuery dbQuery;

    QString dateTable = "CREATE TABLE Dates("
                        "jobID integer NOT NULL PRIMARY KEY AUTOINCREMENT,"
                        "anoID integer NOT NULL,"
                        "timeID integer NOT NULL,"
                        "date TEXT(10),"
                        "FOREIGN KEY (anoID)"
                            "REFERENCES Annotations (anoID),"
                        "FOREIGN KEY (timeID)"
                            "REFERENCES Times (timeID));";

    QString annotationTable = " CREATE TABLE Annotations("
                              "anoID integer NOT NULL PRIMARY KEY AUTOINCREMENT,"
                              "annotation VARCHAR(128));";

    QString timesTable = " CREATE TABLE Times("
                          "timeID integer NOT NULL PRIMARY KEY AUTOINCREMENT,"
                          "workedHours TEXT(5),"
                          "startingTime TEXT(5),"
                          "endingTime TEXT(5),"
                          "pause BOOLEAN);";

  //  QString fullNewDatabaseQuery = dateTable + annotationTable + timesTable;


#ifdef DEBUG
    qDebug() << "Inserting the following queries into database: \n" << dateTable <<annotationTable << timesTable;
#endif

//TODO: fix this

    if (dbQuery.exec(dateTable) && dbQuery.exec(annotationTable) && dbQuery.exec(timesTable) == true)
    {
         qDebug() << "Succesfully created database tables!";
         return true;
    }
    else
    {
        qDebug() << "Error, tables could not be inserted!" << dbQuery.lastError();
        return false;
    }


    db.close();
}

void databaseHandler::removeDatabase(QSqlDatabase db)
{
    QSqlQuery dbQuery;
    QString emptyDates = "DROP TABLE IF EXISTS Dates;";
    QString emptyAnnotations = " DROP TABLE IF EXISTS Annotations;";
    QString emptyTimes = " DROP TABLE IF EXISTS Times;";


    if (dbQuery.exec(emptyDates) && dbQuery.exec(emptyAnnotations) && dbQuery.exec(emptyTimes) == true)
    {
        qDebug() << "Running statements: " << emptyDates << emptyAnnotations << emptyTimes;
        qDebug() << "Successfully deleted all tables from database!" ;
    }
    else
    {
        qDebug() << "Error! could not clear database. Reason:" << dbQuery.lastError();
    }

    db.close();
}

void databaseHandler::insertJob(QDate jobDate, QTime startTime, QTime endTime, bool pause)
{
    int year = 2020;
    QSqlQuery dateQuery, anotationQuery, timesQuery;

    dateQuery.prepare("INSERT INTO Dates ("
                      "date,"
                      "year)"
                      "VALUES (?,?);");

    dateQuery.addBindValue(jobDate);
    dateQuery.addBindValue(year);
}

bool databaseHandler::checkJob()
{

}







