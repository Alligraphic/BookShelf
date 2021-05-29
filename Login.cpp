
#include "dialog.h"
#include "ui_dialog.h"

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}


void Login::on_btnCncl_clicked()
{
    reject();
}

void Login::on_btnCrtAcc_clicked()
{
    SignUp w;
    this->hide();
    w.exec();
}
