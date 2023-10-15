#pragma once
#pragma once
#include <map>

struct AccountDB
{
	virtual ~AccountDB() = default;
	virtual double retrieve_amount(long id) = 0;
	virtual void set_amount(long id, double amount) = 0;
};

struct InMemoryAccountDB : AccountDB
{
	virtual double retrieve_amount(long id)
	{
		return accounts[id];
	}

	virtual void set_amount(long id, double amount)
	{
		accounts[id] = amount;
	}

private:
	std::map<long, double> accounts{ {1234, 100000}, {2345, 150000}, {3456, 200000} };
};