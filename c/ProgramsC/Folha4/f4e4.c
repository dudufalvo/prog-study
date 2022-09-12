/* print caracteres - folha4 e4*/
#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao da variavel */
	int numero, auxiliar_coluna, auxiliar_linha;
	
	do {
		printf("Digite um numero no intervalo [1,20]: ");
		scanf("\n%d", &numero);
		
	} while ((numero>20)||(numero<1));
	
	for (auxiliar_linha=0; auxiliar_linha<numero; auxiliar_linha+=1) {
		for (auxiliar_coluna=0; auxiliar_coluna<numero; auxiliar_coluna+=1) {
			printf("#");
			}
		printf("\n");
		auxiliar_coluna = 0;
		}
	return 0;
}
