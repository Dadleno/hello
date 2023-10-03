#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "utils.h"

#define DELTA 0.0001

int main(int argc, char **argv) {
    double expected;
    double actual; 
    int numPassed = 0;
    int numFailed = 0;



    expected = 0.7853981;
    actual = degreesToRadians(45);
    if(fabs(expected - actual) > DELTA) {
        printf("FAILED: degreesToRadians() returned %.3f instead of the expected %.3f\n", actual, expected);
        numFailed++;
    } else {
        printf("PASSED\n");
        numPassed++;
    }

    expected = 2.391101;
    actual = degreesToRadians(137);
    if(fabs(expected - actual) > DELTA) {
        printf("FAILED: degreesToRadians() returned %.3f instead of the expected %.3f\n", actual, expected);
        numFailed++;
    } else {
        printf("PASSED\n");
        numPassed++;
    }

    expected = 1.16937;
    actual = degreesToRadians(67);
    if(fabs(expected - actual) > DELTA) {
        printf("FAILED: degreesToRadians() returned %.3f instead of the expected %.3f\n", actual, expected);
        numFailed++;
    } else {
        printf("PASSED\n");
        numPassed++;
    }

    expected = 0.000;
    actual = getAirDistance(45, 45, 45, 45);
    if(fabs(expected - actual) > DELTA) {
        printf("FAILED: getAirDistance()) returned %.3f instead of the expected %.3f\n", actual, expected);
        numFailed++;
    } else {
        printf("PASSED\n");
        numPassed++;
    }

    expected = 5003.771699;
    actual = getAirDistance(45, 45, 90, 90);
    if(fabs(expected - actual) > DELTA) {
        printf("FAILED: getAirDistance() returned %.3f instead of the expected %.3f\n", actual, expected);
        numFailed++;
    } else {
        printf("PASSED\n");
        numPassed++;
    }

    expected = 3969.355861;
    actual = getAirDistance(37.55, 45, 36.12, 90);
    if(fabs(expected - actual) > DELTA) {
        printf("FAILED: getAirDistance() returned %.3f instead of the expected %.3f\n", actual, expected);
        numFailed++;
    } else {
        printf("PASSED\n");
        numPassed++;
    }

    expected = 1.0327955;
    actual = lorentzTimeDilation(1, .25);
    if(fabs(expected - actual) > DELTA) {
        printf("FAILED: lorentzTimeDilation() returned %.3f instead of the expected %.3f\n", actual, expected);
        numFailed++;
    } else {
        printf("PASSED\n");
        numPassed++;
    }

    expected = 5.316742;
    actual = lorentzTimeDilation(5, .34);
    if(fabs(expected - actual) > DELTA) {
        printf("FAILED: lorentzTimeDilation() returned %.3f instead of the expected %.3f\n", actual, expected);
        numFailed++;
    } else {
        printf("PASSED\n");
        numPassed++;
    }

    expected = 25.738810;
    actual = lorentzTimeDilation(25.562603, 0.116812);
    if(fabs(expected - actual) > DELTA) {
        printf("FAILED: lorentzTimeDilation() returned %.3f instead of the expected %.3f\n", actual, expected);
        numFailed++;
    } else {
        printf("PASSED\n");
        numPassed++;
    }
    

    printf("Number Test Cases Passed: %6d\n", numPassed);
    printf("Number Test Cases Failed: %6d\n", numFailed);
    printf("Percent Passed:           %6.2f\n", 100.0 * numPassed / (numPassed + numFailed));

   return 0;
}