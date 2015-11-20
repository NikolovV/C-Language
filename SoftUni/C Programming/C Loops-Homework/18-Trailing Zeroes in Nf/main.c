/* 
 Write a program that calculates with how many zeroes the factorial 
 of a given number n has at its end.
 */

#include <stdio.h>
#include <stdlib.h>

void checkIntInput(unsigned long long*);

int main()
{
    int zeroes = 0;
    unsigned long long powerOfFive, n;

    printf("Enter two numbers: ");
    checkIntInput(&n);

    for (powerOfFive = 5; powerOfFive <= n; powerOfFive *= 5)
    {
        zeroes += n / powerOfFive;
    }

    printf("There is %d in %llu!", zeroes, n);

    return (EXIT_SUCCESS);
}

void checkIntInput(unsigned long long *x)
{
    if ((scanf("%llu", x)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}