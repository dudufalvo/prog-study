//=============================================================================
// EDA 2021/22, 2014/15, 2012/2011, 2007/2008, Ficha 9 (pilhas e filas)
//  Rui P. Rocha (2015.04.11) e Paulo Coimbra (2022-04-29, 2012, 2008)
//=============================================================================
// source file: FilaInteiros.cpp
//=============================================================================
#include <iostream>
#include "CFilaInteiros.h"
using namespace std;
//=============================================================================
CFilaInteiros::CFilaInteiros(void) {
    inicio = nullptr;
    fim = nullptr;
}
//=============================================================================
CFilaInteiros::~CFilaInteiros(void) {
    CNoFila *seguinte;

    while (inicio != nullptr) {
        seguinte = inicio->proximo; // elemento seguinte
        delete inicio;              // apaga elemento no inicio da fila
        inicio = seguinte;          // define nova cabeca da fila
    }
    fim = nullptr;
}
//=============================================================================
// insere novo elemento na cauda da fila
void CFilaInteiros::insereNaFila(const int item) {
    // cria elemento a colocar na cauda da lista
    CNoFila *novo = new CNoFila;
    novo->dados = item;
    novo->proximo = nullptr;
    // insere novo elemento na cauda da lista
    if( inicio == nullptr ) // se a fila esta vazia, passa a conter novo
        inicio = novo;
    else // a fila nao esta vazia
        fim->proximo = novo;
    // fim deve apontar para o novo elemento inserido na fila
    fim = novo;
}
//=============================================================================
// remove elemento da cabeca da fila e devolve o seu valor
bool CFilaInteiros::retiraDaFila(int &item){
    if (inicio == nullptr) return false; // nao ha nada para retirar

    // se a fila nao esta vazia, devolve informacao do elemento na cabeca da fila
    item = inicio->dados;

    // auxiliar para remocao da cabeca da fila
    CNoFila * aux = inicio;
    inicio = aux->proximo;
    // se a fila ficou vazia, actualiza fim
    if (inicio == nullptr) fim = nullptr;
    delete aux;   // liberta memoria
    return true;  // indica remocao bem sucedida
}
//=============================================================================
// escreve elementos na fila
void CFilaInteiros::escreveFila(void) const{
    if ( inicio == nullptr )
        cout << "Fila vazia..." << endl;
    else {
        CNoFila * aux = inicio;
        while( aux != nullptr ) {
            cout << aux->dados << endl;
            aux = aux->proximo;
        }
    }
}
//=============================================================================
CNoFila *CFilaInteiros::noMaiorNumero() const {
    CNoFila *maior = inicio;
    for(CNoFila *aux=inicio; aux != nullptr; aux = aux->proximo) {
        if(aux->dados > maior->dados) {
            maior = aux;
        }
    }
    return maior;
}
//=============================================================================
void CFilaInteiros::substitui() {
    if(inicio != fim) {
        fim->dados = this->noMaiorNumero()->dados;
    }
}
//=============================================================================
void CFilaInteiros::troca() {
    if(inicio != fim) {
        CNoFila *maior = this->noMaiorNumero();
        int aux = maior->dados;
        maior->dados = fim->dados;
        fim->dados = aux;
    }
}
//=============================================================================
bool CFilaInteiros::passaAfrente(int index) {
    CNoFila *atual=inicio, *penultimo=nullptr, *aux;
    int contador=0;
    bool validator=false;
    
    while(atual->proximo != nullptr) {
        penultimo = atual;
        atual = atual->proximo;
    }
    
    atual=inicio;
    if(inicio != fim) {
        while(atual->proximo != nullptr) {
            if(index == 0 && contador == 0) {
                aux = atual;
                inicio = fim;
                fim->proximo = aux;

                validator = true;
            }
            else if(contador+1 == index) {
                aux = atual->proximo;
                atual->proximo = fim;
                fim->proximo = aux;

                validator = true;
            }
            else if(atual==penultimo) {
                atual->proximo = nullptr;
            }
            else {
                atual = atual->proximo;
            }
            contador++;

        }
    }
    return validator;
}