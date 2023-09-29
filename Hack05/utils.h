/**
 * Author: Dade Lenox
 * Date: 2023-09-29
 * 
 * This program is a library that includes a degree to radian converter,
 * an air distance calculator, and a time dilation calculator.
*/

/**
 * This simply converts degrees to radians for mathematical problems
*/
double degreesToRadians(double degree);

/**
 * This function is to get the air distance between two points using
 * the longitudes and latitudes of the origin and destination
*/
double getAirDistance(double originLatitude,
                      double originLongitude,
                      double destinationLatitude,
                      double destinationLongitude);

/**
 * This program calulates the time dilation experienced by an object
 * traveling at a velocity (v)
*/
double lorentzTimeDilation(double t, double percentC);
