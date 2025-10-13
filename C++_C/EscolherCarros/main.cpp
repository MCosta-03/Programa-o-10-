#include <iostream>
#include <locale>
#include <string>

#include <stdio.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");

	char c = 'n';
	string Escolhas[3] = { "Volvo", "BMW", "Mercedes" };
	int escolha;

	cout << "Vou fazer uma pergunta e tu vais escolher...\n\n";

	while (c == 'n') {
		cout << "\nEstes são os carros:";
		for (int i = 0; i < 3; i++) {
			cout << "\n" << i << " -> " << Escolhas[i];
		}

		cout << "\nSe fosses escolher um carro, qual escolhias?: ";
		cin >> escolha;

		if (escolha < 3 && escolha > -1) {
			cout << "Escolheste o " << Escolhas[escolha] << " !\n";
		}
		else {
			cout << "\nEscolha inválida!\n";
		}

		cout << "Queres sair? (y/n): ";
		cin >> c;
	}
	
	return 0;

}
