/* print caracteres/inteiros - folha3 e11 */
#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao da variavel */
	char caractere;
	int ascii_number;
	
	printf("DIGITE UM CARACTERE: ");
	scanf("%c", &caractere);
	
	ascii_number = (int) caractere;
	
	if (((ascii_number >= 65) && (ascii_number <= 90)) || ((ascii_number >= 97) && (ascii_number <= 122)))
	{
		printf("%c = LETRA", caractere);
		}
	else if ((ascii_number >= 48) && (ascii_number <= 57)) {
		printf("%c = DIGITO", caractere);
	}
	else 
	{
		printf("NAO E UMA LETRA NEM UM DIGITO");
		}
	
	return 0;
}
