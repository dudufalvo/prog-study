#include <iostream>

using namespace std;
const int DIM=100;

int findNum(int * array, int size, int num) {
    int *inic;

    for(inic=array; inic-array < size; inic++) {
        if(*inic==num) {
            return inic-array;
        }
    } return -1;
}

void createArray(int array[]) {
    for(int i=0;i<DIM;i++) {
       array[i]=(rand()%53)-10;
       cout << "array[" << i << "] = " << array[i] << endl;
    }
}

int main()
{
    int array[DIM];
    createArray(array);
    int val = 0;

    cout << "digite um valor: ";
    cin >> val;
    cout << "index " << val << " = " << findNum(array, DIM, val) << endl;
    return 0;
}
