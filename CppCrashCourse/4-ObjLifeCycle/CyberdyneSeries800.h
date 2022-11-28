#pragma once
#include <cstdio>
#include <stdexcept>

struct CyberdyneSeries800
{
	CyberdyneSeries800()
	{
		printf("I am a friend of Sarah Connor.\n");
	}

	~CyberdyneSeries800()
	{
		throw::std::runtime_error{ "I'll be back\n" }; //std::terminate called when another exception is in flight
	}
};