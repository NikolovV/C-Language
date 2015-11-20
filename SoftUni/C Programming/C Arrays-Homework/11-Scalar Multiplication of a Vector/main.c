/* 
 A Scalar Multiplication of vectors is when you have a given vector 
 (ex. [a 1 , a 2 ... a n ] ) and you want to multiply it by a scalar 
 (a simple number). The multiplication is done by multiplying the scalar 
 with each of the vector members. Write a program to perform a scalar 
 multiplication of a vector. You are given an input number representing 
 the dimension of a vector on the first input line. On the second input 
 line, you are given the scalar to multiply the vector and on the next n 
 lines, you are given the members of the vector.
 */

#include <stdio.h>
#include <stdlib.h>

void check_intInput(int *a);
void fill_array(int str[], int size);
void vector_scalar_multiply(const int str[], int size, int multiply);

int main()
{
    int dimension;

    printf("Enter dimension: ");
    check_intInput(&dimension);
    
    if (dimension <= 0)
    {
        printf("dimension > 0 !");
        exit(EXIT_FAILURE);
    }

    int scalar;
    printf("Enter scalar: ");
    check_intInput(&scalar);

    int vector[dimension];
    printf("Enter vector members : ");
    fill_array(vector, dimension);

    vector_scalar_multiply(vector, dimension, scalar);

    return (EXIT_SUCCESS);
}

void vector_scalar_multiply(const int str[], int size, int multiply)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", str[i] * multiply);
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