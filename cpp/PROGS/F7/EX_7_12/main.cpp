#include <iostream>

using namespace std;

class CAngulo {
    protected:
        int graus;
        int minutos;
        int segundos;
    public:
        CAngulo(); // construtor por defeito
        CAngulo(int g, int m, int s); // construtor por enumeracao
        CAngulo(const CAngulo &); // cosntrutor por copia
        bool operator <(const CAngulo &);
};

CAngulo::CAngulo() {
    graus = 10;
    minutos = 5;
    segundos = 15;
}

CAngulo::CAngulo(int g, int m, int s) {
    graus = g;
    minutos = m;
    segundos = s;
}

CAngulo::CAngulo(const CAngulo &a) {
    graus = a.graus;
    minutos = a.minutos;
    segundos = a.segundos;
}

bool CAngulo::operator <(const CAngulo &a){
    if(graus<a.graus) return true;
    else {
        if(minutos<a.minutos) return true;
        else{
            if(segundos<a.segundos) return true;
            else return false;
        }
    }
}

class CSetor: public CAngulo {
    private:
        int raio;
    public:
        CSetor();
        CSetor(int g, int m, int s, int r);
        bool menorTamanhoQue(const CSetor &s);
};

bool CSetor::menorTamanhoQue(const CSetor &s) {
    if(raio<s.raio && operator <(s)) return true;
    else return false;
}

CSetor::CSetor() {
    graus = 10;
    minutos = 5;
    segundos = 15;
    raio = 0;
}

CSetor::CSetor(int g, int m, int s, int r) {
    graus = g;
    minutos = m;
    segundos = s;
    raio = r;
}

int main()
{
    CSetor set1;
    CAngulo ang1;


    return 0;
}
