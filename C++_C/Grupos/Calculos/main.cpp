#include <iostream>
#include <locale>
#include <string>
using namespace std;
int main() {
	setlocale(LC_ALL, "Portuguese");
	int num[10];
	int pos[10];
	int times = 0, soma = 0;
	char neg, talvez;
	for (int i = 0; i < 10; i++) {
		cout << "Introduz numeros: ";
 
		cin >> num[i];
		if (num[i] < 0) {
			pos[times++] = num[i];
		}
	}
	for (int i = 0; i < times; i++) {
		soma += pos[i];
	}
 
	cout << "Queres somar os numeros? (s/n) ";
	cin >> neg;
	if(neg == 's') {
		cout << "A soma é: " << soma << "!";
	} else {
		cout << "Os números negativos são: " << times;
	}
 
	return 0;
}