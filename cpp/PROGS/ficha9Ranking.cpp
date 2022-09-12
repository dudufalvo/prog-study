#include <iostream>
#include <cstring>
using namespace std;

class CNoFila{ // Nó da fila
    public:
        char pais[50];
        int ranking; //valor mais baixo indica um país mais desenvolvido
        CNoFila *proximo; //próximo nó
};
class CFilaRankings{ // Fila contendo países ordenados pelo seu ranking
    CNoFila *inicio; // Ponteiro para o início da Fila
    CNoFila *fim; // Ponteiro para o fim da Fila
    public:
        CFilaRankings(){inicio=nullptr; fim=nullptr;}
        ~CFilaRankings();
        void escreveFila(void) const;
        void inserePais(char *Pais, int Rating);
};

CFilaRankings::~CFilaRankings() {
    CNoFila *seguinte;
    while (inicio != nullptr){
        seguinte = inicio->proximo;
        delete inicio;
        inicio = seguinte;
    }
    fim = nullptr;
}

void CFilaRankings::escreveFila(void) const {
    if (inicio == nullptr) {
        cout << "Fila vazia..." << endl;
        return;
    }
    for (CNoFila *aux=inicio; aux!=nullptr; aux=aux->proximo) {
        cout << "(" << aux->pais << "," << aux->ranking << ") - ";
    }
    cout << "fim" << endl;
}

void CFilaRankings::inserePais(char *Pais, int Rating) {
    CNoFila *atual, *anterior, *novo=new CNoFila;

    strcpy(novo->pais, Pais);
    novo->ranking = Rating;
    novo->proximo = nullptr;

    atual = inicio;
    if(inicio == nullptr) inicio = novo;
    
    else {
        while(atual != nullptr && atual->ranking != Rating+1) {
            anterior = atual;
            atual = atual->proximo;
        }

        if(atual == nullptr) {
            anterior->proximo = novo;
        }

        else {
            anterior->proximo = novo;
            novo->proximo = atual;
        }
    }
}

int main() {
    CFilaRankings fila1;
    fila1.inserePais("Canada", 1);
    fila1.inserePais("Panama", 2);
    fila1.inserePais("Suica", 1);
    fila1.inserePais("Alemanha", 1);
    fila1.inserePais("Belgica", 3);
    fila1.escreveFila();

    return 0;
}