#include <iostream>

int main() {
	int n = 1;

	while (n != 0) {
		std::cout << "Diz um n�mero: ";
		std::cin >> n;

		if ((n % 2) == 0) {
			std::cout << "N�mero � par!\n";
		}
		else {
			std::cout << "N�mero n�o � par!\n";
		}
	}
	std::cout << "Digitou 0 - vai sair do programa...\n";
	return 0;
}