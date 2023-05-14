#pragma once
#include "Logger.h"
#include "AccountDB.h"
#include <iostream>

struct Bank
{
	Bank(Logger* logger, AccountDB* accountDB) : m_logger{ logger },
												m_accountDB{ accountDB }{}

	void set_logger(Logger* new_logger)
	{
		m_logger = new_logger;
	}

	void make_transfer(long from, long to, double amount)
	{
		if(m_logger)
			m_logger->log_transform(from, to, amount);
	}

	void set_accountDB(AccountDB* new_accountDB)
	{
		m_accountDB = new_accountDB;
	}

	void set_amount(long id, double amount)
	{
		m_accountDB->set_amount(id, amount);
	}

	void retrieve_amount(long id)
	{
		double balance = m_accountDB->retrieve_amount(id);
		std::cout << "account: " << id << " balance: " << balance << std::endl;
	}

private:
	Logger* m_logger;
	AccountDB* m_accountDB;
};