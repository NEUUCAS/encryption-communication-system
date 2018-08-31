#include "caesar.h"
#include"string.h"
#include"malloc.h"
Caesar::Caesar()
{

}

char * Caesar::encrypt(char plain[],int num)     //加密
{
    int i=0;
    char *text=(char *)malloc(strlen(plain)*sizeof(char));
    num=num%26;
    strcpy(text,plain);
    for(i=0;i<strlen(plain);i++)
    {
        text[i]='a'+(text[i]-'a'+num)%26;
        if(text[i]>'z')
        {
            text[i]=text[i]-26;
        }
        if(text[i]<'a')
        {
            text[i]=text[i]+26;
        }
    }
    text[i]='\0';
    return text;
}

char * Caesar::decrypt(char cipher[],int num)     //解密
{
    int i=0;
    char *text=(char *)malloc(strlen(cipher)*sizeof(char));
    strcpy(text,cipher);
    num=num%26;
    for(i=0;i<strlen(text);i++)
    {
        text[i]=text[i]-num;
        if(text[i]<'a')
        {
            text[i]=text[i]+26;
        }
        if(text[i]>'z')
        {
            text[i]=text[i]-26;
        }
    }
        return text;
}
