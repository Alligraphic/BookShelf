#include "lendbook.h"
#include "ui_lendbook.h"

Lendbook::Lendbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lendbook)
{
    ui->setupUi(this);
}

Lendbook::~Lendbook()
{
    delete ui;
}
