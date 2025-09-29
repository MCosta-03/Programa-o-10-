/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

int main()
{
    int gastos, kmi, kmf, litros;
    std::cout<<"Quantos litros? :";
    std::cin >> litros;
    
    std::cout << "Km iniciais: ";
    std::cin >> kmi;
    
    std::cout << "Km finais: ";
    std::cin >> kmf;
    
    gastos = 100*litros/(kmf-kmi);
    std::cout << "Gastou: " << gastos << " aos 100!" << std::endl;
    return 0;
}