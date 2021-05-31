#include "Login.h"
#include "ui_dialog.h"

Login::Login(QList<user>* users, QList<book> *books, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{

    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->setWindowTitle("Login");
    this->users = users;
    this->books = books;
    ui->lnePass->setEchoMode(QLineEdit::Password);
    connect(ui->btnLogin, &QPushButton::clicked , this, &Login::login);
    ui->lneUsrnm->setText(users->at(0).usrnm);
    ui->lnePass->setText(users->at(0).pass);
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
    SignUp w(this->users, this->books);
    this->hide();
    w.exec();
}

void Login::login()
{
    bool cp = false;
    for (int i = 0  ; i < (*users).count() ; i++)
        if ((*users)[i].isMatched(ui->lneUsrnm->text(), ui->lnePass->text()))
        {
            cp = true;
            MainWindow * w = new MainWindow(this->users, this->books);
            this->hide();
            w->show();
//            delete w;
            break;
        }
    if (!cp)
    {
        QMessageBox::critical(this, "Error", "Incorrect username or password.");
    }

}
