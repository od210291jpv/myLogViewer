#include "appwindow.h"
#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include<QMainWindow>
#include<QTabWidget>
#include <QBoxLayout>
#include <QTextEdit>

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
    QAction *closeLog = toolbar->addAction(QIcon(quitpix), "Close last log");

    connect(quit2, &QAction::triggered, this, &QApplication::quit);


    edit = new QTextEdit();
    QBoxLayout * layout = new QBoxLayout(QBoxLayout::LeftToRight, this);
    setLayout(layout);
    defaultTab = new QTabWidget(this);
    defaultTab->addTab(edit, "Tab1");
    edit->append("You can view up to 5 logs");

    connect(closeLog, &QAction::triggered, this, &AppWindow::CloseLastTab);

    layout->addWidget(defaultTab);
    setCentralWidget(defaultTab);
}

void AppWindow::CloseLastTab()
{
    defaultTab[defaultTab->count() - 1].close();
}

void AppWindow::AddNewTab(QString tabTitle)
{
    //defaultTab->addTab();
}
