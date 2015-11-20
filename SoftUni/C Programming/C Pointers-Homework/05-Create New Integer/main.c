/* 
 Write a function that declares and initializes and integer on the stack, 
 then returning it. Try creating the function with two different declarations:
 */

#include <stdio.h>
#include <stdlib.h>

int new_integer();
int* new_integer_ptr();

int main()
{
    /* If we don't initialized stack variable to some other in main,
       on function exit from the stack, it will be gone or unavailable, 
       or may be used from other function.
     */
    printf("New integer from the stack: %d\n", new_integer());

    /* This function create pointer to variable on heap. 
       If we don't initialized with malloc function the variable can point 
       elsewhere on the heap. After that we return the address of that variable
       to main. 
     */
    int *num = new_integer_ptr();
    printf("New integer from the stack return pointer: %d\n", *num);
    
    /* After we stop using this variable we must free this memory,
       or we will get memory leak.
     */
    free(num);

    return (EXIT_SUCCESS);
}

int new_integer()
{
    int newInt = 222;

    return newInt;
}

int* new_integer_ptr()
{
    int *newInt = malloc(sizeof (int));
    *newInt = 222;

    return newInt;
}