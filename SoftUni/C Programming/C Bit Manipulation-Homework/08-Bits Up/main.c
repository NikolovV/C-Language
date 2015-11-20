/* 
 You are given a sequence of bytes. Consider each byte as sequences of 
 exactly 8 bits.  You are given also a number step. Write a program to set to 1 
 the bits at positions: 1, 1 + step, 1 + 2*step, ... Print the output 
 as a sequence of bytes.
 Bits in each byte are counted from the leftmost to the rightmost. 
 Bits are numbered starting from 0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const bool BIT_VALUE = 1;

void check_intInput(unsigned short *a, unsigned short *b);
void fill_array(unsigned int str[], unsigned short size);
unsigned int nth_position(unsigned int num, int position);
unsigned int set_bit(unsigned int number, int position, int bit_value);

int main()
{
    unsigned short n, step;
    printf("Enter a number  and step: ");
    check_intInput(&n, &step);

    printf("Enter %hu numbers: ", n);
    unsigned int numbers[n];
    fill_array(numbers, n);

    int i, ctr = 0;
    for (i = 1; i < n * 8; i += step)
    {
        int currentPos = 7 - i % 8;
        numbers[ctr] = set_bit(numbers[ctr], currentPos, BIT_VALUE);
        int tmp = 8 * (ctr + 1);
        while (i + step >= tmp)
        {
            ctr++;
            tmp += 8;
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%u\n", numbers[i]);
    }

    return (EXIT_SUCCESS);
}

unsigned int set_bit(unsigned int number, int position, int bit_value)
{
    unsigned int nthPos = nth_position(number, position);

    if (nthPos < bit_value)
    {
        return number | (bit_value << position);
    }
    else if (nthPos > bit_value)
    {
        return (number & (~(1 << position)));
    }
    else
    {
        return number;
    }
}

unsigned int nth_position(unsigned int num, int position)
{
    return ((num >> position) & 1);
}

void fill_array(unsigned int str[], unsigned short size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if ((scanf("%u", &str[i])) != 1)
        {
            printf("Not digit!");
            exit(EXIT_FAILURE);
        }
        if (str[i] < 0)
        {
            printf("negative");
            exit(EXIT_FAILURE);
        }
    }
}

void check_intInput(unsigned short *a, unsigned short *b)
{
    if ((scanf("%hu %hu%*c", a, b)) != 2)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
    if (*a < 0 || *b < 0)
    {
        fprintf(stderr, "Can't be negative");
        exit(EXIT_FAILURE);
    }
}