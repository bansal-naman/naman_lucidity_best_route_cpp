#include <iostream>
#include "delivery_executive.h"

void runTest(const std::string& testName, const std::string executiveName, const Location& startLocation, 
    std::vector<Order> orders, std::vector<Consumer> consumers) {

    std::cout << "\nRunning Test: " << testName << "\n";
    DeliveryExecutive exec(executiveName, startLocation, orders, consumers);

    int optimalTime = exec.findOptimalRoute();
    std::vector<int> bestRoute = exec.getBestSequence();

    std::cout << "Optimal Delivery Time: " << optimalTime << " minutes\n";

    std::cout << "Optimal Delivery Time for "<<exec.name<<": " 
              << optimalTime
              << " minutes" << std::endl;

    std::cout << "Optimal Route: ";
    for (int i = 0; i <  (int) bestRoute.size(); i++) {
        if (bestRoute[i] <  (int) orders.size())
            std::cout << "Pickup Order " << bestRoute[i] + 1;
        else
            std::cout << "Deliver Order " << (bestRoute[i] - orders.size()) + 1;

        if (i != (int) bestRoute.size() - 1)
            std::cout << " -> ";
    }
    std::cout << "\n";
}

int main() {
    std::string deliveryExecutiveName = "Aman";
    Location start(12.9352, 77.6245);

    // Test Case 1
    std::vector<Order> orders1 = {
        Order(Restaurant(Location(12.9300, 77.6200)), 10),  
        Order(Restaurant(Location(12.9400, 77.6300)), 15),
    };
    std::vector<Consumer> consumers1 = {
        Consumer(Location(12.9450, 77.6350)),
        Consumer(Location(12.9500, 77.6400)),
    };
    runTest("Test Case 1",deliveryExecutiveName, start, orders1, consumers1);

    // Test Case 2
    std::vector<Order> orders2 = {
        Order(Restaurant(Location(12.9300, 77.6200)), 5),  
        Order(Restaurant(Location(12.9400, 77.6300)), 20),
        Order(Restaurant(Location(12.9250, 77.6150)), 8)
    };
    std::vector<Consumer> consumers2 = {
        Consumer(Location(12.9500, 77.6400)),
        Consumer(Location(12.9450, 77.6350)),
        Consumer(Location(12.9200, 77.6100))
    };
    runTest("Test Case 2",deliveryExecutiveName, start, orders2, consumers2);

    return 0;
    }