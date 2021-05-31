#include "addbook.h"
#include "ui_addbook.h"

addBook::addBook(QList<book> * books, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addBook)
{
    ui->setupUi(this);
    this->books = books;
    this->setFixedSize(this->size());
    this->setWindowTitle("Add a book");
    connect(ui->btnAdd, &QPushButton::clicked, this, &addBook::save);
}

addBook::~addBook()
{
    delete ui;
}

void addBook::save()
{
    book tmp;
    tmp.bookname = ui->lneBookName->text();
    tmp.athor = ui->lneAthor->text();
    tmp.release = ui->lneRelease->text();
    tmp.group = ui->comboGroup->currentText();
    books->append(tmp);
    QSettings Books("Alireza", "BookShelf");
    int size = Books.beginReadArray("books");
    Books.beginWriteArray("books");
    Books.setArrayIndex(size);
    Books.setValue("bookname", books->at(size).bookname);
    Books.setValue("athor", books->at(size).athor);
    Books.setValue("release", books->at(size).release);
    Books.setValue("group", books->at(size).group);
    Books.endArray();
    QMessageBox::information(this, "Saved", "Book added successfully.");
    this->accept();
}

void addBook::on_btnCancel_clicked()
{
    reject();
}
