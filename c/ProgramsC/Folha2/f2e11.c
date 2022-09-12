/*=============================================================== 
 FOLHA 2 - EXERCICIO 11
 * Autor: Eduardo Rocha Falvo                     Data:2021/10/18
 * Objetivo: DemonstraÃ§Ã£o de um programa simples (1)
 * UtilizaÃ§Ã£o: Execute que a mensagem aparece
===============================================================*/
#include <stdio.h> 					  /*definicao da biblioteca*/

int main()						  /*definicao e inicio do bloco*/
{
	/*declaracao de variavel*/
	double givenValue;

	/*impressao pede numero real e escaneia o input*/
	printf("Digite um numero real: ");
	scanf("%lf", &givenValue);

	/*impressao retorna o quadrado do valor fornecido arredondado ao inteiro mais próximo*/
	printf("O quadrado de %.2lf arredondado = %.0lf", givenValue, givenValue*givenValue);
	return 0;
}
