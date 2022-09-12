#include <stdio.h>

double Func1(int tab[], int N, int *Vmin, int *Vmax) {
	// declara variaveis vmed e soma
	double Vmed=0.0;
	int soma=0;
	
	// for para varrer a tabela do primeiro elemento ao ultimo
	for(int i=0; i<N; i++) {
		// incrementa a soma e altera o valor dos endereços maior e menor pelos ponteiros
		soma+=tab[i];
		if(tab[i]>*Vmax) *Vmax=tab[i];
		if(tab[i]<*Vmin) *Vmin=tab[i];
		}
	// calcula a media
	Vmed = (double)soma/ (double) N;
	return Vmed;
}

int Func2(char Str[], char caracter) {
	// declara variaveis vmed e soma
	int numUP=0;
	
	// while para varrer a string ate o fim
	while(*Str!='\0'){
		if(*Str=='n') *Str=caracter;
		if((*Str>='A')&&(*Str<='Z')) numUP++;
		Str++;
		}
	// retorna numero de maiusculas
	return numUP;
	}

int main() {
	// declara variaveis e ponteiros
	int tab1[] = {0, -1, 2, -3, 4, -5, 6, -7, 8, -9, 10};
	int lenT1 = (int) sizeof(tab1)/sizeof(int);
	char tab2[] = {'E', 'n', 'g', 'e', 'n', 'h', 'a', 'r', 'i', 'a', 'D', 'E', 'E', 'C'};
	int numUP=0;
	int maior=0;
	int menor=0;
	double media=0;
	int *ptr_maior=&maior;
	int *ptr_menor=&menor;
	
	// acha a media, minimo e maximo a partir da funcao
	media = Func1(tab1, lenT1, ptr_menor, ptr_maior);
	
	printf("a media = %lg\n", media);
	printf("o valor maximo = %d\n", maior);
	printf("o valor minimo = %d\n", menor);
	
	printf("a string normal = %s\n", tab2);
	
	// acha o numero de maiusculas
	numUP = Func2(tab2, 'w');
	
	printf("a string modificada = %s\n", tab2);
	printf("numero de maiusculas = %d", numUP);
	
	return 0;
}
