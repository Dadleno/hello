#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "utils.h"

#define RADIUS 6371

double degreesToRadians(double degrees) {

    double result = (degrees * M_PI) / 180;

    return result;
}

double getAirDistance(double originLatitude, double originLongitude, double destinationLatitude, double destinationLongitude) {

    double delta;

    originLatitude = degreesToRadians(originLatitude);
    originLongitude = degreesToRadians(originLongitude);
    destinationLatitude = degreesToRadians(destinationLatitude);
    destinationLongitude = degreesToRadians(destinationLongitude);
    delta = destinationLongitude - originLongitude;

    double result = acos((sin(originLatitude) * sin(destinationLatitude)) + (cos(originLatitude) * cos(destinationLatitude) * cos(delta))) * RADIUS;

    return result;
}

double lorentzTimeDilation(double t, double percentC) {
    double result = t / (sqrt(1 - (percentC * percentC)));

    return result;
}
