//#include "mainwindow.h"
#include <QApplication>
#include "appwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppWindow w;
    w.resize(400, 400);
    w.setWindowTitle("MyLogViewer");
    w.show();

    return a.exec();
}
