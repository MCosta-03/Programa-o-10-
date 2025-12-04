#include <iostream>

using namespace std;

int main() {
    int preco, antecedentes, pessoas;
    cin >> preco >> antecedentes >> pessoas;

    double valor = preco * 0.75;
    int atual = (int)valor;
    if (valor > atual) {
        atual++;
    }
    if (atual % 50 != 0) {
        atual += 50 - (atual % 50);
    }

    double fator = 1.0;
    if (antecedentes >= 8) {
        fator = 0.35;
    }
    else if (antecedentes >= 5) {
        fator = 0.60;
    }

    valor = atual * fator;
    atual = (int)valor;
    if (valor > atual) {
        atual++;
    }
    if (atual % 50 != 0) {
        atual += 50 - (atual % 50);
    }
    if (pessoas >= 4) {
        valor = atual * 0.5;
        atual = (int)valor;
        if (valor > atual) {
            atual++;
        }
        if (atual % 50 != 0) {
            atual += 50 - (atual % 50);
        }
    }
    cout << atual << endl;
    return 0;
}
