//=============================================================================
// EDA 2021/22, 2014/15, 2012/2011, 2007/2008, Ficha 9 (pilhas e filas)
//  Rui P. Rocha (2015.04.11) e Paulo Coimbra (2022-04-29, 2012, 2008)
//=============================================================================
// header file: FilaInteiros.h
//=============================================================================
#ifndef CFilaInteiros_h
#define CFilaInteiros_h
//=============================================================================
class CFilaInteiros;
//=============================================================================
class CNoFila {
    int dados;
    CNoFila *proximo;
	
    friend class CFilaInteiros; // permite a esta classe aceder atributos private
};
//=============================================================================
class CFilaInteiros {
private:
    CNoFila *inicio, *fim;
    CNoFila *noMaiorNumero() const;
public:
	CFilaInteiros(void);
	~CFilaInteiros(void);

    void insereNaFila(const int item);
    bool retiraDaFila(int &item);
    void escreveFila(void) const;
    void substitui(void);
    void troca(void);
    bool passaAfrente(int);
    bool filaVazia(void) const { return (inicio == nullptr ); }
};
//=============================================================================
#endif
