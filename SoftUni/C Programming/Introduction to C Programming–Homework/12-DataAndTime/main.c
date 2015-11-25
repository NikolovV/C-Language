/* 
Create a console application that prints the current date and time.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char* now()
{
    time_t t;
    time(&t);
    return asctime(localtime(&t));
}

int main(int argc, char** argv)
{
    printf("Current time is: %s", now());

    return (EXIT_SUCCESS);
}

