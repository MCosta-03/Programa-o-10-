#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    srand(time(0));

    int nums[5];
    int usr_nums[5];
    int correct_nums = 0;

    for (int i = 0; i < 5; i++) {
        nums[i] = (rand() % 49) + 1;
    }

    cout << "Vou perguntar 5 n�meros de 1 a 50....\n";
    for (int i = 0; i < 5; i++) {
        cout << "Diz o " << i + 1 << "� n�mero: ";
        cin >> usr_nums[i];

        if (usr_nums[i] > 50 || usr_nums[i] < 1) {
            cout << "N�mero inv�lido! Tenta outra vez!\n";
            i--;
        }
        else {
            if (usr_nums[i] == nums[i]) {
                correct_nums++;
            }
        }
    }

    cout << "A chave foi: ";
    for (int i = 0; i < 5; i++) {
        cout << "\n" << nums[i];
    }

    if (correct_nums == 5) {
        cout << "\nPARAB�NS GANHASTE 1 MILH�O DE BITCOIN";
    }else {
        cout << "\nE acertaste " << correct_nums << " n�meros!";
    }

    return 0;
}