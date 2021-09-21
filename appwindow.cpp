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
    QPixmap quitpix("quit.png");

    QAction *openLog = new QAction("&Open new log", this);
    QAction *quit = new QAction("&Quit", this);

    QMenu *file;
    file = menuBar()->addMenu("&File");
    file->addAction(openLog);
    file->addAction(quit);

    connect(quit, &QAction::triggered, qApp, &QApplication::quit);

    QToolBar *toolbar = addToolBar("main toolbar");
    toolbar->addSeparator();

    QAction *quit2 = toolbar->addAction(QIcon(quitpix), "Quit application");
    closeLog = toolbar->addAction(QIcon(quitpix), "Close last log");

    connect(quit2, &QAction::triggered, this, &QApplication::quit);
    connect(openLog, &QAction::triggered, this, &AppWindow::openLogFile);

    editors.push_back(Logitem(new QTextEdit()));
    editors[0].textEdit->setEnabled(false);
    QBoxLayout * layout = new QBoxLayout(QBoxLayout::LeftToRight, this);
    setLayout(layout);
    defaultTab = new QTabWidget(this);
    defaultTab->addTab(editors[0].textEdit, "Default");
    editors[0].textEdit->append("You can view up to 4 logs");

    connect(closeLog, &QAction::triggered, this, &AppWindow::CloseLastTab);

    layout->addWidget(defaultTab);
    setCentralWidget(defaultTab);
}

void AppWindow::CloseLastTab()
{
    if(defaultTab->count() == 1)
    {
        closeLog->setEnabled(false);
        return;
    }

    defaultTab->removeTab(defaultTab->count() - 1);
    editors_count -= 1;
}

void AppWindow::readLog()
{    
    QFile * inputFile = editors[editors_count].logFile;
    if (inputFile->open(QIODevice::ReadOnly))
    {
       QTextStream in(inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          editors[editors_count].textEdit->append(line);
       }
       inputFile->close();
    }
}

void AppWindow::AddNewTab(QString tabTitle)
{

    defaultTab->addTab(editors[editors_count].textEdit, tabTitle);

    if(!closeLog->isEnabled())
    {
        closeLog->setEnabled(true);
    }
}

void AppWindow::openLogFile()
{
    editors_count += 1;
    QString log = QFileDialog::getOpenFileName(this, tr("Open Image"));
    editors[0].textEdit->append(log);
    editors.push_back(Logitem(new QTextEdit, new QFile(log)));
    AddNewTab(log + QString::number(editors_count));
    readLog();
}
