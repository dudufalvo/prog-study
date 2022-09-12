//
//  CRanking.h
//  Projeto_2
//
//  Created by Gabriel Santos Correa da Silva on 03/05/22.
//

#ifndef CRanking_h
#define CRanking_h
#include "CJogo.h"
//=====================================================================
class ranking{
    public:
    char nome_C[MAX];
    int pontos;
    ranking *proximo;
};
//=====================================================================
class listaRank{
    ranking *cabeca;
public:
    listaRank(){cabeca = nullptr;}
    ~listaRank();
    void insereItem(ranking &r);
    void atualizaJogador(char *string_C, Jogo &ultimoJogo);
    void escreveFicheiro();
};
//=====================================================================
#endif /* CRanking_h */
