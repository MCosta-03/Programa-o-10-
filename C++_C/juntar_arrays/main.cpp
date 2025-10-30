#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int num_first_generation[10] = { 0 };
    int num_second_generation[10] = { 0 };
    int all_nums[20];

    cout << "Vou pergunta 20 números..\n";
    for (int i = 0; i < 10; i++) {
        cout << "Diz um número do 1º array: ";
        cin >> num_first_generation[i];

        cout << "Diz um número do 2º array: ";
        cin >> num_second_generation[i];
    }

    int times = 0;
    for (int i = 0; i < 20; i++) {
        times++;
        if (times == 1) {
            all_nums[i] = num_first_generation[i / 2];
        }
        else if (times == 2) {
            all_nums[i] = num_second_generation[i / 2];
            times = 0;
        }
    }


    for (int i = 0; i < 20; i++) {
        cout << all_nums[i] << "\n";
    }

    return 0;
}
