#include <iostream>

using namespace std;

int M[8] = { 0 };
int E = 0, C = 0;
void dinheiro_a_pagar() {
    cin >> E >> C;
    cin >> M[0] >> M[1] >> M[2] >> M[3] >> M[4] >> M[5] >> M[6] >> M[7];
    E *= 100;
    E += C;
}

int Esum = 0, Csum = 0;
void obter_sobra() {
    Esum = (M[0] * 2) + M[1];
    Csum = (M[2] * 50) + (M[3] * 20) + (M[4] * 10) + (M[5] * 5) + (M[6] * 2) + M[7];
    Esum *= 100;
    Esum += Csum;
}

int Troco[8] = { 0 };
void Obter_moedasEmTroco() {
    if (Esum < E) {
        for (int i = 0; i < 8; i++)
            Troco[i] = M[i];
    }
    else {
        int Erest = 0, Crest = 0;
        for (int i = 0; i < (Esum - E); i++) {
            Crest++;
            if (Crest > 99) {
                Crest = 0;
                Erest++;
            }
        }

        while (Crest > 0) {
            if (Erest >= 2) {
                Troco[0]++;
                Erest -= 2;
            }
            if (Erest >= 1) {
                Troco[1]++;
                Erest -= 1;
            }
            if (Crest >= 50) {
                Troco[2]++;
                Crest -= 50;
            }
            if (Crest >= 20) {
                Troco[3]++;
                Crest -= 20;
            }
            if (Crest >= 10) {
                Troco[4]++;
                Crest -= 10;
            }
            if (Crest >= 5) {
                Troco[5]++;
                Crest -= 5;
            }
            if (Crest >= 2) {
                Troco[6]++;
                Crest -= 2;
            }
            if (Crest >= 1) {
                Troco[7]++;
                Crest -= 1;
            }
        }
    }
}

void mostrar_resultado() {
    for (int i = 0; i < 8; i++)
        cout << Troco[i] << " ";
}

int main() {
    dinheiro_a_pagar();
    obter_sobra();
    Obter_moedasEmTroco();
    mostrar_resultado();
    return 0;
}
