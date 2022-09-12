#include <iostream>

using namespace std;
const int DIM=100;

void selectSort_down(double tab[], int size) {
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

void createArray(double array[]) {
    for(int i=0;i<DIM;i++) {
       array[i]=(((double)rand()) / (RAND_MAX/58))-12.5;
    }
}

int binSearching(double *array, int size, double min) {
    int inic = 0;
    int fim = size-1;
    int meio;
    int leftGreater=inic;

    while(inic <= fim) {
        meio = (inic+fim)/2;

        if(min < array[meio]) {
            fim = meio - 1;
            leftGreater = meio;
        }
        else inic = meio + 1;

    }
    return leftGreater;
}

int main()
{
    double array[DIM];
    int index_array;
    createArray(array);
    selectSort_down(array, DIM);

    for(int i=0; i<DIM; i++) cout << "array[" << i << "] = " << array[i] << endl;

    index_array = binSearching(array, DIM, 43);

    cout << "temos " << 100 - index_array << " numeros maiores do que 15" << endl;

    return 0;
}
