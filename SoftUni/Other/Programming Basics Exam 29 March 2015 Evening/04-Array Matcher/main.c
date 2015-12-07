#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t read_line(char **buffer, size_t *size);
char *join_arr(const char srcA[], const char srcB[]);
char *right_exclude(const char srcA[], const char srcB[]);
char *left_exclude(const char srcA[], const char srcB[]);
void bubble_sort(char str[], int length);

int main()
{
    char *input = NULL;
    size_t size = 0;

    read_line(&input, &size);

    char *firstArray = strtok(input, "\\");
    char *secondArray = strtok(NULL, "\\");
    char *command = strtok(NULL, "\\");

    char *result = NULL;
    if (strcmp(command, "join") == 0)
    {
        result = join_arr(firstArray, secondArray);
    }
    else if (strcmp(command, "right exclude") == 0)
    {
        result = right_exclude(firstArray, secondArray);
    }
    else if (strcmp(command, "left exclude") == 0)
    {
        result = left_exclude(firstArray, secondArray);
    }

    printf("%s", result);

    free(input);
    free(result);

    return (EXIT_SUCCESS);
}

void bubble_sort(char src[], int length)
{
    int hasSwaped = 1;
    while (hasSwaped)
    {
        hasSwaped = 0;
        int i;
        for (i = 0; i < length - 1; i++)
        {
            char temp;
            if (src[i] > src[i + 1])
            {
                temp = src[i + 1];
                src[i + 1] = src[i];
                src[i] = temp;
                hasSwaped = 1;
            }
        }
    }
}

char *join_arr(const char srcA[], const char srcB[])
{
    size_t lenA = strlen(srcA);
    size_t lenB = strlen(srcB);
    size_t tempSize = lenA + lenB + 1;
    int i, index = 0;
    char temp[tempSize];
    for (i = 0; i < lenA; i++)
    {
        if (strchr(srcB, srcA[i]) != NULL)
        {
            temp[index++] = srcA[i];
            temp[index] = '\0';
        }
    }
    bubble_sort(temp, index);
    char *result = (char *) malloc(index+1);
    strncpy(result, temp, index);
    result[index]='\0';

    return result;
}

char *right_exclude(const char srcA[], const char srcB[])
{
    size_t lenA = strlen(srcA);
    size_t lenB = strlen(srcB);
    size_t tempSize = lenA + lenB + 1;
    int i, j, index = 0;
    char temp[tempSize];
    for (i = 0; i < lenA; i++)
    {
        if (strchr(srcB, srcA[i]) == NULL)
        {
            temp[index++] = srcA[i];
            temp[index] = '\0';
        }
    }

    bubble_sort(temp, index);
    char *result = (char *) malloc(index + 1);
    strncpy(result, temp, index);
    result[index] = '\0';

    return result;
}

char *left_exclude(const char srcA[], const char srcB[])
{
    size_t lenA = strlen(srcA);
    size_t lenB = strlen(srcB);
    size_t tempSize = lenA + lenB + 1;
    int i, j, index = 0;
    char temp[tempSize];
    for (i = 0; i < lenB; i++)
    {
        if (strchr(srcA, srcB[i]) == NULL)
        {
            temp[index++] = srcB[i];
            temp[index] = '\0';
        }
    }

    bubble_sort(temp, index);
    char *result = (char *) malloc(index + 1);
    strncpy(result, temp, index);
    result[index] = '\0';

    return result;
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