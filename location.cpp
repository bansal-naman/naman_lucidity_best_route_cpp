#include "location.h"

Location::Location(double lat, double lon) : latitude(lat), longitude(lon) {}

double Location::distanceTo(const Location &other) const {
    return haversineDistance(latitude, longitude, other.latitude, other.longitude);
}

int Location::travelTimeTo(const Location &other) const {
    return calculateTravelTime(latitude, longitude, other.latitude, other.longitude);
}
