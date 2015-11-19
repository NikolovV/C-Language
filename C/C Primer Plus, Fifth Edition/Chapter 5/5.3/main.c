#include <stdio.h>
#include <stdlib.h>
#define WEEKS_DAY 7

int main()
{
    int day, weeks, days;

    scanf("%d", &day);

    while (day>0)
    {
        weeks = day / WEEKS_DAY;
        // Optin 1.
//      days = day - (weeks*WEEKS_DAY);

        // Optin 2.
        days =day % WEEKS_DAY;
        printf("%d days are %d weeks, %d days\n", day, weeks, days);
        fflush(stdin);
        scanf("%d", &day);
    }

    return 0;
}
