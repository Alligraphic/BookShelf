#include "mainwindow.h"
#include "ui_mainwindow.h"

QList<QTableWidgetItem*> titles;
QList<QTableWidgetItem*> athors;
QList<QTableWidgetItem*> releases;
QList<QTableWidgetItem*> groups;
QList<QTableWidgetItem*> availables;
QList<QTableWidgetItem*> takers;

MainWindow::MainWindow(QList<user> *users, QList<book> * books, user * current, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->users = users;
    this->books = books;
    this->current = current;
    connect(ui->actionAdd_book, &QAction::triggered, this, &MainWindow::openDia);
    connect(ui->actionRemove_book, &QAction::triggered, this, &MainWindow::deleteDia);

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
    updateTable();
}

void MainWindow::deleteDia()
{
    DeleteBooks w(books);
    w.exec();
    updateTable();
}

void MainWindow::updateTable()
{
    ui->tableWidget->clearContents();
    destroyItems();
    loadTable();
}

void MainWindow::loadTable()
{
    ui->tableWidget->setRowCount(books->count());

    for (int i = 0 ; i < books->count() ; i++)
    {
        QColor red, green;
        red.setRgb(255, 0, 0);
        green.setRgb(0, 255, 0);

        QTableWidgetItem *title = new QTableWidgetItem;
        QTableWidgetItem *athor = new QTableWidgetItem;
        QTableWidgetItem *release = new QTableWidgetItem;
        QTableWidgetItem *group = new QTableWidgetItem;
        QTableWidgetItem *available = new QTableWidgetItem;
        QTableWidgetItem *taker = new QTableWidgetItem;

        title->setText(books->at(i).bookname);
        athor->setText(books->at(i).athor);
        release->setText(books->at(i).release);
        group->setText(books->at(i).group);
        available->setText((books->at(i).available)?"Yes":"No");
        available->setTextColor((books->at(i).available)?green:red);
        taker->setText(books->at(i).takenBy);

        titles.append(title);
        athors.append(athor);
        releases.append(release);
        groups.append(group);
        availables.append(available);
        takers.append(taker);
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

void MainWindow::destroyItems()
{
    for (int i = 0 ; i < books->count()-1 ; i++)
    {

        delete titles[i];
        delete athors[i];
        delete releases[i];
        delete groups[i];
        delete availables[i];
        delete takers[i];
    }
    titles.clear();
    athors.clear();
    releases.clear();
    groups.clear();
    availables.clear();
    takers.clear();
}
