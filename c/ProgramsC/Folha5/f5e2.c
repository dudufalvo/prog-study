#include <stdio.h>

void linha(int k, char s) {
	if (k>=1) {
		for(int aux=1; aux<=k; aux++) {
			printf("%c", s);
			}
		printf("\n");}
	}

void quadrado(int d, char s) {
	for(int aux2=1; aux2<=d; aux2++) {
		linha(d,s);
		}
	}

int main () {
	int num=0;
	char letra;
	
	while((num<1)||(num>20)) {
		printf("digite um numero de [1,20]: ");
		scanf("%d", &num);
		}
	
	printf("digite uma letra: ");
	scanf(" %c", &letra);
	
	quadrado(num,letra);
	
	return 0;
	}
