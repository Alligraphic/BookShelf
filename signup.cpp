
#include "signup.h"
#include "ui_signup.h"

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_btnCncl_clicked()
{
    Dialog w;
    this->hide();
    w.exec();
}

void SignUp::on_btnExit_clicked()
{
    reject();
}
