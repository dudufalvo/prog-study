#include <iostream>
#include <cstring>
using namespace std;

struct data {
    char Palavra[25];
    unsigned int Contador;
};

class CNoLista {
    public:
        char Palavra[25];
        unsigned int Contador;
        CNoLista *proximo;  
};
class CListaOcorrencias {
    CNoLista *primeirapalavra;
    public:
        CListaOcorrencias (void);
        ~CListaOcorrencias (void);
        
        CListaOcorrencias & operator += (const char *NovaPalavra);
        void escreveLista(void);
        data porOcorrencia(void);
};

CListaOcorrencias::CListaOcorrencias() {
    primeirapalavra = nullptr;
}

CListaOcorrencias::~CListaOcorrencias() {
    CNoLista *atual, *proximo;

    atual=primeirapalavra;
    while (atual != nullptr){
        proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}

data CListaOcorrencias::porOcorrencia(void) {
    CNoLista *atual;
    data data;

    strcpy(data.Palavra, "");
    data.Contador = 0;

    atual = primeirapalavra;
    if(primeirapalavra == nullptr) return data;

    strcpy(data.Palavra, primeirapalavra->Palavra);
    data.Contador = primeirapalavra->Contador;

    while (atual != nullptr) {
        if(atual->Contador > data.Contador) {
            strcpy(data.Palavra, atual->Palavra);
            data.Contador = atual->Contador;
        }
        atual = atual->proximo;
    }
    return data;
}

void CListaOcorrencias::escreveLista(void) {
    CNoLista *atual;

    atual = primeirapalavra;
    if(primeirapalavra == nullptr) {
        cout << "lista vazia";
        return;
    }

    while(atual != nullptr) {
        cout << atual->Palavra << "-" << atual->Contador << " / ";
        atual = atual->proximo;
    }
    cout << "fim" << endl;
}

CListaOcorrencias &CListaOcorrencias::operator+= (const char *NovaPalavra) {
    CNoLista *atual, *novo=new CNoLista;
    bool existe=false;

    strcpy(novo->Palavra, "");
    novo->Contador = 0;

    atual = primeirapalavra;
    if(primeirapalavra == nullptr) {
        strcpy(novo->Palavra, NovaPalavra);
        novo->Contador = 1;
        primeirapalavra = novo;
    }
    else {
        while(atual->proximo != nullptr) {
            if(atual->Palavra == novo->Palavra) {
                existe = true;
                atual->Contador += 1;
            }
            atual = atual->proximo;
        }
        if(!existe) atual->proximo = novo;
    }
    return *this;
}

int main() {
    CListaOcorrencias lista1;
    data palavra_escolhida;

    char palavra1[] = "agua";
    lista1 += palavra1;
    char palavra2[] = "fogo";
    lista1 += palavra2;
    char palavra3[] = "ar";
    lista1 += palavra3;
    char palavra4[] = "pedra";
    lista1 += palavra4;
    char palavra5[] = "bola";
    lista1 += palavra5;
    char palavra6[] = "vidro";
    lista1 += palavra6;
    char palavra7[] = "areia";
    lista1 += palavra7;
    char palavra8[] = "areia";
    lista1 += palavra8;


    lista1.escreveLista();

    palavra_escolhida = lista1.porOcorrencia();
    cout << palavra_escolhida.Palavra << '-' << palavra_escolhida.Contador << endl;
    return 0;
}