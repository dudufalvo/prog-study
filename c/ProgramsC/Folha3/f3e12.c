/* print caracteres/inteiros - folha3 e12 */
#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	/* declaracao da variavel */
	char caractere;
	int ascii_number;
	
	printf("DIGITE UM CARACTERE: ");
	scanf("%c", &caractere);
	
	ascii_number = (int) caractere;
	
	if ((ascii_number == 33)||(ascii_number == 44)||(ascii_number == 46)||(ascii_number == 58)||(ascii_number == 59)||(ascii_number == 63)){
		printf("if else: '%c'  EH SINAL DE PONTUACAO\n", caractere);
		}
	else {
		printf("if else: '%c' NAO EH UM SINAL DE PONTUACAO\n", caractere);
		}
	switch (caractere){
		case '.': printf("switch: '%c'  EH SINAL DE PONTUACAO", caractere); break;
		case ',': printf("switch: '%c'  EH SINAL DE PONTUACAO", caractere); break;
		case ':': printf("switch: '%c'  EH SINAL DE PONTUACAO", caractere); break;
		case ';': printf("switch: '%c'  EH SINAL DE PONTUACAO", caractere); break;
		case '?': printf("switch: '%c'  EH SINAL DE PONTUACAO", caractere); break;
		case '!': printf("switch: '%c'  EH SINAL DE PONTUACAO", caractere); break;
		default: printf("switch: '%c' NAO EH SINAL DE PONTUACAO", caractere);
		}
	return 0;
}
