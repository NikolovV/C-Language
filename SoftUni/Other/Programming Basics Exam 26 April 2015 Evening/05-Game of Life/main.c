#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOAR_SIZE 10

int get_max(int a, int b);
int get_min(int a, int b);
void set_bit(int *number, int position, int bit_value);
bool nth_position(int num, int position);
void fill_array(int str[], int copy[], size_t size);
void start_game(int src[], int copy[], size_t size);
int count_neighbouts_ones(int src[], size_t size, int row, int col);
void print_in_binary(int src[], size_t size);

int main(int argc, char** argv)
{
    int coordinateCount;
    scanf("%d", &coordinateCount);

    int board[BOAR_SIZE] = {0};
    int temp[BOAR_SIZE] = {0};

    fill_array(board, temp, coordinateCount);

    start_game(board, temp, BOAR_SIZE);

    print_in_binary(board, BOAR_SIZE);

    return (EXIT_SUCCESS);
}

void print_in_binary(int src[], size_t size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 9; j >= 0; j--)
        {
            if (nth_position(src[i], j) == 1)
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
        printf("\n");
    }
}

void start_game(int src[], int copy[], size_t size)
{
    int neighboursCount = 0;
    int currentRow, currentCol;
    for (currentRow = 0; currentRow < size; currentRow++)
    {
        for (currentCol = 0; currentCol < size; currentCol++)
        {
            neighboursCount = count_neighbouts_ones(copy, BOAR_SIZE, currentRow, currentCol);
            if ((nth_position(copy[currentRow], currentCol)) == 1)
            {
                if (neighboursCount < 2 || neighboursCount > 3)
                {
                    set_bit(&src[currentRow], currentCol, 0);
                }
            }
            else if (neighboursCount == 3)
            {
                set_bit(&src[currentRow], currentCol, 1);
            }
        }
    }
}

int count_neighbouts_ones(int src[], size_t size, int row, int col)
{
    int countOfOnes = 0;
    int startRow = get_max(0, row - 1);
    int endRow = get_min(BOAR_SIZE - 1, row + 1);
    int startCol = get_max(0, col - 1);
    int endCol = get_min(BOAR_SIZE - 1, col + 1);

    int i;
    for (i = startRow; i <= endRow; i++)
    {
        int j;
        for (j = startCol; j <= endCol; j++)
        {
            if (i == row && j == col)
            {
                continue;
            }
            if (nth_position(src[i], j) == 1)
            {
                countOfOnes++;
            }
        }
    }

    return countOfOnes;
}

void fill_array(int str[], int copy[], size_t size)
{
    int i, x, y;
    for (i = 0; i < size; i++)
    {
        scanf("%d %d%*c", &x, &y);
        set_bit(&str[x], y, 1);
        
        copy[x] = str[x];
    }
}

int get_max(int a, int b)
{
    int bigger = (a > b) ? a : b;
    return bigger;
}

int get_min(int a, int b)
{
    int smaller = (a < b) ? a : b;
    return smaller;
}

void set_bit(int *number, int position, int bit_value)
{
    if (bit_value == 1)
    {
        *number |= (bit_value << position);
    }
    else
    {
        *number &= (~(1U << position));
    }
}

bool nth_position(int num, int position)
{
    return ((num >> position) & 1);
}