#include <stdio.h>

void imprimeAte(int n) {
    // chama a funcao passando n-1 como parametro ate chegar n=0
    if(n != 0) {
        imprimeAte(n-1);
    }
    // printa os numeros na volta, colocando-os na ordem
    printf("%d ", n);
}

int main()
{
    // declaracao das variaveis
    int val;

    // pergunta ao usuario o valor e atribui-o em 'val'
    printf("digite um valor: ");
    scanf("%d", &val);

    // chama a funcao passando 'val' como parametro
    imprimeAte(val);

    return 0;
}
