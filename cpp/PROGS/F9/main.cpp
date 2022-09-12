#include "CFilaInteiros.cpp"
#include "CPilhaInteiros.h"


int main() {
    CFilaInteiros fila1;

    fila1.insereNaFila(1);
    fila1.insereNaFila(22);
    fila1.insereNaFila(33);
    fila1.insereNaFila(4);
    fila1.insereNaFila(5);
    fila1.insereNaFila(65);
    fila1.insereNaFila(0);

    fila1.passaAfrente(6);
    fila1.escreveFila();

    return 0;
}