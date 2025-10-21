#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");
	srand(time(0));



	string nomes[5];
	int idades[5];
	for (int i = 0; i < 5; i++) {
		cout << "Diz o "<< i+1 << "º nome: ";
		cin >> nomes[i];
		idades [i]= (rand() % 40) + 15;
	}
	int num;
	cout << "Diz um n de 1 a 5: ";
	cin >> num;

	cout << "O nome dela é " << nomes[num-1] << " a idade dela é " << idades[num-1] << ".";
	
	return 0;
}