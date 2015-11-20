/* 
 Write a program that that prints if the number is both greater than 20
 and odd.
 */

#include <stdio.h>
#include <stdlib.h>

void checkInput(int *);
void isOverTwentyAndODD(int);

int main()
{
    int number;

    printf("Enter number: ");
    checkInput(&number);

    isOverTwentyAndODD(number);

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

void isOverTwentyAndODD(int num)
{
    if ((num % 2) == 1 && num > 20)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
}