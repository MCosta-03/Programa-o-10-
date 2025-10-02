#include <iostream>
#include <locale>

using namespace std;
int main() {
	int times = 0;
	int nSum = 0;
	int n = 0;

	setlocale(LC_ALL, "Portuguese");

	cout << "Quantos números queres somar?: ";
	cin >> times;

	for (int i = 0; i < times; i++) {
		cout << "Diz o número pela " << i+1 << " vez: ";
		cin >> n;

		nSum += n;
	}

	cout << "A soma de todos os números foi: " << nSum << " !";

	return 0;
}