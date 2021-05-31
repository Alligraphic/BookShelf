#ifndef DELETEBOOKS_H
#define DELETEBOOKS_H

#include <QDialog>
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

private:
    void loadCombo();
    QList<book> *books;
    Ui::DeleteBooks *ui;
};

#endif // DELETEBOOKS_H
