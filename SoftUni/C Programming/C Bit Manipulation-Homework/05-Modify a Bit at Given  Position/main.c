/* 
 We are given an integer number n, a bit value v(v=0or1) and a position p. 
 Write a sequence of operators(a few lines of C# code)that modifies n to hold 
 the value v at the position p from the binary representation of n while p 
 reserving all other bits in n.
 */

#include <stdio.h>
#include <stdlib.h>

void check_intInput(int *a, int *b, int *c);
int convert_nth_position(int number, int position);
int nth_position(int num, int position);

int main()
{
    printf("Enter decimal, bit position and bit value: ");
    int n, position, v;
    check_intInput(&n, &position, &v);
    
    int valueBit = nth_position(n, position);
    
    if (valueBit == v)
    {
        printf("%d", n);
    }
    else
    {
        printf("converted bit value %d ",
               convert_nth_position(n, position));
    }

    return (EXIT_SUCCESS);
}

int nth_position(int num, int position)
{
    return ((num >> position) & 1);
}

int convert_nth_position(int number, int position)
{
    return (number ^ (1 << position));
}

void check_intInput(int *a, int *b, int *c)
{
    if ((scanf("%d %d %d%*c", a, b, c)) != 3)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
    if (*a < 0 || *b < 0 || *c < 0)
    {
        printf("Can't be negative!");
        exit(EXIT_FAILURE);
    }
}