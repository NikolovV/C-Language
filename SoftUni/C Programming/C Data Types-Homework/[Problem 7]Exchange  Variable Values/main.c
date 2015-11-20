/* 
 Declare two integer variables a and b and assign them with 5 and 10 
 and after that exchange their values by using some programming logic.
 Print the variable values before and after the exchange.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int a = 5, b = 10;

    printf("Now a = %d and b = %d\n", a, b);
    printf("Exchanging....\n");
    
    a = a + b;
    b = a - b;
    a = a - b;

    printf("After the exchange a = %d b = %d\n", a, b);
    return (EXIT_SUCCESS);
}

