# Best Route - Approach and Assumptions

## Approach
This solution finds the optimal route for a delivery executive to pick up orders from multiple restaurants and deliver them to consumers while minimizing total time. The approach consists of:

1. Generating all valid pickup and delivery sequences
2. Simulating each sequence by calculating total travel time and waiting time while eliminating wrong sequences.
3. Keeping track of the sequence with the minimum time along with the route followed.

Note:
- Right now, both pickup and delivery sequences are stored together, with indices differentiating them, and invalid sequences are eliminated using a pickup flag. This could be improved by explicitly separating pickup and delivery sequences for better clarity.
- The program uses the Haversine formula to compute distances and assumes a constant travel speed of 20 km/h, converting all times to whole minutes.
- I've picked the Haversine distance and radian calculations based on standard formulas available online.

## Assumptions
- Prep time is given in whole minutes.
- Travel time is rounded up to ensure realistic time calculations.
- The number of orders should match the number of consumers.

## Running Test Cases

- The `unit_tests.cpp` file runs multiple test cases to verify the solution.
- It initializes all objects and prints the output.
- More tests can be easily added by including additional scenarios with more orders or consumers.
- I'm using Make to compile and build the project.
    - Steps to run:
        -  `make` (make sure make is installed)
        - `./BestRoute`
        - `make clean` to clean

## Next Steps & Potential Improvements

- More Efficient Route Calculation: Right now, we brute-force through all possible sequences, which works for small inputs but isn’t scalable.
    - My next step would be to explore heuristic approaches to find a “good enough” solution efficiently. Since this problem is essentially a Traveling Salesman Problem with added constraints (like ensuring each order’s pickup happens before its delivery and considering preparation times), I believe a greedy approach could work well. A simple idea would be to repeatedly choose the nearest valid pickup or delivery point (while following all constraints) and iteratively build a near-optimal route instead of evaluating all possible permutations.

- Prioritize Certain Deliveries: Some orders, like hot food, might need to be delivered first. Adding priority-based logic could make the system smarter.
- Support More Flexible Order Handling: In the real world, a delivery executive might have more orders than consumers (or vice versa). Extending the solution to handle these cases would make it more robust.
