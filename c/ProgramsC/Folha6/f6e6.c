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

unsigned int elimina(int tab[], unsigned int n, unsigned int k) {
	if (k>=n) return n;
	for(int i=k; i<n; i++) {
		tab[i]=tab[i+1];
		}
	tab[n-1]=0;
	
	return n-1;
	}

unsigned int semrepetidos(int tab[], unsigned int n) {
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; ){
			if (tab[j]==tab[i]) n = elimina(tab, n, j);
			else j++;}
		}
	return n;
	}

int main() {
	int tab[MAX_DIM];
	int num;
	
	num = letab(tab, MAX_DIM);
	num = semrepetidos(tab, num);
	mostratab(tab, num);	
	
	return 0;
	}
