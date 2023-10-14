#pragma once
#include <iostream>
#include "Logger.h"

struct Bank
{
	Bank() : m_logger{ NULL } {};

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

private:
	ConsoleLogger* m_logger;
};