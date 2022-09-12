#include <stdio.h>

void mostratab(int tab[], unsigned int n) {
	int *tab_ptr=tab;
	int i=0;
	
	while(tab_ptr<tab+n) {
		printf("t[%d] = %d\n", i, *tab_ptr);
		tab_ptr++;
		i++;
		}
	}

int main() {
	int t[] = {-1,3,-4,5};
	int lent = sizeof(t)/sizeof(int);
	
	mostratab(t, lent);	
	
	return 0;
	}
