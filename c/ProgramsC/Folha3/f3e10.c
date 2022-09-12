/* print caracteres/inteiros - folha3 e10 */
#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao da variavel */
	char caractere;
	int ascii_number;
	
	printf("DIGITE UM CARACTERE: ");
	scanf("%c", &caractere);
	
	ascii_number = (int) caractere;
	
	if ((ascii_number >= 65) && (ascii_number <= 90))
	{
		printf("%c = CARACTERE MAIUSCULO", caractere);
		}
	else 
	{
		printf("NAO E UM CARACTERE MAIUSCULO");
		}
	
	return 0;
}
