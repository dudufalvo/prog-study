#include <iostream>

using namespace std;

struct ficha {
    string nome;
    int idade;
    int numero;
};

void alphasort(ficha alunos[], int size) {
    //selection sort up
    int i, j, hold_i, hold_n;
    string hold_a;

    for(i=0; i<size-1; i++) {
        for(j=i+1; j<size; j++) {
            if(alunos[i].nome > alunos[j].nome) {
                hold_a = alunos[i].nome;
                alunos[i].nome = alunos[j].nome;
                alunos[j].nome = hold_a;

                hold_i = alunos[i].idade;
                alunos[i].idade = alunos[j].idade;
                alunos[j].idade = hold_i;

                hold_n = alunos[i].numero;
                alunos[i].numero = alunos[j].numero;
                alunos[j].numero = hold_n;

            }
        }
    }
}

void printFicha(ficha alunos[], int size) {
    for(int i=0; i<size; i++) {
        cout << alunos[i].nome << " - " << alunos[i].idade << " - " << alunos[i].numero << endl;
    }
}

int main()
{
    ficha alunos[10] = {{"eduardo", 19, 20212252},
                        {"julia", 20, 25241332},
                        {"ana", 12, 32345432},
                        {"caio", 85, 45234522},
                        {"padovese", 42, 42352342},
                        {"maria", 53, 24572234},
                        {"gabriel", 10, 87673453},
                        {"silvia", 65, 23534654},
                        {"patricia", 14, 96763453},
                        {"ricardao", 18, 32444574}};

    printFicha(alunos, 10);
    cout << endl;
    alphasort(alunos, 10);
    printFicha(alunos, 10);
    return 0;
}
