/* 
 Write a Boolean expression that checks for given integer if it can be 
 divided (without remainder) by 7 and 5 in the same time.
 */

#include <stdio.h>
#include <stdlib.h>

void checkInput(int *);
void isDevideByFiveAndSeven(int);

int main()
{
    int number;

    printf("Enter number: ");
    checkInput(&number);

    isDevideByFiveAndSeven(number);

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

void isDevideByFiveAndSeven(int num)
{
    if ((num % 5) == 0 && (num % 7) == 0 && num != 0)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
}