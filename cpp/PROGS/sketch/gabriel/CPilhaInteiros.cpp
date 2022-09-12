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
//Construtor a partir de uma fila
CPilhaInteiros::CPilhaInteiros(const CFilaInteiros &fila){
    CNoFila *atualFila = fila.inicio;
    CNoPilha *novo;
    topo = nullptr;

    if(fila.inicio == nullptr)return;

    while(atualFila != nullptr){
        novo = new CNoPilha;
        novo->dados = atualFila->dados;
        novo->proximo = topo;
        topo = novo;

        atualFila = atualFila->proximo;
    }

}
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
int CPilhaInteiros::numElementos(void) const{
    CNoPilha *atual = topo;
    int count = 0;

    if(topo == nullptr ) return 0;

    while(atual != nullptr){
        count++;
        atual = atual->proximo;
    }

    return count;

}
//=============================================================================
void CPilhaInteiros::trocaTopo(int &novoTopo){
    topo->dados = novoTopo;
}
//=============================================================================
bool CPilhaInteiros::operator<(const CPilhaInteiros &pilha) const{
    CNoPilha *atual = topo;
    CNoPilha *atualPilha = pilha.topo;

    while(atual != nullptr && atualPilha != nullptr){
        atual = atual->proximo;
        atualPilha = atualPilha->proximo;
    }
    // atual acabou primeiro que a outra pilha, ou seja é menor
    if(atual == nullptr && atualPilha != nullptr) return true;

    return false;

}
//=============================================================================
bool CPilhaInteiros::operator<=(const CPilhaInteiros &pilha) const{
    CNoPilha *atual = topo;
    CNoPilha *atualPilha = pilha.topo;

    while(atual != nullptr && atualPilha != nullptr){
        atual = atual->proximo;
        atualPilha = atualPilha->proximo;
    }
    // atual acabou primeiro que a outra pilha, ou seja é menor
    if(atual == nullptr && atualPilha != nullptr) return true;
    // atual acabou ao mesmo tempo que a outra pilha, ou seja é igual
    if(atual == nullptr && atualPilha == nullptr) return true;

    return false;
}
//=============================================================================
bool CPilhaInteiros::operator>(const CPilhaInteiros &pilha) const{
    CNoPilha *atual = topo;
    CNoPilha *atualPilha = pilha.topo;

    while(atual != nullptr && atualPilha != nullptr){
        atual = atual->proximo;
        atualPilha = atualPilha->proximo;
    }
    // pilha acabou primeiro que a outra atual, ou seja é menor
    if(atual != nullptr && atualPilha == nullptr) return true;
    

    return false;
}
//=============================================================================
bool CPilhaInteiros::operator>=(const CPilhaInteiros &pilha) const{
    CNoPilha *atual = topo;
    CNoPilha *atualPilha = pilha.topo;

    while(atual != nullptr && atualPilha != nullptr){
        atual = atual->proximo;
        atualPilha = atualPilha->proximo;
    }
    // pilha acabou primeiro que a outra atual, ou seja é menor
    if(atual != nullptr && atualPilha == nullptr) return true;
    // pilha acabou ao mesmo tempo que a outra atual, ou seja é igual
    if(atual == nullptr && atualPilha == nullptr) return true;

    return false;
}
//=============================================================================
void CPilhaInteiros::reordenaParesImpares(void){
    CNoPilha *atual = topo->proximo;
    CNoPilha *anterior = topo;
    CNoPilha *aux;

    while(atual != nullptr){
        //Se o atual for par
        if((atual->dados % 2) == 0){
            //Se o topo n for par
            if((topo->dados % 2) != 0 ){
                anterior->proximo = atual->proximo;
                atual->proximo = topo;
                topo = atual;
            }else{
                //Se o topo é parm procura o proximo não par
                aux = topo;
                while((aux->proximo->dados % 2 == 0) && aux != atual){
                    aux = aux->proximo;
                }
                if(aux != atual){
                anterior->proximo = atual->proximo;
                atual->proximo = aux->proximo;
                aux->proximo = atual;
                }
            }
            
            atual = anterior->proximo;
        }else{
            //Se o atual não é par
            anterior = atual;
            atual = atual->proximo;
        }
    
    }

}
//=============================================================================
int CPilhaInteiros::contaNegativosPushandPop(void){
    CPilhaInteiros aux;
    int n, count = 0 ;

    while(pop(n)){
        aux.push(n);
        if(n < 0) count ++;
    } 

    while(aux.pop(n)){
        push(n);
    } 

    return count;
}
//=============================================================================
int CPilhaInteiros::contaNegativoPonteiros(void)const{
    CNoPilha *atual = topo;
    int count = 0;

    if(topo == nullptr) return 0;

    while(atual != nullptr){
        
        if(atual->dados < 0) count++;

        atual = atual->proximo;
    }
}
//=============================================================================
CNoPilha* CPilhaInteiros::ponteiraPara(int i){
   CNoPilha *atual = topo;
    //Se a pilha tiver vazia retorna nullptr
    if(topo == nullptr)return nullptr;

    while (atual != nullptr && i != 0)
    {
        atual = atual->proximo;
        i--;
    }
    // Se o contador chegou a zero q a pilha ainda não foi excedida
    if(i == 0 && atual != nullptr)
    return atual;

    // se a pilha foi excedida
    return nullptr;
}
//=============================================================================
void CPilhaInteiros::operator<<(int i){
    if(i < 0)return;

    if (i == 0) topo = nullptr;
    else topo = ponteiraPara(i);

}
