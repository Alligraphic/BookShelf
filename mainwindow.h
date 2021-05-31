#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "data.h"
#include "addbook.h"
#include "deletebooks.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QList<user> *users, QList<book> * books, QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void openDia();
    void deleteDia();
    void updateTable();
private:
    QList<user> *users;
    QList<book> *books;
    void loadTable();
    void destroyItems();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
