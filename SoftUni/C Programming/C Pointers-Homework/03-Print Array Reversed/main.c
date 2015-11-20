/* 
 You are given a sample array as input and your task is to print the 
 array in reversed order using pointer arithmetic instead of indexing.
 */

#include <stdio.h>
#include <stdlib.h>

void check_intInput(int *a);
void reverced_print(int *str, size_t size);
void fill_array(int str[], int size);

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

    reverced_print(numbers, n);

    return (EXIT_SUCCESS);
}

void fill_array(int str[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if ((scanf("%d", (str + i))) != 1)
        {
            printf("Not digit!");
            exit(EXIT_FAILURE);
        }
    }
}

void check_intInput(int *a)
{
    if ((scanf("%d%*c", a)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}

void reverced_print(int *str, size_t size)
{
    int i;
    for (i = size - 1; i >= 0; i--)
    {
        printf("%d ", *(str + i));
    }
}