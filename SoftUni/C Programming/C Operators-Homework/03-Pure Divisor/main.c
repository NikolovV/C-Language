/* 
 Write a program that prints if a number is divide d by 9, 11 or 13 
 without remainder.
 */

#include <stdio.h>
#include <stdlib.h>

void checkInput(int *);
void isRemaniderZero(int);

int main()
{
    int number;

    printf("Enter number: ");
    checkInput(&number);

    isRemaniderZero(number);

    return (EXIT_SUCCESS);
}

void checkInput(int *N)
{
    if ((scanf("%d", N)) != 1)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
}

void isRemaniderZero(int num)
{
    if (num % 9 == 0 ||
            num % 11 == 0 ||
            num % 13 == 0)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
}