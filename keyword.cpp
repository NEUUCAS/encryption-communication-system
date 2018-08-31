#include "keyword.h"
#include "stdio.h"
#include "string.h"
#include "malloc.h"
keyword::keyword()
{

}
static int square[26][26];      //vigenere鏂归樀
void make_square();
char * keyword::Autokeyplaintext(char key[],char plain[])        //鍔犲瘑绠楁硶
{
    make_square();
    char *text=(char *)malloc(strlen(plain)*sizeof(char));
    int key_length=strlen(key);
    int plain_length=strlen(plain);
    int i,j,c,d;
    for(i=0;i<plain_length;i++)
    {
        if((plain[i]>=65&&plain[i]<=90)||(plain[i]>=97&&plain[i]<=122))
        {
            if(plain[i]>=97&&plain[i]<=122)     //瀛楁瘝涓哄皬鍐欐椂
            {
                c=plain[i]-96;
            }
            else        //瀛楁瘝涓哄ぇ鍐欐椂
            {
                c=plain[i]-64;
            }
            if(i<key_length)
            {
                j=i%key_length;     //j涓哄瘑閽ュ搴旀槑鏂囩殑瀛楁瘝(琛?,c涓烘槑鏂囧瓧姣?鍒?
                text[i]=square[key[j]-96][c];
            }
            else        //褰撹秴杩噆ey闀垮害鏃讹紝瀵嗛挜杞崲鎴恔ey闀垮害涔嬪墠鐨勬槑鏂?
            {
                if(plain[i]>=97&&plain[i]<=122)     //瀛楁瘝涓哄皬鍐欐椂
                {
                    d=plain[i-key_length]-96;
                }
                else        //瀛楁瘝涓哄ぇ鍐欐椂
                {
                    d=plain[i-key_length]-64;
                }
                text[i]=square[d][c];
            }
        }
        else text[i]=plain[i];
    }
    text[i]='\0';
    return text;
}
char * keyword::anti_Autokeyplaintext(char key[],char *cipher)        //瑙ｅ瘑
{
    make_square();
    char *plain=(char *)malloc(strlen(cipher)*sizeof(char));
    int key_length=strlen(key);
    int plain_length=strlen(cipher);
    int i,j,c,k,d;
    for(i=0,j=0;i<plain_length;i++,j++)
    {
        if(cipher[i]>=65&&cipher[i]<=90)
        {
            c=i%key_length;         //鎵€鐢ㄥ瘑閽ュ湪鎵€鍦?
            if(j>=key_length)
            {
                for(j=0;j<key_length;j++)
                {
                    key[j]=plain[i-key_length+j];
                }
                j=0;
            }
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
void make_square()
{
    int i,j;
    for(i=1;i<27;i++)               //鍒濆鍖杤igenere鏂归樀,鐢?~26
        {
            for(j=1;j<27;j++)
            {
                square[i][j]=63+i+j;    //i,j鍧囦粠1寮€濮嬶紝鎵€浠ヤ负63
                if(square[i][j]>90)     //Z鐨凙SCII鐮佷负90
                {
                    square[i][j]=square[i][j]-26;
                }
                 printf("%c ",square[i][j]);    //鎸夎鎵撳嵃鍒濆鍖杤igenere琛?
            }
            printf("\n");
        }
}
