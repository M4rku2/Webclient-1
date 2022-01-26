#include "webclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Webclient w;
    w.show(); // d

    return a.exec();
}
