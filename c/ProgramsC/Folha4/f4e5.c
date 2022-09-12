/* print caracteres - folha4 e5*/
#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao da variavel */
	int numero, auxiliar_coluna, auxiliar_linha;
	
	do {
		printf("Digite um numero no intervalo [1,20]: ");
		scanf("\n%d", &numero);
		
	} while ((numero>20)||(numero<1));
	
	for (auxiliar_linha=1; auxiliar_linha<=numero; auxiliar_linha+=1) {
		for (auxiliar_coluna=1; auxiliar_coluna<=numero; auxiliar_coluna+=1) {
			if ((auxiliar_linha == 1)||(auxiliar_linha == numero)||(auxiliar_coluna==1)||(auxiliar_coluna==numero)) printf("#");
			else printf(" ");
			}
		printf("\n");
		auxiliar_coluna = 0;
		}
	return 0;
}
