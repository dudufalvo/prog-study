#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *strcopia( char *dest, const int dim, const char *src ) {
	for(int i=0; (i<dim); i++) dest[i] = src[i];
	
	return dest;
	}

char *strconcat( char *dest, const int dim, const char *src ) {
	int len_dest=0;
	
	while(dest[len_dest]!='\0') len_dest++;
	
	for(int i=0; (len_dest<dim); i++) {
		dest[len_dest] = src[i];
		len_dest++;
		}
	dest[len_dest] = '\0';
	return dest;
	}

int main() {
	char str1[] = "amarelo";
	char str2[] = "joana asdaaa edu";
	
	strconcat(str2, 100, str1);
	//strcopia(str2, 100, str1);
	
	printf("%s", str2);
	
	return 0;
	}
