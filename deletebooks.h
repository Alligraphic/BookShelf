#ifndef DELETEBOOKS_H
#define DELETEBOOKS_H

#include <QDialog>
#include <QSettings>
#include <QMessageBox>
#include "data.h"

namespace Ui {
class DeleteBooks;
}

class DeleteBooks : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteBooks(QList<book> * books, QWidget *parent = nullptr);
    ~DeleteBooks();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    void loadCombo();
    QList<book> *books;
    Ui::DeleteBooks *ui;
};

#endif // DELETEBOOKS_H
