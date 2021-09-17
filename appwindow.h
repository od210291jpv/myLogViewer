#ifndef APPWINDOW_H
#define APPWINDOW_H
#include <QMainWindow>
#include <QApplication>
#include <QTabWidget>
#include<QTextEdit>
#include <QAction>

class AppWindow : public QMainWindow
{

Q_OBJECT

public:
    AppWindow(QWidget *parent = 0);

public slots:
    void CloseLastTab();

protected:
    void AddNewTab(QString tabTitle);
private:
    QTabWidget * defaultTab;
    QTextEdit *edit;
};

#endif // APPWINDOW_H
