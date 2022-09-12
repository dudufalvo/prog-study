//
//  CJogo.h
//  Projeto_2
//
//  Created by Gabriel Santos Correa da Silva on 03/05/22.
//
//=============================================================================
// Declaracao classe Jogo e MAX (21)
//=============================================================================
#ifndef CJogo_h
#define CJogo_h
#define MAX 51
#include <sys/time.h>
#include <iostream>
using namespace std;

//=====================================================================
class Jogo {
private:
    string palavra, tema, nome;
    bool emJogo;
    char letrasCertas[MAX];
    char erros[7];
    int tentativas;
    int acertos;
    int pontos;
    int indexPalavrasJogadas[24];
    int palavrasTotais;
    int TotalTemas;
    int palavrasJogadas;
    int tamanho_palavra;
    int dificuldade;
    int modo;
    double tempo;

public:
    Jogo();
    void menu(void);
    void novo_jogo(void);
    void carregar_jogo(void);
    void contaQuantosTemas(void);
    void editaTema(void);
    void adicionaTema(void);
    void excluiTema(void);
    void adicionaPalavra(void);
    int jogo(void);
    void avanca_jogo(void);
    int modo_jogo(void);
    void salvarjogo(void);
    void salvarRanking(void);
    void historico(void);
    void formaLista(string tema, char *Palavra);
    int menosJogada(void)const;
    void coutJogo(void);
    double printTime(timeval, timeval, int);
    void sair();
    friend class listaRank;

};
//=====================================================================

#endif /* CJogo_h */
