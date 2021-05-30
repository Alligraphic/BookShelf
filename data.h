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


#endif // DATA_H
