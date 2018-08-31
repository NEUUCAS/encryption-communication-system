#include "column.h"
#include"string.h"
#include"stdio.h"
COLUMN::COLUMN()
{

}
void COLUMN::encryption(char plaintext[],char key[],char ciphertext[],int priority[]){

    int len=(strlen(plaintext));    //计算出明文的长度
    int length=strlen(key);
    int len1=len%length;
    if(len1!=0){
        for(int i=0;i<length-len1;i++){  //在明文不够密钥的整数倍的情况下补‘x'
        plaintext[len+i]='x';
        }
    }


    int totallen=len;
    if(len1!=0){
        totallen=length-len1+len;        //计算明文总长度
    }

    int row=totallen/length;
    int k=0;
    for(int j=0;j<length;j++){
        k=priority[j];
        for(int i=0;i<row;i++){
            ciphertext[i+row*j]=plaintext[k+i*length];  //将明文数组的某列赋值给密文数组
        }
    }

    ciphertext[length*row]='\0';

}

void COLUMN::decryption(char plaintext[],char key[],char ciphertext[],int priority[]){
    int len=strlen(ciphertext);
    int length=strlen(key);
    int row=len/length;

    for(int i=0;i<length;i++){
        int k=priority[i];
        for(int w=0;w<row;w++){
            plaintext[k+length*w]=ciphertext[i*row+w];        //按照明文顺序将对应的密文赋值过去
        }
    }
    plaintext[len]='\0';
}
void COLUMN::priorityfun(char key[],int priority[]){
    int i=0;
    int j=0;
    int length=0;

    while(key[i]!='\0'){      //计算出keyword的长度
        length++;
        i++;}

    i=0;
    for(i;i<length;i++){
        for(j=i+1;j<length;j++){    //记录keyword的每个字母在字母表中的顺序
            if(key[i]>key[j])
                priority[i]++;
            else
                priority[j]++;
        }
    }

    i=0;
    for(i;i<length;i++){printf("%d",priority[i]);} //输出keyword所决定的顺序

    printf("\n");
}
