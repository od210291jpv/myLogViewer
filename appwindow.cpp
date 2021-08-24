#include "appwindow.h"
#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include<QMainWindow>

AppWindow::AppWindow(QWidget *parent) : QMainWindow(parent)
{
    QPixmap newpix("new.png");
    QPixmap openpix("open.png");
    QPixmap quitpix("quit.png");

    QAction *quit = new QAction("&Quit", this);
    QAction *openLog = new QAction("&Open new log", this);

    QMenu *file;
    file = menuBar()->addMenu("&File");
    file->addAction(quit);
    file->addAction(openLog);

    connect(quit, &QAction::triggered, qApp, &QApplication::quit);

    QToolBar *toolbar = addToolBar("main toolbar");
    toolbar->addAction(QIcon(openpix), "Open File");
    toolbar->addSeparator();

    QAction *quit2 = toolbar->addAction(QIcon(quitpix), "Quit application");
    connect(quit2, &QAction::triggered, qApp, &QApplication::quit);
}
