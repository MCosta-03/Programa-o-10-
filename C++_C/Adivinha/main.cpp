#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");
	srand(time(0));

	int num = rand() % 100 + 1;
	int usr_num = 0;

	cout << "Vou escolher um número de 0 a 100...\n";

	while (usr_num != num) {
		cout << "Tenta adivinhar o número: ";
		cin >> usr_num;

		if (usr_num == num) {

		}
		else if(usr_num < num){
			cout << "Pista: mais a cima...\n";
		}
		else if (usr_num > num) {
			cout << "Pista: mais a baixo...\n";
		}
	}

	cout << "Acertaste!!!!";
	
	return 0;
}