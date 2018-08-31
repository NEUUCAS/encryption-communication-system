#ifndef VIGENERE_H
#define VIGENERE_H


class Vigenere
{
public:
    Vigenere();
    char *vigenere(char key[],char plain[]);
    char *anti_vigenere(char key[],char *cipher);
};

#endif // VIGENERE_H
