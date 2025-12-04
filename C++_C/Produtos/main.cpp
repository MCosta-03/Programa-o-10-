#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int resp = 0;
    bool ready = false;

    int gastos_dos_produtos[5][12] = {{ 0 }, { 0 }};

    int totais_mensais = 0;
    int totais_do_produtos = 0;

    string meses[12] = {
        "janeiro",
        "fevereiro",
        "março",
        "abril",
        "maio",
        "junho",
        "julho",
        "agosto",
        "setembro",
        "outubro",
        "novembro",
        "dezembro"
    };
    string produtos[5] = {
        "Batatas",
        "Cenouras",
        "Couves",
        "Alfaces",
        "Bróculos"
    };

    do {
        cout << "O==========================================O\n"
                "| O produto.                               |\n"
                "|------------------------------------------|\n"
                "| 0 - sair                                 |\n"
                "| 1 - calcular totais mensais              |\n"
                "| 2 - calcular totais por produto          |\n"
                "| 3 - Inserir valores                      |\n"
                "O==========================================O\n\n" << endl;

        cout << "Opção: ";
        cin >> resp;
        switch (resp)
        {
        case 1:
            if (ready == true) {
                system("cls");
                for (int i = 0; i < 12; i++) {
                    for (int j = 0; j < 5; j++) {
                        totais_mensais += gastos_dos_produtos[j][i];
                    }
                }

                cout << "Todos os produtos gastos em cada mês foi: " << totais_mensais << ".\n";
                totais_mensais = 0;

                cout << "Enter para sair...\n";
                cin.ignore();
                cin.get();
                system("cls");
            }
            else {
                system("cls");
                cout << "Tens que inserir primeiro!\n";
            }
            break;

        case 2:
            if (ready == true) {
                system("cls");

                cout << "Os gastos de cada produto em 1 ano.\n\n";
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 12; j++) {
                        totais_do_produtos += gastos_dos_produtos[i][j];
                    }
                    cout << "Os gastos de " << produtos[i] << " foram " << totais_do_produtos << ".\n";
                    totais_do_produtos = 0;
                }
                totais_do_produtos = 0;

                cout << "Enter para sair...\n";
                cin.ignore();
                cin.get();
                system("cls");
            }
            else {
                system("cls");
                cout << "Tens que inserir primeiro!\n";
            }
            break;

        case 3:
            ready = true;
            system("cls");
            cout << "Vais dizer os gastos dos 5 produtos em 12 meses!\n\n";

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 12; j++) {
                    cout << "O número de gastos de " << produtos[i] << " no " << j+1 << "º mês: ";
                    cin >> gastos_dos_produtos[i][j];
                }
            }

            system("cls");
            break;

        case 0:
            break;
        default:
            system("cls");
            cout << "Opção inválida! Tenta outra vez....\n";
            break;
        }
    } while (resp != 0);

    return 0;
}