/* 
 Using loops write a program that converts an integer number to its 
 binary representation. The input is entered as long. 
 The output should be a variable of type string.
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER 50

void checkIntInput(long *);
int decimalToBbinary(long, char *);

int main()
{
    long decimal;
    char binary[BUFFER];

    printf("Enter decimal number: ");
    checkIntInput(&decimal);

    if (decimal)
    {
        int startBit = decimalToBbinary(decimal, binary);
        printf("decimal %ld is in binary %s", decimal, (binary + startBit));
    }
    else
    {
        printf("decimal %lu is in binary 0", decimal);
    }

    return (EXIT_SUCCESS);
}

void checkIntInput(long *a)
{
    if ((scanf("%ld", a)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}

int decimalToBbinary(long number, char *str)
{
    int i = BUFFER - 1;
    long decimal = number;

    int remainder;
    while (number > 0)
    {
        remainder = number % 2;
        str[i] = (remainder == 1 ? '1' : '0');
        number = number / 2;
        i--;
    }
    return (i+1);
}