#include <iostream>

using namespace std;

struct Aluno {
    char nome[51];
    int numero;
    int ano;
};

void delFicha(Aluno *array, int size, int index) {
    int i;

    for(i=index; i<size-1; i++) {
        array[i] = array[i+1];
    }

    array[i] = {};
}

void delFichaVelho(Aluno *array, int size) {
    int index_velho = 0;

    for(int i=0; i<size; i++) {
        if(array[i].ano < array[index_velho].ano) index_velho = i;
    }

    delFicha(array, size, index_velho);
}

int main()
{
    Aluno array[5] = {{"EDUARDO", 2021192252, 2003},{"GABRIEL", 2021458723, 2000},
                      {"PADOVESE", 2021452189, 2001},{"CAIO", 2021983467, 2002},
                      {"DINIZ", 2021984365, 2003}};

    for(int i=0; i<5; i++) cout << array[i].nome << " " << array[i].numero << " " << array[i].ano << endl;

    delFichaVelho(array, 5);
    cout << endl;

    for(int i=0; i<5; i++) cout << array[i].nome << " " << array[i].numero << " " << array[i].ano << endl;

    return 0;
}
