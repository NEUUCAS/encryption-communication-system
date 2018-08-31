#include "rc4.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

RC4::RC4()
{

}
void RC4::swap(int s[],int i,int j)
{
    int temp=s[i];
    s[i]=s[j];
    s[j]=temp;
}
void RC4::KSA(int key[],int S[])
{
    int i,j;
    for(i=0;i<256;i++)      //初始化S数组
    {
        S[i]=i;
    }
    for(i=0,j=0;i<256;i++)  //初始随机化
    {
        j=(j+S[i]+key[i])%256;
        swap(S,i,j);
    }
}
/*int PRGA(int S[])
{
    int k;
    int i=0,j=0;
    i=(i+1)%256;
    j=(j+S[i])%256;
    swap(S,i,j);
    k=S[(S[j]+S[i])%256];
    return k;
}*/
char * RC4::encrypt(char plain[],int S[])
{
    char *text=(char *)malloc(strlen(plain)*sizeof(char));
    int i,num,plain_length;
    int m=0,n=0;
    plain_length=strlen(plain);
    strcpy(text,plain);
    for(i=0;i<plain_length;i++)
    {
        m=(m+1)%256;                    //PRGA,产生随机数num
        n=(n+S[m])%256;
        swap(S,m,n);
        num=S[(S[m]+S[n])%256];
        text[i]^=(char)num;
    }
    text[i]='\0';
    return text;
}
