#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

size_t read_line(char **buffer, size_t *size);
void calculete_score(char *str, size_t size, int matrixSize, int *black, int *white);
void print_result(int black, int white);

int main()
{
    int chessboardSize;
    scanf("%d%*c", &chessboardSize);

    char *input = NULL;
    size_t size = 0;
    size_t lenght = read_line(&input, &size);

    int blackScore = 0, whiteScore = 0;
    calculete_score(input, lenght, chessboardSize, &blackScore, &whiteScore);

    print_result(blackScore, whiteScore);

    free(input);

    return (EXIT_SUCCESS);
}

void print_result(int black, int white)
{
    if (black > white)
    {
        printf("The winner is: black team\n");
        printf("%d", black - white);
    }
    else if (black == white)
    {
        printf("Equal result: %d", white);
    }
    else
    {
        printf("The winner is: white team\n");
        printf("%d", white - black);
    }
}

void calculete_score(char *str, size_t size, int matrixSize, int *black, int *white)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        if (i >= matrixSize * matrixSize)
        {
            break;
        }
        if (i % 2 == 0 && isupper(str[i]))
        {
            *white += str[i];
        }
        else if (i % 2 == 0 && (isalpha(str[i]) || isdigit(str[i])))
        {
            *black += str[i];
        }
        else if (i % 2 != 0 && isupper(str[i]))
        {
            *black += str[i];
        }
        else if (i % 2 != 0 && (isalpha(str[i]) || isdigit(str[i])))
        {
            *white += str[i];
        }
    }
}

size_t read_line(char **buffer, size_t *size)
{
    char *line = *buffer;
    if (!line)
    {
        line = (char*) malloc(32);
        if (!line)
        {
            return 0;
        }
    }

    size_t index = 0;
    size_t currentSize = 32;

    char c = getchar();
    while (c != '\n' && c != EOF)
    {
        if (index == currentSize - 1)
        {
            currentSize *= 2;
            char *resized = (char*) realloc(line, currentSize);
            if (!resized)
            {
                return 0;
            }
            line = resized;
        }

        line[index] = c;
        index++;
        c = getchar();
    }

    line[index] = '\0';
    *buffer = line;
    *size = currentSize;

    return index;
}