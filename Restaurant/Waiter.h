#pragma once
#include <queue>
#include <iostream>
#include "Restaurant.h"

class Waiter {
public:
    Waiter(Restaurant& restaurantp);
    void serve();

private:
    Restaurant& restaurant;
};

