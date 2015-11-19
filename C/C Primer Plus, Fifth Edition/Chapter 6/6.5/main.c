#include <stdio.h>
/* Prints a single line of the table */
void printTableLine (int current)
{
    printf(" %10d | %10d | %10d \n", current, current*current,
           current*current*current);
}

/* Prints the table header and contents */
void printTable (int lower, int upper)
{
    int i = 0;

    printf("   Integer  |   Square   |    Cube    \n");
    printf("------------|------------|------------\n");

    for (i = lower; i <= upper; i++)
    {
        printTableLine(i);
    }
}

int main (void)
{
    /* Variable declaration */
    int lowerlimit = 0, upperlimit = 0;

    /* Retrieve upper and lower bounds; ensure that the lower bound
       is less than or equal to the upper bound */
    do
    {
        printf("Please enter the lower limit of the table: ");
        scanf("%d", &lowerlimit);
        printf("Please enter the uppper limit of the table: ");
        scanf("%d", &upperlimit);
    }
    while (lowerlimit > upperlimit);

    /* Print table  */
    printTable(lowerlimit, upperlimit);

    return 0;
}
