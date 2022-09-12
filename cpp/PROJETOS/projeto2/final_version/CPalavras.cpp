#include "CPalavras.h"
#include <string.h>
#include <fstream>

//=====================================================================
listaPalavras_Tema::~listaPalavras_Tema(){
    palavras_Tema *atual, *proximo;
    atual = cabeca;
    while(atual != nullptr){
        proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}
//=====================================================================
void listaPalavras_Tema::insereItem(char *novaPalavra, int numeroJogadas){
    palavras_Tema *novo = new palavras_Tema;
    palavras_Tema *atual;

    strcpy(novo->nome_C, novaPalavra);
    novo->jaJogada = numeroJogadas;
    novo->proximo = nullptr;
    
    if(cabeca == nullptr ) cabeca = novo;
    else{
        atual = cabeca;
        while(atual->proximo != nullptr ) {
            atual = atual -> proximo;
        }
        atual->proximo = novo;
    }
}
//=====================================================================
bool listaPalavras_Tema::removeItem(int index){
    palavras_Tema *anterior, *atual;
    atual = anterior = cabeca;

    if(index == 1){
        cabeca = atual->proximo;
        delete atual;
        return true;
    }

    while( atual != nullptr ){
        index--;
        

        if(index == 0){
            anterior->proximo = atual->proximo;
            delete atual;
            return true;
        }

        if(atual != cabeca){
            anterior = anterior->proximo;
        }

        atual = atual->proximo;       
    }

    return false;

}
//=====================================================================
void listaPalavras_Tema::escreveFicheiro(string tema){
    palavras_Tema *atual = cabeca;
    SPalavras s;
    
    ofstream salvarPalavras;
    salvarPalavras.open(tema+".dat", ios::binary | ios::trunc);
    salvarPalavras.close();
    salvarPalavras.open(tema+".dat", ios::binary | ios::app);

    if(!salvarPalavras.is_open()){
        cout << "ERRO SALVANDO O RANK - ERROR 1" << endl;
        exit(0);
    }

    while(atual != nullptr){
        s.jaJogada = atual->jaJogada;
        strcpy(s.Palavra, atual->nome_C);
        salvarPalavras.write((char *) &s, sizeof(SPalavras));
        atual = atual->proximo;
    }

    salvarPalavras.close();
}
//=====================================================================
void listaPalavras_Tema::reiniciaLista(){
    palavras_Tema *atual = cabeca;
    palavras_Tema *aux;

    if(atual == nullptr) return;

    while (atual != nullptr)
    {
        aux = atual;
        atual = atual->proximo;
        delete aux; 
    }
    cabeca = nullptr;
}
//=====================================================================
void listaPalavras_Tema::escreveLista(void){
     palavras_Tema *atual = cabeca;
     if(atual == nullptr){
         cout << "Lista Vazia..." << endl;
         return;
     }
while (atual != nullptr){

        cout << atual->nome_C << endl;
        cout << "NUMERO DE JOGADAS: " << atual->jaJogada << endl;
        atual = atual->proximo;
    }

}
//=====================================================================
void listaPalavras_Tema::editaLista(int index, char *string_C){
    palavras_Tema *atual = cabeca;


    while (atual != nullptr){
        index--;

        if(index == 0){
            strcpy(atual->nome_C, string_C);
            atual->jaJogada = 0;
        }
       
        atual = atual->proximo;
    }

}
//=====================================================================