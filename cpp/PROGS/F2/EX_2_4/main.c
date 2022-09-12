#include <stdio.h>

int fibo(int n) {
    /* função que calcula o valor de
     * fibonacci de um número 'n' passado*/

    // condições de paragem, quando n=0 e n=1
    if(n==0) return 0;
    else if (n==1) return 1;

    // para n>=2 usamos a formula que será uma recursão
    else return (fibo(n-1)+fibo(n-2));
}

int main()
{
    // declaração da variável
    int val;

    // atribuição de um valor dado pelo usuário à 'val'
    printf("digite o valor: ");
    scanf("%d", &val);

    // impressão do fibonacci do número pedido
    printf("fibo de %d = %d\n", val, fibo(val));
    return 0;
}
