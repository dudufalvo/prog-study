#include <iostream>
#include "CArvoreBinaria.cpp"

using namespace std;

int main(){
    int tabela[9] = { 6, 3, 2, 12, 10, 7, 11, 15, 20};
    CArvoreBinaria Arvore , arvoreDeTabela(tabela, 9), arvorePorFicheiro;
    CListaInteiros lista;
    Arvore.insere(6);
    Arvore.insere(3);
    Arvore.insere(2);
    Arvore.insere(12);
    Arvore.insere(10);
    Arvore.insere(7);
    Arvore.insere(11);
    Arvore.insere(15);
    Arvore.insere(20);

   cout << Arvore.valorPai(24);

    return 0;
}