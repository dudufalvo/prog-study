/*=============================================================== 
 FOLHA 2 - EXERCICIO 8                   
 * Autor: Eduardo Rocha Falvo                     Data:2021/10/18
 * Objetivo: DemonstraÃ§Ã£o de um programa simples (1)
 * UtilizaÃ§Ã£o: Execute que a mensagem aparece
===============================================================*/
#include <stdio.h> 					  /*definicao da biblioteca*/

int main() 						  /*definicao e inicio do bloco*/
{
	/*declaracao da variavel givenValue*/
	int givenValue;
	
	/*impressao solicita um valor inteiro e atribui a variavel*/
	printf("Escreva um valor inteiro:");
	scanf("%d", &givenValue);
	
	/*impressao do valor inteiro em diferentes bases*/
	printf("O inteiro %d na base 10 = %i\n",givenValue,givenValue);
	printf("O inteiro %d na base 8 = %o\n",givenValue,givenValue);
	printf("O inteiro %d na base 16 = %x",givenValue,givenValue);
	
	return 0;
}
