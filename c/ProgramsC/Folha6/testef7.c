#include <stdio.h>
#define MAX_DIM 20

int somatab(int tab[], unsigned int n) {
	int soma=tab[0];
	
	for(int i=1; i<n; i++) soma+=tab[i];
	
	return soma;
	}


double produtoInterno(double a[], double b[], unsigned int n) {
	int soma=0;
	
	for(int i=0; i<n; i++) soma+=(a[i]*b[i]);
	
	return soma;
	}

void somavetores(double a[], double b[], double c[], unsigned int n) {
	
	for(int i=0; i<n; i++) c[i] = (a[i] + b[i]);
	
	}

unsigned int elimina(int tab[], unsigned int n, unsigned int k) {
	
	for(int i=k; i<n; i++) tab[i]=tab[i+1];
	
	return n-1;
	}

unsigned int semrepetidos(int tab[], unsigned int n) {
	int atual=tab[0];
	
	for(int i=0; i<n; i++) {
		atual = tab[i];
		for(int j=i+1; j<n;) {
			if(atual==tab[j]) n = elimina(tab, n, j);
			else j++;
			}
		}
	return n;
	}

void inverte(int tab[], unsigned int n) {
	int aux=0;
	
	n-=1;
	
	for(int i=0; i<=n; i++) {
		aux=tab[i];
		tab[i]=tab[n];
		tab[n]=aux;
		n--;
		}
	}

unsigned int indicamaior(int tab[], unsigned int n) {
	int ind_maior=0;
	
	for(int i=0; i<n; i++){
		if(tab[ind_maior]<tab[i]) ind_maior = i;
		}
		
	return ind_maior;
	}

int maior(int tab[], unsigned int n) {
	int maior=tab[0];
	
	for(int i=1; i<n; i++) {
		if(maior<tab[i]) maior=tab[i];
		}
	
	return maior;
	}

int menor(int tab[], unsigned int n) {
	int menor=tab[0];
	
	for(int i=1; i<n; i++) {
		if(menor>tab[i]) menor=tab[i];
		}
	
	return menor;
	}

unsigned int letab(int tab[], unsigned int capacidade) {
	int max=0;
	
	do{
		printf("quantos valores quer preencher? [maior que zero e menor que %d] ", capacidade);
		scanf("%d", &max);
		} while((max<=0)||(max>capacidade));
	
	for(int i=0; i<max; i++) {
		printf("digite o %d valor: ", i+1);
		scanf("%d", &tab[i]);
		}
	return max;
	}

void mostratab(int tab[], unsigned int n) {
	for(int i=0; i<n; i++) printf("t[%d] = %d\n", i, tab[i]);
	}

int main() {
	int tab[MAX_DIM];
	int elem=0;
	//int indout=0;
	
	elem = letab(tab, MAX_DIM);
	mostratab(tab, elem);
	
	printf("a soma dos elementos eh: %d", somatab(tab, elem));
	
	/*printf("o maior elemento eh: %d\n", maior(tab, elem));
	printf("o indice do maior elemento eh: %d\n", indicamaior(tab, elem));
	
	inverte(tab, elem);
	mostratab(tab, elem);
	
	do{
		printf("digite o indice para ser retirado: [0 a %d] ", elem-1);
		scanf("%d", &indout);} while((indout<0)||(indout>elem-1));
	
	elem = elimina(tab, elem, indout);
	mostratab(tab, elem);
	
	printf("\n");
	
	elem = semrepetidos(tab, elem);
	mostratab(tab, elem);*/
	
	
	
	return 0;
}
