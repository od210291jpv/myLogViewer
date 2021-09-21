#include "logitem.h"

Logitem::Logitem(QTextEdit * pTabEditor) : textEdit(pTabEditor)
{}

Logitem::Logitem(QTextEdit * pTabEditor, QFile * logF) : textEdit(pTabEditor), logFile(logF){}

Logitem::~Logitem()
{
}
