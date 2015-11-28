#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMAND 8
#define BIT_FIED 31

size_t remove_new_line(char *str);
int nth_position(unsigned int num, int position);
void set_bit(unsigned int *number, int position, int bit_value);

int main(int argc, char** argv)
{
    unsigned int n;
    scanf("%u%*c", &n);
    
    unsigned int field[n];

    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%u%*c", &field[i]);
    }

    int row = 0, col = 0, newRow, newCol;

    char comand[COMAND];
    fgets(comand, COMAND, stdin);
    remove_new_line(comand);

    while (strcmp(comand, "end") != 0)
    {
        newCol = col, newRow = row;
        if (strcmp(comand, "right") == 0)
        {
            newCol--;
            if (newCol < 0)
            {
                newCol = BIT_FIED;
            }
        }
        else if (strcmp(comand, "left") == 0)
        {
            newCol++;
            if (newCol >= BIT_FIED)
            {
                newCol = 0;
            }
        }
        else if (strcmp(comand, "up") == 0)
        {
            newRow--;
            if (newRow < 0)
            {
                newRow = n - 1;
            }
        }
        else
        {
            newRow++;
            if (newRow >= n)
            {
                newRow = 0;
            }
        }

        int bitValue = nth_position(field[newRow], newCol);
        if (bitValue == 1)
        {
            printf("GAME OVER. Stepped a mine at %d %d\n", newRow, newCol);
            break;
        }

        set_bit(&field[row], col, 0);
        set_bit(&field[newRow], newCol, 1);
        row = newRow;
        col = newCol;

        fgets(comand, COMAND, stdin);
        remove_new_line(comand);
    }

    for (i = 0; i < n; i++)
    {
        printf("%u\n", field[i]);
    }

    return (EXIT_SUCCESS);
}

size_t remove_new_line(char *str)
{
    int lenght = strlen(str);
    if (str[lenght - 1] == '\n')
    {
        str[lenght - 1] = '\0';
    }
    return lenght;
}

int nth_position(unsigned int num, int position)
{
    return ((num >> position) & 1U);
}

void set_bit(unsigned int *number, int position, int bit_value)
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