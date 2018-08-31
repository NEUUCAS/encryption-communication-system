#ifndef CAESAR_H
#define CAESAR_H


class Caesar
{
public:
    Caesar();
    char *encrypt(char plain[],int num);
    char *decrypt(char plain[],int num);
};

#endif // CAESAR_H
