//
//  CRanking.cpp
//  Projeto_2
//
//  Created by Gabriel Santos Correa da Silva on 03/05/22.
//

#include <iostream>
#include <string.h>
#include <fstream>
#include "CRanking.h"

using namespace std;
//=====================================================================
void listaRank::atualizaJogador(char *string_C, Jogo &ultimoJogo){
    ranking *atual = cabeca;
    
    if(cabeca == nullptr){
        cout << "SEM RANKINGS" << endl;
    }else{
        while(atual != nullptr){
            
            if(!strcmp(string_C, atual->nome_C)){
                atual->pontos = atual->pontos + ultimoJogo.pontos;
            }
            atual = atual->proximo;
        }
        
    }
}
//=====================================================================
void listaRank::escreveFicheiro(){
    ranking *atual = cabeca;
    ranking aux;
    
    ofstream salvarRank;
    salvarRank.open("Ranking.dat", ios::binary | ios::trunc);
    salvarRank.close();
    salvarRank.open("Ranking.dat", ios::binary | ios::app);

    if(!salvarRank.is_open()){
        cout << "ERRO SALVANDO O RANK - ERROR 1" << endl;
        exit(0);
    }

    while(atual != nullptr){
        aux.pontos = atual->pontos;
        strcpy(aux.nome_C , atual->nome_C);
        salvarRank.write((char *) &aux, sizeof(aux));
        atual = atual->proximo;
    }

    salvarRank.close();
}
//=====================================================================
listaRank::~listaRank(){
    ranking *atual, *proximo;
    
    atual = cabeca;
    while(atual != nullptr){
        proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }

}
//=====================================================================
void listaRank::insereItem(ranking &r){
    ranking *novo = new ranking;
    ranking *atual;

    strcpy(novo->nome_C, r.nome_C);
    novo->pontos = r.pontos;
    novo->proximo = nullptr;

    if(cabeca == nullptr ) cabeca = novo;
    else{
        atual = cabeca;
        while(atual->proximo != nullptr) atual = atual -> proximo;
        atual->proximo = novo;
    }

}
//=====================================================================
