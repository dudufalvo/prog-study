/* print caracteres - folha3 e1*/
#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao da variavel */
	int numero_impar, auxiliar_while, auxiliar_for;
	numero_impar = 1;
	
	/* inicia o while com numero_impar atribuido a 1 e solicita que o 
	 usuario digite um valor ate este ser impar e diferente que 1 */
	while ((numero_impar%2 != 1)||(numero_impar == 1)) {
		/* impressao, leitura e atribuicao de um valor a variavel */
		printf("Digite um numero impar maior do que 1: ");
		scanf("%d", &numero_impar);
		}
	/* cria-se uma variavel auxiliar atribuida inicialmente a 0 e imprimi
	 * o numero impar ate auxiliar chegar em numero_impar*/
	auxiliar_while = 0;
	printf("\n (a) Usando while \n");
	while (auxiliar_while < numero_impar) {
		printf("%d ", numero_impar);
		auxiliar_while += 1;
		}
	
	/* cria-se uma variavel auxiliar atribuida inicialmente a 0 e imprimi
	 * o numero impar ate auxiliar chegar em numero_impar*/
	printf("\n (b) Usando for \n");
	for (auxiliar_for=0; auxiliar_for<numero_impar; auxiliar_for+=1) {
		printf("%d ", numero_impar);
		}
	
	return 0;
}
