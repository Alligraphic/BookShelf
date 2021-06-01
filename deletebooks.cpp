#include "deletebooks.h"
#include "ui_deletebooks.h"
#include"QDebug"

DeleteBooks::DeleteBooks(QList<book> * books, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteBooks)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    QPalette pal;
    QColor gray, red;
    gray.setRgb(200,200,200);
    red.setRgb(170,0,0);
    pal.setColor(QPalette::Window, gray);
    pal.setColor(QPalette::Highlight, red);
    this->setPalette(pal);
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
        ui->comboDelete->addItem(books->at(i).bookname);
}

void DeleteBooks::on_buttonBox_accepted()
{
    books->removeAt(ui->comboDelete->currentIndex());
    QSettings Books("Alireza", "BookShelf");
    Books.beginWriteArray("books");
    for (int i = 0 ; i < books->count();i++)

    {
        Books.setArrayIndex(i);
        Books.setValue("bookname", books->at(i).bookname);
        Books.setValue("athor", books->at(i).athor);
        Books.setValue("release", books->at(i).release);
        Books.setValue("group", books->at(i).group);
        Books.setValue("available", books->at(i).available);
        Books.setValue("taken", books->at(i).takenBy);
    }Books.endArray();

    QMessageBox::information(this, "Deleted", "Book Deleted successfully.");
    this->accept();
}

void DeleteBooks::on_buttonBox_rejected()
{
    reject();
}
