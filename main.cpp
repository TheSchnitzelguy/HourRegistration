#include <main.h>
#include <databasehandler.h>

int main(int argc, char *argv[])
{  
    //Sets the database path on the filesystem, TODO: make this specifiable via a QDialog
    QString databasePath = "../db/db.sqlite";


    databaseHandler db(databasePath);
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon("appico.ico"));


    Widget w;
    w.show();
    return app.exec();
}
