#ifndef EDITBOOK_H
#define EDITBOOK_H

#include <QDialog>
#include <QSettings>
#include <QMessageBox>
#include <data.h>

namespace Ui {
class editBook;
}

class editBook : public QDialog
{
    Q_OBJECT

public:
    explicit editBook(QList<book> * books, int bookCode, QWidget *parent = nullptr);
    ~editBook();

private slots:

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::editBook *ui;
    QList<book> * books;
    int bookCode;
};

#endif // EDITBOOK_H
