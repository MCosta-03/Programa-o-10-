#include <iostream>

using namespace std;

int main() {
    int vistas = 0;
    int last = 0;
    int n_pessoas;
    cin >> n_pessoas;

    int n_alturas[1000];

    for(int i = 0; i < n_pessoas; i++)
        cin >> n_alturas[i];
    n_alturas[n_pessoas + 1] = 0;

    for (int i = 0; i < n_pessoas-1; i++) {
        last = n_alturas[i];
        if (last > n_alturas[i+1]) {
            vistas++;
        }
    }

    cout << vistas << endl;
    return 0;
}
