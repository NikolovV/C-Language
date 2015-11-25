/* 
 Declare two string(char array)variables holding your first name and last name. 
 Print them in the console (mind adding an interval between them).
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    char first[11] = "Ventsislav";
    char last[8] = "Nikolov";
    
    printf("%s %s\n", first, last);

    return (EXIT_SUCCESS);
}