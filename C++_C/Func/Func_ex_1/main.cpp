#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <climits>
using namespace std;

int Numeros_escolhidos[10] = { 0 };

int Calc_MaiorNumero() {
    int value = INT_MIN;
    for (int i = 0; i < 10; i++)
        if (value < Numeros_escolhidos[i])
            value = Numeros_escolhidos[i];
    return value;
}

int Calc_MenorNumero() {
    int value = INT_MAX;
    for (int i = 0; i < 10; i++)
        if (value > Numeros_escolhidos[i])
            value = Numeros_escolhidos[i];
    return value;
}

int Calc_Media() {
    int value = 0;
    for (int i = 0; i < 10; i++)
        value += Numeros_escolhidos[i];

    return value / 10;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    cout << "Vou perguntar 10 números....\n\n";
    for (int i = 0; i < 10; i++) {
        cout << "Diz o " << i + 1 << "º número: ";
        cin >> Numeros_escolhidos[i];
    }
    system("cls");

    int op = 0;
    do {
        cout << "O------------------------------------------------O\n"
            "| MENU                                           |\n"
            "|------------------------------------------------|\n"
            "| 1 - Calcular a média dos números               |\n"
            "| 2 - Achar o menor número                       |\n"
            "| 3 - Achar o maior número                       |\n"
            "| 0 - Sair                                       |\n"
            "O------------------------------------------------O\n";
        cout << "Opção: ";
        cin >> op;

        switch (op)
        {
        case 1:
            system("cls");
            cout << "A média dos númros foi: " << Calc_Media() << ".\n";

            cout << "Enter para voltar ao menu...";
            cin.ignore();
            cin.get();
            system("cls");
            break;
        case 2:
            system("cls");
            cout << "O menor númro foi: " << Calc_MenorNumero() << ".\n";

            cout << "Enter para voltar ao menu...";
            cin.ignore();
            cin.get();
            system("cls");
            break;
        case 3:
            system("cls");
            cout << "O maior númro foi: " << Calc_MaiorNumero() << ".\n";

            cout << "Enter para voltar ao menu...";
            cin.ignore();
            cin.get();
            system("cls");
            break;
        case 0:
            return 0;
            break;
        default:
            system("cls");
            cout << "Opção inválida, tenta outra vez...\n\n";
            break;
        }
    } while (op != 0);
    return 0;
}
