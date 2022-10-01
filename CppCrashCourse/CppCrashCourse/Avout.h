#pragma once
#include <cstdio>
#include "ClockOfTheLongNow.h"

struct Avout
{
	Avout(const char* name, long year_of_apert) : name{name}, apert{year_of_apert}
	{
		clock.set_year(apert);
	}

	void announce() const
	{
		printf("My name is %s and my next apert is %d\n", name, clock.get_year());
	}

	const char* name = "Erasmas";
	long apert;
	ClockOfTheLongNow clock;
};