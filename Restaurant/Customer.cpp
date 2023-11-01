#include "Customer.h"
#include <time.h>

Customer::Customer(Restaurant& restaurantp) : restaurant(restaurantp), served(true)
{
}

void Customer::orderMeal()
{
    srand(time(NULL));
    if (served)
    {
        std::vector<int> selectedIngredients;
        int ingredient = 0;

        std::cout << "Customer order a meal with:";

        for (int i = 0; i < 3; i++) {
            ingredient = rand() % 10;
            std::cout << ingredient << ", ";
            selectedIngredients.push_back(ingredient);
        }
        std::cout << std::endl;

        restaurant.order(selectedIngredients);
        served = false;
    }
}

void Customer::eatMeal()
{
    std::this_thread::sleep_for(std::chrono::seconds(10)); // Simulate eating time
    std::cout << "Customer has finished eating.\n";
    served = true;
}
