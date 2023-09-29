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



    expected = (M_PI / 4);
    actual = degreesToRadians(45);
    if(actual != expected) {
        printf("FAILED: degreesToRadians() returned %.3f instead of the expected %.3f\n", actual, expected);
        numFailed++;
    } else {
        printf("PASSED\n");
        numPassed++;
    }


    printf("Number Test Cases Passed: %6d\n", numPassed);
    printf("Number Test Cases Failed: %6d\n", numFailed);
    printf("Percent Passed:           %6.2f\n", 100.0 * numPassed / (numPassed + numFailed));
}