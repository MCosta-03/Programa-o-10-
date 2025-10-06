#include <iostream>
#include <locale>

using namespace std;
int main() {

	setlocale(LC_ALL, "Portuguese");

	cout << "Vou perguntar 4 produtos...\n";

	/*Valores fixos*/
	float Sandes		= 1;
	float Bolos			= 0.8;
	float Refrigerantes = 1.5;
	float cafe			= 0.6;

	/*Valores a cobrar*/
	float Sandes_c			= 0;
	float Bolos_c			= 0;
	float Refrigerantes_c	= 0;
	float cafe_c			= 0;

	int Sandes_Quantidade			= 0;
	int Bolos_Quantidade			= 0;
	int Refrigerantes_Quantidade	= 0;
	int cafe_Quantidade				= 0;

	float lucro = 0;

	cout << "Vendes sandes por quanto?: ";
	cin >> Sandes_c;
	cout << "Quantas?: ";
	cin >> Sandes_Quantidade;

	cout << "Vendes Bolos por quanto?: ";
	cin >> Bolos_c;
	cout << "Quantos?: ";
	cin >> Bolos_Quantidade;

	cout << "Vendes Refrigerantes por quanto?: ";
	cin >> Refrigerantes_c;
	cout << "Quantos?: ";
	cin >> Refrigerantes_Quantidade;

	cout << "Vendes cafe por quanto?: ";
	cin >> cafe_c;
	cout << "Quantos?: ";
	cin >> cafe_Quantidade;

	lucro = (Sandes_c - Sandes)* Sandes_Quantidade + (Bolos_c - Bolos)* Bolos_Quantidade + (Refrigerantes_c - Refrigerantes)* Refrigerantes_Quantidade + (cafe_c - cafe)* cafe_Quantidade;

	cout << "O lucro do bar foi: " << lucro << " euros";

	return 0;
}