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
    }else if(fatherColor == "Lilac"){
        fatherGene = "bbdd";
    }else {
        fatherGene = "Unknown";
    }
    return fatherGene;
}
std::string CatColor::identifyMotherGene(){
    
    if(motherColor == "Red"){
        motherGene = "D-OO";
    }else if(motherColor == "Cream"){
        motherGene = "ddOO";
    }else if(motherColor == "Black"){
        motherGene = "B-D-";
    }else if(motherColor == "Blue"){
        motherGene = "B-dd";
    }else if(motherColor == "Chocolate"){
        motherGene = "bbD-";
    }else if(motherColor == "Lilac"){
        motherGene = "bbdd";
    }else if(motherColor == "Black-Red Tortie"){
        motherGene = "B-D-Oo";
    }else if(motherColor == "Blue-Cream Tortie"){
        motherGene = "B-ddOo";
    }else if(motherColor == "Chocolate-Red Tortie"){
        motherGene = "bbD-Oo";
    }else if(motherColor == "Lilac-Cream Tortie"){
        motherGene = "bbddOo";
    }else {
        motherGene = "Unknown";
    }
    return motherGene;
}

std::string CatColor::calculatePossibilities(){
    fatherGene
}

CatColor::~CatColor(){}
