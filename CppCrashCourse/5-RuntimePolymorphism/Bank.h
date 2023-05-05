#pragma once
#include "Logger.h"

struct Bank
{
	Bank(Logger* logger) : m_logger{ logger } {}

	void set_logger(Logger* new_logger)
	{
		m_logger = new_logger;
	}

	void make_transfer(long from, long to, double amount)
	{
		if(m_logger)
			m_logger->log_transform(from, to, amount);
	}

private:
	Logger* m_logger;
};