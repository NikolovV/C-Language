/* 
 Write  a program that reads from the console  a string of maximum 20 
 characters. If the length of the string is less than 20, the rest 
 of the characters should be filled with asterisks '*'.
 Print the resulting string on the console.
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER 21

char * line_reading(size_t lenght);
void fill_to_end(char *str, size_t lengh);

int main()
{
    char *bufLine = line_reading(BUFFER);

    printf("Line before\n%s", bufLine);

    fill_to_end(bufLine, BUFFER);
    printf("\nLine after\n%s", bufLine);

    free(bufLine);

    return (EXIT_SUCCESS);
}

void fill_to_end(char *str, size_t lengh)
{
    int i;
    for (i = 0; i < lengh; i++)
    {
        if (str[i] == '\0' && i < lengh - 1)
        {
            while (i < lengh - 1)
            {
                str[i] = '*';
                i++;
            }
            str[i] = '\0';
            break;
        }
        else if (str[lengh - 1] != '\0')
        {
            str[lengh - 1] = '\0';
        }
    }
}

char *line_reading(size_t lenght)
{
    char *lineRead = malloc(8 * sizeof (char));
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