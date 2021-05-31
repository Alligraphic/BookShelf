#include "Login.h"
#include <iostream>
#include <QApplication>
#include <QSettings>
#include <QVariant>

QList<user> users;
QList<book> books;

void loadBooks()
{
    QSettings Books("Alireza", "BookShelf");
    int size = Books.beginReadArray("books");
    for (int i = 0 ; i < size ; i++)
    {
        Books.setArrayIndex(i);
        book tmp;
        tmp.bookname = Books.value("bookname","").toString();
        tmp.release = Books.value("release","").toString();
        tmp.group = Books.value("group","").toString();
        books.append(tmp);
    }
}

void loadUsers()
{
    QSettings usrs("Alireza", "BookShelf");
    int size =usrs.beginReadArray("users");
    qDebug() << size;
    for ( int i = 0 ; i < size ; i++)
    {
        usrs.setArrayIndex(i);
        user tmp;
        tmp.usrnm = usrs.value("username","").toString();
        tmp.pass = usrs.value("pass","").toString();
        users.append(tmp);
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loadUsers();
    loadBooks();
    Login w(&users, &books);
    w.show();
    return a.exec();
}
