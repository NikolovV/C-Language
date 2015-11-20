/* 
 A Dot product of two vectors is a scalar which is a result of the sum of 
 the product of each of the two vectors’ members. For example, if we have 
 the vector [a 1 , a 2 ... a n ] and the vector [b 1 , b 2 ... b n ], their 
 dot product is:
 (a 1 b 1 + a 2 b 2 ... + a n b n ). You are given the length n of each of 
 the vectors on the first input line (In order to perform a dot product of 
 two vectors, they have to be with equal dimensions). On the next n lines, 
 you are given the members of the first vector, and on the next n ones, 
 the members of the second one.
 */

#include <stdio.h>
#include <stdlib.h>

void check_intInput(int *a);
void fill_array(int str[], int size);
int dot_product_of_vectors(int str_a[], int str_b[], int size);

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

    printf("Enter vector members :\n");
    int firstVector[dimension], secondVector[dimension];
    fill_array(firstVector, dimension);
    fill_array(secondVector, dimension);

    int result = dot_product_of_vectors(firstVector, secondVector, dimension);
    
    printf("result %d", result);
    
    return (EXIT_SUCCESS);
}

int dot_product_of_vectors(int str_a[], int str_b[], int size)
{
    int sum = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        sum += (str_a[i] * str_b[i]);
    }
    
    return sum;
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