#include <stdio.h>
#include <ctype.h>

unsigned int tudoEmMaiusculas(char linha[]) {
	int aux = 0;
	unsigned int soma = 0;
	
	while(linha[aux]!='\0') {
		if ((linha[aux]>='a')&&(linha[aux]<='z')) {
			linha[aux] = toupper(linha[aux]);
			soma+=1;
			}
		aux+=1;
		}
	return soma;
	}

int main() {
	char lista[50+1];
	unsigned int count=0;
	
	printf("digite um caractere ou nada para terminar: ");
	scanf("%50[^\n]", lista);
	
	count = tudoEmMaiusculas(lista);
	printf("%d: %s", count, lista);

}
