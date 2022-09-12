/* print caracteres - folha4 e6*/
#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao da variavel */
	int num, aux;

	printf("Digite um numero no intervalo [2,9]: ");
	scanf("\n%d", &num);
	
	if ((num>=2)&&(num<=9)) {
		for (aux=1; aux<=10; aux+=1){
			if (aux<10) {
				printf("%d x  %d = ", num, aux);
				if (num*aux<10) printf(" %d\n", num*aux);
				else printf("%d\n", num*aux); }
			else printf("%d x %d = %d\n", num, aux, num*aux);
			}
	}
	else printf("Valor invalido!");
	
	return 0;
}
