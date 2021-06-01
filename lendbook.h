#ifndef LENDBOOK_H
#define LENDBOOK_H

#include <QDialog>

namespace Ui {
class Lendbook;
}

class Lendbook : public QDialog
{
    Q_OBJECT

public:
    explicit Lendbook(QWidget *parent = nullptr);
    ~Lendbook();

private:
    Ui::Lendbook *ui;
};

#endif // LENDBOOK_H
