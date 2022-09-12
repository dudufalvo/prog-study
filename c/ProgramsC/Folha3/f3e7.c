/* print caracteres/inteiros - folha3 e7 */
#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao da variavel */
	char caractere1, caractere2, caractere3;
	int ascii_n1, ascii_n2, ascii_n3;
	
	printf("DIGITE 3 CARACTERES MINUSCULOS: ");
	scanf("%c", &caractere1);
	scanf(" %c", &caractere2);
	scanf(" %c", &caractere3);
	
	ascii_n1 = (int) caractere1;
	ascii_n2 = (int) caractere2;
	ascii_n3 = (int) caractere3;
	
	if (((ascii_n1 >= 97) && (ascii_n1 <= 122)) && ((ascii_n2 >= 97) && (ascii_n2 <= 122)) && ((ascii_n3 >= 97) && (ascii_n3 <= 122)))
	{
		if (ascii_n1 < ascii_n2) 
		{
			if (ascii_n2 < ascii_n3)
			{
				printf("%c %c %c", caractere1, caractere2, caractere3);
				}
			else
			{
				if (ascii_n1 < ascii_n3)
				{
					printf("%c %c %c", caractere1, caractere3, caractere2);
					}
				else 
				{
					printf("%c %c %c", caractere3, caractere1, caractere2);
					}
				}
			}
		else 
		{
			if (ascii_n2 < ascii_n3)
			{
				if (ascii_n1 < ascii_n3)
				{
					printf("%c %c %c", caractere2, caractere1, caractere3);
					}
				else
				{
					printf("%c %c %c", caractere2, caractere3, caractere1);
					} 
				}
			else
			{
				printf("%c %c %c", caractere3, caractere2, caractere1);
				}
			}
		}
	else 
	{
		printf("ERRO: NAO SAO TODOS CARACTERES MINUSCULOS");
		}
	
	return 0;
}
