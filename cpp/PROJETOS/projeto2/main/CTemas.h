//
//  CTemas.h
//  PROJETO2_RASCUNHO
//
//  Created by Gabriel Santos Correa da Silva on 08/05/22.
//

#ifndef CTemas_h
#define CTemas_h

#include "StructAuxiliares.h"
#include "CJogo.h"
//=====================================================================
class Temas{
public:
    Stema tema;
    Temas *proximo;
};
//=====================================================================
class listaTemas{
    Temas *cabeca;
public:
    listaTemas(){cabeca = nullptr;}
    ~listaTemas();
    void Escolhetema(Jogo &JogoAtual);
    void insereItem(Stema tema);
    bool removeItem(int index);
    void escreveLista(void);
    void escreveFicheiro(void);
    void reiniciaLista(void);
};
//=====================================================================

#endif /* CTemas_h */
