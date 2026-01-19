#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

string frases_magicas[4] = {
    "Uau! Ainda vais preso!",
    "A nadar em dinheiro, ahn?",
    "Cuidado para não afundares o banco com tanto dinheiro!",
    "Já vi que finalmente tomaste banho e foste a casa da madrinha"
};

void Limpar_ecran() {
    system("cls");
}

void enter_para_sair() {
    cout << "Enter para sair..." << endl;
    cin.ignore();
    cin.get();
    Limpar_ecran();
}

int Deposito(int saldo) {
    int deposito = 0;
    Limpar_ecran();
    cout << "Quanto queres depositar?: ";
    cin >> deposito;

    if (deposito >= 2000) {
        srand(time(0));
        cout << frases_magicas[rand() % 4] << endl;
    }

    enter_para_sair();
    return deposito;
}

void Verificar_Saldo(int saldo) {
    Limpar_ecran();
    cout << "O teu saldo está: " << saldo << endl;
    enter_para_sair();
}

int Debito(int saldo) {
    Limpar_ecran();
    int retirar = 0;

    cout << "Quanto queres retirar?: ";
    cin >> retirar;

    if (retirar > saldo) {
        retirar = 0;
        cout << "Tu não tens essa quantidade de dinheiro!\n";
    }
    enter_para_sair();

    return retirar;
}

int Enviar_dienheiro(int saldo) {
    int Dinheiro_a_enviar = 0;
    Limpar_ecran();

    cout << "Quanto dinheiro queres enviar?: ";
    cin >> Dinheiro_a_enviar;

    if (saldo >= Dinheiro_a_enviar) {

    }
    else {
        Dinheiro_a_enviar = 0;
        cout << "Valor inválido, não tens esse dinhero no teu saldo!" << endl;
    }

    enter_para_sair();
    return Dinheiro_a_enviar;
}

void iniciarEcran() {
    int escolha = 0;

    int saldo = 1000;
    int limite = 2000;
    do {
        cout << "O------------------------------------------O\n"
            "|  MENU                                    |\n"
            "O------------------------------------------O\n"
            "|  1 - Deposito                            |\n"
            "|  2 - Débito                              |\n"
            "|  3 - Verificar Saldo                     |\n"
            "|  4 - Enviar Dinheiro                     |\n"
            "O------------------------------------------O\n" << endl;
        cin >> escolha;
        switch (escolha)
        {
        case 1:
            saldo += Deposito(saldo);
            break;
        case 2:
            saldo -= Debito(saldo);
            break;
        case 3:
            Verificar_Saldo(saldo);
            break;
        case 4:
            saldo -= Enviar_dienheiro(saldo);
            break;
        default:
            Limpar_ecran();
            cout << "Opção inválida, tenta outra vez...\n";
            break;
        }
    } while (true);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    iniciarEcran();

    return 0;
}
