/* print caracteres/inteiros - folha3 e6 */
#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao da variavel */
	char caractere;
	int ascii_number;
	
	printf("DIGITE UM CARACTERE: ");
	scanf("%c", &caractere);
	
	ascii_number = (int) caractere;
	
	if ((ascii_number >= 97) && (ascii_number <= 122))
	{
		printf("%c = CARACTERE MINUSCULO", caractere);
		}
	else 
	{
		printf("NAO E UM CARACTERE MINUSCULO");
		}
	
	return 0;
}
