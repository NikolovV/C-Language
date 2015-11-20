/* 
 Write a function which takes as input an integer and prints 
 the address of it in the memory. Try printing the address of the integer 
 in the function and in the main function. What is the difference and why?
 */

#include <stdio.h>
#include <stdlib.h>

void check_intInput(int *a);
void print_address_of_variable(int a);
void print_address_of_variable_ptr(int *a); 

int main()
{
    int n;
    printf("Enter number: ");
    check_intInput(&n);
    
    printf("%p - Main address of n.\n", &n);
        
    print_address_of_variable(n);
    /* Here n is pass by value. This mean it is passed to function by copy.
     That is the reason the address are different*/
    
    print_address_of_variable_ptr(&n);
    /* Here n is pass by address. This mean it passed the address of n 
     to function. And address are same.
     */
    
    return (EXIT_SUCCESS);
}

void print_address_of_variable_ptr(int *a)
{
    printf("%p - Function address of n passed by address. "
            "(Where *a point to)\n", a);
    printf("%p - Address of function pointer *a.\n", &a);
}

void print_address_of_variable(int a)
{
    printf("%p - Function address of n passed by copy.\n", &a);
}

void check_intInput(int *a)
{
    if ((scanf("%d%*c", a)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}