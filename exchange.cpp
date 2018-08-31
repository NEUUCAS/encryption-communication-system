#include "exchange.h"
#include "ui_exchange.h"

exchange::exchange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exchange)
{
    ui->setupUi(this);
}

exchange::~exchange()
{
    delete ui;
}
QString exchange::GetLineedit()
{
    return ui->lineEdit->text();
}
void exchange::on_pushButton_clicked()
{
    accept();
}
