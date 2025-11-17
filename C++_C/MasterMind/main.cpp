#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(0));

    int code[4];
    int usr[4];
    int usr_times = 0;
    int usr_corrects = 0;
    int continue_the_fun = 1;
    for (int i = 0; i < 4; i++) {
        code[i] = rand() % 2;
    }

    for (int i = 0; i < 4; i++)
        cout << code[i];

    do{
        for (int j = 0; j < 4; j++) {
            cout << "Diz o " << j + 1 << "º número:";
            cin >> usr[j];
        }

        for (int j = 0; j < 4; j++) {
            if (code[j] == usr[j]) {
                usr_corrects++;
            }
        }

        if (usr_corrects == 4) {
            continue_the_fun = 0;
        }

        cout << "Acertaste " << usr_corrects << " vezes.\n";
        usr_corrects = 0;
        usr_times++;
    } while (continue_the_fun == 1);
    cout << "Demoras-te " << usr_times << " tentativas até acertares.\n";

    return 0;
}