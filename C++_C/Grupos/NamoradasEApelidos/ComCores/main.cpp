#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");

	string Nomes[5];
	string SubNom[5];
	char c = 'y';
	int Select = 0;

	for (int i = 0; i < 5; i++) {
		cout << "Diz o nome da tua " << i + 1 << "º namorada!: ";
		cin >> Nomes[i];
	}

	for (int i = 0; i < 5; i++) {
		cout << "Diz o subnome da tua " << i + 1 << "º namorada!: ";
		cin >> SubNom[i];
	}

	while (c == 'y') {
		cout << "\nDiz aí um número de 1 a 5: ";
		cin >> Select;

		if (Select > 5 || Select < 1) {
			system("cls && color 4");
			cout << "Número inválido! Tenta outravez!\n";
		}
		else {
			system("cls && color 2");
			cout << "O nome é : " << Nomes[Select-1] << " e o apelido é " << SubNom[Select-1] << " !\n";

			cout << "Queres continuar?(y/n) :";
			cin >> c;
		}
	}

	return 0;
}