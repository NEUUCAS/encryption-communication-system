#include "connection.h"
#include "ui_connection.h"
#include"mainwindow.h"
#include"QString"
extern "C"
Connection::Connection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connection)
{
    ui->setupUi(this);
    ui->label->setVisible(false);
    ui->lineEdit->setVisible(false);

}

Connection::~Connection()
{
    delete ui;
}
QString Connection::GetLineedit()
{
    return ui->lineEdit->text();
}

void Connection::on_pushButton_clicked()
{
    accept();
}

void Connection::on_radioButton_2_clicked()
{
    ui->label->setVisible(true);
    ui->lineEdit->setVisible(true);
    control_socket_1=0;
    control_socket_2=1;

}

void Connection::on_radioButton_clicked()
{
    ui->label->setVisible(false);
    ui->lineEdit->setVisible(false);
    control_socket_1=1;
    control_socket_2=0;

}
