#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    string nomes[10] = {"António", "Anabela", "Beatriz", "Bernardo", "Clara", "Carlos", "Diana", "Diogo", "Elisabete", "Eurico"};
    string disciplinas[10] = {"Portugues", "Ingles", "Fisica", "TLP", "TIC", "Matemática", "ACS", "Filosofia", "Quimica", "Ed.Fis."};

    int turma[10][10];
    int total = 0;

    int A_nota_especial = 0;
    string disciplina_do_especial;
    string nome_do_especial;

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            cout << "Diz a nota do " << nomes[x] << " na disciplina " << disciplinas[y] << ": ";
            cin >> turma[x][y];

            if (A_nota_especial < turma[x][y]) {
                A_nota_especial = turma[x][y];
                disciplina_do_especial = disciplinas[y];
                nome_do_especial = nomes[x];
            }
        }
    }

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            total += turma[x][y];
        }
        cout << "A média da nota da disciplina de " << disciplinas[y] << " foi: " << total / 10 << endl;
        total = 0;
    }

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            total += turma[x][y];
        }
    }

    cout << "\nA média de notas das disciplinas foi: " << total / (10*10) << endl;
    cout << "E a maior nota foi: " << A_nota_especial << " de " << nome_do_especial << " na disciplina de " << disciplina_do_especial << endl;

    cout << "Enter para sair...";

    cin.ignore();
    cin.get();
    return 0;
}