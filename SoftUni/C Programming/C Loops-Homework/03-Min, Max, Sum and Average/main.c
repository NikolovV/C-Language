/* 
 Write a program that reads from the console a sequence of n integer numbers 
 and returns the minimal, the maximal number, the sum and the average of all 
 numbers (displayed with 2 digits after the decimal point).The input 
 starts by the number n(alone in a line) followed by n lines, 
 each holding an integer number. The output is like in the examples below. 
 */

#include <stdio.h>
#include <stdlib.h>

void checkIntInput(int *);

int main()
{
    int number, num, sum = 0;
    double average, min = num, max;


    printf("Enter numbers: ");
    checkIntInput(&number);

    int ctr = 1;
    while (ctr <= number)
    {
        checkIntInput(&num);
//        min = num;
        min = (min < num) ? min : num;
        max = (max > num) ? max : num;
        sum += num;
        average = (double) sum / number;
        ctr++;
    }
    
    printf("min = %.2lf\n", min);
    printf("max = %.2lf\n", max);
    printf("sum = %.2lf\n", (double)sum);
    printf("average = %.2lf\n", average);

    return (EXIT_SUCCESS);
}

void checkIntInput(int *a)
{
    if ((scanf("%d", a)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}