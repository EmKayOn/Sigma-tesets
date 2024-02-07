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

    // Compare by probability in descending order, then by color in alphabetic order
    bool operator<(const ColorProbability& other) const {
        if (probability != other.probability) {
            return probability > other.probability;
        }
        return color < other.color;
    }
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
    void oneRedParrentPossibilities(char blackGene1,char dilutionGene1, char dilutionGene2, bool isFemale);
    void twoRedParrentPossibilities(char dilutionGene1, char dilutionGene2);
    void tortieParentPossibilities(char blackGene1, char blackGene2,char dilutionGene1, char dilutionGene2);
    void OneRedOneTortiePossibilities(char blackGene1,char dilutionGene1, char dilutionGene2);
    void printOutPossibilities();





    std::string identifyColor(const std::string& gene);
    ~CatColor();

private:

};
/////////////////////////////////////////////////
#endif // __catcolor__