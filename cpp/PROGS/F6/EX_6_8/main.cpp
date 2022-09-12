#include <iostream>

using namespace std;

class CDiametro {
    private:
        int pes;
        int polegadas;
    public:
        CDiametro();
        CDiametro(int);
        CDiametro(int, int);
        void corrige_polegadas();

};

CDiametro :: CDiametro() {
    pes = 10;
    polegadas = 0;
}

CDiametro :: CDiametro(int p) {
    pes = p;
    polegadas = 0;
}

CDiametro :: CDiametro(int pe, int po) {
    pes = pe;
    polegadas = po;
}

void CDiametro :: corrige_polegadas() {
    if(polegadas>=12) {
        pes+=polegadas/12;
        polegadas = polegadas%12;
    }
    cout << "pes: " << pes << " - polegadas: " << polegadas << endl;
}

int main()
{
    CDiametro dim1;
    dim1.corrige_polegadas();

    CDiametro dim2(12);
    dim2.corrige_polegadas();

    CDiametro dim3(3, 26);
    dim3.corrige_polegadas();

    return 0;
}
