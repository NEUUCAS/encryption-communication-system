#include "playfair.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
Playfair::Playfair()
{

}
char * Playfair::playfair(char plain[],char key[])         //加密算法
{
    char *text=(char *)malloc(100*sizeof(char));
    char *text1=(char *)malloc(100*sizeof(char));
    char c,key1[26],square[5][5];
    int key_length=strlen(key);
    int plain_length=strlen(plain);
    int i,j,k,a[2],b[2],m,flag,n=0;
    ///////////////对key操作处理
    for(i=0;i<key_length;i++)       //去重符字母
    {
        for(j=i+1;j<key_length;j++)
        {
            if(key[j]==key[i])
            {
                for(k=j;k<key_length;k++)
                {
                    key[k]=key[k+1];
                }
                key[key_length]='\0';
                key_length--;
            }
        }
    }
    for(i=0;i<key_length;i++)       //将key中j变成i
    {
        if(key[i]=='j')
        {
            key[i]='i';
        }
    }
    for(i=0;i<key_length;i++)
    {
        key1[i]=key[i];
    }
    key1[key_length]='\0';
    c='a';              //将key补成长度为25的字母串（没有相同的字母）,结果存入key1中
    for(i=0;i<25;i++)
    {
        flag=1;
        if(c=='j')
        {
            c=c+('b'-'a');
        }
        for(j=0;j<strlen(key);j++)
        {
            if(key[j]==c)
            {
                flag=0;
            }
        }
        if(flag==1)
        {
            key1[strlen(key)+n]=c;
            n++;
        }
        c=c+('b'-'a');
    }
    key1[26]='\0';
    for(i=0,j=-1;i<25;i++)          //将key1填入square方阵中
    {
        if(i%5==0)
        {
            j++;
        }
        square[j][i%5]=key1[i];
    }
    /*for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%c",square[i][j]);
        }
        printf("\n");
    }*/
    strcpy(text,plain);
    //printf("%s\n",text);
    ///////////////////对明文操作处理,存入text中
    for(i=0;i<plain_length;i++)       //将text中所有j变成i,并将双字母中间加'q'
    {
        if(text[i]=='j')     // 将text中所有j变成i
        {
            text[i]='i';
        }
        if(i<plain_length-1)
        {
            if(text[i]==text[i+1])        //  双字母中间加入q
            {
                for(j=plain_length;j>i+1;j--)
                {
                    text[j]=text[j-1];
                }
                text[i+1]='q';
                plain_length++;           //  没加入一个'q'，明文长度+1
            }
        }
    }
    if(plain_length%2!=0)     //如果明文长度为奇数，在末尾加入'q',使字母数成为偶数
    {
        text[plain_length]='q';
    }
    /*printf("%s\n",text);
    printf("%d\n",strlen(text));
    printf("%s\n",key1);
    printf("%d\n",strlen(key1));*/

    /////////////加密
    for(i=0;i<strlen(text);i+=2)
    {
        for(j=0;j<strlen(key1);j++)       //将字母对de行列数分别存入数组a,b,行数为第一个数a[0]，列数为第二个数a[1]
        {
            if(text[i]==key1[j])
            {
                a[0]=j/5;
                a[1]=j%5;
                //printf("a:%d,%d\n",a[0],a[1]);
            }
            if(text[i+1]==key1[j])
            {
                b[0]=j/5;
                b[1]=j%5;
                //printf("b:%d,%d\n",b[0],b[1]);
            }
        }
        ///////////////////////////////////////进行加密规则变换
        if(a[0]!=b[0])          //不同行时
        {
            if(a[1]!=b[1])      //不同行，不同列,m用于交换
            {
                m=a[1];
                a[1]=b[1];
                b[1]=m;
            }
            else            //不同行，同列
            {
                a[0]=(a[0]+1)%5;
                b[0]=(b[0]+1)%5;
            }
        }
        else        //同行,不同列时
        {
            a[1]=(a[1]+1)%5;
            b[1]=(b[1]+1)%5;
        }
        ////////////////////将结果写入text1
        text1[i]=square[a[0]][a[1]];
        text1[i+1]=square[b[0]][b[1]];
    }

    text1[strlen(text)]='\0';
    return text1;
}
char * Playfair::anti_playfair(char *cipher,char key[])
{
    char *plain=(char *)malloc(100*sizeof(char));
    char a[2],b[2];
    int i,j,m,k,flag,n=0;
    char c,key1[26],square[5][5];
    int key_length=strlen(key);
    ///////////////对key操作处理
    for(i=0;i<key_length;i++)       //去重符字母
    {
        for(j=i+1;j<key_length;j++)
        {
            if(key[j]==key[i])
            {
                for(k=j;k<key_length;k++)
                {
                    key[k]=key[k+1];
                }
                key[key_length]='\0';
                key_length--;
            }
        }
    }
    for(i=0;i<key_length;i++)       //将key中j变成i
    {
        if(key[i]=='j')
        {
            key[i]='i';
        }
    }
    for(i=0;i<key_length;i++)
    {
        key1[i]=key[i];
    }
    key1[key_length]='\0';
    c='a';              //将key补成长度为25的字母串（没有相同的字母）,结果存入key1中
    for(i=0;i<25;i++)
    {
        flag=1;
        if(c=='j')
        {
            c=c+('b'-'a');
        }
        for(j=0;j<strlen(key);j++)
        {
            if(key[j]==c)
            {
                flag=0;
            }
        }
        if(flag==1)
        {
            key1[strlen(key)+n]=c;
            n++;
        }
        c=c+('b'-'a');
    }
    key1[26]='\0';
    for(i=0,j=-1;i<25;i++)          //将key1填入square方阵中
    {
        if(i%5==0)
        {
            j++;
        }
        square[j][i%5]=key1[i];
    }

    for(i=0;i<strlen(cipher);i+=2)
    {
        for(j=0;j<strlen(key1);j++)      //将字母对de行列数分别存入数组a,b,行数为第一个数a[0]，列数为第二个数a[1]
        {
            if(cipher[i]==key1[j])
            {
                a[0]=j/5;
                a[1]=j%5;
            }
            if(cipher[i+1]==key1[j])
            {
                b[0]=j/5;
                b[1]=j%5;
            }
        }
        ///////////////////////////////////////进行加密规则变换de逆过程
        if(a[0]!=b[0])          //不同行时
        {
            if(a[1]!=b[1])      //不同行，不同列,m用于交换
            {
                m=a[1];
                a[1]=b[1];
                b[1]=m;
            }
            else            //不同行，同列
            {
                a[0]=(a[0]+4)%5;
                b[0]=(b[0]+4)%5;
            }
        }
        else        //同行,不同列时
        {
            a[1]=(a[1]+4)%5;
            b[1]=(b[1]+4)%5;
        }
        ////////////////////将结果写入plain
        plain[i]=square[a[0]][a[1]];
        plain[i+1]=square[b[0]][b[1]];
    }
    return plain;
}
