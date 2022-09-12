/* print caracteres - folha4 e2*/
#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao da variavel */
	char letra;
	int codigo_ascii;
	
	do
	{
		printf("Digite uma letra minuscula: \n");
		scanf(" %c", &letra);
		codigo_ascii = (int) letra;
		
	} while ((letra<'a')||(letra>'z'));
	
	printf("Digitou '%c' e o seu codigo ASCII vale %d na base 10.\n", letra, codigo_ascii);
	printf("A letra dada foi '%c' e a sua maiuscula vale '%c'.\n", letra, (char) (codigo_ascii-32));
	
	return 0;
}
