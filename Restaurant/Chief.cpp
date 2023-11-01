#include "Chief.h"

Chief::Chief(Restaurant& restaurantp) : restaurant(restaurantp)
{
}

void Chief::prepareMeal(const std::vector<int>& order)
{
	std::cout << "Chief prepare the meal with:";
	for (int i = 0; i < 3; i++) {
		std::cout << order[i] << ", ";
	}
	std::cout << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(5)); // Simulate meal preparation time
	restaurant.mealReady(order);
}
