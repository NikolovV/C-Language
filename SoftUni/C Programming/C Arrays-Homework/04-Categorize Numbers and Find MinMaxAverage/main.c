/* 
 Write a program that reads N floating-point numbers from the console. 
 Your task is to separate them in two sets, one containing only 
 the round numbers(e.g. 1, 1.00, etc.) and the other containing 
 the floating-point numbers with non-zero fraction. 
 Print both arrays along with their minimum, maximum, sum and average 
 (rounded to two decimal places). 
 The numbers should be entered one at a line. 
 On the first input line you will be given the count of the numbers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SeparateNumberFindMinMaxAverage.h"

int main()
{
    int n;

    printf("Enter n: ");
    check_intInput(&n);
    
    if (n <= 0)
    {
        printf("n > 0 !");
        exit(EXIT_FAILURE);
    }

    float buffer[n];
    printf("Enter %d numbers : ", n);
    fill_array(buffer, n);

    int roundLenght;
    float roundNumbers[n];
    int floatingLenght;
    float floatingPointNumbers[n];

    floatingLenght = colect_floating(buffer, n, floatingPointNumbers);
    roundLenght = colect_round(buffer, n, roundNumbers);
    
    
    print_info(floatingPointNumbers, floatingLenght);
    print_info(roundNumbers, roundLenght);

    return (EXIT_SUCCESS);
}