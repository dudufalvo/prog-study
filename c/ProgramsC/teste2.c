#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
void capitalizacao(char *pletra) {
	while(*pletra!='\0'){
		if((*pletra>='a')&&(*pletra<='z')) *pletra = toupper(*pletra);
		else if((*pletra>='A')&&(*pletra<='Z')) *pletra = tolower(*pletra);
		else *pletra='?';
		pletra++;
	}
}

int main() {
	while (1){
		char str[100+1]="0";
		printf("frase = ");
		scanf("%100[^\n]", str);
		
		if(str[0]=='\0') break;
		while(getchar()!='\n');
		
		capitalizacao(str);
		printf("%s", str);
		}
	return 0;
}

int contaLetras(char *nomef, int *tab) {
	FILE *fp = fopen(nomef, "r");
	char c;
	
	if(fp==NULL) return 0;
	
	while((c=fgetc(fp))!=EOF) {
		for(int i; i<26; i++) {
			if((c=='a'+i)||(c=='A'+i)) {
				tab[i]++;}
			}
		}
	fclose(fp);
	return 1;
	}

int main() {
	char nome[100];
	int rtncntl = 0;
	int tab[26] = {0};
	
	printf("nome do ficheiro: ");
	scanf("%100[^\n]", nome);
	
	rtncntl = contaLetras("teste.txt", tab);
	
	if (rtncntl == 0) printf("impossivel abrir\n");
	else if (rtncntl == 1) {	
		for(int i = 0; i < 26; i++) {
			printf("%c/%c %d\n", (char) ('a' + i), (char) ('A' + i), tab[i]);
		}
	}
	
	return 0;
	}

*/
/*
void regista(int *numeroCamisola, int *idades) {
	int nmr;
	int idade;
	
	for(int i=0; i<5; i++) {
		printf("numero camisola: ");
		scanf("%d", &nmr);
		printf("idade: ");
		scanf("%d", &idade);
		numeroCamisola[i]=nmr;
		idades[i]=idade;
		}
	}

int guardanovos (int *numeroCamisola, int *idades) {
	FILE *fp;
	int jogadores=0;
	
	fp = fopen("futebol.txt", "a");
	
	for(int i=0; i<5; i++) {
		if(idades[i]<20) {
			fprintf(fp, "%d --> %d", numeroCamisola[i], idades[i]);
			fprintf(fp, "\n");
			jogadores++;
			}
		}
	return jogadores;
	}

int main() {
	int numCamis[5];
	int idades[5];
	int jogadores=0;
	
	regista(numCamis, idades);
	jogadores = guardanovos(numCamis, idades);
	
	printf("%d", jogadores);
	
	return 0;
	}
*/
