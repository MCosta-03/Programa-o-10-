#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");

	char c = 'n';
	string Escolhas[4] = { "Matemática", "Português", "Inglês", "Fisica Química"};
	int escolha;

	cout << "Vou fazer uma pergunta e tu vais escolher...\n\n";

	while (c == 'n') {
		cout << "\nEscolhe um número de 0 a 3: ";
		cin >> escolha;

		if (escolha < 4 && escolha > -1) {
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
