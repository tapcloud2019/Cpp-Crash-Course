#pragma once
#include <stdexcept>
#include <cstdio>
#include <cstring>

struct SimpleString
{
	SimpleString(size_t max_size) : max_size{ max_size },
		length{}
	{
		if (max_size == 0)
			throw std::runtime_error("Max size must be at least 1");

		buffer = new char[max_size];
		buffer[0] = 0;
	}

	//copy constructor
	SimpleString(const SimpleString& other) : max_size{other.max_size},
												buffer{new char[other.max_size]},
												length{other.length}
	{
		std::strncpy(buffer, other.buffer, max_size);
	}

	~SimpleString()
	{
		delete[] buffer;
	}

	void print(const char* tag) const
	{
		printf("%s: %s", tag, buffer);
	}

	bool append_line(const char* x)
	{
		const auto x_len = strlen(x);

		//exceed the max string length
		if (x_len + length + 2 > max_size)
			return false;

		std::strncpy(buffer + length, x, max_size - length);
		length += x_len;
		buffer[length++] = '\n';
		buffer[length] = 0;

		return true;
	}

private:
	size_t max_size;
	char* buffer;
	size_t length;
};

struct SimpleStringOwner
{
	SimpleStringOwner(const char* x) : string{ 10 }
	{
		if (!string.append_line(x))
			throw std::runtime_error{ "Not enough memory!" };

		string.print("Constructed");
	}

	~SimpleStringOwner()
	{
		string.print("About to destroy");
	}

private:
	SimpleString string;
};