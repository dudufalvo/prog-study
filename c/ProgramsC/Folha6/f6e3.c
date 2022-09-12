#include <stdio.h>

unsigned int indicamaior(int tab[], unsigned int n) {
	int num=tab[0];
	int maior=0;
	
	for(int aux=1; aux<n; aux++) {
		if (tab[aux] > num){ 
			num=tab[aux]; 
			maior=aux;}
	}
	return maior;
	}

int main() {
	int t[] = {2, 4, 5, 3, 9};
	int num_el=5;
	printf("o maior indice eh: %d", indicamaior(t, num_el));
	}

/*
 #include <stdio.h>

unsigned int indicamaior(int tab[], unsigned int n) {
	int maior_val=tab[0];
	int maior_ind=0;
	
	for(int i=0; i<n; i++){
		if(maior_val<tab[i]) {
			maior_val = tab[i];
			maior_ind=i;}
		}
	return maior_ind;
	}

int main() {
	int t[] = {2, 4, 5, 3, 1};
	int tam = sizeof(t)/sizeof(int);
	
	printf("maior indice: %d", indicamaior(t, tam));
	
	return 0;
	}
 */
