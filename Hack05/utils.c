#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "utils.h"

double degreesToRadians(double degrees) {

    double result = (degrees * M_PI) / 180;

    return result;
}

double getAirDistance(double originLatitude, double originLongitude, double destinationLatitude, double destinationLongitude) {

    double delta = destinationLongitude - originLongitude;

    delta = degreesToRadians(delta);
    originLatitude = degreesToRadians(originLatitude);
    originLongitude = degreesToRadians(originLongitude);
    destinationLatitude = degreesToRadians(destinationLatitude);
    destinationLongitude = degreesToRadians(destinationLongitude);

    double result = acos((sin(originLatitude) * sin(destinationLatitude)) + (cos(originLatitude) * cos(destinationLatitude) * cos(delta))) * delta;

    return result;
}