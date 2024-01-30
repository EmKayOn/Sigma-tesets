#include "CatColor.h"
#include <iostream>
#include <string>


CatColor::CatColor(std::string fatherColor,std::string motherColor)
:fatherColor(fatherColor),motherColor(motherColor) {}

////////////////////////////////////////////////////
//////////////// Setters ///////////////////////////
void CatColor::setFatherColor(std::string fatherColor){
    this->fatherColor = fatherColor;
}
void CatColor:: setMotherColor(std::string motherColor){
    this->motherColor = motherColor;
}
void CatColor::setFatherGene(std::string fatherGene){
    this->fatherGene = fatherGene;
}
void CatColor::setMotherGene(std::string motherGene){
    this->motherGene = motherGene;
}
////////////////////////////////////////////////////
//////////////// Getters ///////////////////////////
std::string CatColor::getFatherColor(){
    return fatherColor;
}
std::string CatColor::getMotherColor(){
    return motherColor;
}
std::string CatColor::getFatherGene(){
    return fatherGene;
}
std::string CatColor::getMotherGene(){
    return motherGene;
}
/////////////(Functions)///////////////////////////
///////////////////////////////////////////////////

std::string CatColor::identifyFatherGene(){
    
    if(fatherColor == "Red"){
        fatherGene = "D-O";
    }else if(fatherColor == "Cream"){
        fatherGene = "ddO";
    }else if(fatherColor == "Black"){
        fatherGene = "B-D-";
    }else if(fatherColor == "Blue"){
        fatherGene = "B-dd";
    }else if(fatherColor == "Chocolate"){
        fatherGene = "bbD-";
    }else if(fatherColor == "Lilic"){
        fatherGene = "bbdd";
    }else {
        fatherGene = "Unknown";
    }
    return fatherGene;
}
std::string CatColor::identifyMotherGene(){
    
    if(motherColor == "Red"){
        motherGene = "D-O";
    }else if(motherColor == "Cream"){
        motherGene = "ddO";
    }else if(motherColor == "Black"){
        motherGene = "B-D-";
    }else if(motherColor == "Blue"){
        motherGene = "B-dd";
    }else if(motherColor == "Chocolate"){
        motherGene = "bbD-";
    }else if(motherColor == "Lilic"){
        motherGene = "bbdd";
    }else {
        motherGene = "Unknown";
    }
    return motherGene;
}

CatColor::~CatColor(){}
