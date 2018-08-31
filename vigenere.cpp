#include "vigenere.h"
#include "stdio.h"
#include "string.h"
#include "malloc.h"
Vigenere::Vigenere()
{

}
char * Vigenere::vigenere(char key[],char plain[])         //加密算法
{
    int square[26][26];
        int i=0,j;
        for(i=1;i<27;i++)               //初始化vigenere方阵,由1~26
        {
            for(j=1;j<27;j++)
            {
                square[i][j]=63+i+j;    //i,j均从1开始，所以为63
                if(square[i][j]>90)     //Z的ASCII码为90
                {
                    square[i][j]=square[i][j]-26;
                }
                 printf("%c ",square[i][j]);    //按行打印初始化vigenere表
            }
            printf("\n");
        }
    char *text=(char *)malloc(strlen(plain)*sizeof(char));
    int key_length=strlen(key);
    int plain_length=strlen(plain);
    int c;
    for(i=0;i<plain_length;i++)
    {
        if((plain[i]>=65&&plain[i]<=90)||(plain[i]>=97&&plain[i]<=122))
        {
            if(plain[i]>=97&&plain[i]<=122)     //字母为小写时
            {
                c=plain[i]-96;
            }
            else        //字母为大写时
            {
                c=plain[i]-64;
            }
            j=i%key_length;     //j为密钥对应明文的字母(行),c为明文字母(列)
            text[i]=square[key[j]-96][c];
        }
        else text[i]=plain[i];
    }
    text[i]='\0';
    return text;
}


char * Vigenere::anti_vigenere(char key[],char *cipher)         //解密算法
{
    int square[26][26];
        int i,j;
        for(i=1;i<27;i++)               //初始化vigenere方阵,由1~26
        {
            for(j=1;j<27;j++)
            {
                square[i][j]=63+i+j;    //i,j均从1开始，所以为63
                if(square[i][j]>90)     //Z的ASCII码为90
                {
                    square[i][j]=square[i][j]-26;
                }
                 printf("%c ",square[i][j]);    //按行打印初始化vigenere表
            }
            printf("\n");
        }
    char *plain=(char *)malloc(strlen(cipher)*sizeof(char));
    int key_length=strlen(key);
    int plain_length=strlen(cipher);
    int c,k,d;
    for(i=0;i<plain_length;i++)
    {
        if(cipher[i]>=65&&cipher[i]<=90)
        {
            c=i%key_length;         //所用密钥在所在
            k=key[c]-96;
            d=cipher[i]-square[k][1];
            if(d>=0)
            {
              plain[i]='a'+d;
            }
            else
            {
              plain[i]='z'+d+1;
            }
        }
        else
        {
            plain[i]=cipher[i];
        }
    }
    plain[i]='\0';
    return plain;
}
