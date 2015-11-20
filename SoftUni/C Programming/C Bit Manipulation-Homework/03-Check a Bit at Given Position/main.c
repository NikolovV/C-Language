/* 
 Write a Boolean expression that returns if the bit at position p(counting from 
 0, starting from the right) in given integer number n has value of 1. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void check_intInput(int *a, int *b);
int nth_position(int num, int position);

int main()
{
    printf("Enter decimal and bit position: ");
    int n, position;
    check_intInput(&n, &position);

    bool resultBit = nth_position(n, position);

    printf(resultBit > 0 ? "true" : "false");

    return (EXIT_SUCCESS);
}

int nth_position(int num, int position)
{
    return ((num >> position) & 1);
}

void check_intInput(int *a, int *b)
{
    if ((scanf("%d %d%*c", a, b)) != 2)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
    if (*a < 0 || *b < 0)
    {
        printf("Can't be negative!");
        exit(EXIT_FAILURE);
    }
}