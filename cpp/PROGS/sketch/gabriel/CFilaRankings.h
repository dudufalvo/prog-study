#ifndef CFilaRankings_h
#define CFilaRankings_h
//=============================================================================
class CFilaRankings;
//=============================================================================
class CNoFila{ // Nó da fila public:
char pais[50];
int ranking; //valor mais baixo indica um país mais desenvolvido
CNoFila *proximo; //próximo nó

friend class CFilaRankings;
};
//=============================================================================
class CFilaRankings{ // Fila contendo países ordenados pelo seu ranking
CNoFila *inicio; // Ponteiro para o início da Fila
CNoFila *fim; // Ponteiro para o fim da Fila
public:
CFilaRankings();
~CFilaRankings();

void inserePais(char *Pais,int rating);
void escreveLista(void);

};
#endif

