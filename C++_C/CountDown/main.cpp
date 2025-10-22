#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int num = 0;
	cout << "Diz um número: ";
	cin >> num;

	for (int i = num; i > -1; i--) {
		cout << i << "\n";
	}
	
	return 0;
}