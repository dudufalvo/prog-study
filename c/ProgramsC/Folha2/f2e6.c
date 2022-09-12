/*=============================================================== 
 FOLHA 2 - EXERCICIO 6                    
 * Autor: Eduardo Rocha Falvo                     Data:2021/10/18
 * Objetivo: DemonstraÃ§Ã£o de um programa simples (1)
 * UtilizaÃ§Ã£o: Execute que a mensagem aparece
===============================================================*/
#include <stdio.h> 					/* definicao da biblioteca */

int main()					    /* definicao e inicio do bloco */
{
	/* declaracao da variavel */
	float givenValue;

	/* impressao solicitando valor real e escaneando o input */
	printf("Insira um valor real: ");
	scanf("%f", &givenValue);

	/* impressao informando o seu quadrado limitado por 4 casas decimais */
	printf("O quadrado de %f fica aproximadamente: %.4f", givenValue, givenValue*givenValue);
	return 0;
}
