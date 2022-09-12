/* print caracteres/inteiros - folha3 e8 */
#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao da variavel */
	char caractere1;
	int ascii_n1;
	
	printf("DIGITE UM DIGITO DE 0 A 9: ");
	scanf("%c", &caractere1);
	
	ascii_n1 = (int) caractere1;
	
	switch ((ascii_n1 >= 48) && (ascii_n1 <= 57)) {
		case 1: printf("%c E UM DIGITO DE 0 A 9", caractere1); break;
		case 0: printf("%c NAO E UM DIGITO DE 0 A 9", caractere1);
	} 
	
	return 0;
}
