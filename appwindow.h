#ifndef APPWINDOW_H
#define APPWINDOW_H
#include <QMainWindow>
#include <QApplication>
#include <QTabWidget>
#include<QTextEdit>
#include <QAction>
#include <array>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

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
    std::array<QTextEdit *, 5> editors;
    void readLog(QString logPath);

private:
    QTabWidget * defaultTab;
    QTextEdit *edit;   
    QAction *closeLog;
    unsigned long long editors_count = 0;
};

#endif // APPWINDOW_H
