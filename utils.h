#ifndef UTILS_H
#define UTILS_H

#include <cmath>

// Constants for Earth radius and speed
const double EARTH_RADIUS_KM = 6371.0;
const double AVERAGE_SPEED_KMPH = 20.0;

// Function to convert degrees to radians
double degreesToRadians(double degrees);

// Function to compute Haversine distance
double haversineDistance(double lat1, double lon1, double lat2, double lon2);

// Function to compute travel time using Haversine formula
int calculateTravelTime(double lat1, double lon1, double lat2, double lon2);

#endif
