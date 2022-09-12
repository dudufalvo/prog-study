#include <iostream>
#include <time.h>

const int DIM=100000;

using namespace std;

void selectSort_down(int tab[], int size) {
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

void bubbleSort(int tab[], int size) {
    int hold, j, pass;
    bool switched = true;

    for(pass=0; pass<size-1 && switched==true; pass++){

        switched = false;
        for(j=0; j<size-pass-1; j++) {
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
}

int compareVal(const void *num1, const void *num2) {
    int *first = (int*)num1;
    int *second = (int*)num2;

    return (first - second);
}

void createArray(int tab[]) {
    for(int i=0;i<DIM;i++) {
       tab[i]=rand()%10000;
    }
}

int main() {
    clock_t start, end;
    int randArray[DIM];

    createArray(randArray);
    start = clock();
    selectSort_down(randArray, DIM);
    end = clock();
    cout << "selection sort: " << ((double) (end - start)) / CLOCKS_PER_SEC << endl;

    createArray(randArray);
    start = clock();
    qsort(randArray, DIM, sizeof(int), compareVal);
    end = clock();
    cout << "quick sort: " << ((double) (end - start)) / CLOCKS_PER_SEC << endl;

    createArray(randArray);
    start = clock();
    bubbleSort(randArray, DIM);
    end = clock();
    cout << "bubble sort: " << ((double) (end - start)) / CLOCKS_PER_SEC << endl;

    return 0;
}
