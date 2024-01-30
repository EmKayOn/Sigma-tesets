#include "CatColor.h"
#include <iostream>
#include <string.h>

int main(){
    std::string catColorFather;
    while (std::cin >> catColorFather)
    {
        CatColor cat(catColorFather, "Red");
        
        std::cout << cat.getFatherColor() <<std::endl;

        cat.setFatherColor("Red");
        
        std::cout << cat.getFatherColor() <<std::endl;
        std::cout << cat.identifyFatherGene() <<std::endl;
    }
    return 0;
}