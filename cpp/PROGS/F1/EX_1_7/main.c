#include <stdio.h>
#define DIM 5

void subElem(int len, int tab[len][len], int num) {
    /* funcao que recebe uma matriz bidimensional
     * e verifica se o valor do elemento eh maior,
     * igual ou menor que outro passado como parametro*/

    // primeiro ciclo percorre as linhas
    for(int i=0; i<len; i++) {

        // segundo ciclo percorre as colunas
        for(int k=0; k<len; k++) {

            // print de +, = ou - apos comparar o elemento da matriz com o parametro
            if(tab[i][k]>num) printf("+ ");
            if(tab[i][k]==num) printf("= ");
            if (tab[i][k]<num) printf("- ");
        }
        // terminado o ciclo, pulamos de linha
        printf("\n");
    }

}

int main()
{
    // declaracao das variaveis e inicializacao da tabela
    int valor;
    int tab[DIM][DIM] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25}};

    printf("digite uma valor: ");
    scanf("%d", &valor);

    subElem(DIM, tab, valor);

    return 0;
}
