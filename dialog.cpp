
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnCncl_clicked()
{
    reject();
}

void Dialog::on_btnCrtAcc_clicked()
{
    SignUp w;
    this->hide();
    w.exec();
}
