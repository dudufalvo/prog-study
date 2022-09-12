#include <stdio.h>		/* definicao da biblioteca */

int main()		/* definicao e inicio do bloco */
{	
	int num, aux_i, aux_j;
	
	do {
	printf("DIGITE UM NUMERO DE 1 A 9: ");
	scanf("%d", &num);
}	while ((num<=1)||(num>=9));

	for (aux_j=1; aux_j<=num; aux_j+=1) {
		for (aux_i=1; aux_i<=num; aux_i+=1) {
			printf("%d",aux_j);
			}
		aux_i = 0;
		printf("\n");
		}
	
	return 0;
}
