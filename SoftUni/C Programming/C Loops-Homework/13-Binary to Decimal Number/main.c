/* 
 Using loops write a program that converts a binary integer number 
 to its decimal form. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define BUFFER 50

void binaryToDecimal(int, const char []);

int main()
{
    char buffer[BUFFER];

    printf("Enter binary: ");
    int i = 0, ch;
    while (ch = getchar())
    {
        buffer[i] = ch;
        int check = buffer[i] - '0';
        if (ch == '\n')
        {
            buffer[i] = '\0';
            break;
        }
        else if (check > 1 || check < 0)
        {
            printf("Not a binary!");
            exit(1);
        }
        i++;
    }
    
    binaryToDecimal(i,buffer);

    return (EXIT_SUCCESS);
}

void binaryToDecimal(int n, const char str[])
{
    int binaryBase = 1;
    unsigned long decimal = 0;

    n--;

    for (; n >= 0; n--)
    {
        decimal += binaryBase * (str[n] - '0');
        binaryBase *= 2;
    }
    printf("Binary ");
    fputs(str, stdout);
    printf(" in Decimal is %lu", decimal);
}