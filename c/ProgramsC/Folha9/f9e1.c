#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 1001

int main(int argc, char *argv[]) {
	FILE *fp;
	char str[CAPACIDADE] = "";
	
	fp = fopen(argv[1], "w");
	
	for(int i=0; i<10; i++) {
		printf("digite a primeira frase: ");
		scanf("%1000[^\n]", str);
		
		while(getchar()!='\n');
		
		fputs(str, fp);
		fputs("\n", fp);
		}
	fclose(fp);
	return 0;
}
