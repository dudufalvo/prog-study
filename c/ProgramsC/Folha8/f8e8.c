#include <stdio.h>
#define PI 3.14159265359

int esfera(double raio, double *parea, double *pvolume) {
	*parea = 4*PI*raio*raio;
	*pvolume = 4*PI*raio*raio*raio/3;
	
	if (raio>=0) return 0;
	else return -1;
	}

int main() {
	double area;
	double *area_ptr=&area;
	double vol;
	double *vol_ptr=&vol;
	double raio;
	int res;
	
	printf("digite o raio da esfera: ");
	scanf("%lg", &raio);
	
	res = esfera(raio, area_ptr, vol_ptr);
	
	if(res==0) {
		printf("area = %lg\n", area);
		printf("volume = %lg", vol);
		}
	else printf("erro = raio invalido");
	
	return 0;
	}
