#include "double_trans.h"
#include<stdio.h>
#include<string.h>
#include"malloc.h"
Double_trans::Double_trans()
{

}
char *Double_trans::encryption(char plaintext[],char key[])          //加密
{
    char *text=(char *)malloc(strlen(plaintext)*sizeof(char));
    int i,j,m,plain_length,h,key_length;
    int num[20];
    plain_length=strlen(plaintext);
    key_length=strlen(key);
    i=0;
    for(i=0;i<key_length;i++)           //确定读取顺序在num中
    {
        num[i]=0;
        for(j=0;j<key_length;j++)
        {
            if(key[j]<key[i]||(key[j]==key[i]&&j<=i))      //找出比自己小的字母的个数
            {
                num[i]=num[i]+1;
            }
        }
    }
    for(m=plain_length%key_length;m<key_length;m++)         //末尾补x
    {

        plaintext[plain_length+i]='x';
        i++;
    }
    if(plain_length%key_length==0)			//计算有多少行
        m=plain_length/key_length;
    else
        m=plain_length/key_length+1;
    h=0;
    for(i=0;i<key_length;i++)              //将密文顺序写入cipher
    {
        for(j=0;j<m;j++)
        {
            text[h]=plaintext[j*key_length+num[i]-1];
            h++;
        }
    }
    text[h]='\0';
    return text;
}
char *Double_trans::decryption(char cipher[],char key[])          //解密
{
    char *text=(char *)malloc(strlen(cipher)*sizeof(char));
    int i,j,m,cipher_length,h,key_length;
    int num[20];
    cipher_length=strlen(cipher);
    key_length=strlen(key);
    for(i=0;i<key_length;i++)           //确定读取顺序在num中
    {
        num[i]=0;
        for(j=0;j<key_length;j++)
        {
            if(key[j]<key[i]||(key[j]==key[i]&&j<=i))      //找出比自己小的字母的个数
            {
                num[i]=num[i]+1;
            }
        }
    }
    if(cipher_length%key_length==0)			//计算有多少行
        m=cipher_length/key_length;
    else
        m=cipher_length/key_length+1;
    h=0;
    for(i=0;i<key_length;i++)
    {
        for(j=0;j<m;j++)
        {
            text[j*key_length+num[i]-1]=cipher[h];
            h++;
        }
    }
    text[(j-1)*key_length+i]='\0';
    //printf("%s\n",text);
    return text;
}
