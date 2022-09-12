#include <iostream>
#include <cstring>
using namespace std;


class CNoFila {
    int dados;
    CNoFila *proximo;
    friend class CFilaInteiros;
};
class CFilaInteiros {
    CNoFila *inicio; // ponteiro para o início da Fila
    CNoFila *fim; // ponteiro para o fim da Fila
    CNoFila* seek(int) const;
    public:
        CFilaInteiros(void);
        ~CFilaInteiros(void);
        void insereNaFila(const int item);
        bool retiraDaFila(int &item);
        void escreveFila(void) const;
        int numElementos(void);
        bool filaVazia(void) const { return (inicio == nullptr); }
        void substituiFim(void);
        void trocaFim(void);
        CNoFila* retornaNo(int) const;
        bool passaAfrente(int);
        void compactaFila(int, int);
        void parImpar(void);
        void inverteFila(int);
        CFilaInteiros& operator= (const CFilaInteiros &);
        CFilaInteiros& operator+ (CFilaInteiros &);
        CFilaInteiros& operator- (CFilaInteiros &);
        bool passaParaFim(int);
        bool passaParaInicio(int);
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

void CFilaInteiros::substituiFim() {
    CNoFila *atual;

    atual = inicio;
    if(inicio == nullptr) return;

    while(atual != nullptr) {
        if(atual->dados > fim->dados) fim->dados = atual->dados;
        atual = atual->proximo;
    }
}

void CFilaInteiros::trocaFim() {
    CNoFila *atual, *maior;
    int auxiliar;

    atual = inicio;
    maior = inicio;
    if(inicio == nullptr) return;

    while(atual != nullptr) {
        if(atual->dados > maior->dados) maior = atual;
        atual = atual->proximo;
    }
    auxiliar = fim->dados;
    fim->dados = maior->dados;
    maior->dados = auxiliar;
}

CNoFila* CFilaInteiros::retornaNo(int num) const{ 
    CNoFila *atual;
    num--;

    atual = inicio;
    if(inicio == nullptr) return nullptr;

    while(atual != nullptr && num>0) {
        atual = atual->proximo;
        num--;
    }
    if(num == 0) return atual;
    return nullptr;
}

bool CFilaInteiros::passaAfrente(int num) {
    if(num > numElementos()) return false;

    CNoFila *alvo = retornaNo(num),
            *anterior_alvo = retornaNo(num-1),
            *penultimo = retornaNo(numElementos()-1);

    if(num == 1) {
        inicio = fim;
        inicio->proximo = alvo;
        penultimo->proximo = nullptr;
    }
    else if (num == numElementos()) return true;
    
    else {
        anterior_alvo->proximo = fim;
        anterior_alvo->proximo->proximo = alvo;
        penultimo->proximo = nullptr;
    }

    return true;
}

void CFilaInteiros::compactaFila(int a, int b) {
    CFilaInteiros nova_fila;
    int numero_retirado;

    if(inicio == nullptr) return;

    while(inicio != nullptr) {
        retiraDaFila(numero_retirado);
        if(numero_retirado >= a && numero_retirado <= b) nova_fila.insereNaFila(numero_retirado);
    }
    while(nova_fila.inicio != nullptr) {
        nova_fila.retiraDaFila(numero_retirado);
        insereNaFila(numero_retirado);
    }
}

void CFilaInteiros::parImpar() {
    CFilaInteiros fila_impares, fila_pares;
    int numero_retirado;

    if(inicio == nullptr) return;

    while(inicio != nullptr) {
        retiraDaFila(numero_retirado);
        if(numero_retirado%2 != 0) fila_impares.insereNaFila(numero_retirado);
        else fila_pares.insereNaFila(numero_retirado);
    }
    while(fila_pares.inicio != nullptr) {
        fila_pares.retiraDaFila(numero_retirado);
        insereNaFila(numero_retirado);
    }
    while(fila_impares.inicio != nullptr) {
        fila_impares.retiraDaFila(numero_retirado);
        insereNaFila(numero_retirado);
    }
}

void CFilaInteiros::inverteFila(int num){ 
    if(inicio == nullptr || num > numElementos()) return;

    CNoFila *atual, *aux, *novoInicio;
    atual = inicio;
    novoInicio = retornaNo(num);
    
    while(atual != novoInicio){
        aux = atual->proximo;
        atual->proximo = novoInicio->proximo;
        novoInicio->proximo = atual;
        atual = aux;
    }
    inicio = novoInicio;
}

CFilaInteiros &CFilaInteiros::operator= (const CFilaInteiros &fila) {
    CNoFila *esse, *aquele;

    inicio = nullptr;
    fim = nullptr;
    aquele = fila.inicio;
    if(fila.inicio == nullptr) return *this;

    while(aquele != nullptr) {
        esse = new CNoFila;
        esse->dados = aquele->dados;
        esse->proximo = nullptr;

        if(inicio == nullptr) inicio = esse;
        else fim->proximo = esse;

        fim = esse;
        aquele = aquele->proximo;
    }
    return *this;
}

CFilaInteiros &CFilaInteiros::operator+ (CFilaInteiros &cf) {
    CFilaInteiros *somada = new CFilaInteiros;
    CNoFila *esse, *aquele, *novo = new CNoFila;
    CFilaInteiros nova_fila;

    esse = inicio;
    aquele = cf.inicio;

    while(esse != nullptr || aquele != nullptr) {
        if(esse != nullptr) {
            novo = new CNoFila;
            novo->dados = esse->dados;
            novo->proximo = nullptr;

            if(somada->inicio == nullptr) somada->inicio = novo;
            else somada->fim->proximo = novo;

            somada->fim = novo;
            esse = esse->proximo;
        }
        if(aquele != nullptr) {
            novo = new CNoFila;
            novo->dados = aquele->dados;
            novo->proximo = nullptr;

            if(somada->inicio == nullptr) somada->inicio = novo;
            else somada->fim->proximo = novo;

            somada->fim = novo;
            aquele = aquele->proximo;
        }
    }
    return *somada;
}

CFilaInteiros &CFilaInteiros::operator- (CFilaInteiros &cf) {
    CFilaInteiros *nova = new CFilaInteiros;
    CNoFila *esse, *aquele, *novo = new CNoFila;
    bool existe;

    if(cf.inicio == nullptr) return *this;

    esse = inicio;
    while(esse != nullptr) {
        existe = false;
        aquele = cf.inicio;
        while(aquele != nullptr) {
            if(esse->dados == aquele->dados) existe = true;
            aquele = aquele->proximo;
        }
        if(!existe) {
            novo = new CNoFila;
            novo->dados = esse->dados;
            novo->proximo = nullptr;

            if(nova->inicio == nullptr) nova->inicio = novo;
            else nova->fim->proximo = novo;

            nova->fim = novo;
        }
        esse = esse->proximo;
    }
    return *nova;
}

CNoFila* CFilaInteiros::seek(int num) const {
    CNoFila *atual;

    atual = inicio;
    if(inicio == nullptr) return nullptr;

    while(atual != nullptr && num > 0) {
        atual = atual->proximo;
        num--;
    }
    if(num == 0) return atual;
    return nullptr;
}

bool CFilaInteiros::passaParaFim(int index) {
    CNoFila *atual, *anterior;
    int aux=index;
    index--;

    atual = inicio;
    anterior = nullptr;
    if(inicio == nullptr) return false;

    while(atual != nullptr && index > 0) {
        anterior = atual;
        atual = atual->proximo;
        index--;
    }

    if(index == 0) {
        if(aux == 1) inicio = atual->proximo;
        else if (atual == fim) return true;
        else anterior->proximo = atual->proximo;
        fim->proximo = atual;
        fim->proximo->proximo = nullptr;
        return true;
    }
    else return false;
}

bool CFilaInteiros::passaParaInicio(int index) {
    CNoFila *atual, *anterior, *aux;

    if(inicio == nullptr || index > numElementos()) return false;

    atual = retornaNo(index);
    anterior = retornaNo(index-1);

    if(atual == inicio) return true;

    anterior->proximo = atual->proximo;
    aux = inicio;
    inicio = atual;
    inicio->proximo = aux;
    return true;
}

//===============================================================
int main() {
    CFilaInteiros fila1;
    fila1.insereNaFila(1);
    fila1.insereNaFila(3);
    fila1.insereNaFila(5);
    fila1.insereNaFila(7);
    fila1.insereNaFila(9);
    fila1.escreveFila();
    fila1.passaParaInicio(5);
    fila1.escreveFila();


    CFilaInteiros fila2;
    fila2.insereNaFila(2);
    fila2.insereNaFila(1);
    fila2.insereNaFila(6);
    fila2.insereNaFila(7);
    fila2.insereNaFila(10);
    //fila2.escreveFila();

    //CFilaInteiros fila3;
    //fila3 = (fila1-fila2);
    //fila3.escreveFila();
}