#include "mainwindow.h"
#include "ui_mainwindow.h"

QList<QTableWidgetItem*> titles;
QList<QTableWidgetItem*> athors;
QList<QTableWidgetItem*> releases;
QList<QTableWidgetItem*> groups;
QList<QTableWidgetItem*> availables;
QList<QTableWidgetItem*> takers;
QList<QTableWidgetItem*> codes;
QList<book> resBooks;

MainWindow::MainWindow(QList<user> *users, QList<book> * books, user * current, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->users = users;
    this->books = books;
    resBooks = *books;
    this->current = current;
    connect(ui->actionAdd_book, &QAction::triggered, this, &MainWindow::openDia);
    connect(ui->actionRemove_book, &QAction::triggered, this, &MainWindow::deleteDia);
    QPalette pal;
    QColor gray, red, redBase;
    gray.setRgb(200,200,200);
    red.setRgb(170,0,0);
    pal.setColor(QPalette::Window, gray);
    pal.setColor(QPalette::Highlight, red);
    this->setPalette(pal);
    loadTable();
}

MainWindow::~MainWindow()
{
    delete ui;
    destroyItems();
}

void MainWindow::openDia()
{
    addBook w(books);
    w.exec();
    resBooks = *books;
    updateTable();
}

void MainWindow::deleteDia()
{
    DeleteBooks w(books);
    w.exec();
    resBooks = *books;
    updateTable();
}

void MainWindow::updateTable()
{
    ui->tableWidget->clearContents();
    destroyItems();
    loadTable();
}

void MainWindow::updateTableWith(QList<book> *booksLst)
{
    destroyItems();
    ui->tableWidget->clearContents();
    loadTableWith(booksLst);
}

void MainWindow::loadTable()
{
    destroyItems();
    ui->tableWidget->setRowCount(books->count());

    for (int i = 0 ; i < books->count() ; i++)
    {
        QColor red, green, redbase, greenbase;
        redbase.setRgb(255,220,220);
        greenbase.setRgb(220,255,220);
        red.setRgb(170, 0, 0);
        green.setRgb(20, 150, 15);
        QFont font;
        font.setBold(true);

        QTableWidgetItem *title = new QTableWidgetItem;
        QTableWidgetItem *athor = new QTableWidgetItem;
        QTableWidgetItem *release = new QTableWidgetItem;
        QTableWidgetItem *group = new QTableWidgetItem;
        QTableWidgetItem *available = new QTableWidgetItem;
        QTableWidgetItem *taker = new QTableWidgetItem;
        QTableWidgetItem *code = new QTableWidgetItem;

        title->setText(books->at(i).bookname);
        title->setBackgroundColor((books->at(i).available)?greenbase:redbase);
        athor->setText(books->at(i).athor);
        athor->setBackgroundColor((books->at(i).available)?greenbase:redbase);
        release->setText(books->at(i).release);
        release->setBackgroundColor((books->at(i).available)?greenbase:redbase);
        group->setText(books->at(i).group);
        group->setBackgroundColor((books->at(i).available)?greenbase:redbase);
        available->setText((books->at(i).available)?"Yes":"No");
        available->setTextColor((books->at(i).available)?green:red);
        available->setBackgroundColor((books->at(i).available)?greenbase:redbase);
        available->setFont(font);
        taker->setText(books->at(i).takenBy);
        taker->setBackgroundColor((books->at(i).available)?greenbase:redbase);
        code->setText(QString(i));

        titles.append(title);
        athors.append(athor);
        releases.append(release);
        groups.append(group);
        availables.append(available);
        takers.append(taker);
        codes.append(code);
    }

    for ( int i = 0 ; i < books->count() ; i++)
    {
        ui->tableWidget->setItem(i, 0, titles[i]);
        ui->tableWidget->setItem(i, 1, athors[i]);
        ui->tableWidget->setItem(i, 2, releases[i]);
        ui->tableWidget->setItem(i, 3, groups[i]);
        ui->tableWidget->setItem(i, 4, availables[i]);
        ui->tableWidget->setItem(i, 5, takers[i]);
    }
}

