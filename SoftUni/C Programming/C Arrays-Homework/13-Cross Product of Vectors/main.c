/* 
 The cross product of vectors is defined only in a dimension where n = 3. 
 It takes as input two vectors and produces a new one in the same 
 dimension. Each member of the resulting vector is a result of the 
 determinant of the members from different rows in the first vector. 
 Example: [a 1 , a 2 , a 3 ] x [b 1 , b 2 , b 3 ] = 
 [ (a 2 *b 3 – a 3 *b 2 ), (a 3 *b 1 – a 1 *b 3 ), ( a 1 *b 2 – a 2 *b 1 ) ]
 Note how the middle row is calculated with the terms backwards or you could
 just take the negative of the regular calculation. On the first 3 input 
 lines, you are given the members of the first vectors, and on the next 
 ones, you are given the members of the second one. 
 */

#include <stdio.h>
#include <stdlib.h>

#define ROWS 3

void check_intInput(int *a);
void fill_array(int str[], int size);
void cross_product_of_vectors(int str_a[], int str_b[]);

int main()
{
    printf("Enter vector members :\n");

    int firstVector[ROWS], secondVector[ROWS];
    fill_array(firstVector, ROWS);
    fill_array(secondVector, ROWS);

    cross_product_of_vectors(firstVector, secondVector);

    return (EXIT_SUCCESS);
}

void cross_product_of_vectors(int str_a[], int str_b[])
{
    int result[ROWS];
    // [(a1*b2 - a2*b1), (a2*b0 - a0*b2), (a0*b1 - a1*b0)]

    //  0             1             2 
    int i = ROWS - 3, f = ROWS - 2, g = ROWS - 1;

    result[0] = (str_a[f] * str_b[g]) - (str_a[g] * str_b[f]);
    result[1] = (str_a[g] * str_b[i]) - (str_a[i] * str_b[g]);
    result[2] = (str_a[i] * str_b[f]) - (str_a[f] * str_b[i]);

    printf("Printing result:");
    
    printf("[");
    int k;
    for (k = 0; k < ROWS; k++)
    {
        printf("%d", result[k]);
        if (k < ROWS - 1)
        {
            printf(", ");
        }
    }
    printf("]");
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