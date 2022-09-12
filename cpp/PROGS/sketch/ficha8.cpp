#include <iostream>
using namespace std;

class CNoLista{
  public:
    int dados;
    CNoLista *proximo;
};
class CListaInteiros{
    CNoLista *cabeca;
  public:
    CListaInteiros(void);
    CListaInteiros(char*);
    ~CListaInteiros(void);

    void insereItem(int);
    void insereItemOrdenado(int);
    void apagaItem(int);
    bool procuraItem(int) const;
    void escreveLista(void) const;
    int maioresQue(int);
    int ultimoElemento(void);
    int operator[](int);
    void eliminaImpares(void);
    bool operator==(const CListaInteiros &);
    CListaInteiros &operator= (const CListaInteiros &);
    CListaInteiros &operator+=(const CListaInteiros &);
    CListaInteiros operator+(const CListaInteiros &);
};

CListaInteiros::CListaInteiros(){ // Construtor por omissao
    cabeca = nullptr;
}

CListaInteiros::~CListaInteiros(){
    CNoLista *atual, *proximo;

    atual=cabeca;
    while (atual != nullptr){
        proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}

CListaInteiros::CListaInteiros(char *str) {
    cabeca = nullptr;

    while(*str != '\0'){
        insereItem((int)*str);
        str++;
    }
}

void CListaInteiros::escreveLista(void) const {
    CNoLista *atual;

    atual = cabeca;
    if(atual == nullptr) cout << "lista vazia" << endl;
    else {
        while(atual != nullptr) {
            cout << atual->dados << " - ";
            atual = atual->proximo;
        }
        cout << "fim" << endl;
    }
}

void CListaInteiros::insereItem(int num) {
    CNoLista *atual, *novo=new CNoLista;

    novo->dados = num;
    novo->proximo = nullptr;

    atual=cabeca;
    if(atual == nullptr) {
        cabeca = novo;
    }
    else {
        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

void CListaInteiros::insereItemOrdenado(int num) {
    CNoLista *atual, *anterior, *novo=new CNoLista;

    novo->dados = num;
    novo->proximo = nullptr;

    atual=cabeca;
    anterior=nullptr;
    if (atual == nullptr) {
        cabeca = novo;
    }
    else {
        while ((atual != nullptr) && (atual->dados<num)) {
            anterior = atual;
            atual = atual->proximo;
        }
        if (anterior == nullptr) cabeca = novo;
        else anterior->proximo = novo;
        novo->proximo = atual;
        
    }
}

void CListaInteiros::apagaItem(int num) {
    CNoLista *atual, *anterior;

    atual = cabeca;
    anterior = nullptr;
    if(atual == nullptr) return;

    while(atual != nullptr && atual->dados!=num) {
        anterior = atual;
        atual = atual->proximo;
    }
    if(anterior == nullptr)
        cabeca = atual->proximo;
    else
        anterior->proximo = atual->proximo;
    delete atual;
}

bool CListaInteiros::procuraItem(int num) const {
    CNoLista *atual;

    atual=cabeca;
    if(atual == nullptr) return false;
    else {
        while(atual != nullptr) {
            if(atual->dados == num) return true;
            atual = atual->proximo;
        }
        return false;
    }
}

int CListaInteiros::maioresQue(int num) {
    CNoLista *atual;
    int soma=0;

    atual = cabeca;
    if(atual == nullptr) return 0;

    while(atual != nullptr) {
        if(atual->dados > num) soma+=1;
        atual = atual->proximo;
    }
    return soma;
}

int CListaInteiros::ultimoElemento(void) {
    CNoLista *atual;

    atual = cabeca;
    if(atual == nullptr) return -1;

    while(atual->proximo != nullptr) {
        atual = atual->proximo;
    }
    return atual->dados;
}

int CListaInteiros::operator[] (int num) {
    CNoLista *atual;

    atual = cabeca;
    if(atual == nullptr) return -1;

    while(atual != nullptr && num>0) {
        atual = atual->proximo;
        num-=1;
    }
    if (num == 0) return atual->dados;
    else return -1;
}

void CListaInteiros::eliminaImpares(void) {
    CNoLista *atual, *anterior;

    atual = cabeca;
    anterior = nullptr;
    if(atual == nullptr) return;

    while(atual != nullptr) {
        if(atual->dados%2 != 0) {
            if(anterior == nullptr) cabeca = atual->proximo;
            else anterior->proximo = atual->proximo;
            delete atual;
            atual = anterior->proximo;
        }
        else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}

bool CListaInteiros::operator==(const CListaInteiros &cl) {
    CNoLista *atual, *cl_atual;
    bool fim_dessa, fim_daquela;

    atual = cabeca;
    cl_atual = cl.cabeca;
    if(atual == nullptr && cl_atual == nullptr) return true;

    while(atual != nullptr && cl_atual != nullptr) {
        atual = atual->proximo;
        cl_atual = cl_atual->proximo;
    }
    if(atual == nullptr && cl_atual == nullptr) return true;
    else return false;

}

CListaInteiros &CListaInteiros::operator= (const CListaInteiros &lista){
    CNoLista *atual, *proximo;
    if (cabeca != nullptr){
        atual = cabeca;
        while (atual != nullptr){
            proximo = atual->proximo;
            delete atual;
            atual = proximo;
    }
        cabeca = nullptr;
    }

    atual = lista.cabeca;
    while (atual != nullptr){
        this->insereItem(atual->dados);
        atual = atual->proximo;
    }
    return *this;
}

CListaInteiros &CListaInteiros::operator+= (const CListaInteiros &cl){
    CNoLista *atual, *cl_atual;
    bool existe;

    atual = cabeca;
    cl_atual = cl.cabeca;
    if(cl_atual == nullptr) return *this;

    while(cl_atual != nullptr) {
        existe = false;
        while (atual != nullptr) {
            if(atual->dados == cl_atual->dados) existe = true;
            atual = atual->proximo;
        }
        if(!existe) this->insereItemOrdenado(cl_atual->dados);
        cl_atual = cl_atual->proximo;
    }
    return *this;
}

CListaInteiros CListaInteiros::operator+ (const CListaInteiros &cl){
    CListaInteiros nlist;
    CNoLista *atual, *cl_atual;
    bool existe;

    atual = cabeca;
    cl_atual = cl.cabeca;

    while(atual != nullptr) {
        nlist.insereItem(atual->dados);
        atual = atual->proximo;
    }    
    
    atual = cabeca;
    while(cl_atual != nullptr) {
        existe = false;
        while (atual != nullptr) {
            if(atual->dados == cl_atual->dados) existe = true;
            atual = atual->proximo;
        }
        if(!existe) nlist.insereItemOrdenado(cl_atual->dados);
        cl_atual = cl_atual->proximo;
    }
    return nlist;
}

int main() {
    CListaInteiros lista1;
    lista1.insereItem(9);
    lista1.insereItemOrdenado(1);
    lista1.insereItemOrdenado(13);
    lista1.insereItemOrdenado(0);
    lista1.insereItemOrdenado(4);
    lista1.insereItemOrdenado(3);
    lista1.insereItemOrdenado(7);
    lista1.insereItemOrdenado(8);
    lista1.insereItemOrdenado(10);
    lista1.insereItemOrdenado(2);
    lista1.escreveLista();
    
    CListaInteiros lista2;
    lista2.insereItem(94);
    lista2.insereItemOrdenado(91);
    lista2.insereItemOrdenado(6);
    lista2.insereItemOrdenado(5);
    lista2.insereItemOrdenado(4);
    lista2.insereItemOrdenado(23);
    lista2.insereItemOrdenado(234);

    lista2 = lista1;
    lista2.escreveLista();

    return 0;
}