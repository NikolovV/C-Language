/* 
You are given a matrix of numbers. Your task is to print out the numbers, 
one group at a line, which are stationed beneath the matrix’s main diagonal 
along with the diagonal itself. On the first input line, 
you are given the matrix’s rows and cols count.
 */

#include <stdio.h>
#include <stdlib.h>

void check_intInput(int *a);
void fill_D_array(int ROW, int COL, int strTwoD[][COL]);
void print_main_diagonal(int ROW, int COL, int strTwoD[][COL]);

int main()
{
    int n;

    printf("Enter row: ");
    check_intInput(&n);
    
    if (n <= 0)
    {
        printf("n > 0 !");
        exit(EXIT_FAILURE);
    }

    int buffer[n][n];
    printf("Enter matrix element:\n");
    fill_D_array(n, n , buffer);
    
    printf("Numbers Beneath Main Diagonal.\n");
    print_main_diagonal(n, n , buffer);

    return (EXIT_SUCCESS);
}

void print_main_diagonal(int ROW, int COL, int strTwoD[][COL])
{
    int row, col;
    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col <= row; col++)
        {
            printf("%d ", strTwoD[row][col]);
        }
        printf("\n");
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