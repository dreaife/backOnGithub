#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w  = new MainWindow;
    w->setWindowTitle("MouseEvent Demo");
        w->resize(300, 200);
        w->show();
    return a.exec();
}
