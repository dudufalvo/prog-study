#include <stdio.h>

int menor(int tab[], unsigned int n) {
	int menor=tab[0];
	
	for(int i=0; i<n; i++) {
		if(menor>tab[i]) menor=tab[i];
		}
	return menor;
	}

double somatab(double tab[], unsigned int n) {
	int soma=tab[0];
	
	for(int i=1; i<n; i++) soma+=tab[i];
	
	return soma;
	}

double produtoInterno(double a[], double b[], unsigned int n) {
	double prodint=0;
	
	for(int i=0; i<n; i++) prodint+=(a[i]*b[i]);
	
	return prodint;
	}

void somavetores(double a[], double b[], double c[], unsigned int n) {
	for(int i=0; i<n; i++) c[i]=a[i]+b[i];
	}

unsigned int elimina(int tab[], unsigned int n, unsigned int k) {
	if (k>=n) return n;
	for(int i=k; i<n; i++) {
		tab[i] = tab[i+1];
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


void inverte(double tab[], unsigned int n) {
	double aux;
	
	for(int i=0; i<n; i++) {
		aux = tab[i];
		tab[i] = tab[n-1];
		tab[n-1] = aux;
		n--;
		}
	}

unsigned int indicamaior(int tab[], unsigned int n) {
	int maior_el=0;
	
	for(int i=1; i<n; i++) {
		if(tab[maior_el]<tab[i]) maior_el = i;
		}
	return maior_el;
	}

int maior(int tab[], unsigned int n) {
	int maior=tab[0];
	
	for(int i=1; i<n; i++) {
		if(maior<tab[i]) maior = tab[i];
		}
	return maior;
	}

unsigned int letab(int tab[], unsigned int capacidade) {
	int max;
	int elem;
	
	do {
		printf("quantos numeros: ");
		scanf("%d", &max);
		}while((max<0)||(max>capacidade));
	
	for(int i=0; i<max; i++) {
		printf("elemento [%d]: ", i);
		scanf("%d", &elem);
		tab[i] = elem;
		}
	return max;
	}
	
void mostratab(int tab[], unsigned int n) {
	for(int i=0; i<n; i++) printf("t[%d] = %d", i, tab[i]);
	}

int fusao(int tab1[], unsigned int n1, int tab2[], int n2,
		  int tabfusao[], int capacidade) {
	
			  
	}

int main() {
	
	return 0;
	}
