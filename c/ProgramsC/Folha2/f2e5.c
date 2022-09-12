/*=============================================================== 
 FOLHA 2 - EXERCICIO 5                   
 * Autor: Eduardo Rocha Falvo                     Data:2021/10/18
 * Objetivo: DemonstraÃ§Ã£o de um programa simples (1)
 * UtilizaÃ§Ã£o: Execute que a mensagem aparece
===============================================================*/
#include <stdio.h>				    /* definicao da biblioteca */

int main() 						/* definicao e inicio do bloco */
{
	/* declaracao da variavel de dupla precisao */
	double realDuplo;

	/* impressao solicitando um double e escaneando o input */
	printf("Insira um valor real de dupla precisao: ");
	scanf("%lf", &realDuplo);

	/* impressao do double fornecido de modo arredondado */
	printf("O valor %lf arredondado vale %.0lf", realDuplo, realDuplo);
	return 0;
}
