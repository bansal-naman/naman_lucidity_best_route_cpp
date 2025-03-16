#ifndef ORDER_H
#define ORDER_H

#include "restaurant.h"

class Order {
public:
    Restaurant restaurant;
    int prepTime;

    Order(Restaurant res, int prep);
};

#endif
