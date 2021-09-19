#ifndef APPWINDOW_H
#define APPWINDOW_H
#include <QMainWindow>
#include <QApplication>
#include <QTabWidget>
#include<QTextEdit>
#include <QAction>
#include <array>
#include <QFileDialog>

class AppWindow : public QMainWindow
{

Q_OBJECT

public:
    AppWindow(QWidget *parent = 0);

public slots:
    void CloseLastTab();
    QString openLogFile();

protected:
    void AddNewTab(QString tabTitle, QTextEdit * tab_editor);
    std::array<QTextEdit *, 5> editors;

private:
    QTabWidget * defaultTab;
    QTextEdit *edit;   
};

#endif // APPWINDOW_H
