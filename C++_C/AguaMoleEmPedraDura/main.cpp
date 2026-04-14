#include <iostream>
#include <string>
#include <locale.h>
#include <cstdlib>
#include <time.h>
using namespace std;

int main(){
    int cenarios[150000] = {0};
    int n_cenarios = 0;

    string numeros;
    cin >> numeros;
    cin >> n_cenarios;

    for(int i = 0; i < n_cenarios; i++)
        cin >> cenarios[i];

    int quantidade = 0;
    int quantidade_tmp = 0;
    for(int i = 0; i < numeros.length(); i++){
        if(numeros[i] == '1')   quantidade_tmp++;
        else                    quantidade_tmp = 0;

        if(quantidade_tmp > quantidade) quantidade = quantidade_tmp;
    }

    int cenarios_inferiores = 0;
    for(int i = 0; i < n_cenarios; i++)
        if(cenarios[i] < quantidade)  cenarios_inferiores++; 
    
    cout << "\n" << cenarios_inferiores;
    return 0;
}
