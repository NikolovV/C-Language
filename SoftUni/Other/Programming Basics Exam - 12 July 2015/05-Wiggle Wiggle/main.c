#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define BIT_LENGHT 64

uint64_t nth_position(uint64_t num, uint16_t position);
void set_bit(uint64_t *number, int position, int bit_value);
void print_in_binary(uint64_t number);
size_t read_line(char **buffer, size_t *size);
void fill_array(const char src[], uint64_t dest[], size_t size);
void reverce_bit(uint64_t *arr, size_t size);

int main()
{
    char *buf = NULL;
    size_t size = 0;
    size_t spacesCount = read_line(&buf, &size);
    size_t digitCount = spacesCount + 1;
    
    uint64_t digits[digitCount];
    fill_array(buf, digits, digitCount);

    int i = 0;
    for (i = 0; i < digitCount; i += 2)
    {
        int j;
        for (j = 0; j < BIT_LENGHT; j += 2)
        {
            int currentBitOne = nth_position(digits[i], j);
            int currentBitTwo = nth_position(digits[i + 1], j);

            if (currentBitOne != currentBitTwo)
            {
                set_bit(&digits[i], j, currentBitTwo);
                set_bit(&digits[i + 1], j, currentBitOne);
            }
        }
    }

    reverce_bit(digits, digitCount);

    for (i = 0; i < digitCount; i++)
    {
        set_bit(&digits[i], 63, 0);
        printf("%llu ", digits[i]);
        print_in_binary(digits[i]);
        printf("\n");
    }

    free(buf);

    return (EXIT_SUCCESS);
}

void reverce_bit(uint64_t *arr, size_t size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = ~arr[i];
    }
}

void fill_array(const char src[], uint64_t dest[], size_t size)
{
    char *token;
    dest[0] = strtoll(src, &token, 10);
    int i;
    for (i = 1; i < size; i++)
    {
        dest[i] = strtoll(token, &token, 10);
    }
}

void set_bit(uint64_t *number, int position, int bit_value)
{
    if (bit_value == 1)
    {
        *number |= ((uint64_t )bit_value << position);
    }
    else
    {
        *number &= (~(1LLU << position));
    }
}

uint64_t nth_position(uint64_t num, uint16_t position)
{
    return ((num >> position) & 1LLU);
}

void print_in_binary(uint64_t number)
{
    int i;
    for (i = 62; i >= 0; i--)
    {
        int bit = nth_position(number, i);
        printf("%d", bit);
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

    size_t index = 0, spaceCount = 0;
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
        if (c == ' ')
        {
            spaceCount++;
        }


        line[index] = c;
        index++;
        c = getchar();
    }

    line[index] = '\0';
    *buffer = line;
    *size = currentSize;

    return spaceCount;
}