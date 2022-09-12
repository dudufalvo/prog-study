#include <iostream>

using namespace std;

void bubblesort(string *array, int size) {
    string hold;
    int pass, j;
    bool switched = true;

    for(pass=0; pass<size-1 && switched==true; pass++) {
        switched = false;
        for(j=0; j<size-pass-1; j++) {
            if(array[j] > array[j+1]) {

                hold = array[j];
                array[j] = array[j+1];
                array[j+1] = hold;

                switched = true;
            }
        }
    }
}

void printList(string array[], int size) {
    for(int i=0; i<size; i++) cout << array[i] << endl;
}

int main()
{
    string lista[10] = {"eduardo",
                        "carolina",
                        "silvia",
                        "mauricio",
                        "ana clara",
                        "padovese",
                        "gabriel",
                        "maria",
                        "nicole",
                        "caio"};
    printList(lista, 10);
    bubblesort(lista, 10);
    cout << "-------" << endl;
    printList(lista, 10);
    return 0;
}
/*
void bubblesort(int array[], int size) {
    int pass, hold, j;
    bool switched=true;

    for(pass=0; pass<size-1 && switched==true; pass++) {
        switched = false;
        for(j=0; j<size-pass-1; j++) {
            if(array[j]>array[j+1]) {
                hold = array[j];
                array[j] = array[j+1];
                array[j+1] = hold;

                switched = true;
            }
        }

    }
}
*/
