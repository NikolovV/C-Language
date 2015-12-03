#include <stdio.h>
#include <stdlib.h>

size_t read_line(char **buffer, size_t *size);
int get_mask(char *code, size_t size);
void decrupt(char *msg, size_t size, int mask);
void print_reverced(char *msg, size_t size);

int main()
{
    char *buf = NULL;
    size_t size = 0, readCode;

    // Function read_line return bytes readed without '\0'.
    readCode = read_line(&buf, &size);
    int mask = get_mask(buf, readCode);

    readCode = read_line(&buf, &size);
    decrupt(buf, readCode, mask);

    print_reverced(buf, readCode);

    free(buf);

    return (EXIT_SUCCESS);
}

void print_reverced(char *msg, size_t size)
{
    int i;
    for (i = size; i >= 0; i--)
    {
        printf("%c", msg[i]);
    }
}

void decrupt(char *msg, size_t size, int mask)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if ((msg[i] % mask) == 0)
        {
            msg[i] += mask;
        }
        else
        {
            msg[i] -= mask;
        }
    }
}

int get_mask(char *code, size_t size)
{
    int sum = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        sum += code[i];
    }

    int mask = sum, remainder;
    sum = 0;
    while (mask || sum > 9)
    {
        remainder = mask % 10;
        mask /= 10;
        sum += remainder;

        if (mask == 0 && sum > 9)
        {
            mask = sum;
            sum = 0;
            while (mask)
            {
                remainder = mask % 10;
                mask /= 10;
                sum += remainder;
            }
        }
    }

    return sum;
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