#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    string Meses[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    int Temperaturas[12];

    cout << "Vou perguntar a temperatura de cada mês em Cº...\n";

    for (int i = 0; i < 12; i++) {
        cout << "Diz a temperatura do mês de: " << Meses[i] << ": ";
        cin >> Temperaturas[i];
    }

    int tudo = 0;
    int media = 0;
    for (int i = 0; i < 12; i++) {
        tudo += Temperaturas[i];
    }
    media = tudo / 12;

    cout << "A média foi cerca de: " << media << "Cº\n";

    for (int i = 0; i < 12; i++) {
        if (Temperaturas[i] > media) {
            cout << "O mês de " << Meses[i] << " ultrapassou " << Temperaturas[i] - media << " Cº\n";
        }
    }

    return 0;
}