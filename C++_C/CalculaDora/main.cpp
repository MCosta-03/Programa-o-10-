#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	float nLeft, nRight, resultado = 0;
	int error_ocurred = 0;
	char Resposta;
	cout << "Veu perguntar 2 números....\n";

	cout << "Diz o primeiro número: ";
	cin >> nLeft;

	cout << "Diz o segundo número: ";
	cin >> nRight;

	cout << "Queres multiplicar(x), dividir(:), subtrair(-) ou somar(+) -> ";
	cin >> Resposta;

	switch (Resposta){
		case 'x':
			resultado = nLeft * nRight;
			break;

		case ':':
			if (nRight == 0) {
				cout << "Conta inválida!\n";
				error_ocurred = 1;
			}	
			else {
				resultado = nLeft / nRight;
			}
			break;

		case '-':
			resultado = nLeft - nRight;
			break;

		case '+':
			resultado = nLeft + nRight;
			break;
	}

	if(error_ocurred == 0)
		cout << "O resultado foi: " << resultado;	
	
	return 0;
}