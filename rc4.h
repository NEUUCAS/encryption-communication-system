#ifndef RC4_H
#define RC4_H


class RC4
{
public:
    RC4();
    void swap(int *s,int i,int j);
    void KSA(int key[],int S[]);
    //int PRGA(int S[]);
    char *encrypt(char plain[],int S[]);        //加解密
};

#endif // RC4_H
