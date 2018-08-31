#ifndef EXCHANGE_H
#define EXCHANGE_H

#include <QDialog>

namespace Ui {
class exchange;
}

class exchange : public QDialog
{
    Q_OBJECT

public:
    explicit exchange(QWidget *parent = 0);
    ~exchange();

    QString GetLineedit();
private slots:
    void on_pushButton_clicked();

private:
    Ui::exchange *ui;
};

#endif // EXCHANGE_H
