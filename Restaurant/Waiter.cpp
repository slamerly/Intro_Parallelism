#include "Waiter.h"

Waiter::Waiter(Restaurant& restaurantp) : restaurant(restaurantp)
{
}

void Waiter::serve()
{
    while (true) {
        std::vector<int> order = restaurant.getCompletedOrder();
        if (!order.empty()) {
            std::cout << "Waiter serves an order.\n";
            restaurant.notifyMealServed();
        }
    }
}
