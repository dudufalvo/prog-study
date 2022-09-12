#ifndef CListaHelpdesk_h
#define CListaHelpdesk_h
//=============================================================================
class CListaHelpdesk;
//=============================================================================
class CNoLista{
    char codigoPesquisa[5];
    char resposta[300];
    int pesquisas;
    
    CNoLista *proximo;

    friend class CListaHelpdesk;
};
//=============================================================================
class CListaHelpdesk{
private:
    CNoLista *cabeca;

public:
    CListaHelpdesk(void);
    ~CListaHelpdesk(void);

    void inserePerguntaResposta(char *r, char *codigo);
    char *PesquisaLista(char *codigo);

};
//=============================================================================
#endif