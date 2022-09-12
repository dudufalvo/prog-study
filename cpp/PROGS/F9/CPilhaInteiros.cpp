//=============================================================================
// EDA 2021/22, 2014/15, 2012/2011, 2007/2008, Ficha 9 (pilhas e filas)
//  Rui P. Rocha (2015.04.11) e Paulo Coimbra (2022-04-29, 2012, 2008)
//=============================================================================
// source file: PilhaInteiros.cpp
//=============================================================================
#include <iostream>
#include "CPilhaInteiros.h"
using namespace std;
//=============================================================================
CPilhaInteiros::CPilhaInteiros(void) { topo = nullptr; }
//=============================================================================
CPilhaInteiros::~CPilhaInteiros(void) {
    CNoPilha *seguinte;
    while (topo != nullptr) {
        seguinte = topo->proximo;
        delete topo;
        topo = seguinte;
    }
}
//=============================================================================
// insere item no topo da pilha
void CPilhaInteiros::push(const int item) {
    CNoPilha *novo = new CNoPilha;
    novo->dados = item;
    novo->proximo = topo;
    topo = novo;
}
//=============================================================================
// remove elemento no topo da pinha e atribui o seu valor ao parametro item
// devolve true se a pilha nao estava vazia; false caso contrario
bool CPilhaInteiros::pop(int &item) {
    if( topo == nullptr ) return false; // nao havia nada para fazer pop
    // aux <- aponta para elemento no topo da pilha
    CNoPilha * aux = topo;
    topo = topo->proximo; // atualiza topo da pilha
    item = aux->dados;    // devolve valor no topo da pilha
    delete aux;           // liberta a memoria
    return true;          // indica pop bem sucedido
}
//=============================================================================
void CPilhaInteiros::escrevePilha(void) const {
    if( topo == nullptr )
        cout << "Pilha vazia..." << endl;
    else {
        CNoPilha * aux = topo;
        while( aux != nullptr ) {
            cout << aux->dados << endl;
            aux = aux->proximo;
        }
    }
}
//=============================================================================
CNoPilha *CPilhaInteiros::ponteiroPara(int i){
    CNoPilha *pointer = topo;

    while(i != 0){
        pointer = pointer->proximo;
        if(pointer == nullptr) break;
        i -= 1;
    }

    return pointer;
}
//=============================================================================
CPilhaInteiros* CPilhaInteiros::operator<<(int i){
    CNoPilha *atual=topo, *proximo, *anterior;

    if(i < 0) return this;
    else{
        anterior = ponteiroPara(i-1);
        proximo = ponteiroPara(i);
    }

    while(proximo->proximo != nullptr) {
        
    }

    topo = anterior;

    return this;
}
//=============================================================================