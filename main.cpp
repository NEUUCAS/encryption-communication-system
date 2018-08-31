#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>
#include <winsock2.h>

#include <winsock.h>

#pragma comment(lib,"ws2_32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.ui->comboBox->addItem("keyword");
    w.ui->comboBox->addItem("Caesar");
    w.ui->comboBox->addItem("autokey");
    w.ui->comboBox->addItem("playfair");
    w.ui->comboBox->addItem("column");
    w.ui->comboBox->addItem("double-transposition");
    w.ui->comboBox->addItem("RC4");
    w.ui->comboBox->addItem("CA");
    w.ui->comboBox->addItem("Vigenere");
    w.ui->comboBox->addItem("RSA");
    w.ui->comboBox->addItem("DES");

    w.ui->comboBox_2->addItem("keyword");
    w.ui->comboBox_2->addItem("Caesar");
    w.ui->comboBox_2->addItem("autokey");
    w.ui->comboBox_2->addItem("playfair");
    w.ui->comboBox_2->addItem("column");
    w.ui->comboBox_2->addItem("double-transposition");
    w.ui->comboBox_2->addItem("RC4");
    w.ui->comboBox_2->addItem("CA");
    w.ui->comboBox_2->addItem("Vigenere");
    w.ui->comboBox_2->addItem("RSA");
    w.ui->comboBox_2->addItem("DES");
    w.show();
    return a.exec();


 /*   while(1){

    if(control_socket_1==1)
    {
            //初始化WSA
            WORD sockVersion = MAKEWORD(2,2);
            WSADATA wsaData;
            if(WSAStartup(sockVersion, &wsaData)!=0)
            {
                return 0;
            }

            //创建套接字
            SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if(slisten == INVALID_SOCKET)
            {
                printf("socket error !");
                return 0;
            }

            //绑定IP和端口
            sockaddr_in sin;
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
            //循环接收数据
            SOCKET sClient;
            sockaddr_in remoteAddr;
            int nAddrlen = sizeof(remoteAddr);
            char revData[255];
            while (control_socket_1)
            {
                printf("等待连接...\n");
                sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);
                if(sClient == INVALID_SOCKET)
                {
                    printf("accept error !");
                    continue;
                }
                printf("接受到一个连接：%s \r\n", inet_ntoa(remoteAddr.sin_addr));
                w.ui->statue->setText(inet_ntoa(remoteAddr.sin_addr));
                //接收数据
                int ret = recv(sClient, revData, 255, 0);
                if(ret > 0)
                {
                    revData[ret] = 0x00;
                    printf(revData);
                }

                //发送数据
                char * sendData = "你好，TCP客户端！\n";
                send(sClient, sendData, strlen(sendData), 0);
                closesocket(sClient);
            }

            closesocket(slisten);
            WSACleanup();
    }
    if(control_socket_2==1)
    {
        WORD sockVersion = MAKEWORD(2,2);
        WSADATA data;
        if(WSAStartup(sockVersion, &data) != 0)
        {
            return 0;
        }

        SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if(sclient == INVALID_SOCKET)
        {
            printf("invalid socket !");
            return 0;
        }

        sockaddr_in serAddr;
        serAddr.sin_family = AF_INET;
        serAddr.sin_port = htons(8888);
        QByteArray ba = ip_add.toLatin1();
        char *mm = ba.data();
        serAddr.sin_addr.S_un.S_addr = inet_addr(mm);
        if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
        {
            printf("connect error !");
            closesocket(sclient);
            return 0;
        }
        char * sendData = "你好，TCP服务端，我是客户端!\n";
        send(sclient, sendData, strlen(sendData), 0);

        char recData[255];
        int ret = recv(sclient, recData, 255, 0);
        if(ret > 0)
        {
            recData[ret] = 0x00;
            printf(recData);
        }
        closesocket(sclient);
        WSACleanup();
    }
    }//大循环*/
}
