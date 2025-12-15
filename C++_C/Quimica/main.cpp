#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    /*Só para dizer a formula*/
    string formula;
    while (true) {
        cout << "\nDiz a formula química: ";
        cin >> formula;

        if (formula == ".") {
            return 0;/*Para sair*/
        }

        string resultado;   //O resultado que vai obter.
        int n = 0;          //0 = não teve número, 1 = teve número
        int fez = 0;        //Isto são a etapas que fez
        int outravez = 0;   //Isto é no caso se for sempre Maiusculas sem numero

        //Fazer um for com o tamanho da string que o utilizador escreveu (formula.length() -> tamanho da string).
        for (int i = 0; i < formula.length(); i++) {

            /*Verifica se a formula[i], que é neste caso (char), se está dento de "A" e "Z"*/
            if (formula[i] >= 'A' && formula[i] <= 'Z') {
                /*Colocar 1 em caso da formula não tiver número*/
                if (outravez == 2) {
                    resultado += " 1";//Se for só maiuscula
                    outravez = 0;
                }
                else if (n == 0 && fez == 2)
                    resultado += " 1";//Se for minuscula e não tiver numero

                resultado += "\n";      //Mudar a linha na string
                resultado += formula[i];//Escrever para dentro da string a formula(Maiusculas)
                outravez++;             //no caso for só maiuscula, colocar sempre 1 se não tem número.
                n = 0;                  //Colocar o n a 0 para começar outra vez.
            }
            else if (formula[i] >= 'a' && formula[i] <= 'z') {
                resultado += formula[i];
                fez = 2;                //Para dizer que chegou à etapa 2
            }

            /*Verifica se a formula[i], está em "0" e "9"*/
            if (formula[i] >= '0' && formula[i] <= '9') {
                /*muda n para 1, porque existe número*/
                if (n == 0) {
                    resultado += " ";
                    n = 1;
                }
                resultado += formula[i];
                outravez = 0;//Colocar outravez a 0, para não gerar conflito.
            }
        }

        /*No caso, se já acabou a equação, coloca número 1, se não tiver número*/
        if (n == 0)
            resultado += " 1";

        cout << resultado;//Mostrar resultado
    }
    return 0;
}
