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
    this->books = books;
    loadCombo();
}

DeleteBooks::~DeleteBooks()
{
    delete ui;
}

void DeleteBooks::loadCombo()
{
    ui->comboDelete->clear();
    for (int i = 0 ; i < books->count() ; i++)
        ui->comboDelete->addItem(books->at(1).bookname);
}
