/* 
 Write a program that exchanges bits {p, p+1, ..., p+k-1} with bits
 {q, q+1, ..., q+k-1} of a given 32-bit unsigned integer.
 The first and the second sequence of bits may not overlap.
 */

#include <stdio.h>
#include <stdlib.h>

void check_intInput(unsigned int *a, unsigned int *b,
                    unsigned int *c, unsigned int *d);
unsigned int nth_position(unsigned int num, int position);
unsigned int exchange_bits(unsigned int number,
                           int bitFrom, int bitTo, int bits);
unsigned int zero_nth_position(unsigned int num, int position);
int get_max(int a, int b);
int get_min(int a, int b);

int main()
{
    printf("Enter decimal: ");
    unsigned int n, p, q, k;
    check_intInput(&n, &p, &q, &k);

    int bigger = get_max((int)p, (int)q);
    int smaller = get_min((int)p, (int)q);
    if ((bigger + k) > 32)
    {
        fprintf(stderr, "out of range");
        exit(EXIT_FAILURE);
    }
    else if ((smaller + k) >= bigger)
    {
        fprintf(stderr, "overlapping");
        exit(EXIT_FAILURE);
    }    
    
    int result = exchange_bits(n, p, q, k);
    
    printf("result: %u", result);

    return (EXIT_SUCCESS); 
}

int get_max(int a, int b)
{
    int bigger = (a > b) ? a : b;
    return bigger;
}

int get_min(int a, int b)
{
    int smaller = (a < b) ? a : b;
    return smaller;
}

unsigned int exchange_bits(unsigned int number,
                           int bitFrom, int bitTo, int bits)
{
    unsigned int curenBitFrom, curenBitTo;
    int i;
    for (i = 0; i < bits; i++)
    {
        curenBitFrom = nth_position(number, bitFrom);
        curenBitTo = nth_position(number, bitTo);

        if (curenBitFrom != curenBitTo)
        {
            number = zero_nth_position(number, bitTo);
            number = number | (curenBitFrom << bitTo);

            number = zero_nth_position(number, bitFrom);
            number = number | (curenBitTo << bitFrom);
        }

        bitFrom++;
        bitTo++;
    }

    return number;
}

unsigned int zero_nth_position(unsigned int num, int position)
{
    return (num & (~(1 << position)));
}

unsigned int nth_position(unsigned int num, int position)
{
    return ((num >> position) & 1);
}

void check_intInput(unsigned int *a, unsigned int *b,
                    unsigned int *c, unsigned int *d)
{
    if ((scanf("%u %u %u %u%*c", a, b, c, d)) != 4)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
    if (*a < 0 || *b < 0 || *c < 0 || *d < 0)
    {
        printf("Can't be negative!");
        exit(EXIT_FAILURE);
    }
}