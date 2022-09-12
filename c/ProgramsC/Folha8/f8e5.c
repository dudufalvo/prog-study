#include <stdio.h>

int eh_primo(unsigned int n) {
	for(int i=2; i<=n/2; i++) {
		if(n%i != 0) continue;
		else return 0;
		}
	return 1;
}

int tab_prim_dec(unsigned int n, int *t, int lent) {
	int *t_ptr=t;
	
	while(t_ptr<t+lent) {
		while(eh_primo(n)!=1)
			n--;
		*t_ptr=n;
		if (n-1>=2) n--;
		t_ptr++;
		}
	return lent;
	}

int main() {
	int tab[5] = {1, 2, 3, 4, 5};
	int *tab_ptr=tab;
	int lent = sizeof(tab)/sizeof(int);
	
	lent = tab_prim_dec(5, tab, lent);
	
	while(tab_ptr<tab+lent) {
		printf("%d ", *tab_ptr);
		tab_ptr++;
		}
	return 0;
	}
