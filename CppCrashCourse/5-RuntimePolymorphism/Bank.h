#pragma once
#include "Logger.h"

struct Bank
{
	Bank(Logger& logger) : m_logger{ logger } {}
	void make_transfer(long from, long to, double amount)
	{
		m_logger.log_transform(from, to, amount);
	}

private:
	Logger& m_logger;
};