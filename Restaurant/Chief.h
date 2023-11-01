#pragma once
#include <queue>
#include <thread>
#include <iostream>
#include "Restaurant.h"

class Chief {
public:
    Chief(Restaurant& restaurantp);
    void prepareMeal(const std::vector<int>& order);

private:
    Restaurant& restaurant;
};

