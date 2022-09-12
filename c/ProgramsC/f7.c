#include <stdio.h>
#include <ctype.h>
#include <string.h>

unsigned int tudoEmMaiusculas(char linha[]) {
	int i=0;
	while(linha[i]!='\0'){
		linha[i]=toupper(linha[i]);
		i++;
		}
	return i;
	}

void mudaletras(char linha[], char c, unsigned int k) {
	int i=0;
	while(linha[i]!='\0'){
		if(i%k==0) linha[i]=c;
		i++;
		}
	}

void seguidoComAux(char linha[]) {
	int i=0;
	int j=0;
	char aux[100];
	while(linha[i]!='\0') {
		if(linha[i]!=' ') {
			aux[j]=linha[i];
			j++;}
		i++;
		}
	strcpy(linha, aux);
	}

void seguido(char linha[]) {
	int i=0;
	int j=0;
	
	while(linha[i]) {
		if(linha[i]!=' ') {
			linha[j]=linha[i];
			j++;}
		i++;
		}
	linha[j]='\0';
	}

int main() {
	
	return 0;
	}
