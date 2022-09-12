#include <stdio.h>
#define MAX_DIM 20

void mostratab(int tab[], unsigned int n) {
	for(int aux1=0; aux1<n; aux1++) {
		printf("%d ", tab[aux1]);
		}
	}

unsigned int letab(int tab[], unsigned int capacidade) {
	int max;
	int valor;
	
	do {
		printf("quantos numeros quer preencher? ");
		scanf("%d", &max);} while((max<=0)||(max>capacidade));
	
	for(int aux=0; aux<max; aux++) {	
		printf("digite um valor: ");
		scanf("%d", &valor);
		tab[aux]=valor;
		}

	return max;
	}

int main() {
	int tab[MAX_DIM];
	int num;
	
	num = letab(tab, MAX_DIM);
	mostratab(tab, num);	
	
	return 0;
	}

/*
#include <stdio.h>
#define MAX_DIM 20

unsigned int letab(int tab[], unsigned int capacidade) {
	int val = 0;
	int max = 0;
	
	do {
		printf("quantos numeros quer preencher? ");
		scanf("%d", &max);} while((max<=0)||(max>capacidade));
	
	for(int i=0; i<max; i++) {
		printf("digite um valor: ");
		scanf(" %d", &val);
		tab[i] = val;
		}
	return max;
	}

void mostratab(int tab[], unsigned int n) {
	for(int i=0; i<n; i++) {
		printf("\ntab[%d]=%d", i, tab[i]);
		}
	}

int main() {
	int tab[MAX_DIM];
	int num;
	
	num = letab(tab, MAX_DIM);
	mostratab(tab, num);	
	
	return 0;
	}*/
