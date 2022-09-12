
#include <iostream>

using namespace std;

class CDuracao {
    private:
        int horas;
        int minutos;
    public:
        CDuracao();
        CDuracao(int, int);
        CDuracao(const CDuracao &d);
        int compara(const CDuracao &d);
};

CDuracao::CDuracao() {
    horas = 1;
    minutos = 30;
}

CDuracao::CDuracao(int h, int m) {
    horas = h;
    minutos = m;
}

CDuracao::CDuracao(const CDuracao &d) {
    horas = d.horas;
    minutos = d.minutos;
}

int CDuracao::compara(const CDuracao &d) {
    cout << "atual = " << horas << "h" << minutos << "min" << endl;
    cout << "comparado = " << d.horas << "h" << d.minutos << "min" << endl;
    if((horas*60)+minutos == (d.horas*60)+d.minutos) return 0;
    else if((horas*60)+minutos < (d.horas*60)+d.minutos) return -1;
    else return 1;
}

int main()
{
    CDuracao tempo1;
    CDuracao tempo2(2, 0);
    CDuracao tempo3(tempo1);

    cout << tempo1.compara(tempo2) << endl;
    cout << tempo1.compara(tempo3) << endl;
    cout << tempo2.compara(tempo3) << endl;

    return 0;
}
