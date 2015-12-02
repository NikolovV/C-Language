#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

size_t read_line(char **buffer, size_t *size);
void convert_nth_position(uint32_t *number, int position);
bool nth_position(uint32_t num, int position);

int main()
{
    char *input = NULL;
    size_t size = 0;

    read_line(&input, &size);
    uint32_t floor;
    uint64_t points = 0;
    int ligthsOnCount = 0;
    while (strcmp(input, "Stop, God damn it") != 0)
    {
        sscanf(input, "%u", &floor);

        read_line(&input, &size);
        char *token = strtok(input, " ");
        while (token)
        {
            int currentApartment = atoi(token);
            convert_nth_position(&floor, currentApartment);
            token = strtok(NULL, " ");
        }

        points+=floor;
                
        int i;
        for (i = 0; i < 32; i++)
        {
            if (nth_position(floor, i))
            {
                ligthsOnCount++;
            }
        }
        read_line(&input, &size);
    }
    
    printf("Bohemcho left %d lights on and his score is %llu",
           ligthsOnCount, points);
    
    free(input);

    return (EXIT_SUCCESS);
}

bool nth_position(uint32_t num, int position)
{
    return ((num >> position) & 1U);
}

void convert_nth_position(uint32_t *number, int position)
{
    *number ^= (1 << position);
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