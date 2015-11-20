/* 
 Write a function that takes 2 pointers and swaps the memory they point to. 
 The function should also take the size of each memory piece and should work 
 with any data type.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generic_swap(void *a, void *b, size_t size);

int main()
{
    char letter = 'B', symbol = '+';
    printf("Before swap: ");
    printf("%c %c", letter, symbol);
    printf("\n");

    generic_swap(&letter, &symbol, sizeof (char));

    printf("After swap:  ");
    printf("%c %c", letter, symbol);
    printf("\n\n");

    int a = 10, b = 6;
    printf("Before swap: ");
    printf("%d %d", a, b);
    printf("\n");

    generic_swap(&a, &b, sizeof (int));

    printf("After swap:  ");
    printf("%d %d", a, b);
    printf("\n\n");

    double d = 3.14, f = 1.23567;
    printf("Before swap: ");
    printf("%.f2 %.f2", d, f);
    printf("\n");

    generic_swap(&d, &f, sizeof (double));

    printf("After swap:  ");
    printf("%.f2 %.f2", d, f);
    printf("\n");

    return (EXIT_SUCCESS);
}

void generic_swap(void *a, void *b, size_t size)
{
    unsigned char *aPtr = a;
    unsigned char *bPtr = b;
    int i;
    for (i = 0; i < size; i++)
    {
        char oldValue = *(aPtr + i);
        *(aPtr + i) = *(bPtr + i);
        *(bPtr + i) = oldValue;
    }
}