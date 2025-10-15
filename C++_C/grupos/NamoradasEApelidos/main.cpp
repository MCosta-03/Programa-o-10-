#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");

	string Nomes[5];
	string SubNom[5];
	char c = 'n';
	int Select = 0;

	for (int i = 0; i < 5; i++) {
		cout << "Diz o nome da tua " << i+1 << "º namorada!: ";
		cin >> Nomes[i];
	}

	for (int i = 0; i < 5; i++) {
		cout << "Diz o subnome da tua " << i+1 << "º namorada!: ";
		cin >> SubNom[i];
	}

	while (c == 'n') {
		cout << "Diz aí um número de 1 a 5: ";
		cin >> Select;

		cout << "o nome é : " << Nomes[Select] << " e o apelido é " << SubNom[Select] << " !";

		cout << "Queres continuar? :";
		cin >> c;
	}

	return 0;
}