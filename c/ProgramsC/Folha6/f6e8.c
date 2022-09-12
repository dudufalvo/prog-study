#include <stdio.h>

double produtoInterno(double a[], double b[], unsigned int n) {
	double prod = (a[0]*b[0]);
	
	for(int i=1; i<n; i++) {
		prod = prod + (a[i]*b[i]);
		}
	
	return prod;
	}

int main() {
	double a[] = {1, 2, 1};
	double b[] = {0, 1, 3};
	int n = sizeof(b)/sizeof(int);
	
	printf("produto interno de a e b eh: %lg", produtoInterno(a, b, n));
	
	return 0;
	}
