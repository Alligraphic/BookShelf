#include "Login.h"
#include "ui_dialog.h"

Login::Login(QList<user>* users, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{

    ui->setupUi(this);
    this->setFixedSize(this->size());

    ui->lnePass->setEchoMode(QLineEdit::Password);

    this->users = users;
    connect(ui->btnLogin, &QPushButton::clicked , this, &Login::login);
    QSettings usrs("Alireza", "BookShelf");
    int size =usrs.beginReadArray("users");
    qDebug() << size;
    for ( int i = 0 ; i < size ; i++)
    {
        usrs.setArrayIndex(i);
        user tmp;
        tmp.usrnm = usrs.value("username","").toString();
        tmp.pass = usrs.value("pass","").toString();
        users->append(tmp);
    }

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
    SignUp w(this->users);
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

            break;
        }
    if (!cp)
    {
        QMessageBox::critical(this, "Error", "Incorrect username or password.");
    }

}
