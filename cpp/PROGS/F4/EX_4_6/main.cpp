#include <iostream>
#include <fstream>

using namespace std;

void insertionsort(string array[], int size) {
    int i, j;
    string hold;

    for(i=1; i<size; i++) {
        hold = array[i];
        for(j=i; j>0 && hold<array[j]; j--) {
            array[j] = array[j-1];
        }
        array[j] = hold;
    }
}

int main()
{
    string line, data_array[100];
    ifstream myfile;
    myfile.open("dados_desord.txt");

    if(!myfile.is_open()){
        cout << "ERROR: could not open the file1" << endl;
        return -1;
    }
    int k=0;
    while (getline(myfile, line) && k<100) {
        data_array[k] = line;
        k++;
    }
    myfile.close();

    insertionsort(data_array, 100);

    ofstream otherfile;
    otherfile.open("dados_ord.txt");
    if(!otherfile.is_open()){
        cout << "ERROR: could not open the file2" << endl;
        return -1;
    }
    for(int i=0; i<100; i++) {
        otherfile << data_array[i] << endl;
    }
    otherfile.close();
    return 0;
}
