#include <iostream>

using namespace std;

class CRetangulo {
    private:
        int altura;
        int comprimento;
        static int numRet;
    public:
        CRetangulo();
        CRetangulo(int,int);
        ~CRetangulo();
        CRetangulo(const CRetangulo &r);
        void incializaValores(int, int);
        int area (void) {return  altura*comprimento;}
        int perimentro(void) {return 2*altura+2*comprimento;}
        bool estaContido (const CRetangulo &r);
};

int CRetangulo :: numRet=0;

// construtor por omissão
CRetangulo :: CRetangulo() {
    altura = comprimento = 0;
    numRet++;
}

// construtor por parâmetros
CRetangulo :: CRetangulo(int a, int c){
    altura = a;
    comprimento = c;
    numRet++;
}

// construtor por cópia
CRetangulo :: CRetangulo(const CRetangulo &r){
    altura = r.altura;
    comprimento = r.comprimento;
    numRet++;
}

// Destrutor
CRetangulo :: ~CRetangulo() {
    numRet--;
}

void CRetangulo :: incializaValores(int a, int c){
    altura=a;
    comprimento=c;
}

bool CRetangulo :: estaContido(const CRetangulo &r){
    if(r.altura < altura) {
        if (r.comprimento < comprimento) {
            return true;
        }
    }
    return false;
}

int main()
{
    CRetangulo a(2,3), b(4,5), c(6,7);
    cout << a.area() << ' ' << b.perimentro();
    if(a.estaContido(b)) cout << "a contem b, b esta contido em a";
    else cout << "b contem a, a esta contido em b";

    if(b.estaContido(c)) cout << "b contem c, c esta contido em b";
    else cout << "c contem b, b esta contido em c";
    return 0;
}
