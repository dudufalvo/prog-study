#include <stdio.h>

unsigned int elimina(int tab[], unsigned int n, unsigned int k) {
	if (k>=n) return n;
	for(int i=k; i<n; i++) {
		tab[i]=tab[i+1];
		}
	tab[n-1]=0;
	
	return n-1;
	}

unsigned int semrepetidos(int tab[], unsigned int n) {
	int atual;
		
	for(int j=0; j<n; j++) {
		atual = tab[j];
		for(int i=j+1; i<n;) {
			if(atual == tab[i]) n = elimina(tab, n, i);
			else i++;
			}
		}
	return n;}

int fusao(int tab1[], unsigned int n1, int tab2[], int n2, int tabfusao[], int capacidade) {
	int nelem = 0;
	
	n1 = semrepetidos(tab1, n1);
	n2 = semrepetidos(tab2, n2);
	
	for(int i=0; i<capacidade; i++) {
		tabfusao[i]=tab1[i];
		nelem++;
		}
	for(int j=0; j<(capacidade-n1); j++) {
		tabfusao[n1+j]=tab2[j];
		nelem++;
		}
	
	return nelem;
  }

int main() {
	int t1[] = {1,2,3,4,4,4};
	int t2[] = {8,8,8,9,9,10};
	int tf[10];
	
	printf("n elementos: %d\n", fusao(t1, 6, t2, 6, tf, 10));
	
	for(int aux1=0; aux1<10; aux1++) {
		printf("%d ", tf[aux1]);
		}	
	
	return 0;
}
