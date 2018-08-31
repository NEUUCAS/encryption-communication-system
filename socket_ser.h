#ifndef SOCKET_SER_H
#define SOCKET_SER_H
#include <stdio.h>
#include <winsock2.h>
#include <winsock.h>
#include<QString>
#pragma comment(lib,"ws2_32.lib")

class socket_ser
{
public:
    socket_ser();
    WORD sockVersion;
    WSADATA wsaData;
    SOCKET slisten;
    sockaddr_in sin;
    SOCKET sClient;
    sockaddr_in remoteAddr;
    int nAddrlen = sizeof(remoteAddr);
    char revData[255];

    void send_mes(QString str);
    QString recieve_mes();
    int create();
    void shutdown();
    void destroy_one();
    void waitforline();
};

#endif // SOCKET_SER_H
