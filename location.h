#ifndef LOCATION_H
#define LOCATION_H

#include "utils.h"

class Location {
public:
    double latitude, longitude;
    Location(double lat, double lon);
    double distanceTo(const Location &other) const;
    int travelTimeTo(const Location &other) const;
};

#endif
