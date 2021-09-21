#ifndef LOGITEM_H
#define LOGITEM_H
#include<QTextEdit>
#include <QFile>

class Logitem
{
public:
    QTextEdit * textEdit;
    Logitem(QTextEdit * pTabEditor);
    Logitem(QTextEdit * pTabEditor, QFile * logF);
    QFile * logFile;
    ~Logitem();
};

#endif // LOGITEM_H
