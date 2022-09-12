#include <stdio.h>
#include <math.h>

double retPerimetro(double largura, double comprimento) {
	/* funcao que calcula o perimetro do quadrado a partir de 
	* dois parametros (largura e comprimento) fornecidos */
	double perimetro=0.0;
	
	perimetro = (2*largura) + (2*comprimento);
	
	return perimetro;
	}
	
double retArea(double largura, double comprimento) {
	/* funcao que calcula a area do retangulo 
	 * a partir da largura e do comprimento*/
	return (largura*comprimento);
	}

int main () {
	// definicao e declaracao das variaveis
	double larg=1.0, compr=1.0;
	
	/* ciclo que se repete ate que o valor 
	 * atribuido as variaves sejam maiores que zero */
	while ((larg>0)&&(compr>0)) {
		printf("digite a largura: ");
		scanf("%lg", &larg);
		printf("digite o comprimento: ");
		scanf("%lg", &compr);
		
		printf("perimetro = %lg\n", retPerimetro(larg, compr));
		printf("area = %lg\n", retArea(larg, compr));
		}
	
	return 0;
	}
