#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t begin, end;
    double time_spent;

    begin = clock();
    
    // stack ~0.000093
    /*
    char firstName[15], lastName[15];
    scanf("%29s %29s", firstName, lastName);
    printf("%s %s\n", lastName, firstName);    
    */
    
    // heap ~0.000170
    char *firstName, *lastName;
    firstName = malloc(30);
    lastName = malloc(30);
    scanf("%29s %29s", firstName, lastName);
    printf("%s %s\n", lastName, firstName); 
    free(firstName);
    free(lastName);

    end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("%.3lf seconds\n", time_spent);

    return 0;
}
