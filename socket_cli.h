#ifndef SOCKET_CLI_H
#define SOCKET_CLI_H
#include <stdio.h>
#include <winsock2.h>
#include <winsock.h>
#include<QString>
#pragma comment(lib,"ws2_32.lib")

class socket_cli
{
public:
    socket_cli();
    WORD sockVersion;
    WSADATA data;
    SOCKET sclient;
    sockaddr_in serAddr;
    char recData[255];

    int create();
    int conc();
    void send_mes(QString str);
    QString recieve_mes();
    void close();
};

#endif // SOCKET_CLI_H
