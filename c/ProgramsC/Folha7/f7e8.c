#include <stdio.h>

int contaPalavras(char str[]) {
	int i=0;
	int num;
	if ((str[0]!='\0')&&(str[0]!=' ')) num = 1;
	else num = 0;
	
	while (str[i]!='\0') {
		if ((str[i]==' ')&&(str[i+1]!=' ')) num+=1;
		i++;
	}
	
	return num;
	}

int main() {
	char str[] = "agua coca latao";
	int numP;
	
	numP = contaPalavras(str);
	
	printf("o numero de palavras eh: %d", numP);
	
	return 0;
	}
