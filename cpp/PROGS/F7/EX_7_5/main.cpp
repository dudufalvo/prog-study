#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class CEsfera{
    private:
        double raio; // Raio da Esfera
        char cor[15];// String que indica a cor da Esfera
    public:
        CEsfera(); // Construtor por defeito (Raio = 1.0, Cor = Branco)
        CEsfera(double r, const char* c); // Construtor por parâmetros
        CEsfera(const CEsfera& e);// Construtor por cópia
        ~CEsfera(); // Destrutor
        double volume() const; // Devolve o volume da Esfera(4/3*pi*Raio^3)

        // Sobrecarga de operadores:
        CEsfera operator+(const CEsfera&) const; // Sobrecarga do operador +
        // somam-se os raios e a cor é a da primeira Esfera
        CEsfera& operator=(const CEsfera&); // Atribuição de uma Esfera a outra

        // Esfera
        bool operator==(const CEsfera& e) const; //Testa igualdade entre esferas
        bool operator==(double r) const; // Idem em que r é o raio da segunda
}; // fim da classe

CEsfera :: CEsfera() {
    raio = 1.0;
    strcpy(cor, "Branco");
}

CEsfera :: CEsfera(double r, const char *c) {
    raio = r;
    strncpy(cor, c, 15);
}

CEsfera :: CEsfera(const CEsfera &e){
    raio = e.raio;
    strncpy(cor, e.cor, 15);
}

double CEsfera :: volume() const{
    return ((4/3)*M_PI*pow(raio, 3));
}



int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
