#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QRadioButton>
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
    explicit MainWindow(QList<user> *users, QList<book> * books, user * current, QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void openDia();
    void deleteDia();
    void updateTable();
    void updateTableWith(QList<book> * books);
    void on_btnAddBook_clicked();

    void on_lneSrch_textEdited(const QString &arg1);

    void on_btnDeleteBook_clicked();

    void on_btnSrch_clicked();

private:
    QList<user> *users;
    QList<book> *books;
    user * current;
    void loadTable();
    void loadTableWith(QList<book> * books);
    QString getOption(QObject * obj);
    void createSrchList(QString group, QString title);
    void destroyItems();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
