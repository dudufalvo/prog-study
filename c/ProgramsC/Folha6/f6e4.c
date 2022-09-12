#include <stdio.h>

void inverte(double tab[], unsigned int n) {
	double n_tab[n];
	//int aux1=0;
	double temp=0;
	
	n-=1;
	for(int aux2=0; aux2<=n; aux2++) {
		temp = tab[aux2];
		tab[aux2]=tab[n];
		tab[n] = temp;
		n-=1;}
	
	// utilizando duas arrays
	//for(int aux2=n-1; aux2>=0; aux2--) {
		//n_tab[aux1]=tab[aux2];
		//aux1+=1;}
		
	//for(int aux3=0; aux3<n; aux3++) tab[aux3]=n_tab[aux3];
		
}

int main() {
	double t[] = {2.3, 4.3, 5.7, 3.3, 9.1};
	int num_el=5;
	
	inverte(t, num_el);
	
	for(int i=0; i<=num_el-1; i++) {
		printf("%lg ", t[i]);
		}
	}

/*
#include <stdio.h>

void inverte(double tab[], unsigned int n) {
	double aux;
	
	for(int i=0; i<n; i++) {
		aux = tab[n-1];
		tab[n-1] = tab[i];
		tab[i] = aux;
		n--;
		}
	}

void mostratab(double tab[], unsigned int n) {
	for(int aux1=0; aux1<n; aux1++) {
		printf("%lg  ", tab[aux1]);
		}
	}

int main() {
	double r[] = {2.3, 4.2, 5.1, 3.7, 3.2, 1.2};
	int tam = (int)(sizeof(r)/sizeof(double));
	
	inverte(r, tam);
	mostratab(r, tam);
	
	return 0;
}
 */
