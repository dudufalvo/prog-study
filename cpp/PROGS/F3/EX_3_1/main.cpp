#include <iostream>

using namespace std;

void diamond(int num) {
    /* função que, passado um valor inteiro n,
     * desenha um prisma de lado n*/

    // declaração e inicialização de variáveis
    int i, line, tab, star=1, var=0;

    // ciclo para as linhas do triângulo superior
    for(line=0; line<num; line++){

        //
        for(tab=0; tab<(num+var)-star; tab++){
            cout << " ";
        }
        for(i=0; i<star; i++){
            cout << "*";
        }
        cout << endl;
        star+=2;
        var++;
    }
    var-=2;
    star-=4;
    for(line=0; line<num-1; line++){
        for(tab=0; tab<(num+var)-star; tab++){
            cout << " ";
        }
        for(int i=0; i<star; i++){
            cout << "*";
        }
        cout << endl;
        star-=2;
        var--;
    }
}

int main()
{
    diamond(5);
    return 0;
}
