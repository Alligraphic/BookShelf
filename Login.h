#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "signup.h"
#include "mainwindow.h"
#include "data.h"
#include <QSettings>
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Login : public QDialog
{
    Q_OBJECT

public:
    Login(QList<user> *users, QList<book> * books, QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btnCncl_clicked();

    void on_btnCrtAcc_clicked();

    void login();

private:
    QList<user>* users;
    QList<book>* books;
    Ui::Dialog *ui;
};
#endif // DIALOG_H
