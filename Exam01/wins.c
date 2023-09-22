/**
 * Author: Dade Lenox (dlenox2@huskers.unl.edu)
 * Date: 2023-09-22
 * 
 * This program estimates the win percentage for football games
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GAMES 12
#define EXP1 2.37
#define TOLERANCE 0.001

double roundToHund(double x);
double raisePower(double x);

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("ERROR: invalid number of arguemnts");
        exit(1);
    }

    double pointsFor = roundToHund(atof(argv[1]));
    double pointsAgainst = roundToHund(atof(argv[2]));
    double winPercent;
    double wins;
    double loses;

    winPercent = (raisePower(pointsFor)) / (raisePower(pointsFor) + raisePower(pointsAgainst));

    wins = round(winPercent * GAMES);
    loses = GAMES - wins;

    winPercent *= 100;
    winPercent = roundToHund(winPercent);

    printf("Win Percentage: %.2f%%\n", winPercent);
    printf("Win/Loss: %.0f/%.0f\n", wins, loses);


    return 0;
}

double roundToHund(double x) {
    double result;
    result = round(x * 100) / 100;

    return result;
} 

double raisePower(double x) {
    double result;
    result = pow(x, EXP1);

    return result;
}