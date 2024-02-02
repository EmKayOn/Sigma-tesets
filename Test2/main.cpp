#include "CatColor.h"
#include <iostream>
#include <string.h>

int main() {
    std::string femaleColor, maleColor;

    // Get input for female and male colors
    //std::getline(std::cin, femaleColor);
    //std::getline(std::cin, maleColor);

    // Create CatColor object
    CatColor cat(femaleColor, maleColor);

    // Calculate and print possibilities
    char fatherGene = 'B';
    char motherGene = 'b';

    std::string probabilities = cat.calculatePossibilities(fatherGene, motherGene);
    
    std::cout << probabilities << std::endl;

    return 0;
}