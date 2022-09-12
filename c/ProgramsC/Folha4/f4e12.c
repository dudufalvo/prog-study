#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	int valor;
	unsigned short int iva;
	
	do {
	printf("DIGITE O VALOR DO PRODUTO: ");
	scanf("%d", &valor);
}	while (valor<=0); printf("O custo do produdo tem de ser maior do que zero. Repita!");

	do {
	printf("DIGITE O IVA: ");
	scanf("%hu", &iva);
}	while ((iva<0)||(iva>23)); printf("O IVA tem de estar no intervalo [0,23]. Repita!");

	printf("Ilíquido:    %d", valor);
	printf("IVA(%hu%%):     %g", iva, valor*(iva/100));
	printf("Total:       %g", valor+(valor*(iva/100)));
	
	return 0;
}


