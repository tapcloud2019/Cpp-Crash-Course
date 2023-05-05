#include "Bank.h"

void Listing5_14();

int main()
{
	Listing5_14();
}

void Listing5_14()
{
	ConsoleLogger console_logger;
	FileLogger file_logger;
	Bank bank{ &console_logger };
	bank.make_transfer(1000, 2000, 49.95);
	bank.set_logger(&file_logger);
	bank.make_transfer(2000, 4000, 20.00);
}