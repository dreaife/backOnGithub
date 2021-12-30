#include "widget.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login w;
    //Widget w;
    w.show();

    return a.exec();
}
