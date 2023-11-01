#include "Cooker.h"

Cooker::Cooker(Restaurant& restaurantp) : restaurant(restaurantp)
{
}

void Cooker::prepareIngredients(const std::vector<int>& order)
{
	std::cout << "Cooker prepare the ingredients:";
	for (int i = 0; i < 3; i++) {
		std::cout << order[i] << ", ";
	}
	std::cout << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(6)); // Simulate ingredient preparation time
	restaurant.ingredientsReady(order);
}
