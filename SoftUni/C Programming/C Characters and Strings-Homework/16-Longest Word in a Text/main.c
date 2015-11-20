/* 
 Write a program to find the longest word in a text.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER 100

char *line_reading(size_t lenght);
char *longest_word(char *str);

int main()
{
    printf("Enter text\n");
    char *line = line_reading(BUFFER);
    
    char *longestWord = longest_word(line);
    printf("Longest word -> %s", longestWord);
    
    free(line);
    free(longestWord);

    return (EXIT_SUCCESS);
}

char *longest_word(char *str)
{
    char *token = strtok(str, " ,.!?");
    int len = strlen(token);
    char *result = calloc(1, sizeof (char));
    if (!result)
    {
        fprintf(stderr, "%s\n", strerror(errno));
    }

    int biggestWord = 0;

    while (token)
    {
        len = strlen(token);
        if (len > biggestWord)
        {
            biggestWord = len;
            char *relocResult = realloc(result, biggestWord + 1);
            if (!result)
            {
                fprintf(stderr, "%s\n", strerror(errno));
            }
            result = relocResult;
            strcpy(result, token);
        }

        token = strtok(NULL, " ,.!?");
    }

    return result;
}

char *line_reading(size_t lenght)
{
    char *lineRead = malloc(8 * sizeof (char *));
    char *linePtr = lineRead;
    size_t lenMax = 8, len = lenMax - 1;
    int c = 0;

    if (!lineRead)
    {
        return NULL;
    }

    while (c != EOF)
    {
        c = fgetc(stdin);
        if (c == '\n')
        {
            break;
        }
        else if (len > lenght)
        {
            break;
        }

        if (--len == 0)
        {
            len = lenMax;
            char* reallocated_line = (char*) realloc(lineRead, lenMax *= 2);

            if (!reallocated_line)
            {
                free(lineRead);
                return NULL;
            }

            linePtr = reallocated_line + (linePtr - lineRead);
            lineRead = reallocated_line;
        }

        *linePtr++ = c;
    }

    *linePtr = '\0';

    return lineRead;
}