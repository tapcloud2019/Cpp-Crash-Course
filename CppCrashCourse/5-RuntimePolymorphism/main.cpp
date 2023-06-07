#include "Bank.h"

void Listing5_14();
void Question5_1_2_3_4();

int main()
{
	Question5_1_2_3_4();
}

void Question5_1_2_3_4()
{
	ConsoleLogger console_logger("Finance transaction complete");
	InMemoryAccountDB in_mem_accountDB;
	Bank bank{ &console_logger, &in_mem_accountDB };
	bank.retrieve_amount(1234);
	bank.retrieve_amount(2345);
	bank.retrieve_amount(3456);
	bank.set_amount(1234, 1000000);
	bank.set_amount(2345, 1500000);
	bank.set_amount(3456, 1800000);
	bank.retrieve_amount(1234);
	bank.retrieve_amount(2345);
	bank.retrieve_amount(3456);
	bank.make_transfer(1234, 2345, 5000);
	bank.make_transfer(2345, 3456, 3500);
}

void Listing5_14()
{
	ConsoleLogger console_logger("Finance transaction complete");
	FileLogger file_logger;
	/*
	Bank bank{&console_logger};
	bank.make_transfer(1000, 2000, 49.95);
	bank.set_logger(&file_logger);
	bank.make_transfer(2000, 4000, 20.00);
	*/
}