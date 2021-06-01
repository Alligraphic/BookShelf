#ifndef DATA_H
#define DATA_H

#include <QString>
#include <QList>

class user
{
public:
    QString usrnm;
    QString pass;

    bool isMatched(QString usrnm, QString pass);
};

class book
{
public:
    QString bookname;
    QString athor;
    QString release;
    QString group;
    bool available;
    QString takenBy;
    int code;
    book();
};


#endif // DATA_H
