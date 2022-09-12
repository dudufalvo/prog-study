#include <iostream>
#include <iomanip>

using namespace std;

const int COLUMNS = 3;

void matMult(int lines, float array[][COLUMNS], float val) {
    /* função que percorre as linhas e colunas da matriz e
     * multiplica seus elementos pelo valor passado */

    // percorremos os elementos da tabela
    for(int i=0; i <= lines-1; i++) {
        for(int j=0; j <= COLUMNS-1; j++) {

            // multiplicamos o elemento (i,j) pelo valor passado
            array[i][j] = array[i][j]*val;
        }
    }
}

void matForm(float array[][COLUMNS], int dim){
    /* função que percorre a matriz e printa seus elementos de modo formatado*/

    for(int i=0; i <= dim-1; i++) {
        for(int j=0; j <= COLUMNS-1; j++) {
            cout << right << setw(10) << setprecision(3) << fixed << array[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    // declaração e inicialização das variáveis
    int dim = 2;
    float value;
    float array[][COLUMNS] = {{1, 2, 3},
                              {-999.759, 999, -3.14}};

    // pedimos um valor ao usuário
    cout << "digite um valor para multiplicar a matriz: ";
    cin >> value;

    // printamos antes da mudança e depois
    matForm(array, dim);
    matMult(dim, array, value);
    cout << "\n";
    matForm(array, dim);

    return 0;
}
