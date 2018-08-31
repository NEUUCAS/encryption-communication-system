#include "rsa.h"
#include<stdio.h>
#include<string.h>

RSA::RSA()
{

}
int RSA::biggestfactor(int a,int b){
    int remainder=b%a;
    while(remainder!=0){
        b=a;
        a=remainder;
        remainder=b%a;
    }
    return a;
}
int RSA::encryption(int plainnumber[],int length,int e,int n,int str,int endnumber[]){
    int number=0;
    int temp;
    int mi=1;
    int i,j,k;
    int times;
    int add;
    times=(str*8)/length;
    add=(str*8)%length;
    if(add!=0){
        for(i=0;i<length-add;i++){
            plainnumber[times*length+add+i]=0;
//			printf("%d",plainnumber[times*length+add+i-1]);
        }
        times++;         //块数
    }
//	printf("add success\n");

    for(i=0;i<times;i++){
        for(k=0;k<length;k++){

           mi=1;
        for(j=0;j<length-k-1;j++){
            mi=mi*2;}
        number=number+plainnumber[i*length+k]*mi;}

        printf("%d ",number);
        int bin[40];
        int mici=binary(e,bin);

        int end;
        end=modcalculate(mici,bin,number,n);

        endnumber[i]=end;
        printf("%d\n",end);

        number=0;
    }return i;
}

int RSA::chartonumber(char plaintext[],int plainnumber[],int n){
    int block=-1;
    int length=strlen(plaintext);
    int i,j;
    while(n!=0){
        n=n/2;
        block++;
    }

    for(j=0;j<length;j++){
        for(i=1;i<=8;i++){
            plainnumber[8*j-i+8]=plaintext[j]%2;
            plaintext[j]=plaintext[j]/2;
        }
    }

    for(i=0;i<length*8;i++){
            printf("%d",plainnumber[i]);}

    printf("\n");
       return block;
}


int RSA::binary(int number,int bin[]){    //幂次展成二进制
    int i=0;
    while(number!=0){
        bin[i]=number%2;
        number=number/2;
        i++;}
    return i;
}

int RSA::modcalculate(int mici,int bin[],long int b,int mod){  //模重复平方计算
    int i;
    long int a=1;
    for(i=0;i<mici;i++){
        if(bin[i]==0){
            b=(b%mod*b%mod)%mod;}
        else{
            a=(a%mod*b%mod)%mod;
            b=(b%mod*b%mod)%mod;
        }
    }
    return a;
}

void RSA::numbertobinary(int a[],int block,int i,int ciphernumber[],int mod){
    int j,k;
    int index=0;
    for(k=0;k<i;k++){
        if(a[k]<=0)a[k]=a[k]+mod;
        for(j=0;j<block;j++){
            ciphernumber[k*block+block-j-1]=a[k]%2;
            a[k]=a[k]/2;}
    }
    printf("\n");
    for(j=0;j<block*i;j++){
        printf("%d",ciphernumber[j]);}

}
void RSA::decryption(int endnumber[],int orignumber[],int i,int d,int n,int block,int ciphernumber[]){    //解密
    int ii;
    int j;
    int bin[20];
    ii=binary(d,bin);
    printf("解密之后代表明文的数字为:\n");
    for(j=0;j<i;j++){
        orignumber[j]=modcalculate(ii,bin,endnumber[j],n);
        printf("%d ",orignumber[j]);
    }
    numbertobinary(orignumber,block,i,ciphernumber,n);

}

void RSA::binarytochar(int ciphernumber[],char plaintext1[],int str){
    int i,j;
    int mi=1;
    int c=0;
    for(i=1;i<=str;i++){
        for(j=0;j<8;j++){
            c=c+ciphernumber[i*8-j-1]*mi;
            mi=mi*2;
        }
        plaintext1[i]=c;
        printf("%c",plaintext1[i]);
        mi=1;
        c=0;
    }

    for(int a=0;a<str;a++)
    {
        plaintext1[a]=plaintext1[a+1];
    }
    plaintext1[str]='\0';
    printf("%s",plaintext1);
}

int RSA::ExtendedEuclid(int f,int d){              //求逆元
    int x1,x2,x3,y1,y2,y3,t1,t2,t3,q;
    x1=y2=1;
    x2=y1=0;
    x3=(f>=d)?f:d;
    y3=(f>=d)?d:f;
    while(1)
    {
        if (y3==0)
        {
            return 0;}
        if(y3==1)
        {
            return y2;}
        q=x3/y3;
        t1=x1-q*y1;
        t2=x2-q*y2;
        t3=x3-q*y3;
        x1=y1;
        x2=y2;
        x3=y3;
        y1=t1;
        y2=t2;
        y3=t3;}
}
