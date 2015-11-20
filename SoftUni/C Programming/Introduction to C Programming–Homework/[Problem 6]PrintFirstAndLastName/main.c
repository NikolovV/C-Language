/* 
    Create console application that prints your first and last name, 
 each at a separate line.
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    char first[] = "Ventsislav";
    char last[] = "Nikolov";
    
    printf("%s\n%s\n", first, last);
    
    return (EXIT_SUCCESS);
}