#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");

	string Dis[9] = {"mat","ing","pt","fq","ai","acso","edf","TLP","cidadania"};
	string Nomes[9] = { "Silvia", "Artur","José","Saramago","Laura","martim","miguel","ines","claudio"};

	int n = 1;
	
	while (n != 0) {
		cout << "Diz uma disciplina de 1 a 9: ";
		cin >> n;
		if (n == 0)
			return 0;

		if (n > 9 || n < 1) {
			cout << "\nNúmero inválido!\nTenta novamente!\n\n";
		}
		else {
			cout << "\nA disciplina que escolheste é " << Dis[n - 1] << " e o nome é: " << Nomes[n - 1] << "!\n";
		}
	}
	return 0;
}