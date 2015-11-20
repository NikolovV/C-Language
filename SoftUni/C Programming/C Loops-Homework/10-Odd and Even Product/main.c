/* 
 You are given n integers (given in a single line, separated by a space).
 Write a program that checks whether the product of the odd elements 
 is equal to the product of the even elements. Elements are counted from 
 1 to n, so the first element is odd, the second is even
 */

#include <stdio.h>
#include <string.h>

#define BUFFER 30

int main()
{
    char input[BUFFER];
    int oddProduct = 1, evenProduct = 1, isOdd = 1;

    fgets(input, BUFFER, stdin);
    int lengt = strlen(input);

    if (input[lengt - 1] == '\n')
    {
        input[lengt - 1] = '\0';
    }

    char* token = strtok(input, " ");
    int i;
    while (token != NULL)
    {
        int number = atoi(token);

        if ((isOdd = i % 2) != 0)
        {
            oddProduct *= number;
        }
        else
        {
            evenProduct *= number;
        }

        i++;

        token = strtok(NULL, " ");
    }
    
    if (oddProduct == evenProduct)
    {
        printf("yes\n");
        printf("%d", oddProduct);
    }
    else
    {
        printf("no\n");
        printf("odd_product = %d\n", oddProduct);
        printf("even_product = %d", evenProduct);
    }

    return (0);
}