/* 
 Write a program that sets the bit at position p to 0. 
 Print the resulting number.
 */

#include <stdio.h>
#include <stdlib.h>

void check_intInput(int *a, int *b);
int destroy_nth_position_bit(int number, int position);

int main()
{
    printf("Enter decimal and bit position: ");
    int n, position;
    check_intInput(&n, &position);
    
    int destroedBit = destroy_nth_position_bit(n, position);
    printf("new number: %d", destroedBit);

    return (EXIT_SUCCESS);
}
int destroy_nth_position_bit(int number, int position)
{
    return (number & (~(1 << position)));
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