#ifndef DOUBLE_TRANS_H
#define DOUBLE_TRANS_H


class Double_trans
{
public:
    Double_trans();

    char *encryption(char plaintext[], char key[]);
    char *decryption(char cipher[], char key[]);
};

#endif // DOUBLE_TRANS_H
