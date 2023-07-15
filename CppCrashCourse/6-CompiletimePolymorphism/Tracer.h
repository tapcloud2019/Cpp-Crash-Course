#pragma once
#include <cstdio>
#include <utility>

struct Tracer
{
	Tracer(const char* name) :name{ name }
	{
		printf("%s constructed.\n", name);
	}

	~Tracer()
	{
		printf("%s destructed.\n", name);
	}

private:
	const char* const name;
};