#include <stdio.h>

int letab(int t[], int capac) {
	int max;
	int elem;
	
	do {
		printf("quantos numeros quer preencher? ");
		scanf("%d", &max);} while((max<0)||(max>capac));
	
	for(int i=0; i<max; i++) {
		printf("elemento %d: ", i);
		scanf("%d", &elem);
		t[i] = elem;
		}
	return max;
	}

int eh_primo(unsigned int n) {
	for(int i=2; i<=n/2; i++) {
		if(n%i != 0) continue;
		else return 0;
		}
	return 1;
}

int eh_primo_tab(int t[], unsigned int len) {
	int n_prim=0;
	int *t_ptr=t;
	int res;
	
	while(t_ptr<t+len) {
		printf("%d ", *t_ptr);
		res = eh_primo(*t_ptr);
		if((res==1)&&(*t_ptr!=0)&&(*t_ptr!=1)) n_prim+=1;
		t_ptr++;
		}
	return n_prim;
	}

int main() {
	int tab[10+1];
	int len;
	int n_prim;
	
	len = letab(tab, 10);
	n_prim = eh_primo_tab(tab, len);
	
	printf("\n%d", n_prim);
	
	return 0;
	}
