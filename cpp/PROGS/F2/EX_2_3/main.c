#include <stdio.h>

double expo(double x, int n) {
    /* função que calcula expoentes sendo
     * 'x' uma base real e 'n' o expoente inteiro*/

    // condição de paragem, quando n é zero
    if (n == 0) {
        // nesse caso retornamos 1 por ser elemento neutro da multiplicação
        return 1;
    }
    else {
        // usamos a recursão para multiplicar as bases n vezes
        //if (n==1) -> lembrar dessa exceção
        return (x * expo(x, n-1));
    }
}

int main()
{
    // declaração e inicialização das variáveis
    double val, total=0;
    int exp;

    // é pedido ao usuário a base real que é atribuída à variável 'val'
    printf("digite um real: ");
    scanf("%lg", &val);

    printf("digite um expoente: ");
    scanf("%d", &exp);

    // atribuimos o retorno da função à variável total e printamos
    total = expo(val, exp);

    printf("total = %lg", total);
    return 0;
}
