#include "Palindromes.h"

void print_array(char *str[], size_t size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%s", str[i]);
        if (i < size - 1)
        {
            printf(", ");
        }
    }
}

void bubble_sort(char *str[], int length)
{
    int hasSwaped = 1, compare = 0;
    while (hasSwaped)
    {
        hasSwaped = 0;
        int i;
        for (i = 0; i < length - 1; i++)
        {
            char *temp;
            compare = strcasecmp(str[i], str[i + 1]);
            if (compare >= 0)
            {
                temp = str[i + 1];
                str[i + 1] = str[i];
                str[i] = temp;
                hasSwaped = 1;
            }
        }
    }
}

int word_count(const char *str, int *palindromWords)
{
    int wordCounter = 0;
    char *strCopy = calloc(strlen(str) + 1, sizeof (char));
    strCopy = strcpy(strCopy, str);

    char *token = strtok(strCopy, " ,.?!");

    while (token)
    {
        if (is_palindrom(token))
        {
            *palindromWords += 1;
        }

        wordCounter++;
        token = strtok(NULL, " ,.?!");
    }

    free(strCopy);

    return wordCounter;
}

void free_array(char *str[], size_t size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        free(str[i]);
    }

    free(str);
}

char **extract_palindrom(char *line, int palindromWords)
{
    int palindromIndex = 0, palindromLengh = 0;
    char **str = malloc(palindromWords * sizeof (char *));
    if (!str)
    {
        fprintf(stderr, "%s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    char *lineCopy = calloc(strlen(line) + 1, sizeof (char));
    lineCopy = strcpy(lineCopy, line);

    char *token = strtok(lineCopy, " ,.?!");
    while (token)
    {
        if (is_palindrom(token))
        {
            palindromLengh = strlen(token);
            str[palindromIndex] = calloc((palindromLengh + 1), sizeof (char));
            if (!str)
            {
                fprintf(stderr, "%s", strerror(errno));
                exit(EXIT_FAILURE);
            }
            str[palindromIndex] = strcpy(str[palindromIndex], token);
            palindromIndex++;
        }

        token = strtok(NULL, " ,.?!");
    }

    free(lineCopy);

    return str;
}

int is_palindrom(char* str)
{
    int len = strlen(str);
    int i, j;

    for (i = 0, j = len - 1; i < j; ++i, --j)
    {
        if (str[i] != str[j])
        {
            return 0;
        }
    }

    return 1;
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
