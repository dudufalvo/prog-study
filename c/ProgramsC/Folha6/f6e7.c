#include <stdio.h>

void somavetores(double a[], double b[], double c[], unsigned int n) {
	
	for(int aux=0; aux<=n-1; aux++) {
		c[aux] = a[aux] + b[aux];
		}
	
	}

int main() {
	double taba[] = {1,2,3};
	double tabb[] = {4,5,6};
	double tabc[3] = {};
	int num = 3;
	
	somavetores(taba, tabb, tabc, num);
	for(int aux=0; aux<=num-1; aux++) printf("%lg ", tabc[aux]);
	
	return 0;
	}
