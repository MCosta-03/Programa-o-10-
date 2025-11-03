#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    srand(time(0));
    int rand_num = (rand() % 100);

    cout << "Vamos ver como está o clima....\n\n";

    cout << "Está a " << rand_num << "%!\n";

    if (rand_num <= 30) {
        cout << "O clima está seco...\n";
    }
    else if (rand_num >= 31 && rand_num < 60) {
        cout << "Confortável.\n";
    }
    else if(rand_num >= 60){
        cout << "Húmido.";
    }

    return 0;
}