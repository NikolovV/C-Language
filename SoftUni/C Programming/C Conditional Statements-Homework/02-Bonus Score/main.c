/* 
 Write a program that applies bonus score to given score in the range [1...9] 
 by the following rules:
 * If the score is between 1 and 3, the program multiplies it by 10.
 * If the score is between 4 and 6, the program multiplies it by 100.
 * If the score is between 7 and 9, the program multiplies it by 1000.
 * If the score is 0 or more than 9, the program prints “invalid score”.
 */

#include <stdio.h>
#include <stdlib.h>

void checkInput(int *);

int main()
{
    int score;
    
    printf("Enter score: ");
    checkInput(&score);
    
    switch (score)
    {
    case 1:
    case 2:
    case 3:
        printf("result: %d", score*10);
        break;
    case 4:
    case 5:
    case 6:
        printf("result: %d", score*100);
        break;
    case 7:
    case 8:
    case 9:
        printf("result: %d", score*1000);
        break;
    default:
        printf("Invalid score!");
    }

    return (EXIT_SUCCESS);
}

void checkInput(int *a)
{
    if ((scanf("%d", a)) != 1)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
}