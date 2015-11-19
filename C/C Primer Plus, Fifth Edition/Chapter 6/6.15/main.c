/*
Daphne invests $100 at 10% simple interest. (That is, every year, the investment
earns an interest equal to 10% of the original investment.) Deirdre invests $100
at 5% interest compounded annually. (That is, interest is 5% of the current
balance, including previous addition of interest.) Write a program that finds how
many years it takes for the value of Deirdre's investment to exceed the value of
Daphne's investment. Also show the two values at that time.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float investmentDaphne = 0.0, investmentDeirdre = 0.0;
    float balanceDaphne = 100.0, balanceDeirdre = 100.0;
    const float rateDaphne = 0.10, rateDeirdre = 0.05;

    int year;
    while (investmentDeirdre<=investmentDaphne)
    {
    	investmentDaphne += balanceDaphne*rateDaphne;
    	investmentDeirdre += balanceDeirdre*rateDeirdre;
    	balanceDeirdre += rateDeirdre*balanceDeirdre;
    	year++;
    }
    printf("It took %d years for investment of Deirdre %.2f to exceed the investment of Daphne %.2f .",
		year, investmentDeirdre, investmentDaphne);

    return 0;
}
