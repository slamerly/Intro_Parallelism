#pragma once
#include <queue>
#include <thread>
#include <iostream>
#include "Restaurant.h"

class Customer {
public:
    Customer(Restaurant& restaurantp);
    void orderMeal();
    void eatMeal();

private:
    Restaurant& restaurant;
    bool served;
};

