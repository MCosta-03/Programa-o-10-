#include <iostream>
#include <string>
#include <locale.h>
#include <cstdlib>
#include <time.h>
using namespace std;

int main(){
    int times = 0, n_fila = 0;
    cin >> times;  

    int fila[50000] = {0};
    int trocas[20] = {0};
    int temp_troca = 0;
    for(int i = 0; i < times; i++){
        cin >> n_fila;
        for(int A = 0; A < n_fila; A++)
            cin >> fila[A];

        for(int A = 0; A < n_fila; A++){
            if(fila[A-1] > fila[A]){
                temp_troca = fila[A-1];
                fila[A-1] = fila[A]; 
                fila[A] = temp_troca;
                trocas[i]++;
                A = 0;
            }
        }
    }
    for(int i = 0; i < times; i++){
        if(trocas[i] == 1 || trocas[i] == 0)  cout << "SIM " << endl;
        else                                  cout << "NAO " << endl;
    }
    return 0;
}
