#include "CatColor.h"
#include <iostream>
#include <string>


CatColor::CatColor(){}

////////////////////////////////////////////////////
//////////////// Setters ///////////////////////////
void CatColor::setFatherColor(std::string fatherColor){
    this->fatherColor;
}
void CatColor:: setMotherColor(std::string motherColor){
    this->motherColor;
}
void CatColor::setFatherGene(std::string fatherGene){
    this->fatherGene;
}
void CatColor::setMotherGene(std::string motherGene){
    this->motherGene;
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
std::string CatColor::identifyFatherGene(std::string color){
    std::string gene;
    if(color == "Red"){
        gene = "D-O";
    }else if(color == "Cream"){
        gene = "ddO";
    }else if(color == "Black"){
        gene = "B-D-";
    }else if(color == "Blue"){
        gene = "B-dd";
    }else if(color == "Chocolate"){
        gene = "bbD-";
    }else if(color == "Lilic"){
        gene = "bbdd";
    }
}

CatColor::~CatColor(){}
