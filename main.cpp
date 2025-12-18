#include <QApplication>

#include "LockWidget.h"

// ...Klasse LockWidget ist jetzt ausgelagert...

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LockWidget w;
    w.show();
    return a.exec();
}


