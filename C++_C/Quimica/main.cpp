#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    string formula;
    cout << "Diz a formula química: ";
    cin >> formula;

    string resultado;
    int minuscula = 0;
    int n = 0;
    int fez = 0;
    int fez_switch = 0;

    for (int i = 0; i < formula.length(); i++) {


        if (formula[i] >= 'A' && formula[i] <= 'Z') {
            resultado += "\n";
            if (minuscula == 1) {
                minuscula = 0;
                //resultado += "\n";
            }

            fez = 1;
            n = 0;
            fez_switch = 0;
            resultado += formula[i];
        }
        else if (formula[i] >= 'a' && formula[i] <= 'z') {
            resultado += formula[i];
            minuscula = 1;
            fez = 2;
            fez_switch = 1;
            n = 0;
        }

        if (formula[i] >= '0' && formula[i] <= '9') {
            if (n == 0) {
                resultado += " ";
                n = 1;
            }
            resultado += formula[i];
            fez = 3;
        }
        else if (fez == 2 && n == 0) {
            resultado += " 1";
        }
    }

    cout << resultado;

    return 0;
}