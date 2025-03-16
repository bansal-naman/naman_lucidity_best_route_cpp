#include "delivery_executive.h"
#include <algorithm>
#include <limits>

DeliveryExecutive::DeliveryExecutive(std::string name, Location start, std::vector<Order> orders, std::vector<Consumer> consumers)
    : name(name), startLocation(start), orders(std::move(orders)), consumers(std::move(consumers)) {}

int DeliveryExecutive::findOptimalRoute() {

    int numOrders = orders.size();
    if (numOrders != (int) consumers.size()) return -1;  // Invalid case: Mismatched orders and consumers

    std::vector<int> sequence;
    for (int i = 0; i < numOrders; i++) {
        sequence.push_back(i);           // Order pickup index
        sequence.push_back(i + numOrders); // Consumer delivery index
    }

    std::vector<Location> stops;
    std::vector<int> prepTimes;
    for (const auto &order : orders) {
        stops.push_back(order.restaurant.location);
        prepTimes.push_back(order.prepTime);
    }
    for (const auto &consumer : consumers) {
        stops.push_back(consumer.location);
        prepTimes.push_back(0); // Deliveries have no prep time
    }

    int minTime = INT_MAX;
    do {
        int time = 0;
        Location current = startLocation;
        std::vector<bool> pickedUp(numOrders, false);
        bool validSequence = true;

        for (int idx : sequence) {
            int travelTime = std::ceil(current.travelTimeTo(stops[idx]));
            time += travelTime;

            if (idx < numOrders) { // Picking up order
                time = std::max(time, prepTimes[idx]); // Wait if order isn't ready
                pickedUp[idx] = true;
            } else { // Delivering order
                int orderIdx = idx - numOrders;
                if (!pickedUp[orderIdx]) {
                    validSequence = false; // Invalid sequence
                    break;
                }
            }

            current = stops[idx];
        }

        if (validSequence && time < minTime) {
            minTime = time;
            bestSequence = sequence;
        }
    } while (std::next_permutation(sequence.begin(), sequence.end()));

    return minTime; 
}

const std::vector<int>& DeliveryExecutive::getBestSequence() const {
    return bestSequence;
}
