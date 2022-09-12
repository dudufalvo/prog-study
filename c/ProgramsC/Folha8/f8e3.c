#include <stdio.h>
#include <stdbool.h>

int eh_primo(unsigned int n) {
	for(int i=2; i<=n/2; i++) {
		if(n%i != 0) continue;
		else return 1;
		}
	return 0;
}

int main() {
	unsigned int val;
	int res;
	
	do{
		printf("digite um inteiro positivo: ");
		scanf("%ud", &val);} while(val<0);
	
	res = eh_primo(val);
	
	if (res==0) printf("primo\n");
	else printf("nao primo\n");	
		
	for(int i=2; i<= val; i++){
		res = eh_primo(i);
		if(res==0) printf("%d ", i);
		}
	
	return 0;
	}
