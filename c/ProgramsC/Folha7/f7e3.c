#include <stdio.h>
#include <ctype.h>
#include <string.h>

void seguidoComAux(char linha[]) {
	char aux[100+1] = "0";
	int n = 0;
	int j = 0;
	
	while (linha[n]!='\0') {
		if (linha[n]!=' ') {
			aux[j] = linha[n];
			j+=1;}
		n+=1;
		}
	strcpy(linha, aux);
}

void seguido(char linha[]) {
	int i=0;
	int j=0;
	
	while (linha[i]) {
		if (linha[i]!=' ') {
			linha[j] = linha[i];
			j+=1;}
		i+=1;}
	linha[j] = '\0';
}

int main() {
	int aux = 1;
	char linha[100+1] = "1";
	
	while (aux) {
		linha[0] = '\0';
		
		printf("digite uma frase: ");
		scanf("%100[^\n]", linha);
		
		if (linha[0]=='\0') break;
		
		while(getchar()!='\n');
		
		seguido(linha);
		
		printf("%s\n", linha);
		}	
}
