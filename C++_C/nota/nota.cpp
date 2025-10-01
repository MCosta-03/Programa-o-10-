#include <iostream>

int main() {
	float nota = 0;

	std::cout << "Diz a tua nota: ";
	std::cin >> nota;

	if (nota < 20 && nota > 0) {
		if (nota > 9.5) {
			std::cout << "Estás aprovado!";
		}
		else {
			std::cout << "Não foste aprovado!";
		}
	}
	return 0;
}
