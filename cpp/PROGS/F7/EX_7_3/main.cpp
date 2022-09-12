#include <iostream>

using namespace std;

class CPolinomio{
    private:
        int grau; // Contém sempre o grau do polinómio.
        double coef[3]; // Coeficientes do polinómio: [0]=a0, [1]=a1,…
    public:
        CPolinomio(); // Inicialização por defeito (polinómio = 1)
        CPolinomio(double a2, double a1, double a0); /* construtor por parâmetros:
        atualiza grau */
        CPolinomio(const CPolinomio &p); // Construtor por cópia
        ~CPolinomio( );
        void escreve();
        CPolinomio operator -(const CPolinomio &);
        CPolinomio operator *(int mult);
        int operator [](int index);
}; // fim da classe

CPolinomio::CPolinomio() {
    coef[0] = 1;
    coef[1] = 0;
    coef[2] = 0;
    grau = 0;
}

CPolinomio::CPolinomio(double a2, double a1, double a0) {
    coef[0] = a0;
    coef[1] = a1;
    coef[2] = a2;
    if(a2!=0) grau=2;
    else {
        if(a1!=0) grau=1;
        else grau=0;
    }
}

CPolinomio::CPolinomio(const CPolinomio &p) {
    coef[0] = p.coef[0];
    coef[1] = p.coef[1];
    coef[2] = p.coef[2];
    grau = p.grau;
}

CPolinomio::~CPolinomio() {
    coef[0] = 0;
    coef[1] = 0;
    coef[2] = 0;
    grau = 0;
}

void CPolinomio::escreve(){
    cout << coef[2] << "x2 + " << coef[1] << "x + " << coef[0] << endl;
}

CPolinomio CPolinomio::operator -(const CPolinomio &p) {
    CPolinomio polisoma;
    polisoma.coef[0] = coef[0]-p.coef[0];
    polisoma.coef[1] = coef[1]-p.coef[1];
    polisoma.coef[2] = coef[2]-p.coef[2];

    return polisoma;
}

CPolinomio CPolinomio::operator *(int mult){
    CPolinomio polimult;

    polimult.coef[0] = coef[0]*mult;
    polimult.coef[1] = coef[1]*mult;
    polimult.coef[2] = coef[2]*mult;

    return polimult;
}

int CPolinomio::operator [](int index) {
    return coef[index];
}

int main()
{
    CPolinomio poli1;
    CPolinomio poli2(1, 3, 7);

    poli1.escreve();
    poli2.escreve();

    CPolinomio poli3 = poli1-poli2;

    poli3.escreve();

    CPolinomio poli4 = poli3*3;

    poli4.escreve();
    return 0;
}
