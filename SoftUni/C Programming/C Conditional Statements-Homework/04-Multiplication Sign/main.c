/* 
 Write a program that shows the sign (+, - or 0) of the product  of three 
 real numbers, without calculating it. Use a sequence of if operators.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double first, second, third;
    int sign = 0;

    printf("Enter 3 numbers: ");
    if ((scanf("%lf%lf%lf", &first, &second, &third)) != 3)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }

    if (first == 0.0 || second == 0.0 || third == 0.0)
    {
        printf("0");
    }
    else
    {
        if (first < 0.0)
        {
            sign++;
        }
        if (second < 0.0)
        {
            sign++;
        }
        if (third < 0.0)
        {
            sign++;
        }
        
        switch (sign)
        {
        case 0:
            printf("+");
            break;
        case 1:
            printf("-");
            break;
        case 2:
            printf("+");
            break;
        default:
            printf("-");
        }    
    }
    return (EXIT_SUCCESS);
}