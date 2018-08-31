#ifndef COLUMN_H
#define COLUMN_H


class COLUMN
{
public:
    COLUMN();
    void encryption(char plaintext[],char key[],char ciphertext[],int priority[]);
    void decryption(char plaintext[],char key[],char ciphertext[],int priority[]);
    void priorityfun(char key[],int priority[]);
};

#endif // COLUMN_H
