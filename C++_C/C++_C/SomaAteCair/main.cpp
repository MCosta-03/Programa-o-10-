#include <iostream>
#include <locale>

using namespace std;
int main() {
	int n = 0;
	int n_Sum = 0;
	int times = 0;
	setlocale(LC_ALL, "Portuguese");

	cout << "Vou perguntar vários números!\n";

	while (n_Sum < 1000) {
		times++;
		cout << "Diz um número pela " << times << " vez: ";
		cin >> n;

		n_Sum += n;
	}

	cout << "A soma total: " << n_Sum << " !";
	cout << "A média foi :" << n_Sum / times << " !";
	cout << "Foram utilizados " << times << " números!";

	return 0;
}