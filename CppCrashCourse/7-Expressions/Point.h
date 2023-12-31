#pragma once

#include <cstdio>
#include <cstddef>
#include <new>

struct Point
{
	Point() : x{}, y{}, z{} 
	{
		printf("Point at %p constructed\n", this);
	}

	~Point()
	{
		printf("Point at %p destroyed\n", this);
	}

	double x, y, z;
};