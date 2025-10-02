#include <iostream>
#include <random>

int main() {
	int code = 0000;
	int times = 0;
	int continueApp = 0;
	int usrCode = 0000;

	while (continueApp == 0) {
		code = rand() % 9999;
		if (code < 1000) {

		}
		else {
			continueApp = 1;
		}
	}
	std::cout << code << std::endl;

	while(code != usrCode){
		std::cout << "Adivinha o código: ";
		std::cin >> usrCode;

		if (usrCode != code) {
			std::cout << "Código errado!\n";
			times++;
		}

		if (times == 10) {
			std::cout << "Erraste o código, Vai bloquear!\n";
			return 0;
		}
	}
	std::cout << "Acertas-te o código parabéns!!!\n";

	return 0;
}
