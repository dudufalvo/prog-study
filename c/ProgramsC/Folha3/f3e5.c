/* print caracteres/inteiros - folha3 e5 */
#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao da variavel */
	double real_n1;
	double real_n2;
	double minimo;
	
	/* impressao, leitura e atribuicao de um valor a variavel */
	printf("Digite um real: ");
	scanf("%lg", &real_n1);
	printf("Digite outro real: ");
	scanf("%lg", &real_n2);
	
	if (real_n1 < real_n2) {
		minimo = real_n1;
		}
	else {
		minimo = real_n2;
		}
	
	printf("Usando um if else, min(%lg, %lg) = %lg", real_n1, real_n2, minimo);
	printf("\nAgora usando o operador ternario, min(%lg, %lg) = %lg",real_n1, real_n2, real_n1 < real_n2? real_n1 : real_n2 );
	return 0;
}
