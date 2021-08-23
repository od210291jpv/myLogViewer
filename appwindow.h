#ifndef APPWINDOW_H
#define APPWINDOW_H
#include <QMainWindow>
#include <QApplication>

class AppWindow : public QMainWindow
{

Q_OBJECT

public:
    AppWindow(QWidget *parent = 0);
};

#endif // APPWINDOW_H
