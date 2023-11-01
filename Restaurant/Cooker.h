#pragma once
#include <queue>
#include <thread>
#include <iostream>
#include "Restaurant.h"

class Cooker {
public:
    Cooker(Restaurant& restaurantp);
    void prepareIngredients(const std::vector<int>& order);

private:
    Restaurant& restaurant;
};

