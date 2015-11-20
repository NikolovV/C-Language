/* 
 You are given two matrices and you have to output a new matrix which is 
 their sum. The sum of matrices is calculated by adding each of the members 
 from the first matrix with each of the members of the second one and 
 producing a number which is a member of a new matrix and is stationed in 
 the same row and col. Write a program to calculate the sum of two matrices. 
 On the first 2 lines, you are given the dimensions of the two matrices 
 (In order for them to be added together, they must be of the same 
 dimensions). The first line represents the rows of the matrices and the 
 second one – the columns. On the next input lines, you are given the 
 members of the matrices.
 */

#include <stdio.h>
#include <stdlib.h>

void check_intInput(int *a);
void fill_D_array(int ROW, int COL, int strTwoD[][COL]);
void sum_of_matrices(int ROW, int COL, int a[][COL], int b[][COL]);

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
    
    int matrix_A[row][col], matrix_B[row][col];
    printf("Enter matrix element:\n");
    fill_D_array(row, col, matrix_A);
    fill_D_array(row, col, matrix_B);
    
    sum_of_matrices(row, col, matrix_A, matrix_B);

    return (EXIT_SUCCESS);
}

void sum_of_matrices(int ROW, int COL, int a[][COL], int b[][COL])
{
    int result[ROW][COL];
    int i;
    for (i = 0; i < ROW; i++)
    {
        printf("|");
        int k;
        for (k = 0; k < COL; k++)
        {
            result[i][k]=a[i][k]+b[i][k];
            
            printf("%3d", result[i][k]);
        }
        printf("|\n");
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