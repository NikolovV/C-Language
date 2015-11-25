/* 
Create a console application that prints the current date and time.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t dateTimeNow = time(NULL);
    struct tm *DTimeNow = localtime(&dateTimeNow);
    char text[50];
    
    if(dateTimeNow != -1)
    {
        strftime(text, sizeof(text) - 1, "%d %B %Y %H:%M:%S", DTimeNow);
        printf("%s", text);
    }

    return (EXIT_SUCCESS);
}

