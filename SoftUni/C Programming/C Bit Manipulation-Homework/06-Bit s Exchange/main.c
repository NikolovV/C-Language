/* 
 Write a program that exchanges bits 3,4 and 5 with bits 24, 25 and 26 
 of given 32-bit unsigned integer.
 */

#include <stdio.h>
#include <stdlib.h>

#define POS_FROM_THREE 3
#define POS_FROM_TWENTY_FOUR 24

void check_intInput(unsigned int *a);
unsigned int zero_nth_position(unsigned int num, int position);
unsigned int exchange_bits(unsigned int number, int bitFrom, int bitTo);
unsigned int nth_position(unsigned int num, int position);

int main()
{
    printf("Enter decimal: ");
    unsigned int n;
    check_intInput(&n);
    
    unsigned int result = exchange_bits(n, 
                                       POS_FROM_THREE, 
                                       POS_FROM_TWENTY_FOUR);
    printf("%u -> %u", n, result);

    return (EXIT_SUCCESS);
}

unsigned int exchange_bits(unsigned int number, int bitFrom, int bitTo)
{
    unsigned int positionThree_Five, positionTwntyFour_TwentySix;
    positionThree_Five = nth_position(number, bitFrom);
    positionTwntyFour_TwentySix = nth_position(number, bitTo);
    
    number = zero_nth_position(number, bitTo);
    number = number | (positionThree_Five << bitTo);
    
    number = zero_nth_position(number, bitFrom);
    number = number | (positionTwntyFour_TwentySix << bitFrom);
    
    return number;
}

unsigned int nth_position(unsigned int num, int position)
{
    return ((num >> position) & 7);
}

unsigned int zero_nth_position(unsigned int num, int position)
{
    return (num & (~(7 << position)));
}

void check_intInput(unsigned int *a)
{
    if ((scanf("%u%*c", a)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
    if (*a < 0)
    {
        printf("Can't be negative!");
        exit(EXIT_FAILURE);
    }
}