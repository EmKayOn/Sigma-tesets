#include "CatColor.h"
#include <iostream>
#include <string.h>

int main(){
    char catColorFather;
    while (std::cin >> catColorFather)
    {
        CatColor cat;
        cat.setFatherColor("black");
        std::string color = cat.getFatherColor();
        std::cout << color <<std::endl;
    }
    
    return 0;
}