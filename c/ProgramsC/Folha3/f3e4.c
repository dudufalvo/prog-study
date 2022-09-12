/* print caracteres/inteiros - folha3 e4 */
#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao da variavel */
	char letra;
	int inteiro;
	
	/* impressao, leitura e atribuicao de um valor a variavel */
	printf("Digite um inteiro: ");
	scanf("%d", &inteiro);
	printf("Digite uma letra: ");
	scanf(" %c", &letra);
	
	printf("%d, '%c'", inteiro, letra);
	return 0;
}
