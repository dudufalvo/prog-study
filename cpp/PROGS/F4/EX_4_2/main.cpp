#include <iostream>

using namespace std;

void selectsort_down(float tab[], int size) {
    /* função que coloca a tabela passada em
     * ordem a partir do algoritimo de seleção*/

    float aux=0;

    // no primeiro ciclo atualizamos o ponto de paragem
    for(int stop = size-1; stop>0; stop--){
        // percorremos todos os valores até o ponto de paragem
        for(int pres=0; pres<=stop; pres++) {
            // encontrado o maior valor até o stop
            if(tab[pres]>tab[stop]) {
                // colocamos o mais a direita possivel
                aux = tab[stop];
                tab[stop] = tab[pres];
                tab[pres] = aux;}
        }
    }
}

int main() {
    // declaração e inicialização das variaves
    float tab[] = {3.4, 1.2, 0.2, 5.6, 2.3, 4.2, 34.1, 123.12};
    int tabLen = sizeof(tab)/sizeof(int);

    // sorting da tabela a partir da função
    selectsort_down(tab, tabLen);

    // print da nova ordem dos elementos
    for(int i=0; i<tabLen; i++) {
        cout << "tab[" << i << "] = " << tab[i] << endl;
    }

    return 0;
}
