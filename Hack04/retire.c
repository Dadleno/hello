/**
 * Author: Dade Lenox (dlenox2@huskers.unl.edu)
 * Contributor: Jack Fruhling
 * 
 * Date: 2023-09-14
 * 
 * This program produces an amortization table for a 401(k) account
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/**
 * Computes the annual interest required to produce the table
*/
double roundToCents(double x);

int main(int argc, char **argv) {

    if (argc != 6) {
        printf("ERROR: invalid amount of command line arguments");
    }

    double balance = roundToCents(atof(argv[1]));
    double monthlyCont = roundToCents(atof(argv[2]));
    double annualReturn = atof(argv[3]);
    double annualInflation = atof(argv[4]);
    int retireYears = atof(argv[5]);
    double annualInterest;
    double monthlyRate;
    double interestAmt;
    int month = retireYears * 12;

    double annualCont = monthlyCont * 12;
    if (annualCont > 18500) {
        printf("ERROR: monthly contributions exceed $18,500 annual limit");
    }


    

    if (annualReturn < 0 || annualReturn > 1) {
        printf("ERROR: invalid rate of return");
        exit(1);
    } else if (annualInflation < 0 || annualInflation > 1) {
        printf("ERROR: invalid rate of inflation");
        exit(1);
    } 

    printf("Month   Interest      Balance\n");


    double totalInterest = 0;
    for (int i = 1; i <= month; i++) {
        annualInterest = ((1.0 + annualReturn)/(1.0 + annualInflation)) - 1.0;
        monthlyRate = annualInterest/12.0;
        interestAmt = balance * monthlyRate;
        interestAmt = roundToCents(interestAmt);
        balance += (monthlyCont + interestAmt);
        totalInterest += interestAmt;

        printf("%5d $%10.2f $%10.2f\n", i, interestAmt, balance);
    }

    printf("Total Interest Earned: $%10.2f\n", totalInterest);
    printf("Total Nest Egg: $%10.2f\n", balance);

    return 0;
}

double roundToCents(double x) {
    double result = round(x * 100) / 100;

    return result;
}