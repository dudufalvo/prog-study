#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 1001
	
int main(int argc, char *argv[]) {
	FILE *fp;
	int indc;
	int a=0;
	int e=0;
	int i=0;
	int o=0;
	int u=0;
	
	fp = fopen("dezLinhas.txt", "r");
	
	while((indc=fgetc(fp))!=EOF) {
		if (indc=='a') a++;
		else if (indc=='e') e++;
		else if (indc=='i') i++;
		else if (indc=='o') o++;
		else if (indc=='u') u++;
		}
	
	fclose(fp);
	
	printf("a=%d",a);
	printf("e=%d",e);
	printf("i=%d",i);
	printf("o=%d",o);
	printf("u=%d",u);
	
	return 0;
}

