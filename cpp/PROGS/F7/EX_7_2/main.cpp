#include <iostream>

using namespace std;

class CCash {
private:
    int euros;
    int centimos;
public:
    CCash();
    CCash(int, int);
    CCash troco(const CCash &c);
    void imprime();
    CCash operator + (const CCash &c);
    bool operator != (const CCash &c);
};

CCash::CCash() {
    euros = 1;
    centimos = 99;
}

CCash::CCash(int e, int c) {
    euros = e;
    centimos = c;
}

CCash CCash::troco(const CCash &c) {
    CCash troco;
    int veuros = c.euros;
    int vcentimos = c.centimos;

    if(c.euros>euros) {
        veuros-=1;
        vcentimos+=100;
    }
    troco.euros = veuros-euros;
    troco.centimos = vcentimos-centimos;

    return troco;
}

void CCash::imprime() {
    cout << euros << "," << centimos << endl;
}

CCash CCash::operator + (const CCash &c) {
    if (centimos+c.centimos>=100) {
        centimos-=100;
        euros+=1;
    }
    return CCash(euros+c.euros, centimos+c.centimos);
}

bool CCash::operator != (const CCash &c) {
    if (euros!=c.euros && centimos!=c.centimos) return true;
    else return false;
}

int main()
{
    CCash cash1;
    cash1.imprime();

    CCash cash2(2,50);
    cash2.imprime();

    CCash cash3 = cash1.troco(cash2);
    cash3.imprime();

    CCash cash4 = cash1 + cash2;
    cash4.imprime();
    return 0;
}
