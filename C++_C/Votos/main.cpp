#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int votos[100];
    int n_votos = 0;
    int maior_voto = 0;

    do {
        cout << "Diz a tua votação de 1 a 23: ";
        cin >> votos[n_votos];

        if (maior_voto < votos[n_votos]) {
            maior_voto = votos[n_votos];
        }

        if (votos[n_votos] <= 23 && votos[n_votos] >= 0) {
            n_votos++;
        }
        else {
            cout << "É só de 1 a 23, tenta outra vez..\n";
        }
        
    } while (votos[n_votos-1] != 0);

    cout << "Votaram " << n_votos-1 << " pessoas\n";

    int percentagens = 0;
    for (int i = 0; i < n_votos; i++) {
        percentagens = (votos[i] * 100) / maior_voto;
        cout << "O jogador " << i + 1 << " - " << percentagens << "%\n";
    }

    return 0;
}