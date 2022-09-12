/*=============================================================== 
 FOLHA 2 - EXERCICIO 4                    
 * Autor: Eduardo Rocha Falvo                     Data:2021/10/18
 * Objetivo: DemonstraÃ§Ã£o de um programa simples (1)
 * UtilizaÃ§Ã£o: Execute que a mensagem aparece
===============================================================*/
#include <stdio.h> 					/* definicao da biblioteca */

int main() 					      /*definicao e inicio do bloco*/
{   
	/* declaracao das variaveis */
    int i, j;
    double xi, xj;
    
    /* impressao pedindo dos valores */
    printf("De-me dois inteiros positivos: ");
	/* funcao para captura de inputs */
    scanf("%d%d", &i, &j);
    
    printf("\nCalcula uma adicao\n");
    printf("\t%d + %d tem o valor %d\n",  i, j, i+j);
    
    printf("\nQuociente de inteiros\n");
    printf("\t%d / %d em Z tem o valor %d\n", i, j, i/j );      
    printf("\t%d / %d em Z tem o valor %d\n", j, i, j/i );     

    printf("\nResto da divisao de inteiros\n");
    printf("\t%d %% %d em Z tem o valor %d\n", i, j, i%j );      
    printf("\t%d %% %d em Z tem o valor %d\n", j, i, j%i );    
    
    printf("\n------------------------------\nQuociente de numeros reais\n");
    xi = (double)i; /* xi <-- i, atribuição com conversão explícita */
    xj = j;         /* xj <-- j, EVITAR: atribução com conversão implícita*/
    printf("\t%lf/%lf em R tem o valor %lf\n",  xi, xj, xi/xj);      
    printf("\t(%lf+1.5)/%lf em R tem o valor %lf\n", xi, xj, (xi+1.5)/xj);
    return(0);
}
