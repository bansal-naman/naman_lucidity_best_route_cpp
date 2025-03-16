#ifndef DELIVERY_EXECUTIVE_H
#define DELIVERY_EXECUTIVE_H

#include "consumer.h"
#include "location.h"
#include "order.h"
#include <vector>

class DeliveryExecutive {
  private:
    std::vector<int> bestSequence;

  public:
    std::string name;
    Location startLocation;
    std::vector<Order> orders;       // List of orders (restaurants & prep time)
    std::vector<Consumer> consumers; // List of consumers (delivery locations)

    DeliveryExecutive(std::string name, Location start, std::vector<Order> orders,
                      std::vector<Consumer> consumers);
    int findOptimalRoute();
    const std::vector<int> &getBestSequence() const;
};

#endif
