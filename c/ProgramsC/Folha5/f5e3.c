#include <stdio.h>
#include <math.h>

int teto(double x) {
	/* funcao que, recebido um valor x, calcula o seu teto*/
	double dif=0.0;
	
	// caso x seja negativo, seu teto e encontrado convertendo para inteiro
	if (x<0) x =(int)x;
	
	// caso x seja positivo
	else {
		// separamos a parte decimal do double fornecido
		dif = x-((int) x);
		
		/* verificamos se de fato ha parte decimal e, se nao, 
		 * sobreescrevemos x para ele mesmo no formato inteiro (seu teto) */
		if (dif==0.0) x = (int) x;
		
		/* caso haja parte decimal, o teto e o double 
		 * subtraido sua parte decimal e convertido para inteiro */
		else x = (int) ((x-dif)+1);
		}
	return x;
	}


int main () {
	// definicao e declaracao das variaveis
	double num=0.0;
	int vfinal=0;
	
	printf("digite um numero: ");
	scanf("%lg", &num);
	
	vfinal = teto(num);
	
	printf("%lg por math.h = %lg \n", num, ceil(num));
	printf("%lg por teto = %d", num, vfinal);
	
	return 0;
	}
