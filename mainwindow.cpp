#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <math.h>
#include"QString"
#include"stdio.h"
#include"caesar.h"
#include"keyword.h"
#include"double_trans.h"
#include"playfair.h"
#include"autokey.h"
#include"rc4.h"
#include"vigenere.h"
#include"des.h"
#include"ca.h"
#include"column.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <QMessageBox>
#include<connection.h>
#define  RANGE	100  //100之内产生素数
int control_socket_1=0;
int control_socket_2=0;

using namespace std;
int IsPrime(int iprime);
int mochongfujisuan(int a[],int b[],int bin[],int n,int NUM);
int binary(int number,int bin[]);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_10->setVisible(false);
    ui->lineEdit_3->setVisible(false);
    ui->label_11->setVisible(false);
    ui->lineEdit_4->setVisible(false);
    ui->sb->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_action_1_triggered()
{        
    if(connection.exec()==Connection::Accepted)
    {     
        ip_add=connection.GetLineedit();
        if(control_socket_1==1)
        {

             sockVersion = MAKEWORD(2,2);

                        if(WSAStartup(sockVersion, &wsaData)!=0)
                        {

                        }

                        //创建套接字
                        slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                        if(slisten == INVALID_SOCKET)
                        {
                            printf("socket error !");

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

                        }





                            printf("等待连接...\n");
                            sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);
                            if(sClient == INVALID_SOCKET)
                            {
                                printf("accept error !");

                            }
                            printf("接受到一个连接：%s \r\n", inet_ntoa(remoteAddr.sin_addr));
                            QString str="已与";
                            str.append(QString(QLatin1String(inet_ntoa(remoteAddr.sin_addr))));
                            str.append("建立连接");
                            ui->statue->setText(str);

                            //接收数据
                            char revData[255];
                            int ret = recv(sClient, revData, 255, 0);
                            if(ret > 0)
                            {
                                revData[ret] = 0x00;
                                printf(revData);
                            }

                            //发送数据
                            char * sendData = "你好，TCP客户端！\n";
                            send(sClient, sendData, strlen(sendData), 0);
        }
        if(control_socket_2==1)
        {
            sockVersion = MAKEWORD(2,2);

                    if(WSAStartup(sockVersion, &data) != 0)
                    {

                    }

                    sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                    if(sclient == INVALID_SOCKET)
                    {
                        printf("invalid socket !");
                        ui->textBrowser->insertPlainText("invalid socket !");

                    }

                    serAddr;
                    serAddr.sin_family = AF_INET;
                    serAddr.sin_port = htons(8888);
                    QByteArray ba = ip_add.toLatin1();
                    char *addd = ba.data();
                    serAddr.sin_addr.S_un.S_addr = inet_addr(addd);
                    if (::connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
                    {
                        printf("connect error !");
                        closesocket(sclient);

                    }
                    char * sendData = "你好，TCP服务端，我是客户端!\n";
                    send(sclient, sendData, strlen(sendData), 0);

                    char recData2[255];
                    int ret = recv(sclient, recData2, 255, 0);
                    if(ret > 0)
                    {
                        recData2[ret] = 0x00;
                        printf(recData2);
                    }
                    QString str="已与";
                    str.append(ip_add);
                    str.append("建立连接");
                    ui->statue->setText(str);
        }

        QMessageBox::about(NULL, "Congratulation！", "连接成功");
    }

}
void MainWindow::on_action_2_triggered()
{
    if(exch.exec()==exchange::Accepted)
    {
        QString str1=exch.GetLineedit();
        QString str2;
        if(control_socket_1==1)
        {

            QByteArray ba = str1.toLatin1();
            char *sendData = ba.data();
            send(sClient, sendData, strlen(sendData), 0);
            int ret = recv(sClient, recData, 255, 0);
            if(ret > 0)
            {
                recData[ret] = 0x00;
                printf(recData);
            }
            //send(sClient, sendData, strlen(sendData), 0);

            str2=QString(QLatin1String(recData));

        }
        if(control_socket_2==1)
        {

            QByteArray ba = str1.toLatin1();
            char *sendData = ba.data();
            send(sclient, sendData, strlen(sendData), 0);
            int ret = recv(sclient, recData, 255, 0);
            if(ret > 0)
            {
                recData[ret] = 0x00;
                printf(recData);
            }
            //send(sclient, sendData, strlen(sendData), 0);

            str2=QString(QLatin1String(recData));

        }
        int iprime=0,p=0,pol,j,count=0;
           int prime_table[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
           int n=0;
           int b1[15];              //对素因子表的标记
           int b2[15];              //保存欧拉函数的素因子
           while(1)
           {
               srand(time(NULL));  //时间种子可以随机生成数
               iprime=rand()%RANGE;
               if(IsPrime(iprime)!=0)
               {
                  break;
               }
           }
           p=iprime;
           printf("随机产生的素数为%d\n",iprime);
           pol=p-1;   //p的欧拉函数
           for(int i=0;i<15;i++)//求欧拉函数的素因子
           {
               if(pol%prime_table[i]==0)
                   b1[i]=1;
               else
                   b1[i]=0;
           }
           for(int i=0,j=0;i<15;i++)
           {
               if(b1[i]==1)
               {
                   printf("素因子是:%d \n",prime_table[i]);
                   b2[j]=prime_table[i];
                   j++;
                   count++;      //count保存素因子的个数
               }
           }
           printf("欧拉函数分别除以素因子得到的结果:\n");
           for(int k=0;k<count;k++)
           {
               b2[k]=pol/b2[k];
               printf("%d ",b2[k]);
           }

        //**********************************************
           int temp1=0,bin[10],NUM=0,fuzhi=2,js=0,w=0;
           int b[10];
           int a[10];
           while(1)
           {
               for(int i=0;i<count;i++)
               {
                   a[0]=1;
                   b[0]=fuzhi;
                   temp1=b2[i];
                   NUM=binary(temp1,bin);
                   printf("\n");
                   js=mochongfujisuan(a,b,bin,iprime,NUM);
                       if(js==1)
                           break;
                       else
                           w++;
               }
             if(w==2)
                 break;
             fuzhi++;
             w=0;
           }
           int key1=0;
           int key2=0;
           int mm=0;
           int nn=0;
           int key=0;
           printf("素数iprimede的元根是: %d",fuzhi);
           printf("\n");
           printf("***********************************\n");
           /*printf("alice输入自己key1:\n");
           scanf("%d",&key1);
           printf("bob输入自己的key2: \n");
           scanf("%d",&key2);
           printf("得出公共密钥key:\n");*/
           key1=str1.toInt();
           key2=str2.toInt();
           int aa[20];
           aa[0]=1;
           int bb[20];
           bb[0]=fuzhi;
           int bin11[20];
           int NUM1=0;
           NUM1=binary(key1,bin11);
           mm=mochongfujisuan(aa,bb,bin11,iprime,NUM1);
           int aa2[20];
           aa2[0]=1;
           int bb2[20];
           bb2[0]=fuzhi;
           int bin22[20];
           int NUM2=0;
           NUM2=binary(key2,bin22);
           nn=mochongfujisuan(aa2,bb2,bin22,iprime,NUM2);
           key=(mm*nn)%iprime;
           printf("\n");
           int vv=0;
           char final_key[6];
           while(vv<8)
           {
                final_key[vv/2]=(key+vv)%26+'a';
                printf("%c",(key+vv)%26+'a');
                vv=vv+2;
           }
           final_key[vv/2]='\0';
           if(control_socket_1==1)
               ui->lineEdit_2->setText(QString(QLatin1String(final_key)));
           if(control_socket_2==1)
               ui->lineEdit->setText(QString(QLatin1String(final_key)));

    }
}
void MainWindow::on_action_5_triggered()
{
    if(control_socket_1==1&&change==0)
    {
        QMessageBox::about(NULL, "wait", "正在接收，请耐心等待...");
        //清空缓存区
        //接收信息
        int ret = recv(sClient, recData, 1024, 0);
        if(ret > 0)
        {
            recData[ret] = 0x00;
            printf(recData);
        }
        QMessageBox::about(NULL, "Congratulation！", "接收成功");
        ui->textEdit_2->setText(QString(QLatin1String(recData)));
    }
    else if(change==1)
    {
        QMessageBox::about(NULL, "wait", "正在接收，请耐心等待...");
        char recData1[1024];
        /*char recData2[255];
        char recData3[255];
        char recData4[255];*/
        recv(sClient, recData1, 1024, 0);
        //ui->textBrowser->insertPlainText(QString(QLatin1String(recData1)));//测试
        /*recv(sClient, recData2, 1024, 0);
        recv(sClient, recData3, 1024, 0);
        recv(sClient, recData4, 1024, 0);*/
        /*strr=QString(QLatin1String(recData1)).toInt();
        ii=QString(QLatin1String(recData2)).toInt();
        block=QString(QLatin1String(recData4)).toInt();*/
        int a=0,count=0,z=0;
        char strrr[100];char iii[100];char bblock[100];char eendnumber[1024];
        while(recData1[a]!='\0')
        {
            if(recData1[a]=='#')
            {
                if(count==0)
                {
                    strrr[z]='\0';
                    strr=QString(QLatin1String(strrr)).toInt();
                    //ui->textBrowser->insertPlainText(QString(QLatin1String(strrr)));
                }
                else if(count==1)
                {
                    iii[z]='\0';
                    ii=QString(QLatin1String(iii)).toInt();
                    //ui->textBrowser->insertPlainText(QString(QLatin1String(iii)));
                }
                else if(count==2)
                {
                    bblock[z]='\0';
                    block=QString(QLatin1String(bblock)).toInt();
                    //ui->textBrowser->insertPlainText(QString(QLatin1String(bblock)));
                }
                else if(count==3)
                {
                    eendnumber[z]='\0';
                }
                count++;
                a++;
                z=0;

            }
            if(count==0)
            {
                strrr[z]=recData1[a];
            }
            else if(count==1)
            {
                iii[z]=recData1[a];
            }
            else if(count==2)
            {
                bblock[z]=recData1[a];
            }
            else if(count==3)
            {
                eendnumber[z]=recData1[a];
            }
            a++;
            z++;
        }
        change=0;
        int i=0,k=0,j=0;
        char str[100];
        do{
           if(eendnumber[i]==' ')
           {

             str[k]='\0';
             k=0;
             endnumber[j]=atoi(str);
             j++;
             i++;
            }

            str[k]=eendnumber[i];
            k++;
            i++;

          }while(eendnumber[i]!='\0');
        //ui->textBrowser->setText(QString::number(strr));
       // ui->textBrowser->setText(QString::number(block));
        //ui->textBrowser->setText(QString::number(ii));
        for(int a=0;a<ii;a++)
        {
            ui->textEdit_2->insertPlainText(QString::number(endnumber[a]));
            ui->textEdit_2->insertPlainText("#");
        }
        QMessageBox::about(NULL, "Congratulation！", "接收成功");

    }
    else
        QMessageBox::about(NULL, "sorry", "您是加密方，不接收密文");
}
void MainWindow::on_action_6_triggered()
{
    if(control_socket_2==1&&change==0)
    {
        QString str=ui->textBrowser->toPlainText();
        QByteArray ba = str.toLatin1();
        char *sendData = ba.data();
        send(sclient, sendData, strlen(sendData), 0);   
    }
    else if(change==2)
    {
        QString sendsend=QString::number(strr);sendsend.append("#");
        sendsend.append(QString::number(ii));sendsend.append("#");
        sendsend.append(QString::number(block));sendsend.append("#");
        for(int a=0;a<ii;a++)
        {
            sendsend.append(QString::number(endnumber[a]));
            sendsend.append(" ");
        }
        sendsend.append("#");
        //ui->textBrowser_2->setText(sendsend);//测试
        QByteArray ba5 =sendsend.toLatin1();
        char *sendData5 = ba5.data();
        send(sclient, sendData5, strlen(sendData5), 0);
        /*QByteArray ba1 = QString::number(strr).toLatin1();
        char *sendData1 = ba1.data();
        send(sclient, sendData1, strlen(sendData1), 0);
        QByteArray ba2 =QString::number(ii).toLatin1();
        char *sendData2 = ba2.data();
        send(sclient, sendData2, strlen(sendData2), 0);
        QString endnumber2="";
        for(int a=0;a<ii;a++)
        {
            endnumber2.append(QString::number(endnumber[a]));
            endnumber2.append(" ");
        }
        QByteArray ba3 = endnumber2.toLatin1();
        char *sendData3 = ba3.data();
        send(sclient, sendData3, strlen(sendData3), 0);
        QByteArray ba4 = QString::number(block).toLatin1();
        char *sendData4 = ba4.data();
        send(sclient, sendData4, strlen(sendData4), 0);*/
        change=0;
    }
    else
        QMessageBox::about(NULL, "sorry", "您是解密方，不传送密文");
}
void MainWindow::on_action_7_triggered()
{
    if(generation.exec()==Generation::Accepted)
    {

       if(control_socket_1==1)
       {
           n=generation.GetLineedit_3().toInt();
           QString nn=QString::number(n);
           //ui->lineEdit->setText(nn);//测试
           QString pub_key=generation.GetLineedit_1();
           ui->lineEdit_2->setText(generation.GetLineedit_2());
           QByteArray ba = pub_key.toLatin1();
           char *sendData = ba.data();
           send(sClient, sendData, strlen(sendData), 0);
           QByteArray ba2 = nn.toLatin1();
           char *sendData1 = ba2.data();
           send(sClient, sendData1, strlen(sendData), 0);
           change=1;
       }
       if(control_socket_2==1)
       {
           char recData2[255];
           int ret = recv(sclient, recData2, 255, 0);
           if(ret > 0)
           {
               recData2[ret] = 0x00;
               printf(recData2);
           }
           ui->lineEdit->setText(QString(QLatin1String(recData2)));
           char recData3[255];
           int ret2 = recv(sclient, recData3, 255, 0);
           if(ret2 > 0)
           {
               recData2[ret] = 0x00;
               printf(recData2);
           }

           n=QString(QLatin1String(recData3)).toInt();
           ui->sb->setText(QString::number(n));
           change=2;
       }
    }
}
void MainWindow::on_action_12_triggered()
{
    //ui->textBrowser->insertPlainText(QString(control_socket_1));
    if(control_socket_1==1)
    {
        closesocket(sClient);
        closesocket(slisten);
        WSACleanup();
        ui->statue->setText("not connection");
        control_socket_1=0;
    }
    if(control_socket_2==1)
    {
        closesocket(sclient);
        WSACleanup();
        ui->statue->setText("not connection");
        control_socket_2=0;
    }
}
void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->setPlainText("");
    QString p=ui->textEdit->toPlainText();
    QString method=ui->comboBox->currentText();
    QString key1=ui->lineEdit->text();
    QString key2=ui->lineEdit_3->text();
    QByteArray ba = p.toLatin1();
    char *plaintext = ba.data();
    QByteArray ba2 = key1.toLatin1();
    char *ch2 = ba2.data();
    QByteArray ba3 = key2.toLatin1();
    char *ch3 = ba3.data();
    if(method=="Caesar")
    {
        Caesar *choose=new Caesar();
        char *c=choose->encrypt(plaintext,atoi(ch2));
        ui->textBrowser->insertPlainText(QString(QLatin1String(c)));
    }
    if(method=="autokey")
    {
        keyword *choose=new keyword();
        char *c=choose->Autokeyplaintext(ch2,plaintext);
        ui->textBrowser->insertPlainText(QString(QLatin1String(c)));
    }
    if(method=="double-transposition")
    {

        Double_trans *choose=new Double_trans();
        char *c=choose->encryption(plaintext,ch2);
        char *c1=choose->encryption(c,ch3);
        ui->textBrowser->insertPlainText(QString(QLatin1String(c1)));
    }
    if(method=="playfair")
    {
        Playfair *choose=new Playfair();
        char *c=choose->playfair(plaintext,ch2);
        ui->textBrowser->insertPlainText(QString(QLatin1String(c)));
    }
    if(method=="keyword")
    {
        char plain[26];
        int i;
            for(i=0;i<26;i++){               //"abcdefg...xyz"
                plain[i]='a'+i;
            }
        i=strlen(ch2);
        char cipher[50];

        Autokey *choose=new Autokey();
        choose->chart(ch2,i,cipher);
        char ciphertext[50];
        choose->encryption(plaintext,ciphertext,cipher);
        ui->textBrowser->insertPlainText(QString(QLatin1String(ciphertext)));
    }
    if(method=="RC4")
    {
        int key[8];
               int i=0,k=0,j=0;
               char str[100];
               do{
                   if(ch2[i]==' ')
                   {

                       str[k]='\0';
                       k=0;
                       key[j]=atoi(str);
                       j++;
                       i++;
                   }

                   str[k]=ch2[i];
                   k++;
                   i++;

               }while(ch2[i]!='\0');
       int k_text[256];
       for(i=0;i<256;i++)      //将密钥填充密钥数组
           {
               k_text[i]=key[i%8];
           }
       int Sbox[256];
       RC4 *choose=new RC4();
       choose->KSA(k_text,Sbox);
       char *c=choose->encrypt(plaintext,Sbox);
       ui->textBrowser->insertPlainText(QString(QLatin1String(c)));
    }
    if(method=="Vigenere")
    {
        Vigenere *choose=new Vigenere();
        char *c=choose->vigenere(ch2,plaintext);
        ui->textBrowser->insertPlainText(QString(QLatin1String(c)));
    }
    if(method=="RSA")
    {

        RSA *choose=new RSA();
        strr=strlen(plaintext);
        block=choose->chartonumber(plaintext,plainnumber,n);
        ii=choose->encryption(plainnumber,block,key1.toInt(),n,strr,endnumber);
        for(int a=0;a<ii;a++)
            ui->textBrowser->insertPlainText(QString::number(endnumber[a]));
    }
    if(method=="DES")
    {
        char cipher[8];
            ElemType subKeys[16][48];
            ElemType bit[64];
            Char8ToBit64(ch2,bit);
            DES_MakeSubKeys(bit,subKeys);
            DES_EncryptBlock(plaintext,subKeys,cipher);
            cipher[8]='\0';
            printf("%s",cipher);
            //strcat(cipher,"\0");
            printf("\n");
            //DES_DecryptBlock(cipher,subKeys,plaintext);
            //printf("%s",plain);
            ui->textBrowser->insertPlainText(QString(QLatin1String(cipher)));
    }
    if(method=="CA")
    {
        CA *choose=new CA();

        int bin[8];
        int CAg[7];
        int number=key1.toInt();
        int b[100];
        ui->textBrowser->insertPlainText(QString::number(number));
        choose->binary(number,bin);
        for(int a=0;a<7;a++)
        {
            if(ch3[a]=='0')
                CAg[a]=0;
            else
                CAg[a]=1;
        }
        for(int a=0;a<7;a++)
            ui->textBrowser->insertPlainText(QString::number(CAg[a]));
        //choose->jiami(number,CAg,plaintext,b);
        /*for(int a=0;b[a]!=2;a++)
            ui->textBrowser->insertPlainText(QString::number(b[a]));*/
        /*char temp_b[500];
        for(int a=0;b[a]!=2;a++)
        {
            if(b[a]==0)
                temp_b[a]=0;
            else
                temp_b[a]=1;
        }
        ui->textBrowser->insertPlainText(QString(QLatin1String(temp_b)));*/

    }
    if(method=="column")
    {
        int priority2[20]={0};
        char ciphertext_1[50];
        COLUMN *choose=new COLUMN();
        choose->priorityfun(ch2,priority2);
        choose->encryption(plaintext,ch2,ciphertext_1,priority2);
        ui->textBrowser->insertPlainText(QString(QLatin1String(ciphertext_1)));
    }
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->textBrowser->setPlainText("");
    if(arg1=="Caesar")
        ui->attention1->setText("请输入一个自然数");
    else if(arg1=="double-transposition")
    {
        ui->label_10->setVisible(true);
        ui->lineEdit_3->setVisible(true);
        ui->attention1->setText("请输入两个密钥");
    }
    else if(arg1=="CA")
    {
        ui->label_10->setVisible(true);
        ui->lineEdit_3->setVisible(true);
        ui->attention1->setText("key输入255之内的数字，key2输入七个0或1");
    }
    else
        {
            ui->attention1->setText("");
            ui->label_10->setVisible(false);
            ui->lineEdit_3->setVisible(false);
        }
}
void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    ui->textBrowser_2->setPlainText("");
    if(arg1=="Caesar")
        ui->attention1->setText("请输入小于26的自然数");
    else if(arg1=="double-transposition")
    {
        ui->label_11->setVisible(true);
        ui->lineEdit_4->setVisible(true);
        ui->attention1->setText("请输入两个密钥");
    }
    else if(arg1=="CA")
    {
        ui->label_11->setVisible(true);
        ui->lineEdit_4->setVisible(true);
        ui->attention1->setText("key输入255之内的数字，key2输入七个0或1");
    }
    else
    {
        ui->attention1->setText("");
        ui->label_11->setVisible(false);
        ui->lineEdit_4->setVisible(false);
    }
}
void MainWindow::on_pushButton_2_clicked()
{
    ui->textBrowser_2->setPlainText("");
    QString c=ui->textEdit_2->toPlainText();
    QString method=ui->comboBox_2->currentText();
    QString key=ui->lineEdit_2->text();
    QString key2=ui->lineEdit_4->text();
    QByteArray ba = c.toLatin1();
    char *ciphertext = ba.data();
    QByteArray ba2 = key.toLatin1();
    char *ch2 = ba2.data();
    QByteArray ba3 = key2.toLatin1();
    char *ch3 = ba3.data();
    if(method=="Caesar")
    {
        Caesar *choose=new Caesar();
        char *c=choose->decrypt(ciphertext,atoi(ch2));
        ui->textBrowser_2->insertPlainText(QString(QLatin1String(c)));
    }
    if(method=="autokey")
    {
        keyword *choose=new keyword();
        char *c=choose->anti_Autokeyplaintext(ch2,ciphertext);
        ui->textBrowser_2->insertPlainText(QString(QLatin1String(c)));
    }
    if(method=="double-transposition")
    {

        Double_trans *choose=new Double_trans();
        char *c=choose->decryption(ciphertext,ch3);

        char *c1=choose->decryption(c,ch2);

        ui->textBrowser_2->insertPlainText(QString(QLatin1String(c1)));
    }
    if(method=="playfair")
    {
        Playfair *choose=new Playfair();
        char *c=choose->anti_playfair(ciphertext,ch2);
        ui->textBrowser_2->insertPlainText(QString(QLatin1String(c)));
    }
    if(method=="keyword")
    {
        char plain[26];
        int i;
            for(i=0;i<26;i++){               //"abcdefg...xyz"
                plain[i]='a'+i;
            }
        i=strlen(ch2);
        char cipher[50];

        Autokey *choose=new Autokey();
        choose->chart(ch2,i,cipher);
        char plaintext1[50];
        choose->decryption(ciphertext,plaintext1,plain,cipher);
        ui->textBrowser_2->insertPlainText(QString(QLatin1String(plaintext1)));
    }
    if(method=="RC4")
    {
        int key[8];
               int i=0,k=0,j=0;
               char str[100];
               do{
                   if(ch2[i]==' ')
                   {

                       str[k]='\0';
                       k=0;
                       key[j]=atoi(str);
                       j++;
                       i++;
                   }

                   str[k]=ch2[i];
                   k++;
                   i++;

               }while(ch2[i]!='\0');
       int k_text[256];
       for(i=0;i<256;i++)      //将密钥填充密钥数组
           {
               k_text[i]=key[i%8];
           }
       int Sbox[256];
       RC4 *choose=new RC4();
       choose->KSA(k_text,Sbox);
       char *c=choose->encrypt(ciphertext,Sbox);
       ui->textBrowser_2->insertPlainText(QString(QLatin1String(c)));
    }
    if(method=="Vigenere")
    {
        Vigenere *choose=new Vigenere();
        char *c=choose->anti_vigenere(ch2,ciphertext);
        ui->textBrowser_2->insertPlainText(QString(QLatin1String(c)));
    }
    if(method=="RSA")
    {
        int orignuber[50];
        char plaintex[50];
        RSA *choose=new RSA();
        int caonima[50];
        int i=0,k=0,j=0;
        char str[100];
        do{
            if(ciphertext[i]=='#')
            {

                str[k]='\0';
                k=0;
                caonima[j]=atoi(str);
                j++;
                i++;
            }

            str[k]=ciphertext[i];
            k++;
            i++;

        }while(ciphertext[i]!='\0');
        /*for(int a=0;a<j;a++)
        {
            ui->textBrowser_2->insertPlainText(QString::number(caonima[a]));
        }*/
        choose->decryption(caonima,orignuber,ii,key.toInt(),n,block,ciphernumber);  //解密
        choose->binarytochar(ciphernumber,plaintex,strr);
        /*ui->textBrowser_2->insertPlainText(QString::number(ii));
        ui->textBrowser_2->insertPlainText(QString::number(strr));
        ui->textBrowser_2->insertPlainText(QString::number(block));*/
        plaintex[strr]='\0';
        /*char *hello="text:";
        printf("%s",plaintex);
        ui->textBrowser_2->insertPlainText(QString(QLatin1String(hello)));*/
        ui->textBrowser_2->insertPlainText(QString(QLatin1String(plaintex)));
    }
    if(method=="DES")
    {
        char plain[8];
            ElemType subKeys[16][48];
            ElemType bit[64];


            Char8ToBit64(ch2,bit);
            DES_MakeSubKeys(bit,subKeys);
            //DES_EncryptBlock(plaintext,subKeys,cipher);
            //printf("%s",cipher);
            //printf("\n");

            DES_DecryptBlock(ciphertext,subKeys,plain);
            plain[8]='\0';
            ui->textBrowser_2->insertPlainText(QString(QLatin1String(plain)));
            printf("%s",plain);
    }
    if(method=="column")
    {
        int priority2[20]={0};
        char plaintext_1[50];
        COLUMN *choose=new COLUMN();
        choose->priorityfun(ch2,priority2);
        choose->decryption(plaintext_1,ch2,ciphertext,priority2);
        ui->textBrowser_2->insertPlainText(QString(QLatin1String(plaintext_1)));
    }
}
int IsPrime(int iprime)
{  int i=0;
    if(iprime<=3)
    {
       return 0;
    }
    else
    {
       for(i=2;i<=sqrt(iprime);i++)
       {
           if(iprime%i==0)  //只要从2到sqrt(iPrime)中有一个数可以被iPrime整除，则iPrime非素数
           return 0;
       }
    }
return 1;
}
int mochongfujisuan(int a[],int b[],int bin[],int n,int NUM)
{    int jg,i=0;
 for(i=0;i<=NUM;i++)//模重复计算法
 {
     if(bin[i]==1)
     {
      a[i+1]=a[i]*b[i]%n;
      b[i+1]=b[i]*b[i]%n;
     }
     else
     {
       a[i+1]=a[i]%n;
       b[i+1]=b[i]*b[i]%n;
     }
 }
 printf("模重复平方计算结果是:%d\n",a[i-1]);
 jg=a[i-1];
 return jg;
}
int binary(int number,int bin[])
{

 int tmp,NUM=0;//临时变量表示m模2的余数
 while(number!=0)
 {
   tmp=number%2;
   bin[NUM]=tmp;
   number=number/2;
   NUM++;
 }
 return NUM;
}
