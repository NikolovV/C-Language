#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define CONDITION 6000

size_t read_line(char **buffer, size_t *size);

int main()
{
    char *DAYS[] = {"Monday", "Tuesday", "Wednesday", "Thursday",
        "Friday", "Saturday", "Sunday"};
    char *input = NULL;
    size_t size = 0;
    read_line(&input, &size);

    int sum, perfectGirl = 0, dayNumber;
    while (strcmp(input, "Enough dates!"))
    {
        sum = 0;
        char *day = strtok(input, "\\");
        int i;
        for (i = 0; i < 7; i++)
        {
            if (strcmp(day, DAYS[i]) == 0)
            {
                break;
            }
        }
        sum += i + 1;

        char *phone = strtok(NULL, "\\");
        char *braSize = strtok(NULL, "\\");
        char *girlName = strtok(NULL, "\\");

        for (i = 0; i < strlen(phone); i++)
        {
            sum += phone[i] - '0';
        }

        char *remainder;
        sum += strtol(braSize, &remainder, 10)*(*remainder);

        sum -= girlName[0] * strlen(girlName);

        if (sum < CONDITION)
        {
            printf("Keep searching, %s is not for you.\n", girlName);
        }
        else
        {
            printf("%s is perfect for you.\n", girlName);
            perfectGirl++;
        }

        read_line(&input, &size);
    }
    printf("%d", perfectGirl);

    free(input);

    return (EXIT_SUCCESS);
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

    return index - 1;
}