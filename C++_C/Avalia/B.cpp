#include <iostream>
#include <string>
#include <locale.h>
#include <cstdlib>
#include <time.h>
using namespace std;

int main(){
    int n_aldeias = 0, n_perguntas = 0, disponiveis = 0;
    cin >> n_aldeias >> n_perguntas;

    int AldeiasPos[200000] = {0};
    static int Perguntas[200000][2] = {0};
    for(int i = 0; i < n_aldeias;i++){
        cin >> AldeiasPos[i];
    }
    for(int i = 0; i < n_perguntas;i++){
        cin >> Perguntas[i][0] >> Perguntas[i][1];
    }
    for(int i = 0; i < n_perguntas;i++){
        for(int A = 0; A < n_aldeias; A++){
            if(AldeiasPos[A] >= Perguntas[i][0] && Perguntas[i][1] >= AldeiasPos[A]){
                disponiveis++;
            }
        }
        cout << disponiveis << " " << endl;
        disponiveis = 0;
    }
    return 0;
}