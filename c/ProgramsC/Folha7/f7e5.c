#include <stdio.h>
#include <string.h>
/*
void mostraInvertida(char linha[]) {
	int len=0;
	
	while(linha[len]!='\0') {
		len++;
		}
	len-=1;
	for(int i=len; i>=0; i--) printf("%c", linha[i]);
	}
*/
void mostraInvertida(char linha[]) {
	int len=0;
	while(linha[len]!='\0') len++;
	len--;
	while(len>=0) {
		printf("%c", linha[len]);
		len--;}
	}
/*
void inverte(char linha[]) {
	int len=0;
	char aux;
	
	while(linha[len]!='\0') {
		len++;
		}
		
	len-=1;
	
	for(int i=0; i<len; i++) {
		aux = linha[i];
		linha[i] = linha[len];
		linha[len] = aux;
		len-=1;
		}
	}
*/

void inverte(char linha[]) {
	int len=0;
	char aux;
	
	while(linha[len]!='\0'){
		len++;
		}
	len--;
	for(int n=0; n<len; n++) {
		aux = linha[n];
		linha[n]=linha[len];
		linha[len]=aux;
		len--;
		}
}

int main() {
	while (1) {
		char str[] = "";
		
		printf("digite uma frase para inverter:");
		scanf("%100[^\n]", str);
		
		if(str[0]=='\0') break;
		
		mostraInvertida(str);
		printf("\n");
		
		inverte(str);
		
		printf("%s\n", str);
		
		while(getchar()!='\n');
	}		
	
	return 0;
	}
	

