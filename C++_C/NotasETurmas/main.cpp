#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int turma[3][3];
    int total = 0;

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cout << "Diz a nota do " << x+1 << "º aluno da turma " << y+1 << ": ";
            cin >> turma[x][y];
        }
    }

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            total += turma[x][y];
        }
        cout << "A média da nota da turma " << y + 1 << " foi: " << total / 3 << endl;
        total = 0;
    }

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            total += turma[x][y];
        }
    }
    cout << "\nA média de notas das turmas foi: " << total / 9 << endl;

    return 0;
}