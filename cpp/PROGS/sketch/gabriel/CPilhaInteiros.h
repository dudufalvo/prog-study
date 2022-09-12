//=============================================================================
// EDA 2021/2022, 2014/15, 2012/2011, 2007/2008, Ficha 9 (pilhas e filas)
//  Rui P. Rocha (2015.04.11) e Paulo Coimbra (2022-04-29, 2012, 2008)
//=============================================================================
// header file: PilhaInteiros.h
//=============================================================================
#ifndef CPilhaInteiros_h
#define CPilhaInteiros_h
//=============================================================================
class CPilhaInteiros;
//=============================================================================
class CNoPilha {
    int dados;
    CNoPilha *proximo;

    friend class CPilhaInteiros; // permite a esta classe aceder atributos private
};
//=============================================================================
class CPilhaInteiros {
private:
    CNoPilha * topo; // ponteiro para o elemento no topo da pilha
    CNoPilha* ponteiraPara(int i);
public:
	CPilhaInteiros(void);
    CPilhaInteiros(const CFilaInteiros &fila);
	~CPilhaInteiros(void);

    void push(const int item);
    bool pop(int &item);
    void escrevePilha(void) const;
    bool pilhaVazia() const { return (topo == nullptr); }
    int numElementos(void)const;
    void trocaTopo(int &novoTopo);
    bool operator<(const CPilhaInteiros &pilha) const;
    bool operator<=(const CPilhaInteiros &pilha) const;
    bool operator>(const CPilhaInteiros &pilha) const ;
    bool operator>=(const CPilhaInteiros &pilha) const;
    void operator<<(int i);
    void reordenaParesImpares(void);
    int contaNegativosPushandPop(void);
    int contaNegativoPonteiros(void)const;
};
//=============================================================================
#endif
