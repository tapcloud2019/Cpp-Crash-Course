#pragma once
#include <cstdio>
#include <iostream>

struct Logger
{
	virtual ~Logger() = default;

	template<typename T>
	void log_transform(T from, T to, double amount) {}
};

struct ConsoleLogger : Logger
{
	ConsoleLogger(const char* msg)
	{
		message = msg;
	}

	template<typename T>
	void log_transform(T from, T to, double amount) 
	{
		std::cout << "[cons] " << from << " -> " << to << ": " << amount << std::endl;
		std::cout << "Message: " << message << std::endl;
	}

private:
	const char* message;
};

struct FileLogger : Logger
{
	template<typename T>
	void log_transform(T from, T to, double amount)
	{
		std::cout << "[file] " << from << " -> " << to << ": " << amount << std::endl;
	}
};