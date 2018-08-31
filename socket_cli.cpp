#include "socket_cli.h"
#include"mainwindow.h"
socket_cli::socket_cli()
{

}
int socket_cli::create()
{
    sockVersion = MAKEWORD(2,2);
    if(WSAStartup(sockVersion, &data) != 0)
    {
        return 0;
    }

    sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sclient == INVALID_SOCKET)
    {
        printf("invalid socket !");
        return 0;
    }
    serAddr.sin_family = AF_INET;
    serAddr.sin_port = htons(8888);
    QByteArray ba = ip_add.toLatin1();
    char *mm = ba.data();
    serAddr.sin_addr.S_un.S_addr = inet_addr(mm);
}
int socket_cli::conc()
{
    if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
    {
        printf("connect error !");
        closesocket(sclient);
        return 0;
    }
}
void socket_cli::send_mes(QString str)
{
    QByteArray ba = str.toLatin1();
    char *sendData = ba.data();
    send(sclient, sendData, strlen(sendData), 0);
}
QString socket_cli::recieve_mes()
{
    int ret = recv(sclient, recData, 255, 0);
    if(ret > 0)
    {
        recData[ret] = 0x00;
        printf(recData);
    }
}
void socket_cli::close()
{
    closesocket(sclient);
    WSACleanup();
}
