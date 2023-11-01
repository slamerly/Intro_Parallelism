#include "Restaurant.h"

Restaurant::Restaurant() : newOrder(false), mealServed(false), ingreReady(false)
{
}

void Restaurant::order(const std::vector<int>& ingredients)
{
	std::unique_lock<std::mutex> lock(mtx);
	orders.push(ingredients);
    newOrder = true;
	cv.notify_all();
}

std::vector<int> Restaurant::getOrder()
{
    std::vector<int> noOrder;
    if (!orders.empty())
    {
        return orders.back();
    }
    return noOrder;
}

std::vector<int> Restaurant::getCompletedOrder()
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this] { return !orders.empty() && mealServed; });

    std::vector<int> order = completedOrders.front();
    completedOrders.pop();
    orders.pop();
    //mealServed = false;

    return order;
}

void Restaurant::ingredientsReady(const std::vector<int>& order)
{
    std::unique_lock<std::mutex> lock(mtx);

    completedOrders.push(order);
    newOrder = false;
    //mealServed = false;
    ingreReady = true;
    cv.notify_all();
}

void Restaurant::mealReady(const std::vector<int>& order)
{
    std::unique_lock<std::mutex> lock(mtx);

    completedOrders.push(order);
    mealServed = true;
    ingreReady = false;
    cv.notify_all();
}

void Restaurant::notifyMealServed()
{
    std::unique_lock<std::mutex> lock(mtx);
    mealServed = false;
    cv.notify_all();
}
