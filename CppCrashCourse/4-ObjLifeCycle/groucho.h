#pragma once
#include <stdexcept>
#include <cstdio>

struct Groucho
{
	void forget(int x)
	{
		if (x == 0xFACE)
			throw std::runtime_error{ "I'd be glad to make an exception." };

		printf("Forgot 0x%x\n", x);
	}
};