#include <stdio.h>
#define MAX_DIM 20

void mostratab(int tab[], unsigned int n) {
	for(int aux1=0; aux1<n; aux1++) {
		printf("%d ", tab[aux1]);
		}
	}

unsigned int elimina(int tab[], unsigned int n, unsigned int k) {
	int indc;
	int elem=n;
	
	do {
		printf("\nqual indice quer tirar? ");
		scanf("%d", &indc);} while((indc<0)||(indc>k));
	
	for(int aux=0; aux<=n-1; aux++) {
		if ((aux>=indc)&&(aux+1<=n-1)) tab[aux]=tab[aux+1];
		else if (aux==n-1) tab[aux]=0;
		}

	
	return elem-=1;}
	
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
	int indc;
	
	num = letab(tab, MAX_DIM);
	mostratab(tab, num);
	num = elimina(tab, num, indc);
	mostratab(tab, num);
	printf("\nelementos: %d", num);
	return 0;
	}

/*
 #include <stdio.h>
#define MAX_DIM 20

unsigned int elimina(int tab[], unsigned int n, unsigned int k) {
	if (k>=n) return n;
	for(int i=k; i<n; i++) {
		tab[i]=tab[i+1];
		}
	tab[n-1]=0;
	
	return n-1;
	}

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
	int elim;
	
	num = letab(tab, MAX_DIM);
	
	printf("qual indice quer eliminar: ");
	scanf(" %d", &elim);
	
	num = elimina(tab, num, elim);
	mostratab(tab, num);	
	
	return 0;
	}
 */
