/* 
 Write an expression that extracts from given integer n the value of given 
 bit at index p.
 */

#include <stdio.h>
#include <stdlib.h>

void check_intInput(int *a, int *b);
int nth_position(int num, int position);

int main()
{
    printf("Enter decimal and bit position: ");
    int n, position;
    check_intInput(&n, &position);

    int result = nth_position(n, position);
    printf("%d bit position of %d is %d", position, n, result);

    return (EXIT_SUCCESS);
}

int nth_position(int num, int position)
{
    return ((num >> position) & 1);
}

void check_intInput(int *a, int *b)
{
    if ((scanf("%d %d%*c", a, b)) != 2)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
    if (*a < 0 || *b < 0)
    {
        printf("Can't be negative!");
        exit(EXIT_FAILURE);
    }
}