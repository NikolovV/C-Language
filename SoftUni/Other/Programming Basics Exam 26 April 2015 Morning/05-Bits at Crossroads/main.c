#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

#define BUFFER 10

void set_bit(uint32_t *number, int position, int bit_value);
bool nth_position(uint32_t num, int position);
void begin_game(uint32_t size);
void fil_from_top_left(uint32_t arr[], int ROW, int COL, int size, int *counter);
void fill_from_top_right(uint32_t arr[], int ROW, int COL, int size, int *counter);
size_t remove_new_line(char *str);
void print_array(uint32_t str[], size_t size);
void zero_arr(uint32_t str[], size_t size);

int main()
{
    uint32_t boardSize;
    scanf("%u%*c", &boardSize);

    begin_game(boardSize);

    return (EXIT_SUCCESS);
}

void begin_game(uint32_t size)
{
    char input[BUFFER];
    fgets(input, BUFFER, stdin);
    remove_new_line(input);

    int crossroadsCount = 0;
    uint32_t digits[size];
    int currentRow, currentCol;
    zero_arr(digits, size);
    while (strcasecmp(input, "end") != 0)
    {
        char *remainder;
        currentRow = strtol(input, &remainder, 10);
        currentCol = strtol(remainder, &remainder, 10);

        set_bit(&digits[currentRow], currentCol, 1);

        fil_from_top_left(digits, currentRow, currentCol, size, &crossroadsCount);
        fill_from_top_right(digits, currentRow, currentCol, size, &crossroadsCount);

        crossroadsCount++;

        fgets(input, BUFFER, stdin);
        remove_new_line(input);
    }

    print_array(digits, size);
    printf("%u", crossroadsCount);


}

void zero_arr(uint32_t str[], size_t size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        str[i] = 0;
    }
}

void print_array(uint32_t str[], size_t size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%u\n", str[i]);
    }
}

void fil_from_top_left(uint32_t arr[], int ROW, int COL, int size, int *counter)
{
    int startRow, startCol = COL + ROW;

    if (startCol > size - 1)
    {
        startRow = startCol - size + 1;
        startCol = size - 1;
    }
    else
    {
        startRow = 0;
    }

    for (; startRow <= size - 1 && startCol >= 0; startRow++, startCol--)
    {
        if (nth_position(arr[startRow], startCol) == 1 &&
                startRow != ROW && startCol != COL)
        {
            (*counter)++;
        }
        set_bit(&arr[startRow], startCol, 1);
    }
}

void fill_from_top_right(uint32_t arr[], int ROW, int COL, int size, int *counter)
{
    int startRow, startCol = COL - ROW;

    if (startCol < 0)
    {
        startRow = startCol * (-1);
        startCol = 0;
    }
    else
    {
        startRow = 0;
    }

    for (; startRow <= size - 1 && startCol <= size - 1; startRow++, startCol++)
    {
        if (nth_position(arr[startRow], startCol) == 1 &&
                startRow != ROW && startCol != COL)
        {
            (*counter)++;
        }
        set_bit(&arr[startRow], startCol, 1);
    }
}

size_t remove_new_line(char *str)
{
    int lenght = strlen(str);
    if (str[lenght - 1] == '\n')
    {
        str[lenght - 1] = '\0';
    }
    return lenght - 1;
}

void set_bit(uint32_t *number, int position, int bit_value)
{
    if (bit_value == 1)
    {
        *number |= (bit_value << position);
    }
    else
    {
        *number &= (~(1 << position));
    }
}

bool nth_position(uint32_t num, int position)
{
    return ((num >> position) & 1);
}