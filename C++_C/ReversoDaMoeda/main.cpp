#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    string nomes[5];
    char c = 's';

    cout << "Vou perguntar 5 nomes!\n";

    while (c != 'n') {
        for (int i = 0; i < 5; i++) {
            cout << "Diz o " << i + 1 << "º nome: ";
            cin >> nomes[i];
        }

        cout << "Os nomes foram: ";

        for (int i = 5; i > 0; i--) {
            if (i == 1) {
                cout << nomes[i - 1] << ".\n";
            }
            else {
                cout << nomes[i - 1] << ", ";
            }
        }

        cout << "Queres continuar?(s/n): ";
        cin >> c;
    }
  

    return 0;
}