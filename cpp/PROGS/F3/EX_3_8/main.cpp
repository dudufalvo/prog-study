#include <iostream>

using namespace std;

void swapRef(int &a, int &b) {
    /* função que, passados dois endereços como argumento,
     * troca os valores presentes nesses endereços entre si*/

    // guardamos o valor de 'a' temporariamente em 'aux'
    int aux = a;

    // fazemos as substituições
    a = b;
    b = aux;
}

void invert(int array[], int dim) {
    for(int i=0; i <= dim/2; i++) {
        swapRef(array[i], array[dim-i-1]);
    }
}

int main()
{
    int tab[] = {1, 2, 3, 4, 5};
    int dim = sizeof(tab)/sizeof(dim);
    invert(tab, dim);

    // print dos elementos da tabela para verificação
    for(int i=0; i<dim; i++) {
        cout << tab[i] << " ";
    }
    return 0;
}
