/* 
 Write a program to read an array of numbers from the console, sort them 
 and print them back on the console.Use a sorting algorithm of your choosing.
 The numbers should be entered one at a line. On the first input line you will be 
 given the count of the numbers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void check_intInput(int *a);
void fill_array(int str[], int size);
void bubble_sort(int str[], int size);
void print_array(const int str[], int size);

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

    int array[n];

    printf("Enter %d numbers : ", n);
    fill_array(array, n);
    
    bubble_sort(array, n);

    print_array(array, n);

    return (EXIT_SUCCESS);

}
void fill_array(int str[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        check_intInput(&str[i]);
    }
}
void print_array(const int str[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", str[i]);
    }
}

void check_intInput(int *a)
{
    if ((scanf("%d", a)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}

void bubble_sort(int str[], int size)
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