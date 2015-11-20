/* 
 The standard C function strncat(char *dest, const char *src, size_t n)
 concatenates the strings located in the src and the dest buffer into the dest
 buffer. The variable n shows the length from the src string to be concatenated.
 Try implementing that function yourself. 
 Think about how you can get the length of the two strings.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strncat_template(char *dest, const char *src, size_t n);

int main()
{
//    char buffer[10] = "Soft";
//    strncat_template(buffer, "Uni", 7);
//    printf("%s\n", buffer);
    /* When we pass this char it does contain \0.
     * And we must manual include in the end of string
     * wich is in this example - 7.
     */
//    char buffer_2[5] = "Soft";
//    strncat_template(buffer_2, "ware University", 15);
    /* The destination buffer length is not enough.
     * Stack smashing detected!
     */

//    char buffer_3[10] = "C";
//    strncat_template(buffer_3, " is cool", 8);
//    printf("%s\n", buffer_3);
    
    char *buffer_4 = "C";
    strncat_template(buffer_4, " is cool", 8);
    /* Segmentation fault. Trying to write on constant char.*/
    
    return (EXIT_SUCCESS);
}

char *strncat_template(char *dest, const char *src, size_t n)
{
    size_t dest_len = strlen(dest);
    size_t i;
   
    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';

    return dest;
}