#include <stdio.h>

int octalParaDecimal(unsigned int num) {
    /* função que converte o número
     * passado de octal para decimal */

    // condição de paragem é a divisão ja não ser mais possível
    if(num/10 != 0) {
        return ((num%10) + 8*octalParaDecimal(num/10));
    }
    // caso elementar
}

int main()
{
    // declaração da variável
    int val;

    // atribuição de um valor dado pelo usuário à 'val'
    printf("digite o valor: ");
    scanf("%d", &val);

    printf("%d", octalParaDecimal(val));
    return 0;
}
