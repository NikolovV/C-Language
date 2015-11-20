#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Text_Gravity.h"

void print_matrix(int ROW, int COL, char a[][COL])
{
    int i, k;
    for (i = 0; i < ROW; i++)
    {
        printf("|");
        int k;
        for (k = 0; k < COL; k++)
        {
            printf("%c", a[i][k]);
        }
        printf("|\n");
    }
}

int remove_new_line(char *str)
{
    int lenght = strlen(str);
    if (str[lenght - 1] == '\n')
    {
        str[lenght - 1] = '\0';
    }
    return lenght;
}

void check_intInput(int *a)
{
    if ((scanf("%d%*c", a)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}

void fill_D_array(int ROW, int COL, char strTwoD[][COL], char str[], int size)
{
    char space = ' ';
    int row, col, i = 0;
    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col <= COL; col++)
        {
            if (str[i] != '\0')
            {
                strTwoD[row][col] = str[i];
                i++;
            }
            else
            {
                strTwoD[row][col] = space;
            }
        }
        i--;
    }
}

void text_gravity(int ROW, int COL, char a[][COL])
{
    char space = ' ';
    int row, col;
    int i;
    for (i = 0; i < 2; i++)
    {
        for (row = ROW - 1; row; row--)
        {
            for (col = 0; col < COL; col++)
            {
                if (a[row][col] == space)
                {
                    a[row][col] = a[row - 1][col];
                    a[row - 1][col] = space;
                }
            }
        }
    }
}