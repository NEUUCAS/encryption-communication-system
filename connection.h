#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>
#include<string.h>

namespace Ui {
class Connection;
}

class Connection : public QDialog
{
    Q_OBJECT

public:
    explicit Connection(QWidget *parent = 0);
    QString GetLineedit();
    Ui::Connection *ui;
    ~Connection();

private slots:


    void on_pushButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

private:

};

#endif // CONNECTION_H
