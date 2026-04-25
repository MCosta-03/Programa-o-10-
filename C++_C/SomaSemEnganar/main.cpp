#include <iostream>
#include <string>
#include <locale.h>
#include <cstdlib>
#include <time.h>
using namespace std;

int main(){
    int nlinha[3];
    cin >> nlinha[0] >> nlinha[1] >> nlinha[2];

    int maiorLinha = 0;
    if(nlinha[0] >= nlinha[1])      maiorLinha = nlinha[0];
    else if(nlinha[1] >= nlinha[0]) maiorLinha = nlinha[1];
   
    int reserva = 0, keep = 0, erro = 0;
    int l1[20]={0}, l2[20]={0}, l3[20] = {0};

    for(int i = nlinha[0]; i > 0; i--)
        cin >> l1[i];
    for(int i = nlinha[1]; i > 0; i--)
        cin >> l2[i];
    for(int i = nlinha[2]; i > 0; i--)
        cin >> l3[i];

    for(int i = 1; i < maiorLinha+1; i++){
        if(keep == 1){
            keep = 0;
            i -= 1;
            reserva = 0;
        }

        int soma = 0;
        soma = l1[i] + l2[i];
        if(reserva != 0){
            soma += reserva;
            reserva = 0;
        }    

        if(soma >= 10){
            char temp[3] = {0};
            itoa(soma, temp, 10);
            reserva = temp[0] - '0';
            temp[0] = temp[1];
            temp[1] = ' ';
            soma = atoi(temp);

            if(soma != l3[i])   keep = 1;
        }
        
        if(soma != l3[i])   erro++;
    }
    cout << "\n" << erro << endl;
    return 0;
}
