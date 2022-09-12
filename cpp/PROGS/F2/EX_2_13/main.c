#include <stdio.h>

void decimalToOctal(int num) {
    /* função que converte um número octal em decimal*/

    // enquanto for possível dividir mais continuamos
    if(((int) num/8) != 0) {
        decimalToOctal((int) num/8);
    }
    // printamos ao contrário os restos das divisões
    printf("%d", num%8);
}

int main()
{
    // declaração da variável
    int val;

    // atribuição de um valor dado pelo usuário à 'val'
    printf("digite o valor: ");
    scanf("%d", &val);

    decimalToOctal(val);
    return 0;
}
