#include <iostream>

using namespace std;

class CEsfera{ // representa uma esfera de centro (x0,y0,z0) e raio r
    protected:
        double centro[3];
        double raio;
    public:
        CEsfera() {
            for(int i=0; i<3; i++) centro[i] = 0;
            raio = 1;
        } // construtor por omissão

        CEsfera(double x, double y, double z, double r) {
            centro[0] = x;
            centro[1] = y;
            centro[2] = z;
            raio = r;
        } // por enumeração

        void mostra() {
            for (int i=0; i<3; i++) cout << centro[i] << ", ";
            cout << raio;
        }
};

class CBola : public CEsfera {
    protected:
        double peso;
    public:
        CBola() {
            for(int i=0; i<3; i++) centro[i] = 0;
            raio = 1;
            peso = 1;
        }

        CBola(double x, double y, double z, double r, double p) {
            centro[0] = x;
            centro[1] = y;
            centro[2] = z;
            raio = r;
            peso = p;
        }

        void mostra() {
            for (int i=0; i<3; i++) cout << centro[i] << ", ";
            cout << raio << ", ";
            cout << peso;
        }

        double densidade() {
            return (peso/(4*3.1415*raio*raio*raio)/3);
        }
};

int main()
{
    CEsfera esf1;
    CEsfera esf2(1,1,1,3);

    esf1.mostra();
    cout << endl;
    esf2.mostra();
    cout << endl;

    CBola bola1;
    CBola bola2(1,1,1,3,5);

    bola1.mostra();
    cout << endl;
    bola2.mostra();
    cout << endl;
    cout << "densi: " << bola2.densidade() << endl;

    return 0;
}
