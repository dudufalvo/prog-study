/* print caracteres/inteiros - folha3 e3*/
#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao da variavel */
	char letra;
	int inteiro;
	
	/* impressao, leitura e atribuicao de um valor a variavel */
	printf("Digite um caractere: ");
	scanf("%c", &letra);
	printf("Digite um inteiro: ");
	scanf("%d", &inteiro);
	
	printf("'%c', %d", letra, inteiro);
	return 0;
}
