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

int menor(int tab[], unsigned int n) {
	int menor = tab[0];
	
	for(int i=1; i<n; i++) {
		if (tab[i]<=menor) menor = tab[i];
		}
	return menor;
	}

int main() {
	int tab[MAX_DIM];
	int n;
	int men;
	
	n = letab(tab, MAX_DIM);
	men = menor(tab, n);
	mostratab(tab, n);
	
	printf("\nmenor = %d", men);

	return 0;
}
