#include <stdio.h>
#include <stdlib.h>
#define SUM_TO_FARENH 32
#define ADD_TO_FARENH 1.8
#define KELVIN 273.16

void Temperatures(double temperature)
{
	double celsius, kelvin, fahrenheit = temperature;

	celsius = ADD_TO_FARENH*fahrenheit + SUM_TO_FARENH;
	kelvin = KELVIN + celsius;
	printf("celsius = %.2f, kelvin = %.2f, fahrenheit = %.2f", celsius, kelvin, fahrenheit);

}
int main()
{
	double fahrenheit;

	while ((scanf("%lf", &fahrenheit)==1))
	{
		Temperatures(fahrenheit);
	}
    return 0;
}
