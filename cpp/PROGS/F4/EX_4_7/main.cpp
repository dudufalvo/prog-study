#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void compara_linha(const void *linha1, const void *linha2) {

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

    qsort((void *)data_array, 100, sizeof(data_array), compara_linha);

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
