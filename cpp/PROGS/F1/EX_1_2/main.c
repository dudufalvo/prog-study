#include <stdio.h>
#include <stdbool.h>

bool prime(unsigned int num) {
    // funcao que verifica se um numero e primo (retorna true) ou nao (retorna false)
    bool valid = true;

    // zero e um nao sao primos entao ja descartamos
    if(num==0||num==1) valid=false;

    // a partir de um ciclo verificamos se o numero atual eh multiplo ou nao
    for(unsigned int i=2; i <= num/2; i++) {
        if(num%i == 0) valid=false;
    }

    return valid;
}

int main()
{
    // declaracao das variaveis
    unsigned int num;
    bool primo;

    // pede o numero ao utilizador
    printf("digite um numero: ");
    scanf("%u", &num);

    // envia o numero dado a funcao para verificacao
    primo = prime(num);

    if(primo) printf("eh primo\n");
    else printf("NAO eh primo\n");

    return 0;
}
