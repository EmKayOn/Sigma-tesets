#include "CatColor.h"
#include <iostream>
#include <string.h>

int main(){
    std::string catColorFather, catColorMother;
    while (std::cin >> catColorFather)
    {
        std::cin >> catColorMother;
        CatColor cat(catColorFather, catColorMother);
        
        std::cout << cat.getFatherColor() <<std::endl;

        cat.setFatherColor("Red");
        
        std::cout << cat.getFatherColor() <<std::endl;
        std::cout << cat.identifyFatherGene() <<std::endl;
        std::cout << cat.identifyMotherGene() <<std::endl;
    }
    return 0;
}