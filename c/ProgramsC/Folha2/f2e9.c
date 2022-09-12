/*=============================================================== 
 FOLHA 2 - EXERCICIO 9
 * Autor: Eduardo Rocha Falvo                     Data:2021/10/18
 * Objetivo: DemonstraÃ§Ã£o de um programa simples (1)
 * UtilizaÃ§Ã£o: Execute que a mensagem aparece
===============================================================*/
#include <stdio.h> 					  /*definicao da biblioteca*/

int main()						  /*definicao e inicio do bloco*/
{
	/*declaracao da variavel*/
	int givenValue;

	/*impressao pede inteiro e escaneia o input*/
	printf("Digite um valor inteiro: ");
	scanf("%d", &givenValue);

	/*impressao do dobro e do triplo do valor dado*/
	printf("O dobro de %d = %d\n", givenValue, givenValue*2);
	printf("O triplo de %d = %d", givenValue, givenValue*3);

	return 0;
}
