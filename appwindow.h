#ifndef APPWINDOW_H
#define APPWINDOW_H
#include <QMainWindow>
#include <QApplication>
#include <QTabWidget>
#include<QTextEdit>
#include <QAction>
#include <vector>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <logitem.h>

class AppWindow : public QMainWindow
{

Q_OBJECT

public:
    AppWindow(QWidget *parent = 0);

public slots:
    void CloseLastTab();
    void openLogFile();

protected:
    void AddNewTab(QString tabTitle);
    std::vector<Logitem> editors;
    void readLog();

private:
    QTabWidget * defaultTab;
    QAction *closeLog;
    unsigned long long editors_count = 0;
};

#endif // APPWINDOW_H
