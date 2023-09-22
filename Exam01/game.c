/**
 * Author: Dade Lenox
 * Date: 2023-09-22
 *
 * A game that is played between two players. A number is chosen. When the number is even Player 1 scores 
 * and the value is divided by two. When the number is odd, Player 2 scores and the value is multiplied
 * by 3 and incremented by 1.
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("ERROR: invalid amount of arguments");
        exit(1);
    }

    int value = atof(argv[1]);
    int round = 1;
    int scoreA = 0;
    int scoreB = 0;
    int totalScoreA;
    int totalScoreB;


    printf("Starting Value: %d\n", value);

    while (value != 1) {
        printf("Round %2d: %3d... ", round, value);

        if (value % 2 == 0) {
            printf(" even, Player A scores!\n");
            scoreA += 1;

            value /= 2;

        } else {
            printf(" odd, Player B scores!\n");
            scoreB += 1;

            value = (value * 3) + 1;

        }

        round += 1;
    }

    totalScoreA = ((2 * scoreA) - 1) / 3;
    totalScoreB = ((3 * scoreB) + 1) / 2;

    printf("Game over!\n");
    printf("Results: \n");
    printf("Player   Points   Total Score\n");
    printf("A        %d        %d\n", scoreA, totalScoreA);
    printf("B        %d        %d\n", scoreB, totalScoreB);

    //depending on the outcome one of the following should be printed:
    
    if (totalScoreA > totalScoreB) {
        printf("A wins!\n");

    } else if (totalScoreA < totalScoreB) {
        printf("B wins!\n");

    } else {
        printf("Tie!\n");
    }

    return 0;
}
