#include <iostream>
#include <cstring>
using namespace std;

class CNoPilha{
    int dados;
    CNoPilha *proximo;
    friend class CPilhaInteiros; // esta classe acede aos membros private
};
class CPilhaInteiros{
    CNoPilha *topo; // ponteiro para o elemento no topo da pilha
    public:
        CPilhaInteiros(void);
        ~CPilhaInteiros(void);
        void push(const int item);
        bool pop(int &item);
        void escrevePilha(void) const;
        bool pilhaVazia() const { return (topo==nullptr);}
        int numElementos(void);
};

CPilhaInteiros::CPilhaInteiros() {
    topo = nullptr;
}

CPilhaInteiros::~CPilhaInteiros() {
    CNoPilha *seguinte;
    while (topo != nullptr) {
        seguinte = topo->proximo;
        delete topo;
        topo = seguinte;
    }
}

void CPilhaInteiros::escrevePilha() const {
    CNoPilha *atual;

    atual = topo;
    if(topo == nullptr) cout << "lista vazia";

    while(atual != nullptr) {
        cout << atual->dados << " - ";
        atual = atual->proximo;
    }
    cout << "fim" << endl;
}

void CPilhaInteiros::push(const int item) {
    CNoPilha *novo = new CNoPilha;

    novo->dados = item;
    novo->proximo = topo;
    topo = novo;
}

bool CPilhaInteiros::pop(int &item) {
    CNoPilha *atual;

    atual = topo;
    if(topo == nullptr) return false;

    topo = topo->proximo;
    item = atual->dados;
    delete atual;
    return true;
    
}


class CNoFila {
    int dados;
    CNoFila *proximo;
    friend class CFilaInteiros;
};
class CFilaInteiros {
    CNoFila *inicio; // ponteiro para o início da Fila
    CNoFila *fim; // ponteiro para o fim da Fila
    public:
        CFilaInteiros(void);
        ~CFilaInteiros(void);
        CFilaInteiros(CPilhaInteiros &);
        void insereNaFila(const int item);
        bool retiraDaFila(int &item);
        void escreveFila(void) const;
        int numElementos(void);
};

CFilaInteiros::CFilaInteiros() {
    inicio = nullptr;
    fim = nullptr;
}

CFilaInteiros::~CFilaInteiros() {
    CNoFila *seguinte;
    while (inicio != nullptr){
        seguinte = inicio->proximo;
        delete inicio;
        inicio = seguinte;
    }
    fim = nullptr;
}

CFilaInteiros::CFilaInteiros(CPilhaInteiros &cp) {
    CNoFila *atual, *novo;
    CPilhaInteiros auxiliar;

    int num;
    cp.pop(num);
    novo->dados = num;
    novo->proximo = nullptr;
    inicio = novo;

    atual = inicio;
    while(cp.pop(num)) {
        novo->dados = num;
        novo->proximo = nullptr;

        atual->proximo = novo;
    }
    fim = atual->proximo;
}

void CFilaInteiros::insereNaFila(const int item) {
    CNoFila *novo = new CNoFila;
    novo->dados = item;
    novo->proximo = nullptr;
    if (inicio == nullptr) inicio = novo;
    else fim->proximo = novo;
    fim = novo;
}

bool CFilaInteiros::retiraDaFila(int &item) {
    if (inicio==nullptr) return false;

    item = inicio->dados;

    CNoFila *aux = inicio; // ponteiro auxiliar para nó a eliminar

    inicio = inicio->proximo; // atualiza ponteiro inicio da fila
    if (inicio == nullptr) fim = nullptr; // se a fila ficar vazia
    delete aux;
    return true;
}

void CFilaInteiros::escreveFila(void) const {
    if (inicio == nullptr) {
        cout << "Fila vazia..." << endl;
        return;
    }
    for (CNoFila *aux=inicio; aux!=nullptr; aux=aux->proximo) {
        cout << aux->dados << " - ";
    }
    cout << "fim" << endl;
}

int CFilaInteiros::numElementos() {
    CNoFila *atual;
    int contador=0;

    atual = inicio;
    while (atual != nullptr) {
        atual = atual->proximo;
        contador++;
    }
    return contador;
}


int main() {
    CPilhaInteiros pilha1;
    pilha1.push(-1);
    pilha1.push(2);
    pilha1.push(3);
    pilha1.push(-4);
    pilha1.push(5);
    pilha1.escrevePilha();

    CFilaInteiros fila1 = pilha1;
    fila1.escreveFila();
}