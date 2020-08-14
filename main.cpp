#include <main.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon("appico.ico"));



    Widget w;
    w.show();
    return app.exec();
}
