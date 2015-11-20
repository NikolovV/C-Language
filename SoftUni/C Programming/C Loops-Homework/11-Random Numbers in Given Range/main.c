/* 
 Write a program that enters 3 integers n, min and max(min≤ max) and prints 
 n random numbers in the range [min...max].
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void checkIntInput(int *, int *, int *);

int main()
{
    
    int nums, min, max, randNum;
    time_t t;
    srand((unsigned)time(&t));

    printf("Enter numbers, min and max: ");
    checkIntInput(&nums, &min, &max);

    int i;
    for (i = 0; i < nums; i++)
    {
        randNum = (rand() % (max + 1 - min) + min);
        printf("%d\n", randNum);
    }

    return (EXIT_SUCCESS);
}

void checkIntInput(int *a, int *b, int *c)
{
    if ((scanf("%d %d %d", a, b, c)) != 3)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}