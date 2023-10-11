#include "ColorStaticApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ColorStaticApp w;
    w.show();
    return a.exec();
}
