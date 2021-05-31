#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QDialog>
#include <QMessageBox>
#include <QSettings>
#include "data.h"

namespace Ui {
class addBook;
}

class addBook : public QDialog
{
    Q_OBJECT

public:
    explicit addBook(QList<book> *books, QWidget *parent = nullptr);

    ~addBook();

private slots:
    void save();

    void on_btnCancel_clicked();

private:
    QList<book> * books;
    Ui::addBook *ui;
};

#endif // ADDBOOK_H
