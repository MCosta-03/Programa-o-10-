
#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    cout << "Vou pedir 5 números...\n\n";

    int nums[5] = { 0 };
    int verify_num = 0;
    for (int i = 0; i < 5; i++) {
        cout << "Diz o " << i + 1 << "º número: ";
        cin >> nums[i];
    }

    cout << "Qual quer verificar?: ";
    cin >> verify_num;

    int nums_found = 0;         //Só para ver se encontrou algum número...
    int num_pos = 0;

    for (int i = 0; i < 5; i++) {
        if (nums[i] == verify_num) {
            num_pos = i;
        }
    }

    /*Vamos verificar os que estão antes do número para verificar*/
    for (int i = num_pos; i < 5; i++) {
        if (nums[i] < verify_num) {
            cout << "Temos o " << nums[i] << ".\n";
            nums_found++;
        }
    }
    
    /*Em caso se não houver nenhum encontrado.*/
    if (nums_found == 0) {
        cout << "Nenhum.\n";
    }

    return 0;
}