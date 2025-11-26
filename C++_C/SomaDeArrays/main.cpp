#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int My_Array_1[3][5] = { 0 };
    int My_Array_2[3][5] = { 0 };
    int Array_Difusion[3][5] = { 0 };
    int resp = 0;
    int Array = 0;

    do {
        do {
            system("cls");
            /*Menu espetacular!*/
        cout << "O----------------------------------------------------------------O\n"
                "| Soma de arrays!                                                |\n"
                "|----------------------------------------------------------------|\n"
                "|  1 - Inserir                                                   |\n"
                "|  2 - Subtrair                                                  |\n"
                "|  0 - Sair                                                      |\n"
                "O----------------------------------------------------------------O\n" << endl;

            cout << "Opção: ";
            cin >> resp;

            if (resp < 0 || resp > 2) {
                cout << "Opção inválida! Tenta novamente.\n";
            }

            if (resp == 0) {
                return 0;
            }
        } while (resp < 0 || resp > 2);

        if (resp == 1) {
            cout << "Vou perguntar números maravilhosos..\n\n";
            for (int Y = 0; Y < 5; Y++) {
                for (int X = 0; X < 3; X++) {
                    system("cls");
                    if (Array == 0) {
                        /*Mostrar o Array*/
                        cout << "Primeiro array: \n";
                        for (int Y = 0; Y < 5; Y++) {
                            for (int X = 0; X < 3; X++) {
                                cout << "[" << My_Array_1[X][Y] << "]";
                            }
                            cout << "\n";
                        }
                        cout << "Diz um número para o primeiro: ";
                        cin >> My_Array_1[X][Y];

                        if (X == 2 && Y == 4) {
                            Array++;
                            Y = 0;
                            X = -1;
                        }
                    }
                    else if (Array == 1) {
                        cout << "Primeiro array: \n";

                        for (int Y = 0; Y < 5; Y++) {
                            for (int X = 0; X < 3; X++) {
                                cout << "[" << My_Array_1[X][Y] << "]";
                            }
                            cout << "\n";
                        }
                        cout << "\nSegundo array:\n";

                        for (int Y = 0; Y < 5; Y++) {
                            for (int X = 0; X < 3; X++) {
                                cout << "[" << My_Array_2[X][Y] << "]";
                            }
                            cout << "\n";
                        }
                        cout << "\nDiz um número para o segundo:";
                        cin >> My_Array_2[X][Y];
                    }
                }
            }
            
        }
        if (resp == 2) {
            if (Array > 0) {
                /*A subtração-------------------------------*/
                cout << "\nA soma dos dois array foi: \n";
                for (int Y = 0; Y < 5; Y++) {
                    for (int X = 0; X < 3; X++) {
                        Array_Difusion[X][Y] = My_Array_1[X][Y] - My_Array_2[X][Y];
                        cout << "[" << Array_Difusion[X][Y] << "]";
                    }
                    cout << "\n";
                }
                /*------------------------------------------*/
                cout << "enter para sair.\n";
                cin.ignore();
                cin.get();
            }
            else {
                cout << "Tens que inserir primeiro para depois subtrair!\n\n";
            }
        }
    } while (resp != 0);
    return 0;

}


