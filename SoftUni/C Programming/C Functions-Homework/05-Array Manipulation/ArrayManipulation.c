#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ArrayManipulation.h"

int get_min(const int* str, int lenght)
{
    int temp = str[0];
    int i;
    for (i = 1; i < lenght; i++)
    {
        if (temp > str[i])
        {
            temp = str[i];
        }
    }
    return temp;
}

int get_max(const int* str, int lenght)
{
    int temp = str[0];
    int i;
    for (i = 1; i < lenght; i++)
    {
        if (temp < str[i])
        {
            temp = str[i];
        }
    }
    return temp;
}

void arr_clear(int* str, int lenght)
{
    int i;
    for (i = 0; i < lenght; i++)
    {
        str[i] = '\0';
    }
}

double get_avg(const int* str, int lenght)
{
    double average = 0.0;
    int i;
    for (i = 0; i < lenght; i++)
    {
        average += str[i];
    }
    average /= lenght;

    return average;
}

int get_sum(const int* str, int lenght)
{
    int sum = 0;
    int i;
    for (i = 0; i < lenght; i++)
    {
        sum += str[i];
    }

    return sum;
}

bool arr_contains(int* str, int lenght, int specificElement)
{
    bool contains = false;

    int i;
    for (i = 0; i < lenght; i++)
    {
        if (str[i] == specificElement)
        {
            contains = true;
            return contains;
        }
    }

    return contains;
}

int* arr_merge(int* str_1, int* str_2, int lenghtArr_1, int lenghtArr_2)
{
    int *toMerged;
    int mergedLenght = lenghtArr_1 + lenghtArr_2;
    toMerged = malloc(mergedLenght * sizeof (int));
    if (toMerged == NULL)
    {
        printf("No memery!");
        exit(EXIT_FAILURE);
    }
    else
    {
        int i;
        for (i = 0; i < lenghtArr_1; i++)
        {
            toMerged[i] = str_1[i];
        }
        int k;
        for (k = 0; k < lenghtArr_2; i++, k++)
        {
            toMerged[i] = str_2[k];
        }
    }
    
    return toMerged;
}

int get_lenght(const int str[])
{
    int lenght = 0;
    while (str[lenght] != '\0')
    {
        lenght++;
    }

    return lenght;
}