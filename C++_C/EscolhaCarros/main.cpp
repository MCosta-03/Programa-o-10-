#include <iostream>
#include <locale>
#include <string>

#include <stdio.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");

	string Escolhas[3] = { "Volvo", "BMW", "Mercedes" };
	int escolha;

	cout << "Vou fazer um pergunta e tu vais escolher...\n\n";

	cout << "Estes são os carros:";
	for (int i = 0; i < 3; i++) {
		cout << "\n" << i << " -> " << Escolhas[i];
	}

	cout << "\nSe escolhesses um carro, qual escolhias?: ";
	cin >> escolha;

	cout << "Escolheste o " << Escolhas[escolha] << " !";

	return 0;
}