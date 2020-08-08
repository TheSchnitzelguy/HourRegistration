#include "widget.h"

#include <QApplication>
#include <QIcon>
//#define WIN32

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
#ifdef WIN32
    app.setWindowIcon(QIcon("appico.ico"));
#endif
    Widget w;
    w.show();
    return app.exec();
}
