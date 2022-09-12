#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// criação da struct e de seus elementos
struct Customer_Data {
    string name;
    bool female;
    float weight, height, bmi;
};


void computeBMI(Customer_Data &cdata){
    /* função que recebe um cliente em formato
     * de struct, calcula e atualiza seu bmi */

    cdata.bmi = cdata.weight / (cdata.height * cdata.height);
}


void updateBMI(Customer_Data *cdata, int size) {
    /* função que, passada uma lista de clientes em struct,
     * encaminha-os à função computeBMI para ter seu bmi atualizado*/

    // ciclo para percorrer todos os elementos da tabela de structs
    for(int i=0; i<size; i++) {
        computeBMI(cdata[i]);
    }
}

int listCostumers(Customer_Data *cdata, int size, int thold, string filename) {
    /* função que computaa em um ficheiro txt os dados dos
     * clientes da struct dos quais o bmi ultrapassa o valor base*/

    int num=0;

    // criação/abertura do ficheiro em formato append
    ofstream file;
    file.open(filename, std::ios_base::app);

    // no caso do ficheiro não abrir, printamos um erro no ecra
    if(!file) {
        cout << "erro ao abrir o arquivo" << endl;
        return -1;
    }

    // ciclo para percorrer todas as structs
    for(int i=0; i<size; i++){
        // verificação se o bmi do cliente é maior que o valor base
        if(cdata[i].bmi >= thold) {
            // computação dos dados do cliente no ficheiro
            file << left << "NAME: " << cdata[i].name << endl;
            file << right << setw(60) << "WEIGHT: " << setprecision(2) << fixed << cdata[i].weight << endl;
            file << right << setw(70) << "BMI: " << setprecision(2) << fixed << cdata[i].bmi << endl;
            num++;
        }
    }
    file.close();
    return num;
}

int main(){

    Customer_Data costumer_list[6] = {{"EDUARDO",false,60,1.70,0},
                                      {"PADOVESE",false,85,1.85,0},
                                      {"MARIA",true,60,1.65,0},
                                      {"NICOLE",true,60,1.70,0},
                                      {"GARIEL",false,70,1.80,0},
                                      {"GIULIA",true,60,1.70,0}};
    updateBMI(costumer_list, 6);

    listCostumers(costumer_list, 6, 20, "ibm_data.txt");

    return 0;
}
