#include <stdio.h>
int cubo(double aresta, double *parea, double *pvolume) {

	*parea = (aresta)*(aresta)*6;
	*pvolume = (aresta)*(aresta)*(aresta);
	
	if (aresta>=0) return 0;
	else return -1;
	}

int main() {
	double valor;
	double area;
	double volume;
	double *area_ptr=&area;
	double *vol_ptr=&volume;
	int ret;
	
	printf("digite o valor da aresta: ");
	scanf("%lg", &valor);
	
	ret = cubo(valor, area_ptr, vol_ptr);
	
	printf("area: %lg", *area_ptr);
	printf("\nvolume: %lg", *vol_ptr);
	printf("\n%d", ret);
	
	return 0;
	}
