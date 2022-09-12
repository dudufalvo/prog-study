#include <stdio.h>
int intervalo(int tab[], unsigned int n, int *pmaior, int * pmenor) {
	int soma = *tab;
	*pmaior = *tab;
	*pmenor = *tab;
	
	for(int i=1; i<n; i++) {
		soma += tab[i];
		if (*pmaior<tab[i]) *pmaior=tab[i];
		if (*pmenor>tab[i]) *pmenor=tab[i];
		}
	return (int) (double) soma / (double) n;
}

int main() {
	int maior, menor;
	int *maior_ptr=&maior;
	int *menor_ptr=&menor;
	int t[] = {2, 4, 5, -3, 1};
	int lentab = sizeof(t)/sizeof(int);
	int med;
	
	med = intervalo(t, lentab, maior_ptr, menor_ptr);
	
	printf("maior = %d\n", maior);
	printf("menor = %d\n", menor);
	printf("media = %d\n", med);
	
	return 0;
}
