#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class CTempo {
        int horas, minutos, segundos;
    public:
        CTempo() { horas = minutos = segundos = 0; }
        CTempo(float t) { set(t); }


        void set(float t); // ex: se t = 2.56, então horas=2, minutos=33, segundos=36
        float get(void) const; // ex: se horas=2, minutos=33, segundos=36, devolve 2.56
        void mostra(void) const {
            cout << setfill('0') << setw(2) << horas << ':' <<
            setw(2) << minutos<<':'<< setw(2) << segundos << endl; }
        CTempo operator -(const CTempo& t2);
};

float CTempo::get() const{
    return (horas + minutos/60.0 + segundos/3600.0);
}

void CTempo::set(float t) {
    horas = (int) t;
    t = (t-horas) * 60;
    minutos = (int) t;
    segundos = round((t-minutos)*60);
}

CTempo CTempo::operator -(const CTempo &t2) {
    return CTempo(this->get()-t2.get());
}

int main()
{
    CTempo temp1;
    CTempo temp2(2.56);
    CTempo temp3(1.24);

    temp1.mostra();
    temp2.mostra();
    temp3.mostra();

    CTempo temp4;
    temp4 = (temp2-temp3);
    temp4.mostra();

    return 0;
}
