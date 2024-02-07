#include "CatColor.h"
#include <iostream>
#include <string>
#include <functional>

CatColor::CatColor(){}
CatColor::CatColor(std::string fatherColor,std::string motherColor)
:fatherColor(fatherColor),motherColor(motherColor) {}


/////////////(Functions)///////////////////////////
///////////////////////////////////////////////////
std::string CatColor::identifyFatherGene(){
    
    if(fatherColor == "Red"){
        fatherGene = "D-Oo";
    }else if(fatherColor == "Cream"){
        fatherGene = "ddOo";
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
        motherGene = "D-Oo";
    }else if(motherColor == "Cream"){
        motherGene = "ddOo";
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
    if (gene == "D-Oo" || gene == "D-OO") {
        return "Red";
    } else if (gene == "ddOo" || gene == "ddOO" ) {
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
    }else if (gene == "D-Oo"){
        return "Red";
    }else if (gene == "ddOo"){
        return "Cream";
    }else {
        return "Unknown";
    }
}
///////////////////////////////////////////////////////////////////////
////takes first gene from bothe parents and return possibilities //////
////////////// Returns: dominantGene  recessiveGene ///////////////////
///////////////////////////////////////////////////////////////////////
void CatColor::domRecGenePossibilities(char blackGene1, char blackGene2,char dilutionGene1, char dilutionGene2){ // DONE
    
    double blackProb1, blackProb2;
    if (isupper(blackGene1) && isupper(blackGene2) ) {
        blackProb1 = (0.75 + (0.75 * 0.25));  // B-
        blackProb2 = (0.25 * 0.25);  // bb
    } else if (islower(blackGene1) && islower(blackGene2)) {
        blackProb1 = 0.0;   // No B-
        blackProb2 = 1.0;   // bb
    } else {
        blackProb1 = 0.75;  // B-
        blackProb2 = 0.25;  // bb
    }

    double dilutionProb1, dilutionProb2;
    if (isupper(dilutionGene1) && isupper(dilutionGene2) ) {
        dilutionProb1 = (0.75 + (0.75 * 0.25));  // D-
        dilutionProb2 =(0.25 * 0.25);  // dd
    } else if (islower(dilutionGene1) && islower(dilutionGene2)) {
        dilutionProb1 = 0.0;   // No D-
        dilutionProb2 = 1.0;   // dd
    } else {
        dilutionProb1 = 0.75;  // D-
        dilutionProb2 = 0.25;  // dd
    }
    Possibilities.push_back({"B-D-", blackProb1 * dilutionProb1});
    Possibilities.push_back({"B-dd", blackProb1 * dilutionProb2});
    Possibilities.push_back({"bbD-", blackProb2 * dilutionProb1});
    Possibilities.push_back({"bbdd", blackProb2 * dilutionProb2});
}

void CatColor::oneRedParrentPossibilities(char blackGene1,char dilutionGene1, char dilutionGene2, bool isFemale){ // DONE
    
    double blackProb1, blackProb2;

        if (isupper(blackGene1))
        {
            blackProb1 = 0.75 + (0.5 * 0.25);
            blackProb2 = 1 - blackProb1;
        } else {
            blackProb1 = 0.0;  // B-
            blackProb2 = 1.0;  // bb
        }

    double dilutionProb1, dilutionProb2;
    if (isupper(dilutionGene1) && isupper(dilutionGene2) ) {
        dilutionProb1 = (0.75 + (0.75 * 0.25));  // D-
        dilutionProb2 =(0.25 * 0.25);  // dd
    } else if (islower(dilutionGene1) && islower(dilutionGene2)) {
        dilutionProb1 = 0.0;   // No D-
        dilutionProb2 = 1.0;   // dd
    } else {
        dilutionProb1 = 0.75;  // D-
        dilutionProb2 = 0.25;  // dd
    }

    if (isFemale) // The Mother is has O gene
    {

        Possibilities.push_back({"D-OO", dilutionProb1 / 2});
        Possibilities.push_back({"ddOO", dilutionProb2 / 2});
        Possibilities.push_back({"B-D-Oo", (blackProb1 * dilutionProb1) / 2});
        Possibilities.push_back({"B-ddOo", (blackProb1 * dilutionProb2) / 2});
        Possibilities.push_back({"bbD-Oo", (blackProb2 * dilutionProb1) / 2});
        Possibilities.push_back({"bbddOo", (blackProb2 * dilutionProb2) / 2});
    }else {
        Possibilities.push_back({"B-D-", (blackProb1 * dilutionProb1) / 2});
        Possibilities.push_back({"B-D-Oo", (blackProb1 * dilutionProb1 / 2)});
        Possibilities.push_back({"B-dd", (blackProb1 * dilutionProb2) / 2});
        Possibilities.push_back({"B-ddOo", (blackProb1 * dilutionProb2 / 2)});
        Possibilities.push_back({"bbD-",( blackProb2 * dilutionProb1) / 2});
        Possibilities.push_back({"bbD-Oo", (blackProb2 * dilutionProb1) / 2});
        Possibilities.push_back({"bbdd", (blackProb2 * dilutionProb2) / 2});
        Possibilities.push_back({"bbddOo", (blackProb2 * dilutionProb2) / 2});
    }
    

}

void CatColor::tortieParentPossibilities(char blackGene1, char blackGene2,char dilutionGene1, char dilutionGene2){ 

    double blackProb1, blackProb2;
    if (isupper(blackGene1) && isupper(blackGene2) ) {
        blackProb1 = (0.75 + (0.75 * 0.25));  // B-
        blackProb2 = (0.25 * 0.25);  // bb
    } else if (islower(blackGene1) && islower(blackGene2)) {
        blackProb1 = 0.0;   // No B-
        blackProb2 = 1.0;   // bb
    } else {
        blackProb1 = 0.75;  // B-
        blackProb2 = 0.25;  // bb
    }

    double dilutionProb1, dilutionProb2;
    if (isupper(dilutionGene1) && isupper(dilutionGene2) )  {
        dilutionProb1 = (0.75 + (0.75 * 0.25));  // D-
        dilutionProb2 =(0.25 * 0.25);  // dd
    } else if (islower(dilutionGene1) && islower(dilutionGene2)) {
        dilutionProb1 = 0.0;   // No D-
        dilutionProb2 = 1.0;   // dd
    } else {
        dilutionProb1 = 0.75;  // D-
        dilutionProb2 = 0.25;  // dd
    }
    Possibilities.push_back({"B-D-", (blackProb1 * dilutionProb1) / 2});
    Possibilities.push_back({"B-dd", (blackProb1 * dilutionProb2) / 2});
    Possibilities.push_back({"bbD-", (blackProb2 * dilutionProb1) / 2});
    Possibilities.push_back({"bbdd", (blackProb2 * dilutionProb2) / 2});
    Possibilities.push_back({"D-OO", dilutionProb1 / 4});
    Possibilities.push_back({"ddOO", dilutionProb2 / 4});
    Possibilities.push_back({"B-D-Oo", (blackProb1 * dilutionProb1) / 4});
    Possibilities.push_back({"B-ddOo", (blackProb1 * dilutionProb2) / 4});
    Possibilities.push_back({"bbD-Oo", (blackProb2 * dilutionProb1) / 4});
    Possibilities.push_back({"bbddOo", (blackProb2 * dilutionProb2) / 4});
}

void CatColor::OneRedOneTortiePossibilities(char blackGene1,char dilutionGene1, char dilutionGene2){
    double blackProb1, blackProb2;
    if (isupper(blackGene1))
    {
        blackProb1 = (0.75 + (0.75 * 0.25));  // B-
        blackProb2 = 0.25 * 0.25;
    } else {
        blackProb1 = 0.0;  // B- 
        blackProb2 = 1.0;  // bb
    }

    double dilutionProb1, dilutionProb2;
    if (isupper(dilutionGene1) && isupper(dilutionGene2) ) {
       dilutionProb1 = (0.75 + (0.75 * 0.25));  // D-
        dilutionProb2 =(0.25 * 0.25);  // dd
    } else if (islower(dilutionGene1) && islower(dilutionGene2)) {
        dilutionProb1 = 0.0;   // No D-
        dilutionProb2 = 1.0;   // dd
    } else {
        dilutionProb1 = 0.75;  // D-
        dilutionProb2 = 0.25;  // dd
    }
    //Male 50% Red
    Possibilities.push_back({"D-OO", (dilutionProb1)  * 0.50 });
    Possibilities.push_back({"ddOO", (dilutionProb2)  * 0.50 });

    Possibilities.push_back({"B-D-Oo", (blackProb1 * dilutionProb1) * 0.25 });
    Possibilities.push_back({"B-ddOo", (blackProb1 * dilutionProb2) * 0.25  });
    Possibilities.push_back({"bbD-Oo", (blackProb2 * dilutionProb1) * 0.25 });
    Possibilities.push_back({"bbddOo", (blackProb2 * dilutionProb2)  * 0.25 });
}

void CatColor::twoRedParrentPossibilities(char dilutionGene1, char dilutionGene2){
    double dilutionProb1, dilutionProb2;
    if (isupper(dilutionGene1) && isupper(dilutionGene2))
    {
        dilutionProb1 = 0.75 + ( 0.75 * 0.25); // D-
        dilutionProb2 =(0.25 * 0.25);     // dd
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
bool comparePossibilities(const ColorProbability& a, const ColorProbability& b) {
    // Compare by probability in descending order
    if (a.probability != b.probability) {
        return a.probability > b.probability;
    }
    // If probabilities are equal, compare by color in alphabetic order
    return a.color < b.color;
}




void CatColor::printOutPossibilities(){

    identifyMotherGene();
    identifyFatherGene();

    if (motherColor.find("Tortie") != std::string::npos) 
    {   
        if (fatherColor == "Red" || fatherColor == "Cream")
        {
            OneRedOneTortiePossibilities(motherGene[0],motherGene[2], fatherGene[0]);

        }else{
            tortieParentPossibilities(fatherGene[0], motherGene[0],fatherGene[2], motherGene[2]);
        }
        
    }
    else 
    {  
        if ((fatherColor == "Red" || fatherColor == "Cream" ) && (motherColor == "Red" || motherColor == "Cream"))
        {
            twoRedParrentPossibilities(motherGene[0], fatherGene[0]);
        }
        else if (fatherColor == "Red" || fatherColor == "Cream")
        {
            oneRedParrentPossibilities(motherGene[0],motherGene[2], fatherGene[0], 0);
        }
        else if (motherColor == "Cream" || motherColor == "Red" )
        {
            oneRedParrentPossibilities( fatherGene[0],fatherGene[2], motherGene[0], 1);
        }
        else if (fatherColor != "Red" && motherColor != "Red")//NO red parrent
        {
            domRecGenePossibilities(fatherGene[0], motherGene[0],fatherGene[2], motherGene[2]);
        }
    }
     // Sort the Possibilities vector using the custom comparison function
    std::sort(Possibilities.begin(), Possibilities.end(), comparePossibilities);

    
    
    // Printing the sorted Possibilities
    for (const auto& entry : Possibilities) {
        if (entry.probability > 0) {
            std::cout << identifyColor(entry.color)  << " " << std::fixed << std::setprecision(9) <<entry.probability << std::endl;
        }
    }
    
}


CatColor::~CatColor(){}
