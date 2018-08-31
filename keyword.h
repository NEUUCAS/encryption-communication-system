#ifndef KEYWORD_H
#define KEYWORD_H


class keyword
{
public:
    keyword();
    char *Autokeyplaintext(char key[],char plain[]);
    char *anti_Autokeyplaintext(char key[],char *cipher);
};

#endif // KEYWORD_H
