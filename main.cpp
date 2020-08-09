#include <main.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon("appico.ico"));

    qDebug() << "db connection initializing...";
    QSqlDatabase hourDb;
    hourDb = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = QApplication::applicationDirPath() + "../db/db.sqlite";
    hourDb.setDatabaseName("../db/db.sqlite");
    qDebug() << "opening database: " << dbPath;

   //hourDb.setDatabaseName("/home/valentijn/GitRepos/HourRegistrationApp/db/db.sqlite");


    if(!hourDb.open())
    {
        qDebug() << "Error: database could not be opened!";

#ifndef DEBUG
        return -1;
#endif
    }


    Widget w;
    w.show();
    return app.exec();
}
