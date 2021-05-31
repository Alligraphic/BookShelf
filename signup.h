#include <iostream>
using namespace std;

#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "Login.h"
#include "data.h"

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QList<user>* users, QList<book>* books, QWidget *parent = nullptr);

    ~SignUp();

private slots:
    void on_btnCncl_clicked();

    void on_btnExit_clicked();

    void on_btnSgnup_clicked();

private:
    QList<user>* users;
    QList<book>* books;
    void save();
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
