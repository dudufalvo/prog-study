//=============================================================================
// EDA 2021/22 ficha 10 (arvores binarias de pesquisa)
// Rui P. Rocha (2022.04.26, 2019.04.07, 2017.04.24)
// Paulo Coimbra (2010.05.20, 2008.06.01)
//=============================================================================
// source file: CArvoreBinaria.cpp
//=============================================================================

#include "CArvoreBinaria.h"

//=============================================================================
// classe CArvoreBinaria - codigo dos metodos como na ficha 10 (e slides teoricas)
//=============================================================================

CArvoreBinaria::CArvoreBinaria() {  // Construtor
    raiz = nullptr;
}
//=============================================================================

CArvoreBinaria::~CArvoreBinaria() {  // Destrutor
    destroi();    // metodo que elimina todos os nos
}
//=============================================================================

// metodo public para destruir todos os nos da arvore
void CArvoreBinaria::destroi(){
    destroiSubArvore(raiz); // chama o metodo private (recursivo)
    raiz = nullptr;
}
//=============================================================================

// metodo private para destruir uma subarvore
void CArvoreBinaria::destroiSubArvore(CNoArvore *pArvore) {
    if (pArvore != nullptr) {
        destroiSubArvore(pArvore->esq);
        destroiSubArvore(pArvore->dir);
        delete pArvore;
    }
}
//=============================================================================

// metodo public para pesquisar recursivamente toda a arvore
bool CArvoreBinaria::procura(int item) const {
    return procuraRecursiva(raiz, item);
}
//=============================================================================

// metodo private para pesquisar recursivamente numa subarvore
bool CArvoreBinaria::procuraRecursiva(CNoArvore *raiz, int item) const {
    // casos elementares
    if (raiz == nullptr) return false;
    if (raiz->dados == item) return true;

    // caso geral
    if (raiz->dados < item)
        return procuraRecursiva(raiz->dir, item);
    else return procuraRecursiva(raiz->esq, item);
}
//=============================================================================

// metodo public para a travessia da arvore pre-ordem
void CArvoreBinaria::escrevePreOrdem() const {
        escrevePreOrdem(raiz);
        cout << endl;
}
//=============================================================================

// metodo private para a travessia recursiva da subarvore pre-ordem
void CArvoreBinaria::escrevePreOrdem(CNoArvore* raiz) const {
    if (raiz == nullptr) return;
    cout << raiz->dados << endl;
    escrevePreOrdem(raiz->esq);
    escrevePreOrdem(raiz->dir);
}
//=============================================================================

// metodo public para fazer a insercao ordenada de um novo valor
void CArvoreBinaria::insere(int item) {
    if (raiz != nullptr) insere(item, raiz); // chama o metodo private que faz o trabalho
    else {  // cria o primeiro no da arvore
        raiz = new CNoArvore;
        raiz->dados = item;
        raiz->esq = raiz->dir = nullptr;
    }
}
//=============================================================================

// metodo private para fazer a insercao ordenada de um novo valor numa subarvore
void CArvoreBinaria::insere(int item, CNoArvore *raiz) {
    if (item < raiz->dados) {
        if (raiz->esq != nullptr) insere(item, raiz->esq);
        else { // novo no e o primeiro no da subarvore esquerda
            raiz->esq = new CNoArvore;
            raiz->esq->dados = item;
            raiz->esq->esq = raiz->esq->dir = nullptr;
        }
    }
    else if (item > raiz->dados) {
        if (raiz->dir != nullptr) insere(item, raiz->dir);
        else { // novo no e o primeiro no da subarvore direita
            raiz->dir = new CNoArvore;
            raiz->dir->dados = item;
            raiz->dir->esq = raiz->dir->dir = nullptr;
        }
    }
}
//=============================================================================

bool CArvoreBinaria::elimina(int item) {
    CNoArvore *pai, *aux, *filho, *sucessor;
    bool encontrado=false;

    // procura o no a eliminar
    pai = nullptr;
    aux = raiz;
    while ( (aux != nullptr) && (!encontrado) ) {
        if (aux->dados == item) encontrado = true;
        else if (item < aux->dados) {
            pai = aux;
            aux = aux->esq;
        }
        else {
            pai = aux;
            aux = aux->dir;
        }
    }
    // se for encontrado ?aux? aponta para o no
    // a eliminar e ?pai? aponta para o seu pai (se existir)

    if (encontrado) {
        // se no tem no maximo um filho
        if ( (aux->esq == nullptr) || (aux->dir == nullptr) ) {
            if (aux->esq != nullptr)
                filho = aux->esq;
            else filho = aux->dir;
            if (pai == nullptr) // caso especial: apaga raiz
                raiz = filho;
            else {           // atualiza ligacoes
                if (aux->dados < pai->dados) pai->esq = filho;
                else pai->dir = filho;
            }
            delete aux;
        }
        else {  // eliminar no com dois filhos
            // procura sucessor
            sucessor = aux->dir;
            pai = aux;
            while (sucessor->esq != nullptr) {
                pai = sucessor;
                sucessor = sucessor->esq;
            }
            aux->dados = sucessor->dados; // troca val.
            if (sucessor == aux->dir) aux->dir = sucessor->dir;
            else // substitui pelo seu sucessor `a dir.
                pai->esq = sucessor->dir;
            delete sucessor;
        }
        return true;
    }
    return false;
}
//=============================================================================
void CArvoreBinaria::escrevePorOrdem(CNoArvore *pArvore) const {
    if(pArvore==nullptr) return;
    escrevePorOrdem(pArvore->esq);
    cout << pArvore->dados << endl;
    escrevePorOrdem(pArvore->dir);
}
//=============================================================================
void CArvoreBinaria::escrevePorOrdem() const {
    escrevePorOrdem(raiz);
    cout << endl;
}
//=============================================================================
void CArvoreBinaria::maxEminInt(int &maximo, int &minimo) const {
    CNoArvore *atual = raiz;
    if(atual == nullptr) {
        minimo = 0;
        maximo = 1;
    }

    while(atual->esq != nullptr) {
        atual = atual->esq;
    } minimo = atual->dados;

    CNoArvore *atual = raiz;
    while(atual->dir != nullptr) {
        atual = atual->dir;
    } maximo = atual->dados;
}
//=============================================================================
int CArvoreBinaria::getMinimo(CNoArvore *pArvore) const {
    if(pArvore==nullptr) return 0;
    if(pArvore->esq==nullptr) return pArvore->dados;

    return getMinimo(pArvore->esq);
}
//=============================================================================
int CArvoreBinaria::getMaximo(CNoArvore *pArvore) const {
    if(pArvore==nullptr) return 0;
    if(pArvore->dir==nullptr) return pArvore->dados;

    return getMaximo(pArvore->dir);
}
//=============================================================================
void CArvoreBinaria::maxEminRec(int &maximo, int &minimo) const {
    minimo = getMinimo(raiz);
    maximo = getMaximo(raiz);
}
//=============================================================================
int CArvoreBinaria::somaFolha(CNoArvore *pArvore) const {
    if(pArvore == nullptr) return 0;
    if(pArvore->esq == nullptr && pArvore->dir == nullptr) return pArvore->dados;

    return somaFolha(pArvore->esq) + somaFolha(pArvore->dir);
    
}
//=============================================================================
int main() {
    CArvoreBinaria tree;
    int max, min;
    tree.insere(9);
    tree.insere(5);
    tree.insere(3);
    tree.insere(6);
    tree.insere(14);
    tree.insere(23);

    tree.maxEminRec(max, min);
    cout << max;
    cout << min;
}