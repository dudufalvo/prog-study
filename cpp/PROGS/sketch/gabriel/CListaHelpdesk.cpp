#include "CListaHelpdesk.h"
#include <iostream>
#include <string.h>
using namespace std;
//=============================================================================
CListaHelpdesk::CListaHelpdesk(void){
    cabeca = nullptr;
}
//=============================================================================
CListaHelpdesk::~CListaHelpdesk(void){
    CNoLista *atual = cabeca;
    CNoLista *anterior = cabeca;

    while(atual != nullptr){

        atual = atual->proximo;
        delete anterior;

        anterior = atual;
    }
}
//=============================================================================
void CListaHelpdesk::inserePerguntaResposta(char *r, char *codigo){
    CNoLista *novo = new CNoLista;
    CNoLista *atual = cabeca;
    
    strcpy(novo->codigoPesquisa ,codigo);
    strcpy(novo->resposta ,r);
    novo->pesquisas = 0;
    novo->proximo = nullptr;

    if(cabeca == nullptr){
        cabeca = novo;
    }else{
        while(atual->proximo!=nullptr){
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}
//=============================================================================
char* CListaHelpdesk::PesquisaLista(char *codigo){
    CNoLista *atual = cabeca;
    CNoLista *anterior = cabeca;
    bool encontrada = false;

    while (atual != nullptr && encontrada == false)
    { 
        encontrada = true;
        for(int i = 0 ; i < 5; i++){
            if(codigo[i] != atual->codigoPesquisa[i]) encontrada = false;
        }

        if(encontrada == false){
        anterior = atual;
        atual = atual->proximo;
        }
    }

    if(encontrada == true){
        if(atual != cabeca){
        anterior->proximo = atual->proximo;
        atual->proximo = cabeca;
        cabeca = atual;
        atual->pesquisas++;
        }
        return atual->resposta;
    }
    
    return "Pergunta nao encontrada";
}
