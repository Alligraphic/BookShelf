#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "signup.h"
#include "QMessageBox"
#include "data.h"
#include <QSettings>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Login : public QDialog
{
    Q_OBJECT

public:
    QList<user>* users;
    Login(QList<user> *users,QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btnCncl_clicked();

    void on_btnCrtAcc_clicked();

    void login();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
