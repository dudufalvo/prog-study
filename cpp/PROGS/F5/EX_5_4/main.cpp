#include <iostream>
#define MAX 15

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

int binInsertion(int *array, int nelem, int maxelem, int target) {
    int inic = 0;
    int fim = nelem-1;
    int meio, i;
    int leftmost=0;

    while(inic <= fim) {
        meio = (inic+fim)/2;

        if(target == array[meio]) return 0;
        else {
            if (target < array[meio]) {
                fim = meio-1;
                leftmost = meio;
            }
            else inic=meio+1;
        }
    }
    if (nelem < maxelem) {
        for(i=leftmost; i<nelem+1; i++) {
            array[i+1] = array[i];
        }
        array[leftmost] = target;
        return 1;
    } else return -1;
}

void createArray(int array[]) {
    for(int i=0; i<MAX-5; i++) {
       array[i] =  1 + rand() % 100;
    }
}

int main()
{
    int array[MAX];
    createArray(array);
    selectSort_down(array, MAX);

    for(int i=0; i<MAX; i++) cout << "array[" << i << "] = " << array[i] << endl;

    cout << "resposta:" << binInsertion(array, MAX-5, MAX, 8) << endl;

    for(int i=0; i<MAX; i++) cout << "array[" << i << "] = " << array[i] << endl;

    return 0;
}
