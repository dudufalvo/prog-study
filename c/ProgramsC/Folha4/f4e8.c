/* print caracteres - folha4 e8*/
#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao da variavel */
	int num, aux;

	num=0;
	while ((num<20)||(num>50)) {
		printf("DIGITE UM VALOR ENTRE 20 E 50: \n");
		scanf(" %d", &num);
	}
	for(aux=20; aux<200; aux+=1) {
		if (num%aux==0) printf(" %d", aux);
	}
	
	
	return 0;
}
