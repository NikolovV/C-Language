/* 
 A multiplication of two matrices is performed by taking each of the rows 
 of the first matrix and taking the dot product of it and each of the 
 columns in the second matrix. The newly created matrix has dimensions 
 RxC, where R is the number of rows of the first matrix and C is the 
 number of columns of the second matrix.Note that a matrix multiplication 
 is valid only if the number of rows of the first matrix is equal to the 
 number of columns of the second matrix and the number of columns of the 
 first one are equal to the number of rows of the second one. On the first .
 two input lines you are given the dimensions of the first matrix. The second 
 matrix has the same dimensions in inversed order.
 */

#include <stdio.h>
#include <stdlib.h>

void check_intInput(int *a);
void fill_D_array(int ROW, int COL, int strTwoD[][COL]);
void multiplication_of_matrices(int ROW, int COL, int a[][COL], int b[][ROW]);
void print_matrix(int ROW, int COL, int a[][COL]);

int main()
{
    int row, col;

    printf("Enter row and col:");
    check_intInput(&row);
    check_intInput(&col);

    if (row <= 0 || col <= 0)
    {
        printf("row > 0 and col > 0 !");
        exit(EXIT_FAILURE);
    }
    int matrix_A[row][col], matrix_B[col][row];
    printf("Enter matrix element:\n");
    fill_D_array(row, col, matrix_A);
    fill_D_array(col, row, matrix_B);

    multiplication_of_matrices(row, col, matrix_A, matrix_B);

    return (EXIT_SUCCESS);
}
void print_matrix(int ROW, int COL, int a[][COL])
{
    int i, k;
     for (i = 0; i < ROW; i++)
    {
        printf("|");
        int k;
        for (k = 0; k < COL; k++)
        {
            printf("%4d ", a[i][k]);
        }
        printf("|\n");
    }
}

void multiplication_of_matrices(int ROW, int COL, int a[][COL], int b[][ROW])
{
    int result[ROW][ROW];
    int i, f, g;
    for (i = 0; i < ROW; i++)
    {
        for (f = 0; f < ROW; f++)
        {
            result[i][f] = 0;
            for (g = 0; g < COL; g++)
            {
                result[i][f] += a[i][g] * b[g][f];
            }
        }
    }

    printf("Printing...\n");
    print_matrix(ROW, ROW, result);
}

void check_intInput(int *a)
{
    if ((scanf("%d", a)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}

void fill_D_array(int ROW, int COL, int strTwoD[][COL])
{
    int row, col;
    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            if ((scanf("%d", &strTwoD[row][col])) != 1)
            {
                printf("Not digit!");
                exit(EXIT_FAILURE);
            }
        }
    }
}