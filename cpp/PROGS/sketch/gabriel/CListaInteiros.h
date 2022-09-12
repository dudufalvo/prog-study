//=============================================================================
//EDA 2021/22, EDA 2014/15, 2012/2011, 2007/2008, ficha 8 (listas ligadas)
//Paulo Coimbra (2008.04.21, 2012.04.14), Rui P. Rocha (2015.04.11, 2022.04.18)
//=============================================================================
// header file: CListaInteiros.h
//=============================================================================
// classe CListaInteiros - interface (declaracoes)
//=============================================================================
#ifndef CListaInteiros_h
#define CListaInteiros_h
//=============================================================================
class CNoLista{
  public:
	int dados;
	CNoLista *proximo;
}; // fim de class CNoLista
//=============================================================================
class CListaInteiros{
	CNoLista *cabeca;
  public:
	CListaInteiros(void);
	~CListaInteiros(void);

	void insereItem(int);
	void insereItemOrdenado(int);
	void apagaItem(int);
  bool procuraItem(int) const;
  void escreveLista(void) const;
	int ultimoElemento(void) const;
    //	...
}; // fim de class CListaInteiros

#endif
//=============================================================================
