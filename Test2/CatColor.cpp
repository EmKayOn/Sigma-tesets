#include "CatColor.h"
#include <iostream>
#include <string>


CatColor::CatColor(){}
CatColor::CatColor(std::string fatherColor,std::string motherColor)
:fatherColor(fatherColor),motherColor(motherColor) {}


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
    }else if (gene == "D-OO"){
        return "Red";
    }else if (gene == "ddOO"){
        return "Cream";
    }else {
        return "Unknown";
    }
}
///////////////////////////////////////////////////////////////////////
////takes first gene from bothe parents and return possibilities //////
////////////// Returns: dominantGene  recessiveGene ///////////////////
///////////////////////////////////////////////////////////////////////
void CatColor::domRecGenePossibilities(char blackGene1, char blackGene2,char dilutionGene1, char dilutionGene2){
    
    double blackProb1, blackProb2;
    if (isupper(blackGene1) && isupper(blackGene2) ) {
        blackProb1 = 0.75;  // B-
        blackProb2 = 0.25;  // bb
    } else if (islower(blackGene1) && islower(blackGene2)) {
        blackProb1 = 1.0;   // bb
        blackProb2 = 0.0;   // No B-
    } else {
        blackProb1 = 0.75;  // B-
        blackProb2 = 0.25;  // bb
    }

    double dilutionProb1, dilutionProb2;
    if (isupper(dilutionGene1) && isupper(dilutionGene2) ) {
        dilutionProb1 = 0.75;  // D-
        dilutionProb2 = 0.25;  // dd
    } else if (islower(dilutionGene1) && islower(dilutionGene2)) {
        dilutionProb1 = 1.0;   // dd
        dilutionProb2 = 0.0;   // No D-
    } else {
        dilutionProb1 = 0.75;  // D-
        dilutionProb2 = 0.25;  // dd
    }
    Possibilities.push_back({"B-D-", blackProb1 * dilutionProb1});
    Possibilities.push_back({"B-dd", blackProb1 * dilutionProb2});
    Possibilities.push_back({"bbD-", blackProb2 * dilutionProb1});
    Possibilities.push_back({"bbdd", blackProb2 * dilutionProb2});
}

void CatColor::oneRedParrentPossibilities(char blackGene1,char dilutionGene1, char dilutionGene2){
    
    double blackProb1, blackProb2;
    if (isupper(blackGene1))
    {
        blackProb1 = 0.75 + (0.5 * 0.25);
        blackProb2 = 1 - blackProb1;
    } else {
        blackProb1 = 0.75;  // B-
        blackProb2 = 0.25;  // bb
    }

    double dilutionProb1, dilutionProb2;
    if (isupper(dilutionGene1) && isupper(dilutionGene2) ) {
        dilutionProb1 = 0.75;  // D-
        dilutionProb2 = 0.25;  // dd
    } else if (islower(dilutionGene1) && islower(dilutionGene2)) {
        dilutionProb1 = 0.0;   // No D-
        dilutionProb2 = 1.0;   // dd
    } else {
        dilutionProb1 = 0.75;  // D-
        dilutionProb2 = 0.25;  // dd
    }
    Possibilities.push_back({"B-D-", (blackProb1 * dilutionProb1) / 2});
    Possibilities.push_back({"B-D-Oo", (blackProb1 * dilutionProb1 / 2)});
    Possibilities.push_back({"B-dd", (blackProb1 * dilutionProb2) / 2});
    Possibilities.push_back({"B-ddOo", (blackProb1 * dilutionProb2 / 2)});
    Possibilities.push_back({"bbD-",( blackProb2 * dilutionProb1) / 2});
    Possibilities.push_back({"bbD-Oo", (blackProb2 * dilutionProb1) / 2});
    Possibilities.push_back({"bbdd", (blackProb2 * dilutionProb2) / 2});
    Possibilities.push_back({"bbddOo", (blackProb2 * dilutionProb2) / 2});
}

