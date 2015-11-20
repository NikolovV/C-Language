/* 
 Declare a string variable and assign to it the following value
 The "use" of quotations causes difficulties.\n, \t and \are also special characters.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    char someString[] = "The \"use\" of quotations causes difficulties."
                        "\\n, \\t and \\ are also special characters.";
    
    printf("%s", someString);

    return (EXIT_SUCCESS);
}

