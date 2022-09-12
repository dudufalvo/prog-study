#include <stdio.h>

int maior(int tab[], unsigned int n) {
	int num=tab[0];
	
	for(int aux=1; aux<n; aux++) {
		if (tab[aux] > num) num=tab[aux];}
	
	return num;
	}

int main() {
	int t[] = {78, 4, 5, 93, 1};
	printf("o maior eh: %d", maior(t, 5));
	}

/*
 #include <stdio.h>

int maior(int tab[], unsigned int n) {
	int maior_val = tab[0];
	
	for(int i=0; i<n; i++){
		if(tab[i]>maior_val) maior_val = tab[i];
		}
	return maior_val;
	}

int main() {
	int t[] = {2, 24, 5, 3, 144};
	int tam = sizeof(t)/sizeof(int);
	
	printf("o maior valor da tabela eh: %d", maior(t, tam));
	
	return 0;
	}
 */
