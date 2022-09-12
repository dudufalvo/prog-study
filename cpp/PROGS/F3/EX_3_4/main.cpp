#include <iostream>
#include <fstream>

using namespace std;

struct Customer_Data {
    string name;
    bool female;
    float weight, height, bmi;
};

void binaryWrite(Customer_Data *cdata, int size, string filename) {
    ofstream file;
    file.open(filename, ios::out | ios::binary);

    if(!file) {
        cout << "erro ao abrir o arquivo" << endl;
    }

    else{
        for(int i=0; i<size; i++){
            //file << cdata[i].name << " - " << cdata[i].weight << " - " << cdata[i].height << " - " << cdata[i].bmi << endl;
            file.write((char *) &cdata[i], sizeof(Customer_Data));
        }
    }
    file.close();
}

void binaryRead(Customer_Data cdata, int index, string filename) {
    ifstream file;
    file.open(filename, ios::in | ios::binary);

    if(!file) {
        cout << "erro ao abrir o arquivo" << endl;
    }
    else {
        file.seekg();

        file.read((char *) &cdata, sizeof(Customer_Data));
        //gcount() -> bytes lidos

        cout << "NAME: " << cdata.name << endl;
        cout << "WEIGHT: " << cdata.weight << endl;
        cout << "HEIGHT: " << cdata.height << endl;
        cout << "BMI: " << cdata.bmi << endl;

    }
    file.close();
}

int main()
{
    Customer_Data costumer_list[6] = {{"EDUARDO",false,60,1.70,0},
                                      {"PADOVESE",false,85,1.85,0},
                                      {"MARIA",true,60,1.65,0},
                                      {"NICOLE",true,60,1.70,0},
                                      {"GARIEL",false,70,1.80,0},
                                      {"GIULIA",true,60,1.70,0}};

    binaryWrite(costumer_list,6,"binaryTest.txt");
    binaryRead(costumer_list,0,"binaryTest.txt");

    return 0;
}
