/* 
 Problem 1. First Bit
 Write a program that prints the bit at position 1 of a number.
 */

/*
 Bitwise: Extract Bit #3
 Using bitwise operators, write an expression for finding the value of the bit 
 #3 of a given unsigned integer. The bits are counted from right to left, 
 starting from bit #0. The result of the expression should be either 1 or 0.
 */

#include <stdio.h>
#include <stdlib.h>

#define FIRST_POSITION 1
#define THIRD_POSITION 3

void check_intInput(int *a);
int nth_position(int num, int position);

int main()
{
    printf("Enter decimal: ");
    int n;
    check_intInput(&n);

    int resultFirstPos = nth_position(n, FIRST_POSITION);
    printf("%d bit position of %d is %d\n", FIRST_POSITION, n, resultFirstPos);
    
    int resultThirdPos = nth_position(n, THIRD_POSITION);
    printf("%d bit position of %d is %d", THIRD_POSITION, n, resultThirdPos);  

    return (EXIT_SUCCESS);
}

int nth_position(int num, int position)
{
    int result = (num >> position) & 1;

    return result;
}

void check_intInput(int *a)
{
    if ((scanf("%d%*c", a)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}