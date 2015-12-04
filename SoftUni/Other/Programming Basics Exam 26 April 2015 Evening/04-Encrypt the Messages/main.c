#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 1001

size_t remove_new_line(char *str);
void decrupt_massage(const char src[], char dest[], size_t size);

int main(int argc, char** argv)
{
    char input[BUFFER];
    fgets(input, BUFFER, stdin);
    remove_new_line(input);

    while (strcasecmp(input, "start") != 0)
    {
        fgets(input, BUFFER, stdin);
        remove_new_line(input);
    }

    int messegeCount = 0;
    char decrupt[BUFFER] = {0};
    size_t size = 100;
    char *result[size];
    fgets(input, BUFFER, stdin);
    int lenght = remove_new_line(input);
    while (strcasecmp(input, "end") != 0)
    {
        if (strcmp(input, "\0") == 0)
        {
            fgets(input, BUFFER, stdin);
            lenght = remove_new_line(input);
            continue;
        }

        messegeCount++;
        size = messegeCount - 1;
        decrupt_massage(input, decrupt, lenght);

        result[size] = (char *) calloc(lenght+1, sizeof (char));
        if (!result)
        {
            fprintf(stderr, "No memorry.");
            exit(EXIT_FAILURE);
        }

        strncpy(result[size], decrupt, lenght+1);
        result[size][lenght] = '\0';

        fgets(input, BUFFER, stdin);
        lenght = remove_new_line(input);
    }

    if (messegeCount == 0)
    {
        printf("No messages sent.");
    }
    else
    {
        printf("Total number of messages: %d\n", messegeCount);
        int i;
        for (i = 0; i <= size; i++)
        {
            printf("%s\n", result[i]);
            if (result[i])
            {
                free(result[i]);
            }
        }
    }

    return (EXIT_SUCCESS);
}

void decrupt_massage(const char src[], char dest[], size_t size)
{
    int i, j;
    for (i = size -1, j = 0; i >= 0, j < size; j++, i--)
    {
        if (isalpha(src[i]))
        {
            if ((src[i] >= 'a' && src[i] <= 'm') || (src[i] >= 'A' && src[i] <= 'M'))
            {
                dest[j] = src[i] + 13;
            }
            else
            {
                dest[j] = src[i] - 13;
            }
        }
        else if (isdigit(src[i]))
        {
            dest[j] = src[i];
        }
        else
        {
            switch (src[i])
            {
            case(' '):
                dest[j] = '+';
                break;
            case(','):
                dest[j] = '%';
                break;
            case('.'):
                dest[j] = '&';
                break;
            case('?'):
                dest[j] = '#';
                break;
            case('!'):
                dest[j] = '$';
                break;
            }
        }
    }
    dest[j] = '\0';
}

size_t remove_new_line(char *str)
{
    int lenght = strlen(str);
    if (str[lenght - 1] == '\n')
    {
        str[lenght - 1] = '\0';
    }
    return lenght - 1;
}