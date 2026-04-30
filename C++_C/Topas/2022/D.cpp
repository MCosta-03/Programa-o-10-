#include <iostream>
#include <string>
using namespace std;
 
int main() {
    int lx, ly;
    int labirinto[50][50];
 
    cin >> lx >> ly;
 
    for (int i = 0; i < lx; i++) {
        for (int j = 0; j < ly; j++) {
            cin >> labirinto[i][j];
        }
    }
 
    int numero_seguir = labirinto[0][0];
    int soma = numero_seguir;
    string letras;
 
    int ln = 0, visitado = 0;
    labirinto[ln][visitado] = 0;
 
    bool anda = true;
    while (anda) {
        anda = false;
        if (ln > 0 && labirinto[ln - 1][visitado] == numero_seguir) {
            ln--;
            letras += 'C';
            anda = true;
        }
        else if (visitado < ly - 1 && labirinto[ln][visitado + 1] == numero_seguir) {
            visitado++;
            letras += 'D';
            anda = true;
        }
        else if (ln < lx - 1 && labirinto[ln + 1][visitado] == numero_seguir) {
            ln++;
            letras += 'B';
            anda = true;
        }
        else if (visitado > 0 && labirinto[ln][visitado - 1] == numero_seguir) {
            visitado--;
            letras += 'E';
            anda = true;
        }
 
        if (anda) {
            soma += numero_seguir;
            labirinto[ln][visitado] = 0;
        }
    }
 
    cout << letras << endl;
    cout << soma << endl;
 
    return 0;
}
