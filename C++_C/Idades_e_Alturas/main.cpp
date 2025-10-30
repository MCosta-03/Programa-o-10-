#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    int idades[30] = {0};
    float altura[30] = { 0 };
    int pessoal_menor_de_13 = 0;
    int inferior = 0;
    for (int i = 0; i < 30; i++) {
        do {
            if (idades[i] > 150) {
                cout << "Idade inválida! Tenta outra vez.\n";
            }
            cout << "qual tua idade colega do " << i + 1 << "º colega?: ";
            cin >> idades[i];
            if (idades[i] <= 13) {
                pessoal_menor_de_13++;
            }
        } while (idades[i] > 150);
       
        do {
            if (altura[i] > 2.80) {
                cout << "Altura inválida! Tenta outra vez.\n";
            }
            cout << "qual tua altura " << i+1 << "º colega ?: ";
            cin >> altura[i];
        } while (altura[i] > 2.80);
    }
    float media = 0;
    for (int i = 0; i < 30; i++) {
        media += altura[i];
    }

    for (int i = 0; i < 30; i++) {
        if (idades[i] <= 13 && altura[i] < media) {
            inferior++;
        }
    }

    cout << "\nA média de todas as alturas foi: " << media / 30 << "!\n";
    cout << "Existe " << pessoal_menor_de_13 << " menores de 13 anos\n";
    cout << "Existe alturas inferiores como " << inferior << " alunos menores de 13 anos \n";

    return 0;

}
