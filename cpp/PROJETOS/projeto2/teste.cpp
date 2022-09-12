#include <iostream>
#include <cstring>
using namespace std;

int power(int n, int k) {
    int num=1;
    
    for(int i=1; i<=k; i++) {
        num=num*n;
    }

    return num;
}

int main() {
	int n_msg, num;

    cin >> n_msg;

	string hex_num, hex_list[n_msg];

	for(int i=0; i<n_msg; i++) {
		cin >> hex_num;
		hex_list[i] = hex_num;
	}

	for(int i=0; i<n_msg; i++) {
        num=0;
		for(int j=0; j<hex_list[i].length(); j++) {
            if(hex_list[i][j]>='0' && hex_list[i][j]<='9') {
                hex_num = hex_list[i][j];
                num+=(power(16, hex_list[i].length()-j-1)*atoi(hex_num.c_str()));
            }
            else {
                switch (hex_list[i][j]) {
                case 'A':
                    num+=(power(16, hex_list[i].length()-j-1)*10);
                    break;
                case 'B':
                    num+=(power(16, hex_list[i].length()-j-1)*11);
                    break;
                case 'C':
                    num+=(power(16, hex_list[i].length()-j-1)*12);
                    break;
                case 'D':
                    num+=(power(16, hex_list[i].length()-j-1)*13);
                    break;
                case 'E':
                    num+=(power(16, hex_list[i].length()-j-1)*14);
                    break;
                case 'F':
                    num+=(power(16, hex_list[i].length()-j-1)*15);
                    break;
                }
            }
        }
        cout << num << endl;
	}

	return 0;
}
