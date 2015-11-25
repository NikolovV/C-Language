/* 
 Write a program that prints the first 10 members of the 
 sequence: 2, -3, 4, -5, 6, -7 ...
 8.1 - Modify your program to read a number n from the console and then finds the 
 first n members , starting from 2. 
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int number = 2, i;
    int member;
    
    printf("Enter member from the sequence: ");
    scanf("%d", &member);
    for (i = 0; i < member; i++, number++)
    {
        if (number%2==1)
        {
            printf("-");
        }
        printf("%d ", number);
    }

    return (EXIT_SUCCESS);
}