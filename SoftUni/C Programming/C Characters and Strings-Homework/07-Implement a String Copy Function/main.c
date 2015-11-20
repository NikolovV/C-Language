/* 
 The standard C function strncpy(char *dest, const char *src, size_t n)
 copies a chunk from the src string to the dest buffer. 
 Try implementing that function manually. Try doing it without a buffer, 
 by returning a string created in the body of the function. Does it work? 
 Think why it does or it doesn't. How can you modify it to work/break it.
 */

#include <stdio.h>
#include <stdlib.h>

char *strncpy_template(char *dest, const char *src, size_t n);

int main()
{
    char firstString[10];
    strncpy_template(firstString, "SoftUni", 7);
    printf("%s\n", firstString);
    
    char secondString[5];
    strncpy_template(secondString, "SoftUni", 3);
    printf("%s\n", secondString);
    
    char thirdString[10];
    strncpy_template(thirdString, "C is cool", 0);
    printf("%s\n", thirdString);
    
    char *resualt = strncpy_template("SoftUni", 3);
    /* error too few arguments to function*/


    return (EXIT_SUCCESS);
}

char *strncpy_template(char *dest, const char *src, size_t n)
{
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }

    dest[i] = '\0';

    return dest;
}