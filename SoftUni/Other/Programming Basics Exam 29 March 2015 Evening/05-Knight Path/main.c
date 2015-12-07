#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>

#define GAME_FIELD 8
#define COMMAND_BUF 20

void begin_game(const char *commands[]);
void move_the_king(const char *command, int field[],
                   int *ROW, int *COL, int commandNumber);
size_t remove_new_line(char *str);
void convert_nth_position(int *number, int position);
void print_array(int str[], size_t size);

int main()
{
    const char *gameCommands[] = {"left up", "left down",
                                    "right up", "right down",
                                    "up left", "up right",
                                    "down left", "down right"};
    begin_game(gameCommands);

    return (EXIT_SUCCESS);
}

void begin_game(const char *commands[])
{
    char commandBuffer[COMMAND_BUF];
    fgets(commandBuffer, COMMAND_BUF, stdin);
    remove_new_line(commandBuffer);

    int numbers[GAME_FIELD] = {0};
    numbers[0] = 1;
    int currentRow = 0, currentCol = 0;
    while (strcasecmp(commandBuffer, "stop") != 0)
    {
        int i;
        for (i = 0; i < GAME_FIELD; i++)
        {
            if (strcasecmp(commandBuffer, commands[i]) == 0)
            {
                break;
            }
        }
        move_the_king(commandBuffer, numbers, &currentRow, &currentCol, i);

        fgets(commandBuffer, COMMAND_BUF, stdin);
        remove_new_line(commandBuffer);
    }

    print_array(numbers, GAME_FIELD);
}

void move_the_king(const char *command, int field[],
                   int *ROW, int *COL, int commandNumber)
{
    int row = *ROW, col = *COL;
    switch (commandNumber)
    {
    case(0): // left up
        if (row - 1 >= 0 && col + 2 < GAME_FIELD)
        {
            *ROW -= 1;
            *COL += 2;
            convert_nth_position(&field[*ROW], *COL);
        }
        break;
    case(1): // left down
        if (row + 1 < GAME_FIELD && col + 2 < GAME_FIELD)
        {
            *ROW += 1;
            *COL += 2;
            convert_nth_position(&field[*ROW], *COL);
        }
        break;
    case(2): // right up
        if (row - 1 >= 0 && col - 2 >= 0)
        {
            *ROW -= 1;
            *COL -= 2;
            convert_nth_position(&field[*ROW], *COL);
        }
        break;
    case(3): // right down
        if (row + 1 < GAME_FIELD && col - 2 >= 0)
        {
            *ROW += 1;
            *COL -= 2;
            convert_nth_position(&field[*ROW], *COL);
        }
        break;
    case(4): // up left
        if (row - 2 >= 0 && col + 1 < GAME_FIELD)
        {
            *ROW -= 2;
            *COL += 1;
            convert_nth_position(&field[*ROW], *COL);
        }
        break;
    case(5): // up right
        if (row - 2 >= 0 && col - 1 >= 0)
        {
            *ROW -= 2;
            *COL -= 1;
            convert_nth_position(&field[*ROW], *COL);
        }
        break;
    case(6): // down left
        if (row + 2 < GAME_FIELD && col + 1 < GAME_FIELD)
        {
            *ROW += 2;
            *COL += 1;
            convert_nth_position(&field[*ROW], *COL);
        }
        break;
    case(7): // down right
        if (row + 2 < GAME_FIELD && col - 1 >= 0)
        {
            *ROW += 2;
            *COL -= 1;
            convert_nth_position(&field[*ROW], *COL);
        }
        break;
    }
}

void print_array(int str[], size_t size)
{
    int i, zeroCtr = 0;
    for (i = 0; i < size; i++)
    {
        if (str[i] > 0)
        {
            printf("%d", str[i]);
            if (i < size - 1)
            {
                printf("\n");
            }
        }
        else
        {
            zeroCtr++;
        }
    }
    if (i == zeroCtr)
    {
        printf("[Board is empty]");
    }
}

void convert_nth_position(int *number, int position)
{
    *number ^= (1 << position);
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