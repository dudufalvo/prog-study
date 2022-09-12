//
//  StructAuxiliares.h
//  Projeto_2
//
//  Created by Gabriel Santos Correa da Silva on 03/05/22.
//

#ifndef StructAuxiliares_h
#define StructAuxiliares_h
#define MAX 51
#include <sys/time.h>
//=====================================================================
struct timeval before, after;
//=====================================================================
struct saveJogo
{
    char palavra_C[MAX];
    char tema_C[MAX];
    char nome_C[MAX];
    bool emJogo;
    char letrasCertas[MAX];
    char erros[7];
    int tentativas;
    int acertos;
    int pontos;
    int indexPalavrasJogadas[24];
    int palavrasTotais;
    int TotalTemas;
    int palavrasJogadas;
    int tamanho_palavra;
    int dificuldade;
    int modo;
    double tempo;
};
//=====================================================================
struct Stema {
        char tema[MAX];
        int elementos;
    };
//=====================================================================
struct SPalavras{
    char Palavra[MAX];
    int jaJogada;
};
//=====================================================================
#endif /* StructAuxiliares_h */
