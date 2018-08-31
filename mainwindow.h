#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include"connection.h"
#include"exchange.h"
#include"generation.h"
#include"socket_cli.h"
#include"socket_ser.h"
#include <stdio.h>
#include <winsock2.h>
#include <winsock.h>
#pragma comment(lib,"ws2_32.lib")
static QString ip_add;

extern  int control_socket_1;
extern  int control_socket_2;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Ui::MainWindow *ui;
    Connection connection;
    exchange exch;
    Generation generation;

    socket_cli cli;
    socket_ser ser;

    WORD sockVersion;
    WSADATA wsaData;
    SOCKET slisten;
    sockaddr_in sin;
    SOCKET sClient;
    sockaddr_in remoteAddr;
    int nAddrlen = sizeof(remoteAddr);


    WSADATA data;
    SOCKET sclient;
    sockaddr_in serAddr;
    char recData[1024];

    int priority[20]={0};
    int priority1[20]={0};

    int block=0;
    int ii=0;
    int endnumber[30];
    int strr;
    int change=0;
    int plainnumber[400]={0};
    int n=0;
    int ciphernumber[400]={0};

    int orignumber[30];
    ~MainWindow();


public slots:

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_action_1_triggered();
    void on_action_12_triggered();
    void on_action_2_triggered();
    void on_action_5_triggered();
    void on_action_6_triggered();
    void on_comboBox_2_currentIndexChanged(const QString &arg1);
    void on_action_7_triggered();
private:


};

#endif // MAINWINDOW_H
