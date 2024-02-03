#include "CatColor.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

int main() {
    // Example usage
    std::string motherColor = "Lilac-Cream Tortie";
    std::string fatherColor = "Black";

    CatColor cat( fatherColor, motherColor);
    std::vector<std::string> childrenCombinations = cat.generateChildrenCombinations();

    for (const auto& combination : childrenCombinations) {
        std::cout << combination << std::endl;
    }
    return 0;
}