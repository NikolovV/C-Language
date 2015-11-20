/* 
 A marketing company wants to keep record of its employees. 
 Each record would have the following characteristics:
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    char firstName[] = "Amanda";
    char lastName[] = "Jonson";
    unsigned char age = 27;
    char gender = 'f';
    long long personalIDNumber = 8306112507;
    unsigned int uniqueEmployeeNumber = 27563571;
    
    printf("First name: %s\n", firstName);
    printf("Last name: %s\n", lastName);
    printf("Age: %d\n", age);
    printf("Gender: %c\n", gender);
    printf("Personal ID: %lld\n", personalIDNumber);
    printf("Unique Employee number: %u\n", uniqueEmployeeNumber);

    return (EXIT_SUCCESS);
}

