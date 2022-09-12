#include <stdio.h>

void escreveAsteriscos(int n) {
    // printa no ecra n asteriscos
    if(n > 0) {
        printf("* ");
        escreveAsteriscos(n-1);
    }
}

int main()
{
    // declaracao da variavel 'val'
    int val;

    // pergunta ao usuario um valor e atribui a 'val'
    printf("digite um valor: ");
    scanf("%d", &val);

    // chamamos a funcao 'escreveAsteriscos' passando 'val' como parâmetro
    escreveAsteriscos(val);
    return 0;
}
