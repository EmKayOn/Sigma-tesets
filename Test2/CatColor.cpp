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

std::string CatColor::identifyColor(const std::string& gene) {
    if (gene == "D-OO") {
        return "Red";
    } else if (gene == "ddOO") {
        return "Cream";
    } else if (gene == "B-D-") {
        return "Black";
    } else if (gene == "B-dd") {
        return "Blue";
    } else if (gene == "bbD-") {
        return "Chocolate";
    } else if (gene == "bbdd") {
        return "Lilac";
    } else if (gene == "B-D-Oo") {
        return "Black-Red Tortie";
    } else if (gene == "B-ddOo") {
        return "Blue-Cream Tortie";
    } else if (gene == "bbD-Oo") {
        return "Chocolate-Red Tortie";
    } else if (gene == "bbddOo") {
        return "Lilac-Cream Tortie";
    } else {
        return "Unknown";
    }
}
///////////////////////////////////////////////////////////////////////
////takes first gene from bothe parents and calculate possibilities ///
////////////// Returns: dominantGene  recessiveGene ///////////////////
///////////////////////////////////////////////////////////////////////
void CatColor::domRecGenePossibilities(char fGene, char mGene){
    fGene = std::toupper(fGene);
    mGene = std::toupper(mGene); // to make if (fGene == mGene) excute if one is lower case
    if (fGene == mGene)
    {
        if (isupper(fGene)) // both dominant 
        {
            dominantGene = 0.75 + (0.75 * 0.25);
            recessiveGene = 0.25 * 0.25;
        }else{  //both recessiv
            dominantGene = 0.0;
            recessiveGene = 1.0;
        }
    }else { // if one gene is upper case and the secound is lower case
        dominantGene = 0.75;
        recessiveGene = 0.25;
    }
}
///////////////////////////////////////////////////////////////////////////
////////Takes Three Genes (one is diffirerent) Calculate possibilities ////
/////////////////// Returns: extraGene ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
void CatColor::differentGenePossibilities(char gene1, char gene2, char gene3) {
    char g1 = std::toupper(gene1);
    char g2 = std::toupper(gene2);
    char g3 = std::toupper(gene3);

    if ((g1 == g2) && (g1 != g3)) {
        domRecGenePossibilities(gene1, gene2); // Reuse the existing function
        if (isupper(gene3)) //when extra gene is an upper case.
        {
            dominantextraGene =  0.75 + ( 0.5 * 0.25 ); //the uppercase possibilitie.
            recessiveextraGene= 1 - dominantextraGene; //lowercase possibilitie.
        }else {        //when extra gene is a lower case.
            dominantextraGene = 1; //the uppercase possibilitie.
            recessiveextraGene = 1; // Does not exsist !!
        }
        
    } else if ((g1 == g3) && (g1 != g2)) {
        domRecGenePossibilities(gene1, gene3);
    } else if ((g2 == g3) && (g2 != g1)) {
        domRecGenePossibilities(gene2, gene3);
    } else {
        std::cout<< "ERROR: can not identify genes."<<std::endl;
    }
}


///////////////////////////////////////////////////////////////////
////////// Calculate the gene posibilities for each color /////////
///////////////////////////////////////////////////////////////////
void CatColor::calculatePossibilities() {
    double domG1, domG2;
    double resG1, resG2;
    
    // Calculate probabilities for the first gene pair
    domRecGenePossibilities(motherGene[0], fatherGene[0]);
    domG1 = dominantGene;
    resG1 = recessiveGene;

    // Check if the second gene pair is needed (when both parents are not red)
    if (motherColor != "Red" && fatherColor != "Red") {
        domRecGenePossibilities(motherGene[2], fatherGene[2]);
        domG2 = dominantGene;
        resG2 = recessiveGene;

        Possibilities.push_back({ identifyColor("B-D-"), domG1 * domG2 }); //black
        Possibilities.push_back({ identifyColor("B-dd"), domG1 * resG2 }); //blue
        Possibilities.push_back({ identifyColor("bbD-"), resG1 * domG2 }); //chocolate
        Possibilities.push_back({ identifyColor("bbdd"), resG1 * resG2 }); //lilac
    } else {
        if ((motherColor == "Red" || fatherColor == "Red") && (fatherColor == "Cream" || motherColor == "Cream")) { //one of them is red and the other is cream
            
            Possibilities.push_back({ identifyColor("D-OO"), domG1}); //red
            Possibilities.push_back({ identifyColor("ddOO"), resG1 }); //cream

        }else if (((motherColor == "Red" || fatherColor == "Red") &&   motherColor.find("Tortie") == std::string::npos))
        {
            if(motherColor == "Red" || motherColor == "Cream"){
                differentGenePossibilities( motherGene[0],  fatherGene[0],  fatherGene[2]);
            }else{
                differentGenePossibilities( motherGene[0],  fatherGene[0],  motherGene[2]);
            }

            Possibilities.push_back({ identifyColor("B-D-"), ( dominantextraGene * 0.75) / 2 }); //black
            Possibilities.push_back({ identifyColor("B-D-Oo"), (dominantextraGene * 0.75) / 2}); //black-Red-Tortie
            Possibilities.push_back({ identifyColor("B-dd"), (dominantextraGene * resG2) / 2 }); //blue
            Possibilities.push_back({ identifyColor("B-ddOo"), (dominantextraGene * resG2) / 2 }); //blue-cream-Tortie
            Possibilities.push_back({ identifyColor("bbD-"), (recessiveextraGene * domG2) / 2 }); //chocolate
            Possibilities.push_back({ identifyColor("bbD-Oo"), (recessiveextraGene * domG2) / 2  }); //chocolate-cream-Tortie
            Possibilities.push_back({ identifyColor("bbdd"), (recessiveextraGene * resG2) / 2}); //lilac
            Possibilities.push_back({ identifyColor("bbddOo"), (recessiveextraGene * resG2) / 2 }); //lilac-cream-Tortie

        }if (motherColor.find("Tortie") != std::string::npos) {

        }
        
        
        
    }
}

void CatColor::tortieColor(){
    
}


CatColor::~CatColor(){}
