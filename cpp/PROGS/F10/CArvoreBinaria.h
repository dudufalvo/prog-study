//=============================================================================
// EDA 2021/22 ficha 10 (arvores binarias de pesquisa)
// Rui P. Rocha (2022.04.26, 2019.04.07, 2017.04.24)
// Paulo Coimbra (2010.05.20, 2008.06.01)
//=============================================================================
// header file: CArvoreBinaria.h
//=============================================================================

#ifndef CArvoreBinaria_h
#define CArvoreBinaria_h

//=============================================================================
#include <iostream>
using namespace std;


class CArvoreBinaria; // "declarada" aqui para poder ser designada como amiga

//=============================================================================
// classe CNoArvore - definicao - como na ficha 9
//=============================================================================
class CNoArvore {
private:
    int dados;
    CNoArvore *esq;     // ponteiro para subarvore esquerda
    CNoArvore *dir;     // ponteiro para subarvore dreita
    friend class CArvoreBinaria; // esta classe pode aceder a atributos private
};

//=============================================================================
// classe CArvoreBinaria - definicao - como na ficha 9
//=============================================================================
class CArvoreBinaria {
private:
    CNoArvore *raiz;    // ponteiro para a raiz da arvore
    bool procuraRecursiva(CNoArvore*, int) const;
    void escrevePreOrdem(CNoArvore*) const;
    void escrevePorOrdem(CNoArvore*) const;
    void insere(int, CNoArvore*);
    void destroiSubArvore(CNoArvore*);
    int getMinimo(CNoArvore*) const;
    int getMaximo(CNoArvore*) const;

public:
    CArvoreBinaria();
    ~CArvoreBinaria();
    bool procura(int) const;
    void escrevePreOrdem() const;
    void insere(int);
    bool elimina(int);
    void destroi();
    void escrevePorOrdem(void) const;
    void maxEminInt(int&, int&) const;
    void maxFolha(int*) const;
    void minFolha(int*) const;
    void maxEminRec(int&, int&) const;
    int somaFolha(CNoArvore*) const;
};

//=============================================================================
#endif
