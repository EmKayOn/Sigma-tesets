#ifndef ___catcolor___
#define ___catcolor___
////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <iomanip>
#include <algorithm>

struct ColorProbability {
    std::string color;
    double probability;
};


class CatColor
{
private:
    std::string fatherColor, motherColor;
    std::string fatherGene, motherGene;
    std::vector<ColorProbability> Possibilities;
    
public:
    CatColor();
    CatColor(std::string fatherColor,std::string motherColor);
    
    std::string identifyFatherGene();
    std::string identifyMotherGene();

    void domRecGenePossibilities(char blackGene1, char blackGene2,char dilutionGene1, char dilutionGene2);
    void oneRedParrentPossibilities(char blackGene1,char dilutionGene1, char dilutionGene2);
    void twoRedParrentPossibilities(char dilutionGene1, char dilutionGene2);
    void tortieParentPossibilities(char blackGene1, char blackGene2,char dilutionGene1, char dilutionGene2);
    void printOutPossibilities();

    std::vector<std::string> generateChildrenCombinations();
    void differentGenePossibilities(char gene1, char gene2, char differentGene);
    void calculatePossibilities();

    std::string identifyColor(const std::string& gene);
    ~CatColor();

private:

};
/////////////////////////////////////////////////
#endif // __catcolor__