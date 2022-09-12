/* print caracteres - folha3 e1*/
#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao da variavel */
	char caractere;
	
	/* impressao, leitura e atribuicao de um valor a variavel */
	printf("Digite um caractere: ");
	scanf("%c", &caractere);
	
	printf("%c\n", caractere);
	
	/* conversao de char para int, incrementacao de uma unidade
	 * ao valor inteiro correspondente a tabela ASCII e conversao de
	 * volta para char */
	caractere = (char) (((int) caractere)+1);
	
	/* impressao do caracter seguinte ao inicial fornecido */
	printf("%c", caractere);
	return 0;
}
