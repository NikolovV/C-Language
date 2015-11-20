/* 
 The standard C function size_t strlen(const char *s) returns the 
 size of the input string. Try implementing it yourself. 
 Think about how strings are represented in C in order
 to calculate their length.
 */

#include <stdio.h>
#include <stdlib.h>

size_t strlen_template(const char *str);

int main()
{
    printf("%d\n", strlen_template("Soft"));

    printf("%d\n", strlen_template("SoftUni"));

    char buffer[10] = {'C', '\0', 'B', 'a', 'b', 'y'};
    printf("%d\n", strlen_template(buffer));

//    char *buffer_1 = {'D', 'e', 'r', 'p'};
//    printf("%d\n", strlen_template(buffer_1));
    /* Initialization makes pointer from integer without a cast.
     * Segmentation fault */

    return (EXIT_SUCCESS);
}

size_t strlen_template(const char *str)
{
    size_t i;

    for (i = 0; str[i] != '\0'; i++);

    return i;
}