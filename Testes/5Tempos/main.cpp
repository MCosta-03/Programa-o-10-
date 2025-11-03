#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int times[5];
    int maior = 0;
    int menor = 0;

    for (int i = 0; i < 5; i++) {
        cout << "Diz o " << i + 1 << "º tempo em minutos: ";
        cin >> times[i];
    }

    int mudou = 0;
    int AUX = 0;
    do {
        mudou = 0;
        for (int i = 0; i < 5; i++) {
            if (times[i] > times[i + 1]) {
                mudou++;

                AUX = times[i];
                times[i] = times[i + 1];
                times[i + 1] = AUX;
            }
        }
    } while (mudou != 0);

    int escolha = 0;
    int media = 0;

    cout << "Que quer calcular?\n";
    cout << "1 - Média dos tempos.\n";
    cout << "2 - Tempo mais alto.\n";
    cout << "3 – Tempo mais baixo.\n";
    cin >> escolha;

    switch (escolha)
    {
        case 1:
            for (int i = 0; i < 5; i++) {
                media += times[i];
            }
            cout << "A média foi: " << media / 5 << endl;
        break;

        case 2:
            cout << "O maior foi: " << times[4];
        break;

        case 3:
            cout << "O menor foi: " << times[0];
        break;
    default:
        break;
    }

    return 0;
}