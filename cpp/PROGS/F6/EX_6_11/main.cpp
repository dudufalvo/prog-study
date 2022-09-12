#include <iostream>

using namespace std;

class CNumComplexo {
    private:
        double preal;
        double pimag;
    public:
        CNumComplexo();
        CNumComplexo(double, double);
        bool compara(const CNumComplexo &n);
};

CNumComplexo::CNumComplexo() {
    preal = 1;
    pimag = 0;
}

CNumComplexo::CNumComplexo(double r, double i) {
    preal = r;
    pimag = i;
}

bool CNumComplexo::compara(const CNumComplexo &n) {
    return (preal * preal + pimag * pimag) == (n.preal * n.preal + n.pimag * n.pimag);
}

int main()
{
    CNumComplexo comp1;
    CNumComplexo comp2(1, 0);
    CNumComplexo comp3(2, 4);

    cout << comp1.compara(comp2) << endl;
    cout << comp2.compara(comp3) << endl;

    return 0;
}
