/*
Chuckie Lucky won a million dollars, which he places in an account that earns 8%
a year. On the last day of each year, Chuckie withdraws $100,000. Write a
program that finds out how many years it takes for Chuckie to empty his account.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int ChuckieLuckyWon = 1000000;
	float account = 1.08;
	const int withdraws = 100000;
	float balance;
	int years = 0;

	balance = (float)ChuckieLuckyWon*account - (float)withdraws;
	while (balance>=0.0)
	{
		balance = balance*account -(float)withdraws;
		years++;
	}
	printf("It takes %d years for Chuckie to empty his account\n", years);
    return 0;
}
