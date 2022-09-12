#include <cstring>
#include <iostream>

using namespace std;

int procuraSubString(const char *tab, int numElemsTab, const char *subString) {
    const char *inic;
    char *p;
    for(inic=tab; inic<tab+numElemsTab; inic++) {
        p = strstr(*inic, subString);
    }
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
