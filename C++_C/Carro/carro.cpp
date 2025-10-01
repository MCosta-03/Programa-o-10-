#include <iostream>

int main()
{
    int gastos, kmi, kmf, litros;
    std::cout << "Quantos litros? :";
    std::cin >> litros;

    std::cout << "Km iniciais: ";
    std::cin >> kmi;

    std::cout << "Km finais: ";
    std::cin >> kmf;

    gastos = (100 * litros) / (kmf - kmi);
    std::cout << "Gastou: " << gastos << " a cada 100!" << std::endl;
    return 0;
}