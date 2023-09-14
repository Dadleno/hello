/**
 * Author: Dade Lenox dlenox2@huskers.unl.edu
 * Date: 2023-09-07
 *
 * Takes the average data usage
*/

#include <stdio.h>
#include <stdlib.h>

#define PLAN_LENGTH 30



int main(int argc, char **argv) {
    double planSize = atof(argv[1]);
    int currentDay = atof(argv[2]);
    double currentUsed = atof(argv[3]);

    double averageDaily, limitDaily, projectedUse;
    int dayRemain;


    if (planSize < 0) {
        printf("ERROR: invalid plan size\n");
        exit(1);
    } else if (currentDay > PLAN_LENGTH || currentDay < 0) {
        printf("ERROR: invalid amount of days\n");
        exit(1);
    } else if (currentUsed < 0) {
        printf("ERROR: invlaid amount used\n");
        exit(1);
    } else if (argc < 4 || argc > 4) {
        printf("ERROR: not enough command lines");
        exit(1);
    }

    averageDaily = currentUsed / currentDay;
    limitDaily = planSize / PLAN_LENGTH;
    dayRemain = PLAN_LENGTH - currentDay;
    projectedUse = ((averageDaily * dayRemain) + currentUsed) - planSize;

    if ((averageDaily > limitDaily) && !(currentUsed > planSize)) {
        printf("%d days used, %d days remaining.\n", currentDay, dayRemain);
        printf("Average daily use: %.3f GB/Day\n \n", averageDaily);
        printf("Average daily use EXCEEDS daily limit (%.3f).\n", limitDaily);
        printf("Approximately %.3f GB will be overused!", projectedUse);
    } else if (currentUsed > planSize) {
        printf("%d days used, %d days remaining.\n", currentDay, dayRemain);
        printf("Average daily use: %.3f GB/Day\n \n", averageDaily);
        printf("You have already met your limit for this month.\n");
    } else if (averageDaily < limitDaily) {
        printf("%d days used, %d days remaining.\n", currentDay, dayRemain);
        printf("Average daily use: %.3f GB/Day\n \n", averageDaily);
        printf("You are at or below your average daily limit (%.3f).\n", limitDaily);
        
        limitDaily = (planSize - currentUsed) / dayRemain;
        printf("You can now use up to %.3f GB/Day.\n", limitDaily);

    }

    return 0;
}