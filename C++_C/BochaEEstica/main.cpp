#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");

	int n = 0;
	int times = 0;

	int maior = -2147483647;
	int menor = 2147483647;

	cout << "Vou perguntar várias vezes números...\n\n";
	do {
		cout << "Diz um número pela " << times + 1 << "º vez: ";
		cin >> n;

		if (n > maior) {
			maior = n;
		}
		
		if (n < menor && n != 0) {
			menor = n;
		}

		times++;
	} while (n != 0);

	cout << "O maior número foi: " << maior << " e o menor foi " << menor << "!";

	return 0;

}
