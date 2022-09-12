#include <stdio.h>

int intervalo(int tab[], unsigned int n, int *pmaior, int * pmenor) {
	int soma=0;
	//int *tab_ptr=tab;
	*pmaior=*tab;
	*pmenor=*tab;
	/*
	while(tab_ptr<tab+n) {
		soma += *tab_ptr;
		if(*tab_ptr>*pmaior) *pmaior=*tab_ptr;
		if(*tab_ptr<*pmenor) *pmenor=*tab_ptr;
		
		tab_ptr++;
		}*/
		
	for(int i=0; i < n; i++, tab++) {
		soma+=*tab;
		if(*tab>*pmaior) *pmaior=*tab;
		if(*tab<*pmenor) *pmenor=*tab;
		}
		
	return (int) (((double)soma/(double)n)+0.5);
	}

int main() {
	int maior;
	int menor;
	int media=0;
	int *maior_ptr=&maior;
	int *menor_ptr=&menor;
	
	int t[5] = {1, 2, 3, 4, 8};
	int lent = sizeof(t)/sizeof(int);
	
	media = intervalo(t, lent, maior_ptr, menor_ptr);
	
	printf("maior = %d\n", maior);
	printf("menor = %d\n", menor);
	printf("%d", media);
	
	return 0;
	}
