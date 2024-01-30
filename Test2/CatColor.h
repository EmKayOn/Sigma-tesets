#ifndef ___catcolor___
#define ___catcolor___
////////////////////////////////////////////////
#include <iostream>
#include <string>

class CatColor
{
private:
    std::string fatherColor, motherColor;
    std::string fatherGene, motherGene;

public:
    CatColor(std::string fatherColor,std::string motherColor);
    void setFatherColor(std::string fatherColor);
    void setMotherColor(std::string motherColor);
    void setFatherGene(std::string fatherGene);
    void setMotherGene(std::string motherGene);
    std::string getFatherColor();
    std::string getMotherColor();
    std::string getFatherGene();
    std::string getMotherGene();
    std::string identifyFatherGene();
    std::string identifyMotherGene();
    ~CatColor();
};
/////////////////////////////////////////////////
#endif // __catcolor__