#include "Login.h"
#include <iostream>
#include <QApplication>
#include <QSettings>
#include <QVariant>

QList<user> users;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w(&users);
    w.show();
    return a.exec();
}
