#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

#define BUFFER 100

size_t remove_new_line(char *str);

int main()
{
    char input[BUFFER];
    fgets(input, BUFFER, stdin);
    remove_new_line(input);

    uint32_t minute, second;
    uint32_t totalSeconds = 0;
    int gameCount = 0;

    while (strcmp(input, "Quit") != 0)
    {
        minute = atoi(strtok(input, ":"));
        second = atoi(strtok(NULL, ":"));

        if ((minute >= 0 && minute <= 99) && (second >= 0 && second <= 59))
        {
            totalSeconds += (minute * 60) + second;
        }
        gameCount++;

        fgets(input, BUFFER, stdin);
        remove_new_line(input);
    }

    float averageSeconds = totalSeconds / ((float) gameCount);
    averageSeconds = round(averageSeconds);

    if (averageSeconds < 720)
    {
        printf("Gold Star\n");
    }
    else if (averageSeconds >= 720 && averageSeconds <= 1440)
    {
        printf("Silver Star\n");
    }
    else
    {
        printf("Bronze Star\n");
    }

    printf("Games - %d \\ Average seconds - %.0f", gameCount, averageSeconds);

    return (EXIT_SUCCESS);
}

size_t remove_new_line(char *str)
{
    int lenght = strlen(str);
    if (str[lenght - 1] == '\n')
    {
        str[lenght - 1] = '\0';
    }
    return lenght;
}