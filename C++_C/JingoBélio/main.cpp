#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    string nomes[3] = { "Mateus", "Clara", "Brunão" };
    string produtos[3] = { "Batatas Fritas", "Bolo rei", "Perfume" };

    int quantidades[3][3], total = 0, total_por_pessoa[3] = {0 };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Diz a quantidade de " << produtos[j] << " para " << nomes[i] << ": ";
            cin >> quantidades[i][j];
            total += quantidades[i][j];
            total_por_pessoa[i] += quantidades[i][j];
        }
    }
    cout << "O total de produtos foi : " << total << endl;
    cout << "O total de " << produtos[0] << " foi de " << quantidades[0][0] + quantidades[1][0] + quantidades[2][0] << endl;
    cout << "O total de " << produtos[1] << " foi de " << quantidades[0][1] + quantidades[1][1] + quantidades[2][1] << endl;
    cout << "O total de " << produtos[2] << " foi de " << quantidades[0][2] + quantidades[1][2] + quantidades[2][2] << endl;

    cout << "O total do " << nomes[0] << "foi: " << total_por_pessoa[0] << endl;
    cout << "O total do " << nomes[1] << "foi: " << total_por_pessoa[1] << endl;
    cout << "O total do " << nomes[2] << "foi: " << total_por_pessoa[2] << endl;
    return 0;
}
