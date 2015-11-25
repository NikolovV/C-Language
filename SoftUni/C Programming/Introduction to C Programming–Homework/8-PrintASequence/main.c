/* 
 Write a program that prints the first 10 members of the 
 sequence: 2, -3, 4, -5, 6, -7 ...
 */

#include <stdio.h>
#include <stdlib.h>
#define MEMBER 10

int main(int argc, char** argv)
{
    int number = 2, i;
    
    for (i = 0; i < MEMBER; i++, number++)
    {
        if (number%2==1)
        {
            printf("-");
        }
        printf("%d", number);
        if (i < MEMBER - 1)
        {
            printf(", ");
        }

    }

    return (EXIT_SUCCESS);
}

