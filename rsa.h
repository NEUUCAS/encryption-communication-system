#ifndef RSA_H
#define RSA_H


class RSA
{
public:
    RSA();
    int biggestfactor(int a,int b);
    int inverse(int a,int b);
    int encryption(int plainnumber[],int length,int e,int n,int str,int endnumber[]);
    int chartonumber(char plaintext[],int plainnumber[],int n);
    void encrpnumber(int number,char ciphertext[],int length,int p);
    int binary(int number,int bin[]);
    int modcalculate(int mici,int bin[],long int b,int mod);
    void numbertobinary(int a[],int block,int i,int ciphernumber[],int mod);
    void decryption(int endnumber[],int orignumber[],int i,int d,int n,int block,int ciphernumber[]);
    void binarytochar(int ciphernumber[],char plaintext1[],int str);
    int ExtendedEuclid(int f,int d);
};

#endif // RSA_H
