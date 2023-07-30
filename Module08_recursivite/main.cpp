
#include <iostream>
#include "compteARebours.h"

int main()
{
    compteARebours(10, 5);
    std::cout<<std::endl;
    compteARebours(10);
    std::cout << std::endl;
    compteARebours(100, 0, 10);
    std::cout << std::endl;
    float resultat = divisionEntiere(99, 26);
    std::cout << "resultat division: " << resultat << std::endl;
}
