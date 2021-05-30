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
    explicit SignUp(QList<user>* users, QWidget *parent = nullptr);
    QList<user>* users;
    void save();
    ~SignUp();

private slots:
    void on_btnCncl_clicked();

    void on_btnExit_clicked();

    void on_btnSgnup_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
