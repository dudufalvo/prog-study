//=============================================================================
// EDA 2021/22, 2014/15, 2012/2011, 2007/2008, Ficha 9 (pilhas e filas)
//  Rui P. Rocha (2015.04.11) e Paulo Coimbra (2022-04-29, 2012, 2008)
//=============================================================================
// source file: FilaInteiros.cpp
//=============================================================================
#include <iostream>
#include "CFilaInteiros.h"
using namespace std;
//=============================================================================
CFilaInteiros::CFilaInteiros(void) {
    inicio = nullptr;
    fim = nullptr;
}
//=============================================================================
CFilaInteiros::~CFilaInteiros(void) {
    CNoFila *seguinte;

    while (inicio != nullptr) {
        seguinte = inicio->proximo; // elemento seguinte
        delete inicio;              // apaga elemento no inicio da fila
        inicio = seguinte;          // define nova cabeca da fila
    }
    fim = nullptr;
}
//=============================================================================
// insere novo elemento na cauda da fila
void CFilaInteiros::insereNaFila(const int item) {
    // cria elemento a colocar na cauda da lista
    CNoFila *novo = new CNoFila;
    novo->dados = item;
    novo->proximo = nullptr;
    // insere novo elemento na cauda da lista
    if( inicio == nullptr ) // se a fila esta vazia, passa a conter novo
        inicio = novo;
    else // a fila nao esta vazia
        fim->proximo = novo;
    // fim deve apontar para o novo elemento inserido na fila
    fim = novo;
}
//=============================================================================
// remove elemento da cabeca da fila e devolve o seu valor
bool CFilaInteiros::retiraDaFila(int &item){
    if (inicio == nullptr) return false; // nao ha nada para retirar

    // se a fila nao esta vazia, devolve informacao do elemento na cabeca da fila
    item = inicio->dados;

    // auxiliar para remocao da cabeca da fila
    CNoFila * aux = inicio;
    inicio = aux->proximo;
    // se a fila ficou vazia, actualiza fim
    if (inicio == nullptr) fim = nullptr;
    delete aux;   // liberta memoria
    return true;  // indica remocao bem sucedida
}
//=============================================================================
// escreve elementos na fila
void CFilaInteiros::escreveFila(void) const{
    if ( inicio == nullptr )
        cout << "Fila vazia..." << endl;
    else {
        CNoFila * aux = inicio;
        while( aux != nullptr ) {
            cout << aux->dados << endl;
            aux = aux->proximo;
        }
    }
}
//=============================================================================
void CFilaInteiros::tornaUltimoMaior(void) {
    CNoFila *atual = inicio->proximo;
    int maior = inicio->dados;

    if(inicio == nullptr) return;

    while(atual != nullptr){

        if(maior < atual->dados){
            maior = atual->dados;
        }

        atual = atual->proximo;
    }

    fim->dados = maior;
}
//=============================================================================
void CFilaInteiros::trocaUltimoComMaior(void){
    CNoFila *atual, *maior;
    int aux;
    if(inicio == nullptr)return;

    atual = inicio->proximo;
    maior = inicio;

    while(atual != nullptr){
        
        if(atual->dados > maior->dados ){
            maior = atual;
        }

        atual = atual->proximo;
    }

    aux = maior->dados;
    maior->dados = fim->dados;
    fim->dados = aux;
    
}
//=============================================================================
CNoFila* CFilaInteiros::retornaNo(int N) const{
    CNoFila *atual = inicio;
    N--;
    //Se a fila tiver vazia retorna nullptr
    if(inicio == nullptr)return nullptr;

    while (atual != nullptr && N != 0)
    {
        atual = atual->proximo;
        N--;
    }
    // Se o contador chegou a zero q a fila ainda não foi excedida
    if(N == 0 && atual != nullptr)
    return atual;

    // se a fila foi excedida
    return nullptr;
}
//=============================================================================
int CFilaInteiros::tamanhoFila(void)const{
    CNoFila *atual = inicio;
   int tamanho = 0;

    if(atual == nullptr) return 0;

    while(atual!=nullptr){
        tamanho++;

        atual = atual->proximo;
    }

    return tamanho;
}
//=============================================================================
bool CFilaInteiros::passaAfrente(unsigned int N){
    CNoFila *alvo = retornaNo(N);

    if(alvo == nullptr) return false;

    //Se o Alvo já está na frente, não faz nada
    if(alvo == inicio) return true;

    //Caso o Elemento não seja o inicio
    CNoFila *anterior ;
    anterior = retornaNo(N-1);

    // Se o Alvo está no fim, Passa a frente alterando o final
    if(alvo == fim){

        anterior->proximo = nullptr;
        fim = anterior;

        alvo->proximo = inicio;
        inicio = alvo;

    }else{
        //Se o Alvo está no meio, é passado a frente e seu anterior aponta
        // para qual o alvo apontava
        anterior->proximo = alvo->proximo;
        alvo->proximo = inicio;
        inicio = alvo;
    }

    return true;
}
//=============================================================================
void CFilaInteiros::compactaFila(int a, int b){
    CNoFila *atual, *anterior;
    atual = inicio;
    anterior = inicio;

    if(inicio == nullptr ) return;

    while(atual != nullptr ){
        // Caso o numero nao esteja no intervalo
        if(atual->dados < a || atual->dados > b){
            //Analise os casos especiais
            if(atual == inicio){
                atual = atual->proximo;
                delete anterior;
                inicio = atual;
                anterior = atual;
            }else if( atual == fim ){
                anterior->proximo = nullptr;
                fim = anterior;
                delete atual;
                atual = nullptr;
            }else{
                //Caso geral
                anterior->proximo = atual->proximo;
                delete atual;
                atual = anterior->proximo;
            }
        // Numero dentro do intervalo
        }else{
            if( anterior != atual) anterior = atual;
            atual = atual->proximo;
        }
    }   

}
//=============================================================================
void CFilaInteiros::inverteFila(int N){
    //Se a fila está vazia ou se N for maior que o tamanho da fila, nada é feito
    if(inicio == nullptr || N > tamanhoFila()) return;

    CNoFila *atual, *aux, *novoInicio;
    atual = inicio;
    novoInicio = retornaNo(N);
    // Se for inveter a fila toda
    if(novoInicio == fim)fim = inicio;

    while(atual != novoInicio){
        aux = atual->proximo;
        atual->proximo = novoInicio->proximo;
        novoInicio->proximo = atual;
        atual = aux;
    }
    inicio = novoInicio;

}
//=============================================================================
CFilaInteiros& CFilaInteiros::operator=(const CFilaInteiros &Fila){
    CNoFila *atual = inicio;
    CNoFila *outra = Fila.inicio;

    //Atual deve ser toda apagada.
    while(atual != nullptr){
        inicio = atual->proximo;
        delete atual;
        atual = inicio;
    }
    inicio = nullptr;
    fim = nullptr;

    //Se a fila estiver vazia, esta também fica
    if(Fila.inicio == nullptr) return *this;

    //Se não estiver vazia, é copiada para esta
    while(outra != nullptr){
        atual = new CNoFila; 
        atual->dados = outra->dados;
        atual->proximo = nullptr;
        
        if(inicio == nullptr) // se a fila esta vazia, passa a conter novo
            inicio = atual;
        else // a fila nao esta vazia
            fim->proximo = atual;
        
        // fim deve apontar para o novo elemento inserido na fila
        fim = atual;

        outra = outra->proximo;
    }

    return *this;
}
//=============================================================================
CFilaInteiros& CFilaInteiros::operator+(const CFilaInteiros &fila)const {
    CFilaInteiros *somada = new CFilaInteiros;
    CNoFila *esta = inicio;
    CNoFila *aquela = fila.inicio;
    CNoFila *soma; 

    while(esta != nullptr || aquela != nullptr){

        if(esta != nullptr){
          // cria elemento a colocar na cauda da lista
            soma = new CNoFila;
            soma->dados = esta->dados;
            soma->proximo = nullptr;
          // insere novo elemento na cauda da lista
        if( somada->inicio == nullptr ) // se a fila esta vazia, passa a conter novo
            somada->inicio = soma;
        else // a fila nao esta vazia
            somada->fim->proximo = soma;
        // fim deve apontar para o novo elemento inserido na fila
            somada->fim = soma;

          esta = esta->proximo;
        }

        if(aquela != nullptr){
            // cria elemento a colocar na cauda da lista
            soma = new CNoFila;
            soma->dados = aquela->dados;
            soma->proximo = nullptr;
          // insere novo elemento na cauda da lista
        if( somada->inicio == nullptr ) // se a fila esta vazia, passa a conter novo
            somada->inicio = soma;
        else // a fila nao esta vazia
            somada->fim->proximo = soma;
        // fim deve apontar para o novo elemento inserido na fila
            somada->fim = soma;
            aquela = aquela->proximo;
        }
        
    }

    return *somada;

}
//=============================================================================
CFilaInteiros& CFilaInteiros::operator-(const CFilaInteiros &fila)const{
    CNoFila *esta = inicio;
    CNoFila *aquela;
    CNoFila *sub;
    CFilaInteiros *resultado = new CFilaInteiros;
    bool contida = false;

    while(esta != nullptr){
        aquela = fila.inicio;
        while(aquela != nullptr){
            if(aquela->dados == esta->dados) contida = true;

            aquela = aquela->proximo;
        }

        if(!contida){
            sub = new CNoFila;
            sub->dados = esta->dados;
            sub->proximo = nullptr;
            if( resultado->inicio == nullptr ) // se a fila esta vazia, passa a conter novo
            resultado->inicio = sub;
        else // a fila nao esta vazia
            resultado->fim->proximo = sub;
        // fim deve apontar para o novo elemento inserido na fila
            resultado->fim = sub;
        }

        contida = false;
        esta = esta->proximo;
    }

    return *resultado;
}
//=============================================================================
bool CFilaInteiros::passaParaFim(unsigned int N){
    CNoFila *alvo = retornaNo(N);
    //Se N excedeu a fila, retorna false
    if(alvo == nullptr) return false;

    //Se o alvo é o incio
     if(alvo == inicio){
        inicio = alvo->proximo;
        alvo->proximo = nullptr;
        fim->proximo = alvo;
        fim = alvo;
        return true;
    }
    //Se o alvo ja está no final
    if(alvo == fim)return true;

    CNoFila *anterior = retornaNo(N-1);
    //Caso geral
    anterior->proximo = alvo->proximo;
    fim->proximo = alvo;
    alvo->proximo = nullptr;
    alvo = fim;
    return true;

}