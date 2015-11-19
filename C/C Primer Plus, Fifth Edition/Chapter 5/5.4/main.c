#include <stdio.h>
#include <stdlib.h>

int main()
{
    float cm, feet, inches;

    while (scanf("%f", &cm)==1)
    {
        printf("Enter a height in centimeters: ");
        feet = (int)cm /36.4;
        inches = cm / 2.54;
        printf("%.1f cm = %d feet, %.1f inches\n", cm, (int)feet, inches);
    }

    return 0;
}
