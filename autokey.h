#ifndef AUTOKEY_H
#define AUTOKEY_H


class Autokey
{
public:
    Autokey();
    void chart(char key[],int i,char cipher[]);
    void encryption(char plaintext[],char ciphertext[],char cipher[]);
    void decryption(char ciphertext[],char plaintext1[],char plain[],char cipher[]);
};

#endif // AUTOKEY_H
