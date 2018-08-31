#ifndef GENERATION_H
#define GENERATION_H

#include <QDialog>
#include"rsa.h"

namespace Ui {
class Generation;
}

class Generation : public QDialog
{
    Q_OBJECT

public:
    explicit Generation(QWidget *parent = 0);
    Ui::Generation *ui;


    ~Generation();

    QString GetLineedit_1();
    QString GetLineedit_2();
    QString GetLineedit_3();
private slots:
    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_pushButton_3_clicked();

private:

};

#endif // GENERATION_H
