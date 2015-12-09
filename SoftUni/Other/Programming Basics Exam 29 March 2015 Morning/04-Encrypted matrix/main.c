#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define DEBUG 0

size_t read_line(char **buffer, size_t *size);
void convert_str_to_int(const char *msg, size_t size, int dest[]);
void encrypt_digits(int src[], size_t size);
void copy_arr(const int src[], size_t size, int dest[]);
int digit_count(const int src[], size_t size);

int main()
{
    char *input = NULL;
    size_t size = 0;
    size_t lenght = read_line(&input, &size);

    int inToDigigt[lenght];
    convert_str_to_int(input, lenght, inToDigigt);
    
    free(input);

    encrypt_digits(inToDigigt, lenght);
    
#if DEBUG 
    int i;
    for (i = 0; i < lenght; i++)
    {
        printf("%d ", inToDigigt[i]);
    }
    exit(0);
#endif
    
    int matrixSize = digit_count(inToDigigt, lenght);

    char diagonalDirection;
    scanf("%1c", &diagonalDirection);

    int matrix[matrixSize][matrixSize];
    int row, col;
    for (row = 0; row < matrixSize; row++)
    {
        for (col = 0; col < matrixSize; col++)
        {
            matrix[row][col] = 0;
        }
    }

    switch (diagonalDirection)
    {
    case('\\'):
    {
        int i, m_row, m_col = 0;
        for (i = 0, m_row = 0; i < lenght; i++, m_row++)
        {
            if (inToDigigt[i] <= 9)
            {
                matrix[m_row][m_col] = inToDigigt[i];
                m_col++;
            }
            else
            {
                int temp[2];
                temp[1] = inToDigigt[i] % 10;
                inToDigigt[i] /= 10;
                temp[0] = inToDigigt[i] % 10;
                matrix[m_row][m_col] = temp[0];
                m_row++;
                m_col++;
                matrix[m_row][m_col] = temp[1];
                m_col++;
            }
        }
        break;
    }
    case('/'):
    {
        int i, row = matrixSize - 1, col = 0;
        for (i = 0; i < lenght; i++, row--)
        {
            if (inToDigigt[i] <= 9)
            {
                matrix[row][col] = inToDigigt[i];
                col++;
            }
            else
            {
                int temp[2];
                temp[1] = inToDigigt[i] % 10;
                inToDigigt[i] /= 10;
                temp[0] = inToDigigt[i] % 10;
                matrix[row][col] = temp[0];
                row--;
                col++;
                matrix[row][col] = temp[1];
                col++;
            }
        }
        break;
    }
    }

    for (row = 0; row < matrixSize; row++)
    {
        for (col = 0; col < matrixSize; col++)
        {
            printf("%d", matrix[row][col]);
            if (col < matrixSize - 1)
            {
                printf(" ");
            }
        }
        if (row < matrixSize - 1)
        {
            printf("\n");
        }
    }

    return (EXIT_SUCCESS);
}

int digit_count(const int src[], size_t size)
{
    int i, digitCount = 0;
    for (i = 0; i < size; i++)
    {
        if (src[i] <= 9)
        {
            digitCount++;
        }
        else
        {
            int temp = src[i];
            while (temp > 0)
            {
                temp /= 10;
                digitCount++;
            }
        }
    }

    return digitCount;
}

void copy_arr(const int src[], size_t size, int dest[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        dest[i] = src[i];
    }
}

void encrypt_digits(int src[], size_t size)
{
    int temp[size];
    copy_arr(src, size, temp);

    int i;
    for (i = 0; i < size; i++)
    {
        if (temp[i] % 2 == 0 || temp[i] == 0)
        {
            src[i] = temp[i] * temp[i];
        }
        else
        {
            int currentDigit = temp[i];
            int previos = 0, next = 0;
            if (i > 0)
            {
                previos = temp[i - 1];
            }
            if (i < size - 1)
            {
                next = temp[i + 1];
            }
            src[i] = currentDigit + previos + next;
        }
    }
}

void convert_str_to_int(const char *msg, size_t size, int dest[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        dest[i] = msg[i] % 10;
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