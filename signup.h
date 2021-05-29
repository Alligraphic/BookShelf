#include <iostream>
using namespace std;

#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "dialog.h"

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_btnCncl_clicked();

    void on_btnExit_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
