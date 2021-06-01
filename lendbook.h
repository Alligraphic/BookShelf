#ifndef LENDBOOK_H
#define LENDBOOK_H

#include <QDialog>
#include <QSettings>
#include <QMessageBox>
#include "data.h"

namespace Ui {
class Lendbook;
}

class Lendbook : public QDialog
{
    Q_OBJECT

public:
    explicit Lendbook(QList<book> * books, int bookCode, user* current, QWidget *parent = nullptr);
    ~Lendbook();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    QList<book> * books;
    int bookCode;
    Ui::Lendbook *ui;
};

#endif // LENDBOOK_H
