#include "lendbook.h"
#include "ui_lendbook.h"

Lendbook::Lendbook(QList<book> * books, int bookCode, user * current, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lendbook)
{
    ui->setupUi(this);
    this->books = books;
    this->bookCode = bookCode;
    this->setFixedSize(this->size());
    QPalette pal;
    QColor gray, red;
    gray.setRgb(200,200,200);
    red.setRgb(170,0,0);
    pal.setColor(QPalette::Window, gray);
    pal.setColor(QPalette::Highlight, red);
    this->setPalette(pal);
    this->setWindowTitle("Lend Book");
    ui->lneTaker->setText(current->usrnm);
}

Lendbook::~Lendbook()
{
    delete ui;
}

void Lendbook::on_buttonBox_rejected()
{
    reject();
}

void Lendbook::on_buttonBox_accepted()
{
    (*books)[bookCode].available = false;
    (*books)[bookCode].takenBy = ui->lneTaker->text();
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

    QMessageBox::information(this, "Lended", "Book lended successfully.");
    this->accept();
}
