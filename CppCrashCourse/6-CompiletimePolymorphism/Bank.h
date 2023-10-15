#pragma once
#include <iostream>
#include "Logger.h"

template<typename Y>
struct Bank
{
	Bank() : m_logger{ NULL },m_accountDB{NULL}{};

	void set_logger(ConsoleLogger* new_logger)
	{
		m_logger = new_logger;
	}

	template<typename T>
	void make_transfer(T from, T to, double amount)
	{
		if (m_logger)
			m_logger->log_transform<T>(from, to, amount);
	}

	void set_accountDB(Y* new_accountDB)
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
	ConsoleLogger* m_logger;
	Y* m_accountDB;
};