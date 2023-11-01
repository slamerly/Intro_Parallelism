#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>
#include <vector>

class Restaurant {
public:
    Restaurant();
    void order(const std::vector<int>& ingredients);
    std::vector<int> getOrder();
    std::vector<int> getCompletedOrder();
    void ingredientsReady(const std::vector<int>& order);
    void mealReady(const std::vector<int>& order);
    void notifyMealServed();

    bool getNewOrder() { return newOrder; }
    bool getMealServed() { return mealServed; }
    bool getIngreReady() { return ingreReady; }

private:
    std::queue<std::vector<int>> orders;
    std::queue<std::vector<int>> completedOrders;
    std::mutex mtx;
    std::condition_variable cv;
    bool newOrder;
    bool mealServed;
    bool ingreReady;
};

