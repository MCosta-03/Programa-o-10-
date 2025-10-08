#include <iostream>
#include <locale>

using namespace std;
int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int num = 0;
	cout << "Diz um número: ";
	cin >> num;

	int times = 0;

	for (int i = 1; i <= num; i++) {
		if ((num % i) == 0) {
			times++;
		}
	}

	if (times == 2 || num == 1) {
		cout << "O número é primo!";
	}
	else {
		cout << "O número não é primo!";
	}	

	return 0;
}