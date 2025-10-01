#include <iostream>

int main() {
	int n1, n2, n3, n_result;
	std::cout << "Vou perguntar 3 números...\n";

	std::cout << "Diz o primeiro número: ";
	std::cin >> n1;

	std::cout << "Diz o segundo número: ";
	std::cin >> n2;

	std::cout << "Diz o terceiro número: ";
	std::cin >> n3;

	if (n1 > n2 && n1 > n3) {
		n_result = n1;
	}
	else if (n2 > n1 && n2 > n3) {
		n_result = n2;
	}
	else {
		n_result = n3;
	}

	std::cout << "O maior número é: " << n_result << "!\n";

	return 0;
}