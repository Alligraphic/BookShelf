#include "data.h"

bool user::isMatched(QString ursnm, QString pass)
{
    if (this->usrnm == ursnm && this->pass == pass)
        return true;
    return false;
}

book::book()
{
    this->release = "";
}
