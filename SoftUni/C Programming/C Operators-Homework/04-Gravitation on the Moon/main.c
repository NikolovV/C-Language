/* 
 The gravitational field of the Moon is approximately 17% of that 
 on the Earth. Write a program that calculates the weight of a man 
 on the moon by a given weight on the Earth.
 */

#include <stdio.h>
#include <stdlib.h>

void checkInput(double *);
void gravityOnMoon(double);

int main()
{
    double weightOnErth;
    
    printf("What's your weight on the Earth? ");
    checkInput(&weightOnErth);
    
    gravityOnMoon(weightOnErth);

    return (EXIT_SUCCESS);
}

void checkInput(double *N)
{
    if ((scanf("%lf", N)) != 1)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
}

void gravityOnMoon(double gravity)
{
    const double gravitationalMoon = 17.0 / 100;

    printf("Gravity on the Moon is %.3lf\n", gravity*gravitationalMoon);
}