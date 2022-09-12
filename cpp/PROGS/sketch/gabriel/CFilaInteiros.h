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
    friend class CPilhaInteiros;

};
//=============================================================================
class CFilaInteiros {
private:
    CNoFila *inicio, *fim;
    CNoFila *retornaNo(int N)const;
public:
	CFilaInteiros(void);
	~CFilaInteiros(void);

    void insereNaFila(const int item);
    bool retiraDaFila(int &item);
    void escreveFila(void) const;
    bool filaVazia(void) const { return (inicio == nullptr ); }
    void tornaUltimoMaior(void);
    void trocaUltimoComMaior(void);
    int tamanhoFila(void)const;
    bool passaAfrente(unsigned int N);
    bool passaParaFim(unsigned int N);
    void compactaFila(int a, int b);
    void inverteFila(int N);
    CFilaInteiros& operator=(const CFilaInteiros &fila);
    CFilaInteiros& operator+(const CFilaInteiros &fila) const;
    CFilaInteiros& operator-(const CFilaInteiros &fila) const;


    friend class CPilhaInteiros;
};
//=============================================================================
#endif
