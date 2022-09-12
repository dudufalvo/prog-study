#include <iostream>
#define DIM 5

using namespace std;

struct sucursalData{
    char name[61];
    int people;
    double area;
};

void selectSort_down(sucursalData tab[], int size) {
    /* função que coloca a tabela passada em
     * ordem a partir do algoritimo de seleção*/

    float aux=0;

    // no primeiro ciclo atualizamos o ponto de paragem
    for(int stop = size-1; stop>0; stop--){
        // percorremos todos os valores até o ponto de paragem
        for(int pres=0; pres<=stop; pres++) {
            // encontrado o maior valor até o stop
            if(tab[pres].area>tab[stop].area) {
                // colocamos o mais a direita possivel
                aux = tab[stop].area;
                tab[stop].area = tab[pres].area;
                tab[pres].area = aux;}
        }
    }
}

/*int contaDim(sucursalData tab[], int size, double areaDada){
    int start = 0;
    int end = size-1;
    int middle;

    while (start <= end){
       middle = (start + end)/2;

       if(tab[middle].area > areaDada){

           if(tab[middle-1].area <= areaDada)
               return (size - middle);

           end = middle;
           }

       if(tab[middle].area < areaDada){

           if(tab[middle+1].area >= areaDada)
               return (middle + 1);

           start = middle;
       }
    }
    return -1;
}*/

int contaDim(sucursalData *array, int size, double areaDada) {
    int quantidade=0;

    for(int i=0; i<size; i++) {
        if(array[i].area > areaDada) quantidade++;
    }
    return quantidade;
}

int main()
{
    int total=0;
    sucursalData sucursais[DIM] = { {"LOJA1", 435, 123.123},
                                    {"LOJA2", 243, 24.1233},
                                    {"LOJA3", 35, 54.12311},
                                    {"LOJA4", 32, 63.23441},
                                    {"LOJA5", 573, 724.234}};

    selectSort_down(sucursais, DIM);
    total = contaDim(sucursais, DIM, 100.0);
    cout << total << endl;


    return 0;
}
