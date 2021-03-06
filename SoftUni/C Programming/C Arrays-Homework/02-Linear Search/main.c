/* 
 Given an array of n integers, write a linear search function that determines
 whether a given element exists in the array. On the first line 
 you will receive the number n. On the second line, there will be n numbers, 
 space-separated. On the third line, the search number will be given.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void check_intInput(int *a);
void fill_array(int str[], int size);
bool is_exists(int *str, int size, int num);

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
    
    int numbers[n];
    printf("Enter %d numbers : ", n);
    fill_array(numbers, n);
    
    int searchElement;
    printf("Enter number to search: ");
    check_intInput(&searchElement);
    
    printf(is_exists(numbers, n, searchElement) ? "yes" : "no");
       
    return (EXIT_SUCCESS);
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