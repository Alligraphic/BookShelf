#include "mainwindow.h"
#include "ui_mainwindow.h"

QList<QTableWidgetItem*> titles;
QList<QTableWidgetItem*> athors;
QList<QTableWidgetItem*> releases;
QList<QTableWidgetItem*> groups;

MainWindow::MainWindow(QList<user> *users, QList<book> * books, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->users = users;
    this->books = books;
    connect(ui->actionAdd_book, &QAction::triggered, this, &MainWindow::openDia);

    loadTable();
}
MainWindow::~MainWindow()
{
    delete ui;
    for (int i = 0 ; i < books->count() ; i++)
    {

        delete titles[i];
        delete athors[i];
        delete releases[i];
        delete groups[i];
    }
    titles.clear();
    releases.clear();
    groups.clear();
}

void MainWindow::openDia()
{
    addBook w(books);
    w.exec();
}

void MainWindow::loadTable()
{
    ui->tableWidget->setRowCount(books->count());

    for (int i = 0 ; i < books->count() ; i++)
    {
        QTableWidgetItem *title = new QTableWidgetItem;
        QTableWidgetItem *athor = new QTableWidgetItem;
        QTableWidgetItem *release = new QTableWidgetItem;
        QTableWidgetItem *group = new QTableWidgetItem;

        title->setText(books->at(i).bookname);
        athor->setText(books->at(i).athor);
        release->setText(books->at(i).release);
        group->setText(books->at(i).group);

        titles.append(title);
        athors.append(athor);
        releases.append(release);
        groups.append(group);
    }

    for ( int i = 0 ; i < books->count() ; i++)
    {
        ui->tableWidget->setItem(i, 0, titles[i]);
        ui->tableWidget->setItem(i, 1, athors[i]);
        ui->tableWidget->setItem(i, 2, releases[i]);
        ui->tableWidget->setItem(i, 3, groups[i]);
    }
}
