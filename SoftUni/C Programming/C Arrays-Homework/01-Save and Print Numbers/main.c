/* 
 Write a program that reads n numbers from the console and saves them 
 in an array. The program should then print the elements of the array 
 on the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER 30

void check_intInput(int *a);
void fill_array(int str[], int size);
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

    int numbers[n];
    printf("Enter %d numbers : ", n);
    fill_array(numbers, n);

    print_array(numbers, n);

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

void print_array(const int str[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", str[i]);
    }
}