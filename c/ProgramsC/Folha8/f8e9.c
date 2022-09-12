#include <stdio.h>
#include <ctype.h>

unsigned int tudoEmMaiusculasPPTR(char *linha, char ** pprim) {
	char *linha_ptr=linha;
	char aux;
	int count=0;
	**pprim = NULL;
	
	while(*linha_ptr!='\0') {
		aux = *linha_ptr;
		if (*linha_ptr != toupper(aux)) {
			*linha_ptr = toupper(*linha_ptr);
			if(count==0) pprim = &linha_ptr;
			count++;
			}
		linha_ptr++;
		}
	return count;
	}

int main() {
	char linha[100+1] = "1";
	char **pprim=linha;
	
	while (1) {
		linha[0] = '\0';
		
		printf("digite uma frase: ");
		scanf("%100[^\n]", linha);
		
		if (linha[0]=='\0') break;
		
		while(getchar()!='\n');
		
		tudoEmMaiusculasPPTR(linha, pprim);
			
		printf("%s\n", linha);
		}	
	
	return 0;
	}
