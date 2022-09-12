/* print caracteres - folha4 e7*/
#include <stdio.h>
#include <float.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao da variavel */
	char sinal, aux, num1, num2;
	
	aux = 0;
	while (aux==0) {
	
	printf("DIGITE UMA OPERACAO VALIDA: ");
	scanf("%c", &sinal);
	printf("DIGITE DOIS NÚMEROS A, B: ");
	scanf(" %g", &num1);
	scanf(" %g", &num2);
	
	switch (sinal) {
		case '+': {
			printf("%g + %g = %g", num1, num2, num1+num2);
			aux = 1;
			break;
			}
		case '-': {
			printf("%g - %g = %g", num1, num2, num1-num2);
			aux=1;
			break;
			}
		case '*': 
			{ printf("%g * %g = %lg", num1, num2, DBL_MIN); 
			  aux=0;
			  break;
		case '/':{
			if (num2!=0.0) printf("%g / %g = %g", num1, num2,num1/num2); 
			else {
				if (num1>0.0) printf("%lg", DBL_MAX);
				else if (num1<0) printf("%lg", DBL_MIN);
				else printf("0.0");
			aux=0;
			break;
			}
		}
		default: printf("OPERCAO INVALIDA. TENTE DE NOVO.");
		}
	}
}
	return 0;
}
