#include <iostream>
#include <cmath>

using namespace std;

class CPiramide{
    protected:
        int numLadosBase; // número de lados da base regular
        double altura, lado; // altura da pirâmide e comprimento dos lados da base
        double apotema; // comprimento do apótema da base
    public:
        CPiramide() { numLadosBase = 3; altura = 1.0; lado = 1.0; setApotema(); }
        CPiramide(int n, double a, double l) {
            numLadosBase = n;
            altura = a;
            lado = l;
            setApotema();
        }

        void mostra()const{
            cout << "Piramide regular de altura " << altura << " e base de lado " << lado << endl;
        }
        void setApotema() {
            apotema = lado / (2.0 * tan(3.14159265 / numLadosBase)); }
        double areaBase() const {
            return (0.5 * apotema * numLadosBase * lado); }
        virtual double volume() = 0; // método para calcular o volume da pirâmide
};

class CPiramideHexagonal: public CPiramide {
    public:
        CPiramideHexagonal(double a, double l) {
            numLadosBase = 6;
            altura = a;
            lado = l;
            setApotema();
        }
        double volume() {
            return ((areaBase()+altura)/3);
        }
};

int main() {
    CPiramideHexagonal pir1(7,3);
    CPiramide *p1=&pir1;

    cout << p1->volume() << endl;
    p1->mostra();

    return 0;
}
