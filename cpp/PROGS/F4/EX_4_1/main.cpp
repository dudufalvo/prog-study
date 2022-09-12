#include <iostream>
#define DIM 20

using namespace std;

void bubblesort(int array[], int size) {
    int pass, hold;
    bool switched=true;

    for(pass=0; (pass<size-1) && (switched == true); pass++) {

        switched = false;
        for(int j=0; j<size-pass-1; j++) {
            if(array[j]>array[j+1]){
                hold = array[j];
                array[j] = array[j+1];
                array[j+1] = hold;

                switched = true;
            }
        }
    }
}

void makeArray(int array[], int size) {
    for(int i=0; i<size; i++) {
        array[i] = (18 + rand() % (90-18+1));
    }
}

void printArray(int array[], int size) {
    for(int i=0; i<size; i++) {
        cout << "array[" << i << "] = " << array[i] << endl;
    }
}

int main()
{
    int array[DIM];
    makeArray(array, DIM);
    printArray(array, DIM);
    cout << endl;
    bubblesort(array, DIM);
    printArray(array, DIM);

    return 0;
}
