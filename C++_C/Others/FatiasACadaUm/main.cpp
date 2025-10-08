#include <iostream>
#include <locale>

using namespace std;
int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int fatias = 0;
	int familiares = 0;
	int fatias_cada_um = 0;
	int pessoas_que_sobram = 0;
	int fatias_que_sobraram = 0;

	cout << "Quantas fatias tem o bolo?: ";
	cin >> fatias;

	cout << "Quantos familiares? :";
	cin >> familiares;

	if (familiares > fatias) {
		fatias_cada_um = familiares / fatias;
		pessoas_que_sobram = familiares % fatias;
	}
	else {
		fatias_cada_um = fatias / familiares;
	}
	
    if(fatias > familiares){
	    fatias_que_sobraram = fatias % familiares;
	}
	
	if (fatias_cada_um == 1) {
		cout << "Dá " << fatias_cada_um << " fatia a cada um. ";
	}
	else {
		cout << "Dá " << fatias_cada_um << " fatias a cada um. ";
	}

	if (pessoas_que_sobram != 0) {
		if (pessoas_que_sobram == 1) {
			cout << "E sobrou " << pessoas_que_sobram << " pessoa sem fatia.";
		}
		else {
			cout << "E sobraram " << pessoas_que_sobram << " pessoas sem fatia.";
		}
	}else if (fatias_que_sobraram != 0) {
		if (fatias_que_sobraram == 1) {
			cout << "E sobrou " << fatias_que_sobraram << " fatia.";
		}
		else {
			cout << "E sobrou " << fatias_que_sobraram << " fatias.";
		}
	}
	return 0;
}
