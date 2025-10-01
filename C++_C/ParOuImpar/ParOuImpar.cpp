#include <iostream>

int main() {
	int n = 1;

	while (n != 0) {
		std::cout << "Diz um número: ";
		std::cin >> n;

		if ((n % 2) == 0) {
			std::cout << "Número é par!\n";
		}
		else {
			std::cout << "Número não é par!\n";
		}
	}
	std::cout << "Digitou 0 - vai sair do programa...\n";
	return 0;
}