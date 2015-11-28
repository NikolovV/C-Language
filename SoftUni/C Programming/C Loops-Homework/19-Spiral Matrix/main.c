/* 
 Write a program that reads from the console a positive integer number 
 n(1 ≤ n≤ 20) and prints a matrix holding the numbers from 1 to n*n in the 
 form of square spiral like in the examples below.
 */

#include <stdio.h>
#include <stdlib.h>

void check_intInput(int *a);
void fill_array_spiral(int n, int arr[][n]);
void print_array(int n, int arr[][n]);

int main(int argc, char** argv)
{
    int n;
    check_intInput(&n);
    
    int spiral[n][n];
    fill_array_spiral(n, spiral);

    print_array(n, spiral);

    return (EXIT_SUCCESS);
}

void check_intInput(int *a)
{
    if ((scanf("%d", a)) != 1)
    {
        fprintf(stderr, "Not digit!");
        exit(EXIT_FAILURE);
    }
    if (*a <= 0)
    {
        fprintf(stderr, "Must be grater from 0.");
        exit(EXIT_FAILURE);
    }
}

void fill_array_spiral(int n, int arr[][n])
{
    int maxRow, maxCol;
    maxRow = maxCol = n - 1;

    int ctr = 1;
    int row = 0, col = 0;
    int i;
    while (ctr <= n * n)
    {
        // right
        for (i = col; i <= maxCol; i++)
        {
            arr[row][i] = ctr;
            ctr++;
        }
        row++;
        // down
        for (i = row; i <= maxRow; i++)
        {
            arr[i][maxCol] = ctr;
            ctr++;
        }
        maxCol--;
        // left
        for (i = maxCol; i >= col; i--)
        {
            arr[maxRow][i] = ctr;
            ctr++;
        }
        maxRow--;
        // up
        for (i = maxRow; i >= row; i--)
        {
            arr[i][col] = ctr;
            ctr++;
        }
        col++;
    }
}

void print_array(int n, int arr[][n])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%3d ", arr[i][j]);
        }

        printf("\n");
    }
}