/* 
 A beer time is after 1:00 PM and before 3:00 AM. Write a program that 
 enters a time in format “hh:mm tt” (an hour in range [01...12], a minute 
 in range [00...59] and AM / PM designator) and prints “beer time” or 
 “non-beer time” according to the definition above or “invalid time” 
 if the time cannot be parsed. Note that you may need to learn how to parse
 dates and times.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 10

size_t remove_new_line(char *str);

int main()
{
    char input[BUFFER];
    fgets(input, BUFFER, stdin);
    remove_new_line(input);

    char *token = strtok(input, ": ");
    char *remainder;
    int hour = (int) strtol(token, &remainder, 10);
    if (hour < 1 || hour > 12)
    {
        printf("Incorrect input.");
        exit(EXIT_FAILURE);
    }

    token = strtok(NULL, ": ");
    int minute = (int) strtol(token, &remainder, 10);
    if (minute < 0 || minute > 59)
    {
        printf("Incorrect input.");
        exit(EXIT_FAILURE);
    }

    char *tt = strtok(NULL, ": ");
    if (strcmp(tt, "AM") != 0 && strcmp(tt, "PM") != 0)
    {
        printf("Incorrect input.");
        exit(EXIT_FAILURE);
    }
    else if ((hour >= 1 && tt[0] == 'P') || (hour < 3 && tt[0] == 'A'))
    {
        printf("bear time");
    }
    else
    {
        printf("non-bear time");
    }

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