#include <iostream>

int main() {
	int n1, n2, n3, n_result;
	std::cout << "Vou perguntar 3 n�meros...\n";

	std::cout << "Diz o primeiro n�mero: ";
	std::cin >> n1;

	std::cout << "Diz o segundo n�mero: ";
	std::cin >> n2;

	std::cout << "Diz o terceiro n�mero: ";
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

	std::cout << "O maior n�mero �: " << n_result << "!\n";

	return 0;
}