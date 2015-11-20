/* 
 Write a program that reads a text file and prints on the console its odd lines.
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void error(const char *msg);
ssize_t read_line(char **bufferPtr, size_t *bufSize, FILE *stream);

int main()
{
    char *fileName = "oddLines.txt";
    FILE *srcFile = fopen(fileName, "r");
    if (!srcFile)
    {
        error(fileName);
    }

    char *buffer = NULL;
    size_t size = 0;
    int lineNumber = 1;

    while (!feof(srcFile))
    {
        lineNumber %= 2;
        read_line(&buffer, &size, srcFile);
        if (lineNumber != 0)
        {
            printf("%s\n", buffer);
        }
        lineNumber++;
    }

    free(buffer);
    fclose(srcFile);

    return (EXIT_SUCCESS);
}

void error(const char *msg)
{
    if (errno)
    {
        perror(msg);
    }
    else
    {
        fprintf(stderr, "ERROR: %s", msg);
    }

    exit(1);
}

ssize_t read_line(char **bufferPtr, size_t *bufSize, FILE *stream)
{
    char *buffer = *bufferPtr;
    size_t size = *bufSize;

    if (buffer == NULL)
    {
        buffer = malloc(64);
        size = 64;
        if (!buffer) return 0;
    }

    size_t i = 0;
    char c = fgetc(stream);
    while (!feof(stream))
    {
        if (i == size - 1)
        {
            char *resized = realloc(buffer, 2 * size);
            if (!resized)
            {
                return 0;
            }

            buffer = resized;
            size *= 2;
        }

        if (c == '\n')
        {
            buffer[i] = '\0';
            *bufferPtr = buffer;
            *bufSize = size;

            return i;
        }

        buffer[i] = c;
        i++;

        c = fgetc(stream);
    }

    buffer[i] = '\0';
    *bufferPtr = buffer;
    *bufSize = size;

    return -1;
}