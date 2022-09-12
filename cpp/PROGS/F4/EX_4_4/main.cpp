#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;
//const int DIM=6;
/*
struct Fichas {
    string name;
    int age, nstudent;
};
int main(){

    Fichas student_data[DIM] = {{"EDUARDO",18, 2021192252},
                                {"PADOVESE",12,2021324922},
                                {"MARIA", 48,  2023324242},
                                {"NICOLE", 24, 2021192252},
                                {"GARIEL", 67, 2021243532},
                                {"GIULIA", 27, 2021342425}};

    qsort((void *)student_data, DIM, sizeof(Fichas), sortAge);

    for(int i=0; i<DIM; i++) {
        cout << "NAME: " << student_data[i].name << endl;
        cout << setw(10) << "AGE: " << student_data[i].age << endl;
        cout << setw(20) << "STUDENT NUMBER: " << student_data[i].nstudent << endl;
    }
    return 0;
}*/

struct Fichas {
    string nome;
    int idade;
    int numero;
};


int sortAge(const void *age1, const void *age2) {

    const struct Fichas *p_age1 = (Fichas *)age1;
    const struct Fichas *p_age2 = (Fichas *)age2;

    return (p_age1->idade - p_age2->idade);
}

void printFicha(Fichas alunos[], int size) {
    for(int i=0; i<size; i++) {
        cout << alunos[i].nome << " - " << alunos[i].idade << " - " << alunos[i].numero << endl;
    }
}

int main()
{
    Fichas alunos[10] = {{"eduardo", 19, 20212252},
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
    qsort((void *) alunos, 10, sizeof(Fichas), sortAge);
    printFicha(alunos, 10);
    return 0;
}
