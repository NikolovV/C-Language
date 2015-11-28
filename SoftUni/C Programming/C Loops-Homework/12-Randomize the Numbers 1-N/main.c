/*
 Write a program that enters in integer n and prints the numbers 1, 2, ..., n
 in random order. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void checkIntInput(int *a);

int main()
{
    int n;
    checkIntInput(&n);

    srand(time(NULL));

    int numbers[n];
    int i;
    for (i = 0; i < n; i++)
    {
        numbers[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        int random = rand() % n;
        while (numbers[random] != 0)
        {
            random = rand() % n;
        }
        printf("%d ", random + 1);
        numbers[random] = 1;
    }

    return 0;
}

void checkIntInput(int *a)
{
    if ((scanf("%d", a) != 1))
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}