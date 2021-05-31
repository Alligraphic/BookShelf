#include "deletebooks.h"
#include "ui_deletebooks.h"
#include"QDebug"

DeleteBooks::DeleteBooks(QList<book> * books, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteBooks)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->setWindowTitle("Delete book");
    loadCombo();

    this->books = books;
}

DeleteBooks::~DeleteBooks()
{
    delete ui;
}

void DeleteBooks::loadCombo()
{
//    ui->comboDelete->clear();
//    for (int i = 0 ; i < books->count() ; i++)
    qDebug() << books->at(0).bookname;
        ui->comboDelete->addItem(books->at(1).bookname);
}
