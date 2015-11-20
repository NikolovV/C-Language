#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SeparateNumberFindMinMaxAverage.h"

void print_info(const float str[], int size)
{
    printf("[");
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%g", str[i]);
        if (i < size - 1)
        {
            printf(", ");
        }
    }
    printf("]");
    printf(" -> ");
    printf("min: %g", get_mininal(str, size));
    printf(", max: %g", get_maxinal(str, size));
    printf(", sum: \n%g", get_sum(str, size));
    printf(", avg: %.2f\n", get_average(str, size));
}

float get_mininal(const float str[], int size)
{
    float minimal = str[0];
    int i;
    for (i = 1; i < size; i++)
    {
        if (minimal > str[i])
        {
            minimal = str[i];
        }
    }
    
    return minimal;
}

float get_maxinal(const float str[], int size)
{
    float maximal = str[0];
    int i;
    for (i = 1; i < size; i++)
    {
        if (maximal < str[i])
        {
            maximal = str[i];
        }
    }
    
    return maximal;
}

float get_sum(const float str[], int size)
{
    float sum = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        sum += str[i];
    }
    
    return sum;
}

float get_average(const float str[], int size)
{
    float average = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        average += str[i];
    }
    
    return average / size;
}

void check_intInput(int *a)
{
    if ((scanf("%d", a)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}

bool is_floating_point(float a)
{
    float diference = a - (int) a;
    if (diference > FLOATING_COMPARSION)
    {
        return true;
    }
    return false;
}

void fill_array(float str[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if ((scanf("%f", &str[i])) != 1)
        {
            printf("Not digit!");
            exit(EXIT_FAILURE);
        }
    }
}

int colect_floating(const float *str, int size, float destiantion[])
{
    int i, counter = 0;
    for (i = 0; i < size; i++)
    {
        if (is_floating_point(str[i]))
        {
            destiantion[counter] = str[i];
            counter++;
            if (counter < size)
            {
                destiantion[counter] = 0.0;
            }
        }
    }
    return counter;
}

int colect_round(const float *str, int size, float destiantion[])
{
    int i, counter = 0;
    for (i = 0; i < size; i++)
    {
        if (!is_floating_point(str[i]))
        {
            destiantion[counter] = str[i];
            counter++;
            if (counter < size)
            {
                destiantion[counter] = 0.0;
            }
        }
    }
    return counter;
}