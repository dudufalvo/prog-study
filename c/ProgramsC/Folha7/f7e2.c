#include <stdio.h>
#include <ctype.h>

void mudaletras(char linha[], char c, unsigned int k) {
	int aux = 0;
	
	while(linha[aux]!='\0') {
		if ((aux!=0)&&(aux%k==0)) linha[aux] = c;
		aux+=1;
		}
}

int main() {
	int aux = 1;
	char linha[100+1] = "1";
	char car = ' ';
	int ind = 0;
	
	while (aux) {
		linha[0] = '\0';
		
		printf("digite uma frase: ");
		scanf("%100[^\n]", linha);
		
		if (linha[0]=='\0') break;
		
		printf("digite um caractere: ");
		scanf(" %c", &car);
		
		printf("digite um indice: ");
		scanf("%d", &ind);
		
		while(getchar()!='\n');
		
		mudaletras(linha, car, ind);
		
		printf("%s\n", linha);
		}	
}
