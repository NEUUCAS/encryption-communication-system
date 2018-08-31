#ifndef PLAYFAIR_H
#define PLAYFAIR_H

static char square[5][5];        //5 x 5方阵
class Playfair
{
public:
    Playfair();
    char *playfair(char plain[],char key[]);
    char *anti_playfair(char *cipher,char key[]);
};

#endif // PLAYFAIR_H
