//
//  CTemasMetodos.h
//  PROJETO2_RASCUNHO
//
//  Created by Gabriel Santos Correa da Silva on 08/05/22.
//

#include "CTemas.h"
#include <fstream>
//=====================================================================
listaTemas::~listaTemas() {
    Temas *atual, *proximo;
    
    atual = cabeca;
    while(atual != nullptr){
        proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}
//=====================================================================
bool listaTemas::removeItem(int index) {
    Temas *anterior, *atual;
    atual = anterior = cabeca;

    if (index == 1) {
        cabeca = atual->proximo;
        delete atual;
        return true;
    }

    while (atual != nullptr) {
        index--;

        if (index == 0) {
            anterior->proximo = atual->proximo;
            delete atual;
            return true;
        }

        if (atual != cabeca) {
            anterior = anterior->proximo;
        }

        atual = atual->proximo;
    }

    return false;
}
//=====================================================================
void listaTemas::insereItem(Stema tema) {
    Temas *novo = new Temas;
    Temas *atual;

    novo->tema = tema;
    novo->proximo = nullptr;

    if (cabeca == nullptr)
        cabeca = novo;
    else
    {
        atual = cabeca;
        while (atual->proximo != nullptr)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}
//=====================================================================
void listaTemas::escreveLista() {
    Temas *atual = cabeca;
    if (atual == nullptr)
    {
        cout << "Lista Vazia..." << endl;
        return;
    }
    while (atual != nullptr)
    {
        cout << atual->tema.tema << endl;
        atual = atual->proximo;
    }
}
//=====================================================================
void listaTemas::escreveFicheiro(){
    Temas *atual = cabeca;
    
    ofstream salvarTemas;
    salvarTemas.open("Temas.dat", ios::binary | ios::trunc);
    salvarTemas.close();
    salvarTemas.open("Temas.dat", ios::binary | ios::app);

    if(!salvarTemas.is_open()){
        cout << "ERRO SALVANDO OS TEMAS" << endl;
        exit(0);
    }

    while(atual != nullptr){
        salvarTemas.write((char*)&atual->tema, sizeof(atual->tema));
        atual = atual->proximo;
    }

    salvarTemas.close();
}
//=====================================================================
void listaTemas::reiniciaLista(){
    Temas *atual = cabeca;
    Temas *aux;

    if(atual == nullptr) return;

    while (atual != nullptr)
    {
        aux = atual;
        atual = atual->proximo;
        delete aux; 
    }
    cabeca = nullptr;
}