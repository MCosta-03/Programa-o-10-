/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*Fazer médias com 4 números*/

#include <iostream>

int main(){
    int p, p1, p2, p3, total;
    std::cout << "Vou pedir 4 númros...\n" << std::endl;
    
    std::cout   << "Diz um número pela 1 vez: ";
    std::cin    >>  p; 
    
    std::cout   << "Diz um número pela 2 vez: ";
    std::cin    >>  p1; 
    
    std::cout   << "Diz um número pela 3 vez: ";
    std::cin    >>  p2; 
    
    std::cout   << "Diz um número pela 4 vez: ";
    std::cin    >>  p3; 

    total = (p + p1 + p2 + p3)/4;
    std::cout   << "A média foi: " << total << "!";
    return 0;
}
