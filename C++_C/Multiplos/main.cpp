#include <iostream>
#include <locale>

using namespace std;
int main() {
	setlocale(LC_ALL, "Portuguese");

	int num = 0;

	do {
		cout << "Diz um número: ";
		cin >> num;

		if (num == 0) {
			return 0;
		}

		if ((num % 5) == 0) {
			cout << "É multiplo 5!\n";
		}
		else {
			cout << "Não é multiplo 5!\n";
		}

		if ((num % 3) == 0) {
			cout << "É multiplo 3!\n";
		}
		else {
			cout << "Não é multiplo 3!\n";
		}

	} while (num != 0);

	return 0;
}