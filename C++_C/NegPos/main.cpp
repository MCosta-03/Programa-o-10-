#include <iostream>

int main() {
	int numero;
	std::cout << "escreve numero";
	std::cin >> numero;

	if (numero == 0)
		return 0;

	if (numero > 0 )
		std::cout << "o número é Positivo";
	else
		std::cout << " o numero é negativo";

	return 0;
}