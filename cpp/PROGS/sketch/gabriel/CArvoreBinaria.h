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
#include <fstream>
#include "CListaInteiros.cpp"
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
    void escrevePosOrdem(CNoArvore*) const;
    void escreveFicheiroPreOrdem(CNoArvore*, string) const;
    int Max(CNoArvore*) const;
    int Min(CNoArvore*) const;
    int Soma(CNoArvore*) const;
    int SomaFolhas(CNoArvore*) const;
    int SomaEsquerda(CNoArvore*, CNoArvore*) const;
    int folhaMenosFunda(CNoArvore*)const;
    int folhaMaisFunda(CNoArvore*)const;
    bool caminhoDesdeRaiz(CNoArvore *raiz, int item, CListaInteiros &cam)const;
    int profundidade(CNoArvore*, int)const;
    int obtemMinExcetoFolhas(CNoArvore*,CNoArvore *)const;
    CNoArvore* ponteiroParaPai(CNoArvore *raiz,CNoArvore *pai, int n)const;
    CNoArvore* getNo(CNoArvore *raiz, int n)const;
    void insere(int, CNoArvore*);
    void destroiSubArvore(CNoArvore*);
public:
    CArvoreBinaria();
    CArvoreBinaria(int *, int);
    ~CArvoreBinaria();
    bool procura(int) const;
    void escrevePreOrdem(void) const;
    void escrevePorOrdem(void) const;
    void escrevePosOrdem(void) const;
    void escreveFicheiroPreOrdem(string) const;
    void leFicheiroPreOrdem(string);
    void maxMin(int &, int &) const;
    void soma(int &)const;
    void somaFolhas(int &) const;
    void somaEsquerda(int &) const;
    int  desequilibrio(void) const;
    bool caminhoDesdeRaiz(int item, CListaInteiros &cam)const;
    int profundidade(int)const;
    int obtemMinExcetoFolhas(void)const;
    int valorPai(int n)const;
    void insere(int);
    bool elimina(int);
    void destroi(void);
};

//=============================================================================
#endif
