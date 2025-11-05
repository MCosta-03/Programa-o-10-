/*
*   A lígua dos P´S é estranha, Coisa marada..
*/

#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    string word;
    int tamanho=0;

    cout << "Diz uma palavra: ";
    cin >> word;

    //Inicializar a string porque se não não dá nada!
    string result = "                                                                                                ";
    
    //strlen -> obter o tamanho da palavra
    for (int i = 0; i < strlen(word.c_str()); i++) {
        result[tamanho]=word[i];
        tamanho++;
        //Verificar se é uma vogal, em caso de minúscula ou maiúscula
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' ||
            word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U') {
            result[tamanho] = 'p';
            tamanho++;                                          //definir a posição, aumentando 1 a 1.
            result[tamanho] = word[i];
            tamanho++;
        }
    }
    cout << result;
    return 0;
}