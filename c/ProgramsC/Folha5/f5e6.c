#include <stdio.h>

void triIsCheio(int num) {
	int linha, coluna;
	for(linha=1; linha<=num; linha+=1) {
		
		for(coluna=1; coluna<=linha; coluna+=1) {
			printf("%d", num);}
			
		coluna=0;
		printf("\n");}
	}

void triIsVazado(int num) {
	int linha, coluna;
	for(linha=1; linha<=num; linha+=1) {
		
		for(coluna=1; coluna<=linha; coluna+=1) {
			if (linha==num) printf("%d", num);
			else if ((coluna==1)||(coluna==linha)) printf("%d", num);
			else printf(" ");}
			
		coluna=0;
		printf("\n");}
	}

int main () {
	int valor=0, aux;
	
	while ((valor<1)||(valor>9)) {
		printf("digite um numero inteiro de  1 a 9: ");
		scanf("%d", &valor); }
	triIsCheio(valor);
	for(aux=1; aux<=valor; aux++) printf("-");
	printf("\n");
	triIsVazado(valor);
	
	return 0;}
