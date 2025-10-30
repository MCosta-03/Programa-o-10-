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
    for (int i = 0; i < 20; i++) {
        cout << "Diz o " << i + 1 << "º número: ";

        if (i < 10) {
            cin >> num_first_generation[i];
        }
        else {
            cin >> num_second_generation[i-10];
        }
    }

    for (int i = 0; i < 20; i++) {
        if (i < 10) {
            all_nums[i] = num_first_generation[i];
        }
        else {
            all_nums[i] = num_second_generation[i - 10];
        }
    }

    for (int i = 0; i < 20; i++) {
        cout << all_nums[i] << "\n";
    }

    return 0;
}