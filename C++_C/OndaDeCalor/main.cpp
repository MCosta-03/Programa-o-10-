#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;
int main() {
    setlocale(LC_ALL, "Portuguese");

    int temp_media = 0, n_dias = 0, ultrapassou = 0, temp = 0;
    cin >> temp_media;
    cin >> n_dias;
    for (int i = 0; i < n_dias; i++) {
        cin >> temp;
        if (temp > temp_media + 5) ultrapassou++;
    }
    if (ultrapassou >= 6) cout << "WAVE";
                     else cout << "FLAT";
    return 0;
}
