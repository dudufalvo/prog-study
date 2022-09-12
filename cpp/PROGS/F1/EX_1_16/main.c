#include <stdio.h>

void invert(int array[], int dim) {
    int aux;
    for(int i=0; i<dim/2; i++) {
        aux = array[i];
        array[i] = array[dim-i];
        array[dim-i] = aux;
    }
}

int main()
{
    int len = 5;

    return 0;

}
