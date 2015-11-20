/* 
 Write a function that reads an entire line from the standard input stream 
 (until end of line ('\n')or end of file (EOF) and returns a pointer to the 
 read string. The function should be able to read lines of unknown size.
 The returned string's length should be equal to its allocated memory.
 */

#include <stdio.h>
#include <stdlib.h>

char *line_reading();

int main()
{
    char *line = line_reading();
    printf("%s\n", line);
    
    free(line);

    return (EXIT_SUCCESS);
}

char *line_reading(void)
{
    char *lineRead = malloc(8);
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