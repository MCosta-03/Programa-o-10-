#include <iostream>
#include <locale>
#include <string>
using namespace std;
int main() {
	setlocale(LC_ALL, "Portuguese");
	char cf;
	float temp;
	cout << "Digite C  ou F";
	cin >> cf;
 
	cout << "Quantos Graus quer converter? ";
	cin >> temp;
	float temperatura = 0;
	if (cf == 'f') {
		//C = (c - 32) × 5/9
	//	temperatura = ((temp - 32) * (5 / 9));
		temperatura = (temp * 9 / 5) + 32;
		cout << "Temp em graus Fahqualquercoisa =  " << temperatura << "º";
	} else {
		temperatura = (temp - 32) * 5 / 9;
		cout << "Temp em graus celcius =  " << temperatura << "º";
 
	}

	return 0;
}