/* 
 Write a program that takes as input two arrays of integers and joins them. 
 The result should hold all numbers from the first array, and all numbers 
 from the second array, without repeating numbers, and arranged in increasing 
 order. On the first input line, you are given the count of the elements 
 of the first array. On the next line you are given the length of the second array. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void check_intInput(int *a);
void fill_array(int str[], int size);
int *join_list(int str_a[], int lenght_a, int str_b[], int lenght_b, int *element);
void bubble_sort(int str[], int size);
void print_array(const int str[], int size);
bool is_exists(int *str, int size, int num);


int main()
{
    int firstIndex, secondIndex;

    printf("Enter firstIndex and secondIndex: ");
    check_intInput(&firstIndex);
    check_intInput(&secondIndex);
    
    if (firstIndex <= 0 || secondIndex<= 0)
    {
        printf("Index > 0 !");
        exit(EXIT_FAILURE);
    }

    int firstArray[firstIndex];
    int secondArray[secondIndex];
    printf("Enter numbers : ");
    fill_array(firstArray, firstIndex);
    fill_array(secondArray, secondIndex);

    int uniqueElemet;
    int *joinArr = join_list(firstArray, firstIndex, secondArray, secondIndex, &uniqueElemet);

    bubble_sort(joinArr, uniqueElemet);

    print_array(joinArr, uniqueElemet);

    free(joinArr);

    return (EXIT_SUCCESS);
}

void print_array(const int str[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", str[i]);
    }
}

void bubble_sort(int *str, int size)
{
    bool isSwap = true;
    int i;
    while (isSwap)
    {
        isSwap = false;
        for (i = 0; i < size - 1; i++)
        {
            if (str[i] > str[i + 1])
            {
                int oldValue = str[i];
                str[i] = str[i + 1];
                str[i + 1] = oldValue;
                isSwap = true;
            }
        }
    }
}

int *join_list(int str_a[], int lenght_a, int str_b[], int lenght_b, int *element)
{
    int joinIndex = lenght_a + lenght_b;
    
    int *result = malloc(joinIndex * sizeof (int));
    int count = 1;

    result[0] = str_a[0];
    
    int i;
    for (i = 1; i < lenght_a; i++)
    {
        if (!is_exists(result, count, str_a[i]))
        {
            result[count] = str_a[i];
            count++;
        }
    }
    
    for (i = 0; i < lenght_b; i++)
    {
        if (!is_exists(result, count, str_b[i]))
        {
            result[count] = str_b[i];
            count++;
        }
    }

    *element = count;

    return result;
}

void check_intInput(int *a)
{
    if ((scanf("%d", a)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}

void fill_array(int str[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if ((scanf("%d", &str[i])) != 1)
        {
            printf("Not digit!");
            exit(EXIT_FAILURE);
        }
    }
}

bool is_exists(int *str, int size, int num)
{
    int i;
    for (i = 0; i <= size; i++)
    {
        if (str[i] == num)
        {
            return true;
        }
    }
    return false;
}