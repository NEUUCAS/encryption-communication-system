#include "ca.h"
#include"stdio.h"
#include"string.h"
#include"math.h"
CA::CA()
{

}
void CA::binary(int number,int bin1[])
{

 int tmp,NUM=0,j=0;//临时变量表示m模2的余数
 int bin2[8];
 while(number!=0)
 {
   tmp=number%2;
   bin1[NUM]=tmp;
   number=number/2;
   NUM++;
 }
 while(NUM<8)
 {
     bin1[NUM]=0;
     NUM++;
 }
for(int i=7;i>=0;i--)
{
    bin2[j]=bin1[i];
     j++;
}
 for(int i=0;i<8;i++)
 {
     bin1[i]=bin2[i];
 }
}


void CA::jiami(int number,int CA[],char mingwen[],int b[100])
{
    printf("经过8轮测试生成密钥(规定每轮都从CA[4]中得到密钥位):\n");
    int n=8;
    int count=0;
    int CA1[8];
    int temp1=0,temp2=0,temp3=0;
    int y=0;
    while(n>0)
    {
        CA1[count]=CA[4];
         printf("%d ",CA[4]);
         for(int i=0;i<7;i++)
         {
             if(i==0)
             {
                 temp1=CA[6]*4+CA[0]*2+CA[1]*1;
                 CA[0]=CA[temp1];
             }
             else if(i==6)
             {
                 temp2=CA[5]*4+CA[6]*2+CA[0]*1;
                 CA[6]=CA[temp2];
             }
             else
                 temp3=CA[i-1]*4+CA[i]*2+CA[i+1]*1;

                 CA[i]=CA[temp3];
         }
         n--;
         count++;
    }
    printf("\n");
    printf("**********************\n");
    printf("     加密   \n");
    printf("**********************\n");
    int  v1[8]; //起始用于保存明文二进制,后者用于临时存密文二进制.
    int  temp=0;
    int length=0,jj=0;
    length=strlen(mingwen);
    for(int i=0;i<length;i++)
    {	temp=mingwen[i];
         binary(temp,v1);
         for(jj=0;jj<8;jj++)
         {
             if(CA1[jj]==0&&v1[jj]==0||CA1[jj]==1&&v1[jj]==1)
                   v1[jj]=0;
            else
                v1[jj]=1;
         }
         for(int k=0;k<8;k++)
         {
            printf("%d",v1[k]);
            b[y]=v1[k];
            y++;
         }
         printf("\n");
    }
    b[y+1]=2;
//	return y;
}


void CA::jiemi(int number,int CAg[],int b[])
{

    int n=8;
    int count=0;
    int CA1[8];
    int temp1=0,temp2=0,temp3=0;
    int y1=0;
    int y=0;
    while(b[y1]!=2)
        y1++;
    y=y1-1;
    while(n>0)
    {
        CA1[count]=CAg[4];
         printf("%d ",CAg[4]);
         for(int i=0;i<7;i++)
         {
             if(i==0)
             {
                 temp1=CAg[6]*4+CAg[0]*2+CAg[1]*1;
                 CAg[0]=CAg[temp1];
             }
             else if(i==6)
             {
                 temp2=CAg[5]*4+CAg[6]*2+CAg[0]*1;
                 CAg[6]=CAg[temp2];
             }
             else
                 temp3=CAg[i-1]*4+CAg[i]*2+CAg[i+1]*1;

                 CAg[i]=CAg[temp3];
         }
         n--;
         count++;
    }
    printf("针对得到的明文进行解密并输出明文:\n");
    static int num=0,z=0,c=0;
    int sum=0;
    char p1[50];    //用于保存解密后的明文
//做异或运算
     for(int i=0;i<y;i++,c++)
     {
         if(b[c]==0&&CA1[(i%8)]==0||b[c]==1&&CA1[(i%8)]==1)
                b[c]=0;
         else
                b[c]=1;
     }
     printf("\n");
     for(int i=0;i<y;i++)
         printf("%d",b[i]);
     printf("\n");
    while(1)
    {
        int d;
        for( d=num;d<num+8;d++)
        {
            sum=b[d]*(int)pow(2,7-(d%8))+sum;
        }
        p1[z]=sum;
        z++;
        num=num+8;
        sum=0;
        if(d==y)
            break;
    }
    for(int d=0;d<z;d++)
        printf("%c",p1[d]);
}
