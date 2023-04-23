#include "Bank.h"

void Listing5_12();

int main()
{
	Listing5_12();
}

void Listing5_12()
{
	ConsoleLogger logger;
	Bank bank{ logger };
	bank.make_transfer(1000, 2000, 49.95);
	bank.make_transfer(2000, 4000, 20.00);
}