#include "socket_ser.h"
#include "mainwindow.h"
#include <stdio.h>
#include <winsock2.h>
#include<string.h>
#include <winsock.h>
socket_ser::socket_ser()
{

}

void socket_ser::send_mes(QString str)
{
    QByteArray ba = str.toLatin1();
    char *sendData = ba.data();
    //发送数据
    send(sClient, sendData, strlen(sendData), 0);
}
QString socket_ser::recieve_mes()
{
    int ret = recv(sClient, revData, 255, 0);
    if(ret > 0)
    {
        revData[ret] = 0x00;
        printf(revData);
    }
    return QString(QLatin1String(revData));
}
int socket_ser::create()
{
    //初始化WSA
    sockVersion = MAKEWORD(2,2);
    if(WSAStartup(sockVersion, &wsaData)!=0)
    {
        return 0;
    }

    //创建套接字
    slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(slisten == INVALID_SOCKET)
    {
        printf("socket error !");
        return 0;
    }

    //绑定IP和端口
    sin.sin_family = AF_INET;
    sin.sin_port = htons(8888);
    sin.sin_addr.S_un.S_addr = INADDR_ANY;
    if(bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
    {
        printf("bind error !");
    }

    //开始监听
    if(listen(slisten, 1) == SOCKET_ERROR)
    {
        printf("listen error !");
        return 0;
    }
}
void socket_ser::shutdown()
{
    closesocket(slisten);
    WSACleanup();
}
void socket_ser::destroy_one()
{
    closesocket(sClient);
}
void socket_ser::waitforline()
{
    //循环接收数据
    nAddrlen = sizeof(remoteAddr);

        printf("等待连接...\n");
        sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);
        if(sClient == INVALID_SOCKET)
        {
            printf("accept error !");
            //continue;
        }
        printf("接受到一个连接：%s \r\n", inet_ntoa(remoteAddr.sin_addr));

}
