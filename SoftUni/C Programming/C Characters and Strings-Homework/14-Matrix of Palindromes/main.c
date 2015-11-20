/* 
 Write a program to generate the following matrix of palindromes of 3 letters 
 with r rows and c columns:
 */

#include <stdio.h>
#include <stdlib.h>

void check_intInput(int *a, int *b);

int main()
{
    int rows, cols;
    
    printf("Enter row and col: ");
    check_intInput(&rows, &cols);
    
    int i;
    for (i = 0; i < rows; i++)
    {
        char letter = 'a' + i;
        int j;
        for (j = 0; j < cols; j++)
        {
            printf("%c%c%c ", letter, letter + j, letter);
        }
        
        printf("\n");
    }
    
    return 0;

    return (EXIT_SUCCESS);
}

void check_intInput(int *a, int *b)
{	
    if ((scanf("%d %d%*c", a, b)) != 2)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}