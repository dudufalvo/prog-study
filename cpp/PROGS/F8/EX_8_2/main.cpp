#include <iostream>
#include "CListaInteiros.h"

using namespace std;

int CListaInteiros::maioresQue(int numero) {
    CNoLista *atual = cabeca;
    int maiores=0;

    if(cabeca == nullptr) return 0;
    else {
        while(atual != nullptr) {
            if(numero < atual->dados) maiores++;
            atual = atual->proximo;
        }
    }
    return maiores;
}

int CListaInteiros::ultimoElemento() {
    CNoLista *atual = cabeca;
    int ultimo=0;

    if(cabeca == nullptr) return -1;
    else {
        /*while(atual != nullptr) {
            atual = atual->proximo;
            if(atual != nullptr) ultimo = atual->dados;
        }*/

        while (atual->proximo != nullptr){
            atual = atual->proximo;
        }
        ultimo = atual->dados;
    }
    return ultimo;
}

void CListaInteiros::eliminaImpares() {
    CNoLista *atual, *anterior;

    if(cabeca==nullptr) return;
    else {
        anterior = nullptr;
        atual = cabeca;
        while(atual != nullptr) {
            if(atual->dados%2!=0) {
                anterior->proximo = atual->proximo;
                delete atual;
                atual = anterior->proximo;
            }
            else {
                anterior = atual;
                atual = atual->proximo;
            }
        }
    }
}


bool CListaInteiros::operator==(const CListaInteiros &r){
    CNoLista *atual_this = cabeca;
    CNoLista *atual_that = r.cabeca;
    //int num_this=0, num_that=0;

    if(cabeca == nullptr && r.cabeca == nullptr) return true;

    /*else {
        while(atual_this != nullptr) {
            num_this++;
            atual_this = atual_this->proximo;
        }
    }

    if(r.cabeca == nullptr) num_that=0;
        else {
            while(atual_that != nullptr) {
                num_that++;
                atual_that = atual_that->proximo;
            }
        }

    if(num_this == num_that) return true;
    else return false;
    */

    else {
        while(atual_this!=nullptr && atual_that!=nullptr) {
            atual_this = atual_this->proximo;
            atual_that = atual_that->proximo;
        }
        if(atual_this==nullptr && atual_that==nullptr) return true;
        else return false;
    }
}

CListaInteiros::CListaInteiros(char *str) {
    cabeca = nullptr;

    while(*str != '\0'){
        insereItem((int)*str);
        str++;
    }
}

void CListaInteiros::operator+=(const CListaInteiros &l) {
    CNoLista *atual_this, *atual_that;
    bool existe;

    if(l.cabeca == nullptr){
        return;
    }else{
        atual_that = l.cabeca;
        while (atual_that->proximo != nullptr) {
            existe = false;
            atual_this = cabeca;
            while (atual_this->proximo != nullptr) {
                if(atual_this->dados==atual_that->dados) existe=true;
                atual_this = atual_this->proximo;
            }
            if (!existe) atual_this->proximo = atual_that;
            atual_that = atual_that->proximo;
        }
    }
}

int CListaInteiros::operator[](int index) {
    CNoLista *atual = cabeca;
    int count=0;

    if(cabeca == nullptr) return -1;
    else {
        while (atual->proximo != nullptr){
            if(count == index) return atual->dados;
            atual = atual->proximo;
            count++;
        }
    }
    return -1;
}

void CListaInteiros::operator+(const CListaInteiros &l) {
    CNoLista *atual_this, *atual_that, *atual_aux , *anterior=nullptr;
    bool existe;

    if(l.cabeca == nullptr){
        return;
    }else{
        atual_that = l.cabeca;
        while (atual_that->proximo != nullptr) {
            existe = false;
            atual_this = cabeca;
            while (atual_this->proximo != nullptr) {
                if(atual_this->dados==atual_that->dados) existe=true;
                atual_this = atual_this->proximo;
            }
            if (!existe) atual_this->proximo = atual_that;
            atual_that = atual_that->proximo;
        }
    }
    atual_this = cabeca;
    while(atual_this->proximo != nullptr) {
        atual_aux = atual_this->proximo;
        anterior = atual_this;
        while(atual_aux->proximo != nullptr) {
            if(atual_aux->dados==atual_this->dados) {
                anterior->proximo = atual_aux->proximo;
                delete atual_aux;
                atual_aux = anterior->proximo;
            }
            else {
                anterior = atual_aux;
                atual_aux = atual_aux->proximo;
            }
        }
        atual_this = atual_this->proximo;
    }
}

int main()
{
    CListaInteiros teste;
    teste.insereItem(21);

    CListaInteiros teste2;
    teste2.insereItem(45);
    teste2.insereItem(12);
    teste2.insereItem(4);
    teste2.insereItem(12);
    teste2.insereItem(12);
    teste2.insereItem(4);
    teste2.insereItem(5);

    CListaInteiros teste4;

    char str[] = "ABETO";

    CListaInteiros teste3(str);

    //cout << teste.maioresQue(15) << endl;
    //cout << teste.ultimoElemento() << endl;
    //cout << (teste == teste2) << endl;
    //teste3.escreveLista();

    //teste.eliminaImpares();
    //teste.escreveLista();

    teste2.escreveLista();
    cout << teste2[0] << endl;

    //teste+teste2;
    //teste.escreveLista();
    return 0;
}
