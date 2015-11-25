/* 
 Write a program that reads your birthday from the console as text and prints
how old you are now and how old you will be after 10 years.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    int currentYear = tm.tm_year + 1900;
    int currentMonth = tm.tm_mon + 1;
    int currentDay = tm.tm_mday;
    int birthYear, birthMonth, dayOfBirht;
    
    if (scanf("%d.%d.%d", &dayOfBirht, &birthMonth, &birthYear) != 3)
    {
        printf("Incorrect input!");
        exit(EXIT_FAILURE);
    }

    int years = currentYear - birthYear;
    if (currentMonth < birthMonth)
    {
        years--;
    }
    else if (currentMonth == birthMonth && currentDay < dayOfBirht)
    {
        years--;
    }

    printf("Now: %d\n", years);
    printf("After 10 years: %d\n", years + 10);
    return 0;

    return (EXIT_SUCCESS);
}

