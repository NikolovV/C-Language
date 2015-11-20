/* 
 Write an expression that checks if given positive integer number n(n≤ 100) is prime
 (i.e. it is divisible without remainder only to itself and 1).
 Print true or false 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void checkInput(int *);
int checkPrime(int);

int main()
{
    int number;
    int isPrime;

    printf("Enter number: ");
    checkInput(&number);

    isPrime = checkPrime(number);
    printf(isPrime ? "true" : "false");

    return (EXIT_SUCCESS);
}

void checkInput(int *num)
{
    if ((scanf("%d", num)) != 1)
    {
        if (*num > 100)
        {
            fprintf(stderr, "Over 100!");
            exit(EXIT_FAILURE);
        }
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
}

int checkPrime(int num)
{
    int ctr;
    if (num > 1)
    {
        for (ctr = 2; ctr <= num - 1; ctr++)
        {
            if (num % ctr == 0)
                return 0;
        }
        if (ctr == num)
            return 1;
    }
    return 0;
}