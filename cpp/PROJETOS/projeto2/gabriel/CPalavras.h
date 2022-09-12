#ifndef CPalavras_h
#define CPalavras_h
#include "CJogo.h"
#include <iostream>
#include "StructAuxiliares.h"
using namespace std;
//=====================================================================
class palavras_Tema{
    public:
    char nome_C[MAX];
    int jaJogada;
    palavras_Tema *proximo;
};
//=====================================================================
class listaPalavras_Tema{
    palavras_Tema *cabeca;
public:
    listaPalavras_Tema(){cabeca = nullptr;}
    ~listaPalavras_Tema();
    void reiniciaLista();
    void insereItem(char *novaPalavra, int numeroJogadas);
    bool removeItem(int index);
    void escreveFicheiro(string tema);
    void editaLista(int index, char *string_C );
    void escreveLista(void);
};
//=====================================================================
#endif /* CPalavras_h */

/* 
************ Lógica modo profissional *********************
*
*   Teremos uma Linked List de Palavras para serem sorteadas,
*   De acordo com o número de vezes que já foi jogada, ela ocupará X espaços na Linked List
*   No máximo a Palavra pode ocupar 5 lugares na linked list
*   E sendo a palavra menos jogada o parâmetro de comparação
*   A cada 2 jogada a mais q o parâmetro, a palavra terá menos 1 lugar na linked list
*   Sendo o minimo de 1 lugar.
*   Sorteio normal com rand a partir dai.
*
*   OU
*
*   https://stackoverflow.com/questions/12885356/random-numbers-with-different-probabilities
*
*
*/