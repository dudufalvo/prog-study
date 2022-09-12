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
    CNoPilha *ponteiroPara(int) const;
    public:
        CPilhaInteiros(void);
        ~CPilhaInteiros(void);
        void push(const int item);
        bool pop(int &item);
        void escrevePilha(void) const;
        bool pilhaVazia() const { return (topo==nullptr);}
        int numElementos(void);
        void inverteString(string);
        void trocaTopo(int valor);
        bool operator< (const CPilhaInteiros &);
        bool operator<= (const CPilhaInteiros &);
        bool operator> (const CPilhaInteiros &);
        bool operator>= (const CPilhaInteiros &);
        int contaNegAuxiliar(void);
        int contaNegPonteiro(void);
        void operator<<(int i);
        
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

CNoPilha *CPilhaInteiros::ponteiroPara(int num) const {
    CNoPilha *atual;

    atual = topo;
    if(topo == nullptr) return nullptr;

    while(atual != nullptr && num > 0) {
        atual = atual->proximo;
        num--;
    } 
    if(num == 0) return atual;
    else return nullptr;
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

int CPilhaInteiros::numElementos() {
    CNoPilha *atual;
    int counter=0;

    atual=topo;
    while(atual != nullptr) {
        atual = atual->proximo;
        counter++;
    }

    return counter;
}

void CPilhaInteiros::trocaTopo(int num) { topo->dados = num; }

bool CPilhaInteiros::operator< (const CPilhaInteiros &cp) {
    CNoPilha *atual, *cp_atual;

    atual = topo;
    cp_atual = cp.topo;
    while(atual != nullptr && cp_atual != nullptr) {
        atual = atual->proximo;
        cp_atual = cp_atual->proximo;
    }
    if(atual == nullptr && cp_atual!=nullptr) return true;
    return false;
}

bool CPilhaInteiros::operator<= (const CPilhaInteiros &cp) {
    CNoPilha *atual, *cp_atual;

    atual = topo;
    cp_atual = cp.topo;
    while(atual != nullptr && cp_atual != nullptr) {
        atual = atual->proximo;
        cp_atual = cp_atual->proximo;
    }
    if(atual == nullptr && cp_atual != nullptr || atual == nullptr && cp_atual == nullptr) return true;
    return false;
}

bool CPilhaInteiros::operator> (const CPilhaInteiros &cp) {
    CNoPilha *atual, *cp_atual;

    atual = topo;
    cp_atual = cp.topo;
    while(atual != nullptr && cp_atual != nullptr) {
        atual = atual->proximo;
        cp_atual = cp_atual->proximo;
    }
    if(atual != nullptr && cp_atual == nullptr) return true;
    return false;
}

bool CPilhaInteiros::operator>= (const CPilhaInteiros &cp) {
    CNoPilha *atual, *cp_atual;

    atual = topo;
    cp_atual = cp.topo;
    while(atual != nullptr && cp_atual != nullptr) {
        atual = atual->proximo;
        cp_atual = cp_atual->proximo;
    }
    if(atual != nullptr && cp_atual == nullptr) return true;
    return false;
}

int CPilhaInteiros::contaNegAuxiliar() {
    CPilhaInteiros pilha_aux;
    int num, contador = 0;

    while(pop(num)) {
        pilha_aux.push(num);
        if(num < 0) contador++;
    }

    while(pilha_aux.pop(num)) {
        push(num);
    }

    return contador;
}

int CPilhaInteiros::contaNegPonteiro() {
    CNoPilha *atual;
    int contador = 0;

    atual=topo;
    while(atual != nullptr) {
        if(atual->dados < 0) contador++;
        atual = atual->proximo;
    }

    return contador;
}

void CPilhaInteiros::operator<<(int i){
    if(i < 0)return;

    if (i == 0) topo = nullptr;
    else topo = ponteiroPara(i);

}

int main() {
    CPilhaInteiros pilha1;
    CPilhaInteiros pilha2;
    pilha1.push(-1);
    pilha1.push(2);
    pilha1.push(3);
    pilha1.push(-4);
    pilha1.push(5);
    pilha1.escrevePilha();
    pilha1.operator<<(3);
    pilha1.escrevePilha();
}