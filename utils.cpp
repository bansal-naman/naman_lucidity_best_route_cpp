#include "utils.h"

double degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

double haversineDistance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = degreesToRadians(lat2) - degreesToRadians(lat1);
    double dlon = degreesToRadians(lon2) - degreesToRadians(lon1);    
    
    double a = pow(sin(dlat / 2), 2) + cos(degreesToRadians(lat1)) * cos(degreesToRadians(lat2)) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    return EARTH_RADIUS_KM * c;
}

double calculateTravelTime(double lat1, double lon1, double lat2, double lon2) {
    double distanceKm = haversineDistance(lat1, lon1, lat2, lon2);
    double timeInHours = distanceKm / AVERAGE_SPEED_KMPH;
    return timeInHours * 60;
}