void CatColor::tortieParentPossibilities(char blackGene1, char blackGene2,char dilutionGene1, char dilutionGene2){

    double blackProb1, blackProb2;
    if (isupper(blackGene1) && isupper(blackGene2) ) {
        blackProb1 = 0.75;  // B-
        blackProb2 = 0.25;  // bb
    } else if (islower(blackGene1) && islower(blackGene2)) {
        blackProb1 = 0.0;   // No B-
        blackProb2 = 1.0;   // bb
    } else {
        blackProb1 = 0.75;  // B-
        blackProb2 = 0.25;  // bb
    }

    double dilutionProb1, dilutionProb2;
    if (isupper(dilutionGene1) && isupper(dilutionGene2) ) {
        dilutionProb1 = 0.75;  // D-
        dilutionProb2 = 0.25;  // dd
    } else if (islower(dilutionGene1) && islower(dilutionGene2)) {
        dilutionProb1 = 0.0;   // No D-
        dilutionProb2 = 1.0;   // dd
    } else {
        dilutionProb1 = 0.75;  // D-
        dilutionProb2 = 0.25;  // dd
    }

    std::string firstSetMother = motherGene.substr(0, 4);
    std::string secoundSetMother = motherGene.substr(2, 4);



    Possibilities.push_back({fatherGene, (blackProb1 * dilutionProb2) / 2});
    Possibilities.push_back({secoundSetMother , dilutionProb2 / 4 });
    Possibilities.push_back({fatherGene + "Oo", (blackProb1 * dilutionProb2) / 4 });
    Possibilities.push_back({firstSetMother, (blackProb2 * dilutionProb2) / 2 });
    Possibilities.push_back({firstSetMother + "Oo", (blackProb2 * dilutionProb2) / 4 });
}

void CatColor::twoRedParrentPossibilities(char dilutionGene1, char dilutionGene2){
    double dilutionProb1, dilutionProb2;
    if (isupper(dilutionGene1) && isupper(dilutionGene2))
    {
        dilutionProb1 = 0.75 + ( 0.75 * 0.25); // D-
        dilutionProb2 = 1 - dilutionProb1;     // dd
    }
    else if (islower(dilutionGene1) && islower(dilutionGene2))
    {
        dilutionProb1 =  0.0;
        dilutionProb2 =  1.0;
    }
    else
    {
        dilutionProb1 = 0.75;  // D-
        dilutionProb2 = 0.25;  // dd
    }
    Possibilities.push_back({"D-OO", dilutionProb1});
    Possibilities.push_back({"ddOO", dilutionProb2});
}

void CatColor::printOutPossibilities(){

    std::getline(std::cin, motherColor);
    std::getline(std::cin, fatherColor);
    
    identifyMotherGene();
    identifyFatherGene();

    if (motherColor.find("Tortie") != std::string::npos) 
    {
        tortieParentPossibilities(fatherGene[0], motherGene[0],fatherGene[2], motherGene[2]);
    } 
    else 
    {
    
        
        if ((fatherColor == "Red" || fatherColor == "Cream" ) && (motherColor == "Red" || fatherColor == "Cream"))
        {
            twoRedParrentPossibilities(motherGene[0], fatherGene[0]);
        }
        else if (fatherColor == "Red" || fatherColor == "Cream")
        {
            oneRedParrentPossibilities(motherGene[0],motherGene[2], fatherGene[0]);
        }
        else if (motherColor == "Cream" || motherColor == "Red" )
        {
            oneRedParrentPossibilities(fatherGene[0],fatherGene[2], motherGene[0]);
        }
        else if (fatherColor != "Red" && motherColor != "Red")//NO red parrent
        {
            domRecGenePossibilities(fatherGene[0], motherGene[0],fatherGene[2], motherGene[2]);
        }
        
    
    }
    for (const auto& combination : Possibilities) {
        std::cout << identifyColor(combination.color) << " " << combination.probability << std::endl;
    }

}























