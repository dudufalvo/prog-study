#include <iostream>

using namespace std;

struct Filial {
    char nome[56];
    int ntrabalhadores;
    double volume;
};

int contaFiliais(Filial *array, int size, double valorInf, double valorSup) {
    int quantidade=0;

    for(int i=0; i<size; i++) {
        if(array[i].volume > valorInf && array[i].volume < valorSup) {
            quantidade+=1;
        }
    }
    return quantidade;
}

int main()
{
    Filial array[200] = {{"LOJA 1", 500, 200.000}, {"LOJA 2", 250, 95.000},
                         {"LOJA 3", 400, 250.000}, {"LOJA 4", 350, 300.000}};
    int nfiliais = 4;

    cout << contaFiliais(array, nfiliais, 100.00, 300.000) << endl;

    return 0;
}
