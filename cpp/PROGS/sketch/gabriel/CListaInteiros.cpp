//=============================================================================
//EDA 2021/22, EDA 2014/15, 2012/2011, 2007/2008, ficha 8 (listas ligadas)
//Paulo Coimbra (2008.04.21, 2012.04.14), Rui P. Rocha (2015.04.11, 2022.04.18)
//=============================================================================
//  file: CListaInteiros.cpp
//=============================================================================
// classe CListaInteiros - codigo dos metodos
//=============================================================================
#include <iostream>
#include "CListaInteiros.h"
using namespace std;
//=============================================================================
CListaInteiros::CListaInteiros(){ // Construtor por omissao
    cabeca = nullptr;
}
//=============================================================================
CListaInteiros::~CListaInteiros(){
    CNoLista *atual, *proximo;

    atual=cabeca;
    while (atual != nullptr){
        proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}
//=============================================================================
void CListaInteiros::insereItem(int item){
    CNoLista *novo = new CNoLista;
    CNoLista *atual;

    novo->dados = item;
    novo->proximo = nullptr;

    if(cabeca == nullptr){
        cabeca=novo;
    }else{
        atual = cabeca;
        while (atual->proximo != nullptr)
            atual = atual->proximo;
        atual->proximo = novo;
    }
}
//=============================================================================
void CListaInteiros::insereItemOrdenado(int item){
    CNoLista *novo = new CNoLista;     // aloca espaço para o novo nó
    CNoLista *atual, *anterior;

    novo->dados = item;                // inicializa os dados do novo nó
    novo->proximo = nullptr;

    if(cabeca == nullptr){                // se lista vazia então este é o primeiro nó
        cabeca = novo;
        return;
    }

    atual = cabeca;
    anterior = nullptr;
    while ( (atual != nullptr) && (atual->dados < item) ){    // procura a posição de
        anterior = atual;                                // inserção
        atual = atual->proximo;
    }
    if(anterior == nullptr)    // se o ponteiro para o elemento anterior
        cabeca = novo;    //  for nullptr então insere no princípio
    else
        anterior->proximo = novo;    // caso contrário insere entre dois nós

    novo->proximo = atual; // em qualquer dos casos atualiza o ponteiro
}                        //   para o próximo elemento no novo nó.
//=============================================================================
void CListaInteiros::escreveLista(void) const{
    CNoLista *atual = cabeca;

    if(cabeca == nullptr)
        cout << "Lista Vazia..." << endl;
    else{
        while (atual != nullptr){
            cout << atual->dados << ", ";
            atual = atual->proximo;
        }
        cout << "FIM" << endl;
    }
}
//=============================================================================
bool CListaInteiros::procuraItem(int item) const{
    CNoLista *atual = cabeca;

    if(cabeca == nullptr)
        return false;
    else{
        while (atual != nullptr){
            if (atual->dados == item)
                return true;
            atual = atual->proximo;
        }
        return false;
    }
}
//=============================================================================
void CListaInteiros::apagaItem(int item){

    CNoLista *atual = cabeca;
    CNoLista *anterior;

    if(cabeca == nullptr) return;
    else{
        anterior = nullptr;
        while (atual != nullptr){
            if (atual->dados == item){
                if (anterior == nullptr)
                    cabeca = atual->proximo;
                else
                    anterior->proximo = atual->proximo;
                delete atual;
                return;
            }
            anterior = atual;
            atual = atual->proximo;
        }
    }
}
//=============================================================================

int CListaInteiros::ultimoElemento(void)const {
    CNoLista *atual = cabeca;
    int ultimoNumero;

    if(cabeca == nullptr){
        cout << "Lista vazia..." << endl;
        return 0;
        }
    else{
        
        while(atual->proximo != nullptr){
            atual = atual->proximo;
        }
        ultimoNumero = atual->dados;
        
    }
    return ultimoNumero;
}
//=============================================================================