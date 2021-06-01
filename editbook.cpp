#include "editbook.h"
#include "ui_editbook.h"

editBook::editBook(QList<book> * books, int bookCode, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editBook)
{
    ui->setupUi(this);
    this->books = books;
    this->bookCode = bookCode;
    QPalette pal;
    QColor gray, red;
    gray.setRgb(200,200,200);
    red.setRgb(170,0,0);
    pal.setColor(QPalette::Window, gray);
    pal.setColor(QPalette::Highlight, red);
    this->setPalette(pal);
    this->setWindowTitle("Edit a book");

    ui->lneBookName->setText(books->at(bookCode).bookname);
    ui->lneAuthor->setText(books->at(bookCode).athor);
    ui->lneRelease->setText(books->at(bookCode).release);
    ui->comboGrps->setCurrentText(books->at(bookCode).group);
}

editBook::~editBook()
{
    delete ui;
}

void editBook::on_buttonBox_rejected()
{
    reject();
}

void editBook::on_buttonBox_accepted()
{
    (*books)[bookCode].bookname = ui->lneBookName->text();
    (*books)[bookCode].athor = ui->lneAuthor->text();
    (*books)[bookCode].release = ui->lneRelease->text();
    (*books)[bookCode].group = ui->comboGrps->currentText();
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
        Books.setValue("code", i);
    }Books.endArray();

    QMessageBox::information(this, "Edited", "Book edited successfully.");
    this->accept();
}
