#include "hub.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Hub w;
    w.show();
    return a.exec();
}
