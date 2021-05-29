#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "signup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Login : public QDialog
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btnCncl_clicked();

    void on_btnCrtAcc_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
