#include <main.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon("appico.ico"));

    /*initialize and create database*/
    qDebug() << "db connection initializing...";
    QSqlDatabase hourDb;
    hourDb = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = "../db/db.sqlite";
    hourDb.setDatabaseName(dbPath);
    qDebug() << "opening database: " << dbPath;


    if(!hourDb.open())
    {
        QMessageBox dbNotLoaded;
        dbNotLoaded.critical(0, "Error", "Database could not be opened!");
        qDebug() << "Error: database could not be opened: " << hourDb.lastError();

#ifndef DEBUG
        return -1;
#endif
    }

   // if(hourDb.tables()contains(QLatin1String("records")))
    //{

    //}


    Widget w;
    w.show();
    return app.exec();
}
