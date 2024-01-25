#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Ingredient {
public:
    std::string name;
    float weight;
    float percentage;
};

class Recipe {
public:
    int numOfIngredients;
    int recipePortions;
    int desiredPortions;
    std::vector<Ingredient> ingredients;

    Recipe(){}
    Recipe(int numOfIngredients, int recipePortions, int desiredPortions)
        : numOfIngredients(numOfIngredients), recipePortions(recipePortions), desiredPortions(desiredPortions),
            ingredients(numOfIngredients) {}

    void readIngredients() {
        for (size_t j = 0; j < numOfIngredients; j++) {
            std::cin >> ingredients[j].name >> ingredients[j].weight >> ingredients[j].percentage;
        }
    }

    void scaleRecipe() {
        float mainIngredient = 0.0;
        // loop to fined the main ingredient weight
        for (size_t j = 0; j < numOfIngredients; j++){
            if (ingredients[j].percentage == 100){
                mainIngredient = ingredients[j].weight;
            }
        }
        for (size_t j = 0; j < numOfIngredients; j++) {
            float scalingFactor = desiredPortions / static_cast<float>(recipePortions);
            
            if (ingredients[j].percentage == 100) {
                std::cout << ingredients[j].name << " " << std::fixed << std::setprecision(1) << (ingredients[j].weight * scalingFactor) << "\n";
                
            } else {
                // Calculate the scaled weight using the Baker’s percentage
                float ingredientScaledWeight = mainIngredient * ((ingredients[j].percentage / 100) * scalingFactor );
                std::cout << ingredients[j].name << " " << ingredientScaledWeight << "\n";
            }
        }

        
    }
};
class RecipeAdmin {
private:
    std::vector<Recipe> recipes;
public:

    void readRecipes(){
        int numResipes;
        std::cin >> numResipes;

        for (size_t i = 0; i < numResipes; i++){
            Recipe recipe;
            std::cin >> recipe.numOfIngredients >> recipe.recipePortions >> recipe.desiredPortions;
            recipe.ingredients.resize(recipe.numOfIngredients);
            recipe.readIngredients();
            recipes.push_back(recipe);
        }
    }

    void printScaledResipes(){
        for (size_t i = 0; i < recipes.size(); i++) {
            Recipe& recipe = recipes[i];
            std::cout << "Recipe # " << i + 1 << "\n";
            recipe.scaleRecipe();
            std::cout << std::string(40, '-') << "\n";
        }
    }
};


int main() {
    int numOfCases;

    RecipeAdmin admin;
    admin.readRecipes();
    admin.printScaledResipes();

    return 0;
}
