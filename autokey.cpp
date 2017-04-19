#include "autokey.h"
#include"stdio.h"
#include"string.h"
Autokey::Autokey()
{

}
void Autokey::chart(char key[],int i,char cipher[]){
        int k,j,q,flag;
        char ca;
        for(k=0;k<i;k++){                    //将重复的字母删除
        ca=key[k];
        for(j=k+1;j<i;j++){
            if(ca==key[j]){
                if(j==i-1)
                    i--;
                else
                {
                    for(q=j;q<i-1;q++)
                        key[q]=key[q+1];
                    i--;
                    j--;
                }
            }
        }
    }key[i]='\0';
    j=0;

    while(key[j]!='\0'){
        cipher[j]=key[j];
        j++;}


    for(q=0;q<26;q++){
        flag=0;
        for(k=0;k<i;k++){
            if('a'+q==key[k]){
                flag=1;
                break;}
        }
        if(flag==0)
        {
            cipher[j]='a'+q;                //生成对应表格
            j++;
        }
    }
        for(i=0;i<26;i++){
        printf("%c",cipher[i]);
    }printf("\n");
}
void Autokey::encryption(char plaintext[],char ciphertext[],char cipher[]){
    int index,i;
    for(i=0;i<strlen(plaintext);i++){                //加密
          index=plaintext[i]-'a';
          ciphertext[i]=cipher[index];
    }ciphertext[i]='\0';

    printf("%s\n",ciphertext);
}

void Autokey::decryption(char ciphertext[],char plaintext1[],char plain[],char cipher[]){
    int i,j;
    for(i=0;i<strlen(ciphertext);i++){          //解密
        for(j=0;j<26;j++){
            if(ciphertext[i]==cipher[j])
                plaintext1[i]=plain[j];
        }
    }plaintext1[i]='\0';

    printf("%s",plaintext1);
}
