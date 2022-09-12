#include <stdio.h>

double somatab(double tab[], unsigned int n) {
	double soma = tab[0];
	
	for(int i=1; i<n; i++) {
		soma += tab[i];
		}
	
	return soma;
	}	

int main() {
	double r[] = {2.3, 4.2, 5.1, 3.2, 1.2};
	
	printf("a soma dos elementos da tabela eh: %lg", somatab(r, 5));
	
	return 0;
	}
