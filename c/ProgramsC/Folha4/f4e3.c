/* print caracteres - folha4 e3*/
#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao da variavel */
	int numero, auxiliar;
	
	do {
		printf("Digite um numero no intervalo [1,20]: ");
		scanf("\n%d", &numero);
		
	} while ((numero>20)||(numero<1));
	
	for (auxiliar=0; auxiliar<numero; auxiliar+=1) {
		printf("#");
		}
		
	return 0;
}
