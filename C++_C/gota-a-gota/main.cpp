#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    int m = 0, M = 0, A = 0, B = 0, C = 0;
    cin >> m >> M >> A >> B;
    cin >> C;

    string binarios;
    int quantidade_de_gotas, adequados = 0, maior_que_valor_maximo = 0, menor_que_valor_minimo = 0;
    for (int i = 0; i < C; i++) {
        binarios = "";
        quantidade_de_gotas = 0;
        cin >> binarios;
        for (int j = 0; j < binarios.length(); j++) {
            if (binarios[j] == '1') quantidade_de_gotas++;
        }
        if (quantidade_de_gotas >= M) maior_que_valor_maximo++;
        if (quantidade_de_gotas < m) menor_que_valor_minimo++;

        if (quantidade_de_gotas >= A && quantidade_de_gotas <= B) adequados++;
    }
    cout << menor_que_valor_minimo << " " << maior_que_valor_maximo << " " << adequados;
    return 0;
}
