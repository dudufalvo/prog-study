#include <iostream>
#define PI 3.1415

using namespace std;

class Odometria {
    private:
        double x;
        double y;
        double theta;
    public:
        Odometria();
        Odometria(double, double, double);
        void simplifOrient();
};

Odometria::Odometria() {
    x=0;
    y=0;
    theta=0;
}

Odometria::Odometria(double xp, double yp, double tp) {
    x=xp;
    y=yp;
    theta=tp;
}

void Odometria::simplifOrient() {
    while(theta<-PI||theta>PI) {
        if(theta<0) theta+=2*PI;
        else theta-=2*PI;
    }
}

int main() {

    return 0;
}
