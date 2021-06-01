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