void MainWindow::loadTableWith(QList<book> *booksLst)
{
    ui->tableWidget->setRowCount(booksLst->count());

    for (int i = 0 ; i < booksLst->count() ; i++)
    {
        QColor red, green, redbase, greenbase;
        redbase.setRgb(255,220,220);
        greenbase.setRgb(220,255,220);
        red.setRgb(170, 0, 0);
        green.setRgb(20, 150, 15);
        QFont font;
        font.setBold(true);

        QTableWidgetItem *title = new QTableWidgetItem;
        QTableWidgetItem *athor = new QTableWidgetItem;
        QTableWidgetItem *release = new QTableWidgetItem;
        QTableWidgetItem *group = new QTableWidgetItem;
        QTableWidgetItem *available = new QTableWidgetItem;
        QTableWidgetItem *taker = new QTableWidgetItem;
        QTableWidgetItem *code = new QTableWidgetItem;

        title->setText(booksLst->at(i).bookname);
        title->setBackgroundColor((booksLst->at(i).available)?greenbase:redbase);
        athor->setText(booksLst->at(i).athor);
        athor->setBackgroundColor((booksLst->at(i).available)?greenbase:redbase);
        release->setText(booksLst->at(i).release);
        release->setBackgroundColor((booksLst->at(i).available)?greenbase:redbase);
        group->setText(booksLst->at(i).group);
        group->setBackgroundColor((booksLst->at(i).available)?greenbase:redbase);
        available->setText((booksLst->at(i).available)?"Yes":"No");
        available->setTextColor((booksLst->at(i).available)?green:red);
        available->setBackgroundColor((booksLst->at(i).available)?greenbase:redbase);
        available->setFont(font);
        taker->setText(booksLst->at(i).takenBy);
        taker->setBackgroundColor((booksLst->at(i).available)?greenbase:redbase);
        code->setText(QString(i));

        titles.append(title);
        athors.append(athor);
        releases.append(release);
        groups.append(group);
        availables.append(available);
        takers.append(taker);
        codes.append(code);
    }

    for ( int i = 0 ; i < booksLst->count() ; i++)
    {
        ui->tableWidget->setItem(i, 0, titles[i]);
        ui->tableWidget->setItem(i, 1, athors[i]);
        ui->tableWidget->setItem(i, 2, releases[i]);
        ui->tableWidget->setItem(i, 3, groups[i]);
        ui->tableWidget->setItem(i, 4, availables[i]);
        ui->tableWidget->setItem(i, 5, takers[i]);
    }
}

QString MainWindow::getOption(QObject *obj)
{
    {
        QString value = "None";
        QList<QRadioButton*> lst = obj->findChildren<QRadioButton*>(QString(),Qt::FindDirectChildrenOnly);

        foreach(QRadioButton* rdo, lst)
        {
            if(rdo->isChecked())
            {
                value = rdo->text();
                break;
            }
        }

        return value;
    }
}

void MainWindow::createSrchList(QString group, QString title)
{
    resBooks.clear();
    for (int i = 0 ; i < books->count() ; i++)
    {
        if (books->at(i).group == group && books->at(i).bookname.contains(title))
        {
            resBooks.append(books->at(i));
        }
    }
}

void MainWindow::destroyItems()
{
    for (int i = 0 ; i < titles.count() ; i++)
    {

        delete titles[i];
        delete athors[i];
        delete releases[i];
        delete groups[i];
        delete availables[i];
        delete takers[i];
        delete codes[i];
    }
    titles.clear();
    athors.clear();
    releases.clear();
    groups.clear();
    availables.clear();
    takers.clear();
    codes.clear();
}

void MainWindow::on_btnAddBook_clicked()
{
    openDia();
}

void MainWindow::on_lneSrch_textEdited(const QString &arg1)
{
    QString selectedGrp = getOption(ui->grpSearch);

    createSrchList(selectedGrp, arg1);
    qDebug() << arg1;
    updateTableWith(&resBooks);
}

void MainWindow::on_btnDeleteBook_clicked()
{
    deleteDia();
    resBooks = *books;
    updateTable();
}

void MainWindow::on_btnSrch_clicked()
{
    on_lneSrch_textEdited(ui->lneSrch->text());
}

void MainWindow::on_btnLendBook_clicked()
{
    qDebug() << ui->tableWidget->currentRow();
    Lendbook w(books, resBooks.at(ui->tableWidget->currentRow()).code, current);
    w.exec();
    updateTable();
}

void MainWindow::on_btnReturn_clicked()
{
    (*books)[resBooks.at(ui->tableWidget->currentRow()).code].available = true;
    (*books)[resBooks.at(ui->tableWidget->currentRow()).code].takenBy = "";
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

    QMessageBox::information(this, "Returned", "Book returned successfully.");
    updateTable();
}
