#include "CFilaRankings.h"
#include <iostream>
#include <string.h>
using namespace std;

CFilaRankings::CFilaRankings(){
    inicio=nullptr; fim=nullptr;
}
//=============================================================================

CFilaRankings::~CFilaRankings(){
    CNoFila *aux = inicio;

    while(inicio != nullptr){
        aux = inicio->proximo;
        delete inicio;
        inicio = aux;
    }
    fim = nullptr;
}
//=============================================================================
void CFilaRankings::inserePais(char *Pais,int rating){
    CNoFila *atual = inicio;
    CNoFila *anterior = inicio;
    CNoFila *novo = new CNoFila;

    novo->ranking = rating;
    strcpy(novo->pais, Pais);
    novo->proximo = nullptr;

    //Se a Fila estiver vazia ou só possuir pais com ranking menor
    if(inicio == nullptr || inicio->ranking < novo->ranking ){
        novo->proximo = inicio;
        if(inicio == nullptr) fim = novo;
        inicio = novo;
        return;
    }
    
    while(atual != nullptr){

         if(atual->ranking < novo->ranking){
            anterior->proximo = novo;
            novo->proximo = atual;
            return;
        }

        if(atual == fim){
            atual->proximo = novo;
            fim = novo;
            return;
        }
        
        anterior = atual;
        atual = atual->proximo;

    }


}
//=============================================================================
void CFilaRankings::escreveLista(void){
    CNoFila *atual = inicio;

    while(atual != nullptr){
        cout << atual->pais << ", " << atual->ranking << endl;
        atual = atual->proximo;
    }
}
