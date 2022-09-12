#include <iostream>

using namespace std;

/*class RArray {
    private:
        int max;
        double *tab;
        int n;
    public:
        RArray();
        RArray(int);
        RArray(const RArray &r);
        ~RArray();
        void apaga();
        bool vazia();
        bool insere();
};

// construtor por omissão
RArray :: RArray() {
    max = 100;
    tab = new double[max];
    n = 0;
}

// construtor por parâmetros
RArray :: RArray(int d){
    max = d;
    tab = new double(d);
}

// construtor por cópia
RArray :: RArray(const RArray &r){
    max = r.max;
    n = r.n;
    tab = new double(max);
    for(int i=0; i<r.max; i++){
        tab[i] = r.tab[i];
    }
}

// Destrutor
RArray :: ~RArray() {
    delete []tab;
}

void RArray :: apaga() {
    n = 0;
}

bool RArray :: vazia () {
    if (n==0) return true;
    else return false;
}

bool RArray :: insere () {
    if (n == max) return false;
    else {
        int hold, j, pass;
        bool switched = true;

        for(pass=0; pass<max-1 && switched==true; pass++){
            switched = false;
            for(j=0; j<max-pass-1; j++) {
                // comparamos o elemento atual com o seguinte
                if(tab[j] > tab[j+1]){

                    // se o elemento da direita for maior, invertemos
                    hold = tab[j];
                    tab[j] = tab[j+1];
                    tab[j+1] = hold;

                    // mantemos a flag ativa, ainda estamos atualizando a tabela
                    switched = true;
                }
            }
        }
        return true;
    }
}*/

class CArray {
    private:
        double *tab;
        int max;
        int n;
    public:
        CArray();
        CArray(int);
        CArray(const CArray &a);
        ~CArray();
        void apaga();
        bool vazia();
        bool insere(double);

};

CArray :: CArray() {
    max = 100;
    tab = new double[max];
    n = 0;
}

CArray :: CArray(int m) {
    max = m;
    tab = new double[max];
    n = 0;
}

CArray :: CArray(const CArray &a) {
    max = a.max;
    n = a.n;
    tab = new double[max];
    for(int i=0; i<max; i++) {
        tab[i] = a.tab[i];
    }
}

CArray :: ~CArray() {
    max = 0;
    delete[] tab;
    n = 0;
}

void CArray::apaga() {
    for(int i=0; i<n; i++) tab[i]=0;
    n = 0;
}

bool CArray::insere(double valor) {
    int index=0, meio, inic=0, fim=n-1;

    if(n==max) return false;
    else {
        while(inic<=fim) {
            meio = (inic+fim)/2;
            if(tab[meio]==valor) index = meio;
            else {
                if(valor>tab[meio]) {
                    inic = meio+1;
                    index = meio+1;
                }
                else fim=meio-1;
            }
        }
        for(int i=index; i<n; i++) {
            tab[i] = tab[i+1];
        }
        tab[index] = valor;
        return true;
    }
}

bool CArray::vazia() {
    if(n==0) return true;
    else return false;
}

void bubbleSort(double *tab, int comp) {
    bool trocado;
    double aux;

    for(int i=0; i<comp-1; i++) {
        trocado=false;
        for(int j=1; j<comp-1; j++) {
            if(tab[j]<tab[j-1]) {
                aux = tab[j-1];
                tab[j-1] = tab[j];
                tab[j] = aux;
                trocado=true;
            }
        }
        if(!trocado) break;
    }
}

int main() {
    CArray array1;
    CArray array2(50);
    CArray array3(array1);

    cout << array2.vazia() << endl;
}
