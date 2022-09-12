#include <stdio.h>

int menorVal(int a, int b) {
	// declaracao da variavel menor
	int menor = 0;
	
	// verificacao e retorno do menor parametro fornecido
	if (a<b) menor = a;
	else if (a>b) menor = b;
	else menor = a;
	
	return menor;
	}

int maiorVal(int c, int d) {
	// devlaracao da variavel maior
	int maior = 0;
	
	// verificacao e retorno do maior parametro fornecido
	if (c>d) maior = c;
	else if (c<d) maior = d;
	else maior = c;
	
	return maior;
	}

double mediaVal(int e, int f) {
	// declaracao da variavel media
	double media = 0.0;
	
	/* calculo e retorno da media dos parametros 
	 * fornecidos somando-os e dividindo por dois */
	media = ((double) (e+f))/2.0;
	
	return media;
	}

double variancia(int x1, int x2, double med) {
	// declaracao da variavel var (variancia)
	double var = 0.0;
	
	/* calculo da variancia entre os parametros 
	fornecidos pela equacao e seu retorno */
	var = (((x1-med)*(x1-med))+((x2-med)*(x2-med)))/2.0;
	
	return var;
	}

int main() {
	// iniciamos o bloco delcarando as variaveis
	int n1=0;
	int n2=0;
	int menor = 0;
	int maior = 0;
	double vm = 0.0;
	double var = 0.0;
	
	/* ciclo para pedir novamente as variaveis 
	 * caso elas nao satisfacao as condicoes de serem 
	 * diferentes, menores que zero e maiores que cinquenta */
	while ((n1==n2)||(n1<=0)||(n2<=0)||(n1>=50)||(n2>=50)) {
		
		// impressoes pedindo os valores e atribuindo as variaveis
		printf("digite um inteiro: ");
		scanf("%d", &n1);
		printf("digite outro inteiro: ");
		scanf("%d", &n2);
		
		// alerta de erro caso os valores nao sejam validos
		if ((n1==n2)||(n1<=0)||(n2<=0)||(n1>=50)||(n2>=50)) printf("valores invalidos\n");
		}
	
	// impressao dos valores apos validados
	printf("\nos valores dados sao: %d e %d\n", n1, n2);
	
	// chamada das funcoes e atribuicao nas respectivas variaveis
	menor = menorVal(n1, n2);
	maior = maiorVal(n1, n2);
	vm = mediaVal(n1, n2);
	var = variancia(n1, n2, vm);
	
	// impressao dos valores calculados pelas variaveis
	printf("menor = %d\n", menor);
	printf("maior = %d\n", maior);
	printf("media(vm) = %lg\n", vm);
	printf("variancia(var[%d,%d]) = %lg", n1, n2, var);
	
	return(0);
	}
