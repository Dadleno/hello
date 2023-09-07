/**
 * Author: Dade Lenox dlenox2@huskers.unl.edu
 * Date: 2023-09-07
 *
 * Takes the average data usage
*/

#include <stdio.h>
#include <stdlib.h>

#define PLAN_LENGTH 30

int isError(){
    switch 
}

int main(int argc, char **argv) {
    double planSize = atof(argv[1]);
    int currentDay = atof(argv[2]);
    double dataAmountUsed = atof(argv[3]);

    double averageDaily, limitDaily, dayRemain, projectedUse;

    if (planSize <= 0) {
        printf("ERROR: invalid plan size");
    } else if (currentDay > 30) {

    }


    averageDaily = dataAmountUsed / currentDay;
    limitDaily = planSize / PLAN_LENGTH;
    dayRemain = PLAN_LENGTH - currentDay;
    projectedUse = averageDaily * PLAN_LENGTH;







    return 0;
}