#include <iostream>
#include <thread>
#include <vector>
#include "Restaurant.h"
#include "Customer.h"
#include "Waiter.h"
#include "Cooker.h"
#include "Chief.h"


int main() {
	Restaurant restaurant;
	Customer customer(restaurant);
	Waiter waiter(restaurant);
	Cooker cooker(restaurant);
	Chief chief(restaurant);

	std::thread customerThread([&]() {
		while (true) {
			customer.orderMeal();
			if (restaurant.getMealServed())
			{
				customer.eatMeal();
			}
		}
	});

	std::thread waiterThread([&]() {
		waiter.serve();
	});

	std::thread cookerThread([&]() {
		while (true) {
			std::vector<int> order = restaurant.getOrder();
			if (!order.empty() && restaurant.getNewOrder()) {
				cooker.prepareIngredients(order);
			}
		}
	});

	std::thread chiefThread([&]() {
		while (true) {
			std::vector<int> order = restaurant.getOrder();
			if (!order.empty() && restaurant.getIngreReady()) {
				chief.prepareMeal(order);
			}
		}
	});

	customerThread.join();
	waiterThread.join();
	cookerThread.join();
	chiefThread.join();

	return 0;
}