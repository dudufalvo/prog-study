#include <stdio.h>

void linha(int k, char s) {
	if (k>=1) {
		for(int aux=1; aux<=k; aux++) {
			printf("%c", s);
			}
		printf("\n");}
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
	
	linha(num,letra);
	
	return 0;
	}
