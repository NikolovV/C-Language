/* 
 Write a program that reverses an array of numbers. The numbers 
 should be entered one at a line. On the first input line 
 you will be given the count of the numbers.
 */

#include <stdio.h>
#include <stdlib.h>

void check_intInput(int *a);
void fill_array(int str[], int size);
void print_reverced(const int str[], int size);

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

    int buffer[n];
    printf("Enter %d numbers : ", n);
    fill_array(buffer, n);

    printf("Printing reversed...\n");
    print_reverced(buffer, n);

    return (EXIT_SUCCESS);
}

void print_reverced(const int str[], int size)
{
    if (size <= 0)
    {
        return;
    }
    print_reverced(str + 1, --size);
    printf("%d ", str[0]);
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