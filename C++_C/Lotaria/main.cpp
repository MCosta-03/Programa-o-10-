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
    int repeat = 0;

    do {
        repeat = 0;
        for (int i = 0; i < 5; i++) {
            nums[i] = (rand() % 50) + 1;
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (nums[i] == nums[j] && j != i) {
                    repeat = 1;
                }
            }
        }
    } while (repeat == 1);

    for (int i = 0; i < 5; i++)
        cout << nums[i] << "\n";

    cout << "\nVou perguntar 5 números de 1 a 50....\n";
    for (int i = 0; i < 5; i++) {
        cout << "Diz o " << i + 1 << "º número: ";
        cin >> usr_nums[i];

        if (usr_nums[i] > 50 || usr_nums[i] < 1) {
            cout << "Número inválido! Tenta outra vez!\n";
            i--;
        }
        else {
            if (usr_nums[i] == nums[i]) {
                correct_nums++;
            }
        }
    }

    int AUX = 0;
    int trocas = 0;

    do {
        trocas = 0;
        for (int i = 0; i < 10; i++) {
            if (nums[i] > nums[i + 1]) {
                AUX = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = AUX;
                trocas++;
            }
        }
    } while (trocas != 0);

    cout << "A chave foi: ";
    for (int i = 0; i < 5; i++) {
        cout << "\n" << nums[i];
    }

    if (correct_nums == 5) {
        cout << "\nPARABÉNS GANHASTE 1 MILHÃO DE BITCOIN";
    }
    else {
        cout << "\nE acertaste " << correct_nums << " números!";
    }

    return 0;
}
