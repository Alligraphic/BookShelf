#include "dialog.h"
#include <QApplication>

class a
{};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.show();
    return a.exec();
}