////////////////////////////////////////////////////////////////
////// Functions to generate children combinations///////////////
////////////////////////////////////////////////////////////////
std::vector<std::string> CatColor::generateChildrenCombinations() {
    std::vector<std::string> childrenCombinations;
    identifyMotherGene();
    identifyFatherGene();
    if (motherGene.size() > 3) //Tortie
    {
        std::string firstSetMother = motherGene.substr(0, 4);
        std::string secoundSetMother = motherGene.substr(2, 4);
        childrenCombinations.push_back(fatherGene);
        childrenCombinations.push_back(secoundSetMother);
        childrenCombinations.push_back(fatherGene + "Oo");
        childrenCombinations.push_back(firstSetMother);
        childrenCombinations.push_back(firstSetMother + "Oo");

    }else
    {
        if (motherGene[2] == 'O' && fatherGene[2] == 'O') //bothe parent are red or Cream.
        {
            //Red, Cream.
            childrenCombinations.push_back("D-OO");
            childrenCombinations.push_back("ddOO");
        }
        else if (fatherGene[2] == 'O' || motherGene[2] == 'O')
        {
            childrenCombinations.push_back("B-D-");
            childrenCombinations.push_back("B-D-Oo");
            childrenCombinations.push_back("B-dd");
            childrenCombinations.push_back("B-ddOo");
            childrenCombinations.push_back("bbD-");
            childrenCombinations.push_back("bbD-Oo");
            childrenCombinations.push_back("bbdd");
            childrenCombinations.push_back("bbddOo");
        }
        else
        {
            //Black, Blue, Chocolate, Lilac.
            // Add combinations to the vector
            childrenCombinations.push_back("B-D-");
            childrenCombinations.push_back("B-dd");
            childrenCombinations.push_back("bbD-");
            childrenCombinations.push_back("bbdd");

        }
    }
    
    return childrenCombinations;
}


/*
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
*/















///////////////////////////////////////////////////////////////////
////////// Calculate the gene posibilities for each color /////////
///////////////////////////////////////////////////////////////////
/*void CatColor::calculatePossibilities() {
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
    //mother to gene sets
    std::string firstSetMother = motherGene.substr(0, 2);
    std::string secondSetMother = motherGene.substr(2, 2);
    //father two gene sets 
    std::string firstSetFather = fatherGene.substr(0, 2);
    std::string secondSetFather = fatherGene.substr(2, 2);

    // Concatenate the two substrings
    if (fatherGene == motherGene.substr(0,4))
    {
        if (isupper(fatherGene[0])) //all gene are dominant
        {
            Possibilities.push_back({fatherColor, 0.75 / 2});
            Possibilities.push_back({identifyColor(secondSetMother + "Oo"), 0.5 / 2});
            Possibilities.push_back({identifyColor(firstSetFather + secondSetMother), (0.75 * 0.5) / 2 });
            if (fatherGene[0] == 'B'){
                Possibilities.push_back({identifyColor( "bb" + secondSetMother) , 0.25 / 2 });
                Possibilities.push_back({identifyColor( "bb" + secondSetMother + "Oo") , 0.25 * 0.5 / 2 });
            }else{
                Possibilities.push_back({identifyColor( "dd" + secondSetMother) , 0.25 / 2 });
                Possibilities.push_back({identifyColor( "dd" + secondSetMother + "Oo") , 0.25 * 0.5 / 2 });
            }
        }else //all genes are ressiciv
        {
            Possibilities.push_back({"bbdd", 0.5 });//Lilac
            Possibilities.push_back({"ddOo", 0.25});//Cream
            Possibilities.push_back({"bbddOo", 0.25});//Lilac-Cream-Tortie
        }   
    }else //both are not equal
    {
        
        
    }
}*/


CatColor::~CatColor(){}
