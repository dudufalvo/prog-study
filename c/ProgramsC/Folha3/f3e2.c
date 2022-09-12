/* print caracteres - folha3 e2*/
#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao das variaveis */
	char caractere;
	char novo_caractere;
	
	/* impressao e atribuicao de um valor a variavel */
	printf("Digite um caractere: ");
	caractere = getchar();
	
	printf("%c\n", caractere);
	
	/* conversao de char para int, incrementacao de uma unidade
	 * ao valor inteiro correspondente a tabela ASCII e conversao de
	 * volta para char para atribuir a nova variavel*/
	novo_caractere = (char) (((int) caractere)+1);
	
	/* impressao do caracter seguinte ao inicial fornecido */
	printf("%c", novo_caractere);
	return 0;
}
