/* 
 Declare a variable called isFemale and assign an appropriate value corresponding to 
 your gender. Print it on the console.
 */

#include <stdio.h>
#include <stdlib.h>
#define male 1
#define female 0

int main(int argc, char** argv)
{
    int isFemale = male;
    
    if (isFemale)
    {
        printf("false");
    }
    else
    {
        printf("true");
    }

    return (EXIT_SUCCESS);
}