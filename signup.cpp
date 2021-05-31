#include "signup.h"
#include "ui_signup.h"

SignUp::SignUp(QList<user>* users, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());

    ui->lnePass->setEchoMode(QLineEdit::Password);
    ui->lneConfPass->setEchoMode(QLineEdit::Password);

    this->users = users;
}

void SignUp::save()
{
    QSettings usrs("Alireza", "BookShelf");
    usrs.beginWriteArray("users");
    for (int i = 0 ; i < users->count() ; i++)
    {
        usrs.setArrayIndex(i);
        usrs.setValue("username", users->at(i).usrnm);
        usrs.setValue("pass", users->at(i).pass);
    }
    usrs.endArray();
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_btnCncl_clicked()
{
    Login w(this->users);
    this->hide();
    w.exec();
}

void SignUp::on_btnExit_clicked()
{
    reject();
}

void SignUp::on_btnSgnup_clicked()
{
    if (ui->lnePass->text() == ui->lneConfPass->text())
    {
        user tmp;
        tmp.usrnm = ui->lneUsrnm->text();
        tmp.pass = ui->lnePass->text();
        users->append(tmp);
        this->save();
        QMessageBox::information(this, "","Account created successfully.");
        Login w(this->users);
        this->hide();
        w.exec();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Passwords doesn't match.");
    }
}
