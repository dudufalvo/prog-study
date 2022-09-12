#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEM 50
#define MAX_TEXT 41

struct Carro {
	
	char info[MAX_TEXT]; 
	char matricula[MAX_TEXT]; 
	unsigned int ano;
	double custo;
	
};

struct Carro novoCarro() {
	
	struct Carro aux;
	do {
	printf("digite uma informacao do carro: ");
	scanf("%40[^\n]", aux.info);} while(aux.info[0]=='\0');
	
	while(getchar()!='\n');
	
	do {
	printf("digite a matricula do carro: ");
	scanf("%40[^\n]", aux.matricula);}while(aux.matricula[0]=='\0');
	
	while(getchar()!='\n');
	
	do {
	printf("digite o ano do carro: ");
	scanf("%d", &aux.ano);}while((aux.ano<1900)||(aux.ano>2022));
	
	do {
	printf("digite o custo do carro: ");
	scanf("%lg", &aux.custo);}while(aux.custo<0);
	
	return aux;
	}

void mostraCarro(struct Carro c) {
	printf("%s | %s | %d | %lf", c.info, c.matricula, c.ano, c.custo);
	}

void salvaCarro(struct Carro c) {
	FILE *fp;
	
	fp = fopen("carros.txt", "a");
	fputs(c.info, fp);
	fputs("\n", fp);
	fputs(c.matricula, fp);
	fputs("\n", fp);
	fprintf(fp, "%d", c.ano);
	fputs("\n", fp);
	fprintf(fp, "%lg", c.custo);
	fputs("\n", fp);
	fclose(fp);
	}

int main() {
	struct Carro car;
	car = novoCarro();
	mostraCarro(car);
	salvaCarro(car);
	return 0;
}
