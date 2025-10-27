#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");

	int list[10] = { 15, 2, 53, 4, 1, 17, 5, 23, 45, 19 };
	int AUX = 0;
	int trocas = 0;

	do {
		trocas = 0;
		for (int i = 0; i < 10; i++) {
			if (list[i] > list[i + 1]) {
				AUX = list[i];
				list[i] = list[i + 1];
				list[i+1] =AUX;
				trocas++;
			}
		}
	} while (trocas != 0);

	for (int i = 0; i < 10; i++)
		cout << list[i] << "\n";
	return 0;

}
