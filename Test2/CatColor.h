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
    double dominantGene, recessiveGene, dominantextraGene, recessiveextraGene;
public:
    CatColor(std::string fatherColor,std::string motherColor);
    void setFatherColor(std::string fatherColor);
    void setMotherColor(std::string motherColor);
    void setFatherGene(std::string fatherGene);
    void setMotherGene(std::string motherGene);
    std::string getFatherColor();
    std::string getMotherColor();
    std::string identifyFatherGene();
    std::string identifyMotherGene();
    std::string getFatherGene();
    std::string getMotherGene();

    void domRecGenePossibilities(char fGene, char mGene);
    void differentGenePossibilities(char gene1, char gene2, char differentGene);
    void calculatePossibilities();
    void CatColor::tortieColor();

    std::string identifyColor(const std::string& gene);
    ~CatColor();
};
/////////////////////////////////////////////////
#endif // __catcolor__