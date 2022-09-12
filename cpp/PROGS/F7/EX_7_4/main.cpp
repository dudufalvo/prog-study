#include <iostream>
#include <cmath>

using namespace std;

class CVector{
    private:
        double vector[3][1];
    public:
        CVector(); // Construtor por omissão
        CVector(int, int, int);
        double modulo();
        void inverte();
        CVector operator+(const CVector &v);
        bool operator!= (const CVector &v);

}; // fim da classe


CVector :: CVector() {
   vector[0][0] = 1;
   vector[1][0] = 1;
   vector[2][0] = 1;

}

// por parametros
CVector :: CVector(int a, int b, int c) {
    vector[0][0] = a;
    vector[1][0] = b;
    vector[2][0] = c;
}

// fazemos o módulo do vetor
double CVector :: modulo() {
    double v1 = vector[0][0]*vector[0][0];
    double v2 = vector[1][0]*vector[1][0];
    double v3 = vector[2][0]*vector[2][0];
    return sqrt(v1+v2+v3);
}

// invertemos o vetor multipliando seus componentes por -1
void CVector :: inverte() {
    vector[0][0]=-(vector[0][0]);
    vector[1][0]=-(vector[1][0]);
    vector[2][0]=-(vector[2][0]);
}

CVector CVector :: operator+(const CVector &v) {
    CVector vecSoma;

    vecSoma.vector[0][0] = vector[0][0] + v.vector[0][0];
    vecSoma.vector[1][0] = vector[1][0] + v.vector[1][0];
    vecSoma.vector[2][0] = vector[2][0] + v.vector[2][0];

    // return CVetor(this->x+outro.x, this->y+outro.y, this->z+outro.z);
    return vecSoma;
}

bool CVector :: operator!= (const CVector &v) {
    if(vector[0][0]==v.vector[0][0]&&vector[1][0]==v.vector[1][0]&&vector[2][0]==v.vector[2][0]) return true;
    else return false;
}

int main()
{

}
