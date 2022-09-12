#include <stdio.h>

int leitorDig(char carac) {
	
	if ((carac>='0')&&(carac<='9')) return 1;
	else return 0;
	}
	
int leitorMin(char carac) {
	
	if ((carac>='a')&&(carac<='z')) return 1;
	else return 0;
	}

int leitorMai(char carac) {
	
	if ((carac>='A')&&(carac<='Z')) return 1;
	else return 0;
	}
	
int leitorLet(char carac) {
	
	if (((carac>='a')&&(carac<='z'))||((carac>='A')&&(carac<='Z'))) return 1;
	else return 0;
	}

int main () {
	// definicao e declaracao das variaveis
	char caractere='.';
	
	while (caractere!='#') {
		
		printf("digite um caractere ou # para terminar: ");
		scanf(" %c", &caractere);
		
		if (caractere!='#') {
			if (leitorDig(caractere)) printf("%c eh digito\n", caractere);
			else if (leitorLet(caractere)) printf("%c eh letra\n", caractere);
			else printf("%c nao eh digito nem letra\n", caractere);
		}
	}
	return 0;}
