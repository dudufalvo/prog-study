#ifndef CPalavras_h
#define CPalavras_h
#include "CJogo.h"
#include <iostream>
using namespace std;
//=====================================================================
class palavras_Tema{
    public:
    char nome_C[MAX];
    palavras_Tema *proximo;
};
//=====================================================================
class listaPalavras_Tema{
    palavras_Tema *cabeca;
public:
    listaPalavras_Tema(){cabeca = nullptr;}
    ~listaPalavras_Tema();
    void reiniciaLista();
    void insereItem(char *novaPalavra);
    bool removeItem(int index);
    void escreveFicheiro(string tema);
    void editaLista(int index, char *string_C );
    void escreveLista(void);
};
//=====================================================================
#endif /* CPalavras_h */