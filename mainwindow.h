#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "data.h"
#include "addbook.h"

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
private:
    QList<user> *users;
    QList<book> *books;
    void loadTable();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
