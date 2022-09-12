#include <stdio.h>
#include <ctype.h>

void entrelaca(char a[], char b[], char f[], unsigned capacidade) {
	int k=0;
	int i=0;
	
	while(b[k]!='\0'){
		f[k*2+1] = b[k];
		k++;
		}
	
	while(a[i]!='\0') {
		f[i*2] = a[i];
		i++;
		}
	}

int main() {
	int capacidade = 100;
	
	while (1) {
		char stra[] = "";
		char strb[] = "";
		char strf[100+1] = "1";
		
		printf("digite a primeira frase: ");
		scanf("%100[^\n]", stra);
		
		if (stra[0]=='\0') break;
		
		while(getchar()!='\n');
		
		printf("digite outra frase: ");
		scanf("%100[^\n]", strb);
		
		if (strb[0]=='\0') break;
		
		while(getchar()!='\n');
		
		entrelaca(stra, strb, strf, capacidade);
		
		printf("%s\n", strf);
		}
			
	return 0;
}
