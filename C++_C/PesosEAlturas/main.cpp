#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int escolha = 0;
    float alturas[10] = { 0 };
    float pesos[10] = { 0 };
    float IMC_lindo = 0;
    float IMC_lindo_media = 0;
    int pessoa = 0;

    for (int j = 0; j < 4; j++) {
        do {
            if (escolha < 0 || escolha > 3) {
                cout << "Escolha inválida!\n";
            }

            cout << "\n1 - Digitar altura e peso de 10 pessoas.\n";
            cout << "2 - Calcular IMC de um dos utilizadores.\n";
            cout << "3 - Calcular a média dos IMC's\n";
            cout << "0 - Sair\n";
            cin >> escolha;
        } while (escolha < 0 || escolha > 3);

        if (escolha == 1) {
            cout << "\nDiz as 10 alturas e pesos.\n";
            for (int i = 0; i < 10; i++) {
                cout << "Diz a altura da " << i + 1 << "º pessoa: ";
                cin >> alturas[i];
                cout << "Diz o peso da " << i + 1 << "º pessoa: ";
                cin >> pesos[i];
            }
        }
        else if (escolha == 2) {
            cout << "Diz o número da pessoa: ";
            cin >> pessoa;

            IMC_lindo = (pesos[pessoa] / (alturas[pessoa] * alturas[pessoa]));
            cout << "O IMC ficou " << IMC_lindo;
        }
        else if (escolha == 3) {
            for (int i = 0; i < 10; i++) {
                IMC_lindo_media += (pesos[i] / (alturas[i] * alturas[i]));
            }
           
            cout << "A média foi: " << (IMC_lindo_media/10);
        }
        else if (escolha == 0) {
            return 0;
        }
    }
    return 0;
}