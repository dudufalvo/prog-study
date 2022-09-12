#include <stdio.h>
#define DIM 255

int main()
{
    // cria-se o arquivo e declara-se a variavel com o nome do arquivo
    FILE *fp;
    char fname[DIM] = "", line[DIM], strg[] = "word";
    int l, s;

    // pede-se o nome do arquivo ao usuario
    printf("nome do arquivo: ");
    scanf("%100[^\n]", fname);

    // limpa o buffer
    while(getchar()!='\n');

    // abertura do arquivo em formato de leitura
    fp = fopen(fname, "r");

    // caso o arquivo esteja vazio, uma mensagem surge no ecra
    if (fp==NULL) printf("nao foi possivel abrir o arquivo %s\n", fname);

    else {
        // le-se linha por linha do ficheiro
        while(fgets(line, sizeof(line), fp)) {
            // criamos indices para a linha e para a palavra "word"
            l=0;
            s=0;

            // percorre-se a linha até o seu fim ('\n')
            while(line[l] != '\n') {
                if(line[l]==strg[s]) s++; // caso a letra da linha seja igual a letra da palavra, vamos a proxima
                else s=0; // se nao, zeramos o indice e voltamos ao 'w'

                // caso o indice chegue a 4, significa que achamos 'word' na linha entao printamos no ecra
                if(s==4) {
                    printf("%s", line);
                    break;
                }
                // mudamos de caractere
                l++;
            }
        }
    }

    fclose(fp);
    return 0;
}
