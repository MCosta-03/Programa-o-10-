#include <iostream>
#include <locale>

using namespace std;
int main() {
	int times = 0;
	int nSum = 0;
	int n = 0;

	setlocale(LC_ALL, "Portuguese");

	cout << "Quantos n�meros queres somar?: ";
	cin >> times;

	for (int i = 0; i < times; i++) {
		cout << "Diz o n�mero pela " << i+1 << " vez: ";
		cin >> n;

		nSum += n;
	}

	cout << "A soma de todos os n�meros foi: " << nSum << " !";

	return 0;
}